// -*-Faust-*-

declare name "master_me";
declare version "1.0";
declare author "Klaus Scheuermann";
declare license "GPLv3";

// double precision -double needed!

ebu = library("lib/ebur128.dsp");
import("stdfaust.lib");

// init values

Nch = 2; //number of channels
Nba = 8; //number of bands of the multiband compressor

init_noisegate_threshold = -70; // not used in voc version

init_leveler_target = -18;
init_leveler_maxboost = 40;
init_leveler_maxcut = 40;
init_leveler_gatethreshold = -45;
init_leveler_speed = 25;

init_kneecomp_thresh = -3;
init_kneecomp_postgain = 0;

init_limiter_lad_ceil = -2;
init_limiter_postgain = 0;

init_brickwall_ceiling = -1;
init_brickwall_release = 75;


target = vslider("v:soundsgood/h:easy/[3]Target[unit:dB][symbol:target]", init_leveler_target,-50,0,1);


// main
process =
    //tone_generator :
    si.bus(2)


    : bp2(checkbox("[symbol:global_bypass]global bypass"),(
    in_gain
    : peakmeter_in
    : lufs_meter_in
    : dc_blocker_bp
    : mono_bp
         : (phase_invert_L , phase_invert_R)
    //: correlate_meter
    : correlate_correct_bp

    : gate_bp
    : eq_bp

    : (
        leveler_sc(target)

        : (sc_compressor


              : mscomp_bp
             // : kneecomp_bp

           : limiter_rms_bp
             // : brickwall_bp

           : brickwall_no_latency_bp

          )~(si.bus(2))
    )~(si.bus(2))
    ))

    : lufs_meter_out
    : peakmeter_out
;

// stereo bypass with si.smoo fading
bp2(sw,pr) =  _,_ <: _,_,pr : (_*sm,_*sm),(_*(1-sm),_*(1-sm)) :> _,_ with {
    sm = sw : si.smoo;
};

// DC FILTER
dc_blocker_bp = bp2(sw,dc_blocker(2)) with {
  sw = 1 - checkbox("v:soundsgood/t:expert/h:[1]pre-processing/[4][symbol:dc_blocker]dc blocker");
};

dc_blocker(N) = par(i,N,fi.dcblockerat(dc_filter_freq))
with {
  dc_filter_freq = 10.0;
};

// phase switches
phase_invert_L = _ <: _,_ : (_ : *(-1)),_ : _*sw,_*(1-sw) :> _ with{
  sw = checkbox("v:soundsgood/t:expert/h:[1]pre-processing/[2][symbol:phase_l]phase L");
};
phase_invert_R = _ <: _,_ : (_ : *(-1)),_ : _*sw,_*(1-sw) :> _ with{
  sw = checkbox("v:soundsgood/t:expert/h:[1]pre-processing/[3][symbol:phase_r]phase R");
};

// input gain
in_gain = par(i,2,(_*g)) with{
  g = vslider("v:soundsgood/t:expert/h:[1]pre-processing/[1][symbol:in_gain][unit:dB]input gain",0,-100,24,1) : ba.db2linear;
};

// stereo to m/s encoder
ms_enc = _*0.5,_*0.5 <: +, -;

// m/s to stereo decoder
ms_dec = _,_ <: +, -;

// peak meters
peakmeter_in = in_meter_l,in_meter_r with {
envelop = abs : max(ba.db2linear(-70)) : ba.linear2db : min(10)  : max ~ -(80.0/ma.SR);
in_meter_l(x) = attach(x, envelop(x) : vbargraph("v:soundsgood/h:easy/[0][symbol:peakmeter_in_l]in L[unit:dB]", -70, 0));
in_meter_r(x) = attach(x, envelop(x) : vbargraph("v:soundsgood/h:easy/[1][symbol:peakmeter_in_r]in R[unit:dB]", -70, 0));
           };
peakmeter_out = out_meter_l,out_meter_r with {
  envelop = abs : max(ba.db2linear(-70)) : ba.linear2db : min(10)  : max ~ -(80.0/ma.SR);
  out_meter_l(x) = attach(x, envelop(x) : vbargraph("v:soundsgood/h:easy/[8][symbol:peakmeter_out_l]out L[unit:dB]", -70, 0));
  out_meter_r(x) = attach(x, envelop(x) : vbargraph("v:soundsgood/h:easy/[9][symbol:peakmeter_out_r]out R[unit:dB]", -70, 0));
};





// GATE
gate_bp = bp2(checkbox("v:soundsgood/t:expert/h:[2]gate/[1][symbol:gate_bypass]gate bypass"),gate);
gate(x,y) = attach(x,gateview(abs(x)+abs(y))),y : ef.gate_stereo(gate_thresh,gate_att,gate_hold,gate_rel) with{
  gate_thresh = vslider("v:soundsgood/t:expert/h:[2]gate/[2][symbol:gate_threshold][unit:dB]gate threshold",-90,-90,0,1);
  gate_att = vslider("v:soundsgood/t:expert/h:[2]gate/[3][symbol:gate_attack][unit:ms]gate attack",0,0,100,1) *0.001;
  gate_hold = vslider("v:soundsgood/t:expert/h:[2]gate/[4][symbol:gate_hold][unit:ms]gate hold",50,0,500,1) *0.001;
  gate_rel = vslider("v:soundsgood/t:expert/h:[2]gate/[5][symbol:gate_release][unit:ms]gate release",500,50,5000,1) *0.001;
  gateview = ef.gate_gain_mono(gate_thresh,gate_att,gate_hold,gate_rel) : ba.linear2db : max(-70) :
      vbargraph("v:soundsgood/t:expert/h:[2]gate/[6][symbol:gate_meter][unit:dB]gate meter", -70,0);
};



// correlation meter
correlate_meter(x,y) = x,y <: x , attach(y, (corr(t) : meter_correlate_meter )) : _,_ with {
  t = .2; // averaging period in seconds

  avg(t, x) = fi.pole(p, (1 - p) * x) // 1-pole lowpass as average
  with {
    p = exp((((-2.0 * ma.PI) / t) / ma.SR));
  };
  var(t, x) = avg(t, (x - avg(t, x)) ^ 2); // variance
  sd(t, x) = sqrt(var(t, x)); // standard deviation
  cov(t, x1, x2) = avg(t, (x1 - avg(t, x1)) * (x2 - avg(t, x2))); // covariance
  corr(t, x1, x2) = cov(t, x1, x2) / max(ma.EPSILON, (sd(t, x1) * sd(t, x2))); // correlation

  meter_correlate_meter = vbargraph("v:soundsgood/t:expert/h:[1]pre-processing/correlation meter[symbol:correlation_meter]",-1,1);
};

// stereo correction based on correlation
correlate_correct_bp = bp2(1 - checkbox("v:soundsgood/t:expert/h:[1]pre-processing/[5][symbol:stereo_correct]stereo correct"), correlate_correct);
correlate_correct(l,r) = out_pos1, out_neg1, out_0, out_pos, out_neg :> _,_ with {

  t = .2; // averaging period in seconds

  avg(t, x) = fi.pole(p, (1 - p) * x) // 1-pole lowpass as average
  with {
    p = exp((((-2.0 * ma.PI) / t) / ma.SR));
  };
  var(t, x) = avg(t, (x - avg(t, x)) ^ 2); // variance
  sd(t, x) = sqrt(var(t, x)); // standard deviation
  cov(t, x1, x2) = avg(t, (x1 - avg(t, x1)) * (x2 - avg(t, x2))); // covariance
  corr(t, x1, x2) = cov(t, x1, x2) / max(ma.EPSILON, (sd(t, x1) * sd(t, x2))); // correlation


  th =.0001;
  corr_pos1 = avg(t, (corr(t,l,r) > (1-th))) : smoothing /*: vbargraph("[5]1[symbol:corr_pos1]",0,1)*/;
  corr_neg1 = avg(t, corr(t,l,r) < (-1+th)) : smoothing /*: vbargraph("[9]-1[symbol:]corr_neg1",0,1)*/;
  corr_0 = avg(t, ((corr(t,l,r) < th) & (corr(t,l,r) > (0-th)))) : smoothing /*: vbargraph("[7]0[symbol:corr_0]",0,1)*/;
  corr_pos = avg(t, ((corr(t,l,r) > (0+th)) & (corr(t,l,r) < (1-th)))) : smoothing /*: vbargraph("[6]>0,<1[symbol:corr_pos]",0,1)*/;
  corr_neg = avg(t, ((corr(t,l,r) > (-1+th)) & (corr(t,l,r) < (0-th)))) : smoothing /*: vbargraph("[8]>-1,<0[symbol:corr_neg]",0,1)*/;

  smoothing = lp1p(2) ;

  out_pos1 = ((l * corr_pos1 + r * corr_pos1) /2) , ((l * corr_pos1 + r * corr_pos1) /2);
  out_neg1 = ((l * corr_neg1 + (-r) * corr_neg1) /2) , ((l * corr_neg1 + (-r) * corr_neg1) /2);
  out_0 = (l * corr_0 + r * corr_0) , (l * corr_0 + r * corr_0);
  out_pos = l * corr_pos , r * corr_pos;
  out_neg = l * corr_neg , r * corr_neg; // old: out_neg = l * corr_neg , (0-(r * corr_neg));

  lp1p(cf) = si.smooth(ba.tau2pole(1/(2*ma.PI*cf)));
};

// Mono Switch
mono_bp = bp2(1 - checkbox("v:soundsgood/t:expert/h:[1]pre-processing/[2][symbol:mono]mono"),mono);
mono = _*0.5,_*0.5 <: +, +;

// EQ with bypass
eq_bp = bp2(checkbox("v:soundsgood/t:expert/h:[3]eq/[1][symbol:eq_bypass]eq bypass"),eq);
eq = hp_eq : tilt_eq : side_eq_b with{
  // HIGHPASS
  hp_eq = par(i,2,fi.highpass(1,freq)) with {
  freq = vslider("v:soundsgood/t:expert/h:[3]eq/h:[1]highpass/[1]eq highpass freq [unit:Hz] [scale:log] [symbol:eq_highpass_freq]", 5, 5, 1000,1);
};

  // TILT EQ STEREO
  tilt_eq = par(i,2,_) : par(i,2, fi.lowshelf(N, -gain, freq) : fi.highshelf(N, gain, freq)) with{
    N = 1;
    gain = vslider("v:soundsgood/t:expert/h:[3]eq/h:[2]tilt eq/[1]eq tilt gain [unit:dB] [symbol:eq_tilt_gain]",0,-6,6,0.5);
    freq = 630; //vslider("v:soundsgood/t:expert/h:[3]eq/h:[2]tilt eq/[2]eq tilt freq [unit:Hz] [scale:log] [symbol:eq_tilt_freq]", 630, 200, 2000,1);
  };



  // SIDE EQ
  side_eq_b =  ms_enc : _,band_shelf(freq_low,freq_high,eq_side_gain) : ms_dec with{

    //band_shelf(freq1 ,freq2 ,gain) = fi.low_shelf(0-gain,freq1): fi.low_shelf(gain,freq2);
    band_shelf(freq1 ,freq2 ,gain) = fi.svf.ls(freq1,0.7,0-gain): fi.svf.ls(freq2,0.7,gain);

    freq_low = eq_side_freq - eq_side_freq*eq_side_width : max(50);
    freq_high = eq_side_freq + eq_side_freq*eq_side_width : min(8000);

    eq_side_gain = vslider("v:soundsgood/t:expert/h:[3]eq/h:[3]side eq/[1]eq side gain [unit:dB] [symbol:eq_side_gain]",0,0,12,0.5);
    eq_side_freq = vslider("v:soundsgood/t:expert/h:[3]eq/h:[3]side eq/[2]eq side freq [unit:Hz] [scale:log] [symbol:eq_side_freq]", 600,200,5000,1);
    eq_side_width = vslider("v:soundsgood/t:expert/h:[3]eq/h:[3]side eq/[3]eq side bandwidth [symbol:eq_side_bandwidth]", 1,0.5,4,0.5);

  };
};



// LEVELER


leveler_sc(target,fl,fr,l,r) =
  (calc(lk2_var(length,fl,fr))*(1-bp)+bp)
  <: (_*l,_*r)
with {

  lp1p(cf) = si.smooth(ba.tau2pole(1/(2*ma.PI*cf)));

  calc(lufs) = FB(lufs)~_: ba.db2linear;
  FB(lufs,prev_gain) =
    (target - lufs)
    +(prev_gain )
    :  limit(limit_neg,limit_pos)
    : lp1p(leveler_speed_gated(fl+fr))
    : leveler_meter_gain;

  bp = checkbox("v:soundsgood/t:expert/h:[3]leveler/[1]leveler bypass[symbol:leveler_bypass]") : si.smoo;
  leveler_meter_gain = vbargraph("v:soundsgood/h:easy/[4][unit:dB][symbol:leveler_gain]leveler gain",-50,50);
  meter_leveler_gate =  vbargraph("v:soundsgood/t:expert/h:[3]leveler/[6][unit:%]leveler gate[symbol:leveler_gate]",0,1);

  leveler_speed = vslider("v:soundsgood/t:expert/h:[3]leveler/[4][unit:%][symbol:leveler_speed]leveler speed", init_leveler_speed, 0, 100, 1) * 0.0015; //.005, 0.15, .005);
  leveler_gate_thresh = target + vslider("v:soundsgood/t:expert/h:[3]leveler/[5][unit:db][symbol:leveler_gate_threshold]leveler gate threshold", init_leveler_gatethreshold,-90,0,1);

  limit_pos = vslider("v:soundsgood/t:expert/h:[3]leveler/[7][symbol:leveler_max_plus][unit:db]leveler max +", init_leveler_maxboost, 0, 60, 1);
  limit_neg = vslider("v:soundsgood/t:expert/h:[3]leveler/[8][symbol:leveler_max_minus][unit:db]leveler max -", init_leveler_maxcut, 0, 60, 1) : ma.neg;
  limit(lo,hi) = min(hi) : max(lo);
  leveler_speed_gated(sc) = (ef.gate_gain_mono(leveler_gate_thresh,0.1,0,0.1,abs(sc)) <: attach(_, (1-_) : meter_leveler_gate)) : _ * leveler_speed;
  length = 0.4;
};

// SIDE CHAIN COMPRESSOR

sc_compressor(fl,fr,l,r) =
  (fl,fr,l,r)
  : feedforward_feedback
  : (ms_enc,ms_enc):
  (((RMS_compression_gain_N_chan_db(strength,thresh,att,rel,knee,0,link,N)),si.bus(N) )
   : ro.interleave(N,2) : par(i,N,(meter(i) : post_gain : ba.db2linear*(1-bypass)+bypass)*_))
  : ms_dec
  : ((l,_,r,_):par(i, 2, it.interpolate_linear(dw)))

with {
  N = 2;
  B = si.bus(2);
  bypass = checkbox("v:soundsgood/t:expert/h:[5]kneecomp/[0][symbol:kneecomp_bypass]kneecomp bypass"):si.smoo;
  strength = vslider("v:soundsgood/t:expert/h:[5]kneecomp/[1][unit:%][symbol:kneecomp_strength]kneecomp strength", 10, 0, 100, 1) * 0.01;
  thresh = target + vslider("v:soundsgood/t:expert/h:[5]kneecomp/[2][symbol:kneecomp_threshold][unit:dB]kneecomp tar-thresh",init_kneecomp_thresh,-12,6,1);
  att = vslider("v:soundsgood/t:expert/h:[5]kneecomp/[3][symbol:kneecomp_attack][unit:ms]kneecomp attack",40,1,100,1)*0.001;
  rel = vslider("v:soundsgood/t:expert/h:[5]kneecomp/[4][symbol:kneecomp_release][unit:ms]kneecomp release",200,1,1000,1)*0.001;
  knee = vslider("v:soundsgood/t:expert/h:[5]kneecomp/[5][unit:dB][symbol:kneecomp_knee]kneecomp knee",6,0,30,1);
  link = vslider("v:soundsgood/t:expert/h:[5]kneecomp/[6][unit:%][symbol:kneecomp_link]kneecomp link", 60, 0, 100, 1) *0.01;
  fffb = vslider ("v:soundsgood/t:expert/h:[5]kneecomp/[7][unit:%][symbol:kneecomp_fffb]kneecomp ff-fb",50,0,100,1) *0.01;
  dw = vslider ("v:soundsgood/t:expert/h:[5]kneecomp/[9][unit:%][symbol:kneecomp_drywet]kneecomp dry/wet",100,0,100,1) * 0.01:si.smoo;

  meter(i) =
    _<: attach(_, (max(-6):min(0):vbargraph(
                     "v:soundsgood/t:expert/h:[5]kneecomp/[unit:dB]", -6, 0)
                  ));

  feedforward_feedback = B,(B<:B,B) : par(i,2,_*fffb), par(i,2,_* (1-fffb)),B : (_,_,_,_:>_,_),_,_;


  // dev version of faust has this in the libs, TODO, use co.RMS_compression_gain_N_chan_db
  RMS_compression_gain_N_chan_db(strength,thresh,att,rel,knee,prePost,link,1) =
    RMS_compression_gain_mono_db(strength,thresh,att,rel,knee,prePost);

  RMS_compression_gain_N_chan_db(strength,thresh,att,rel,knee,prePost,link,N) =
    par(i,N,RMS_compression_gain_mono_db(strength,thresh,att,rel,knee,prePost))
    <: (si.bus(N),(ba.parallelMin(N) <: si.bus(N))) : ro.interleave(N,2) : par(i,N,(it.interpolate_linear(link)));

  RMS_compression_gain_mono_db(strength,thresh,att,rel,knee,prePost) =
    RMS(rel) : ba.bypass1(prePost,si.onePoleSwitching(att,0)) : ba.linear2db : gain_computer(strength,thresh,knee) : ba.bypass1((prePost!=1),si.onePoleSwitching(0,att))
  with {
    gain_computer(strength,thresh,knee,level) =
      select3((level>(thresh-(knee/2)))+(level>(thresh+(knee/2))),
              0,
              ((level-thresh+(knee/2)) : pow(2)/(2*max(ma.EPSILON,knee))),
              (level-thresh))
      : max(0)*-strength;
    RMS(time) = ba.slidingRMS(s) with {
      s = ba.sec2samp(time):int:max(1);
    };
  };
  //post_gain
  post_gain =
    _+
    (vslider("v:soundsgood/t:expert/h:[5]kneecomp/[8][unit:dB][symbol:kneecomp_makeup]kneecomp makeup", init_kneecomp_postgain,-10,+10,0.5) :si.smoo);



};


// MSCOMP Interpolated (Bart Brouns)
mscomp_bp = bp2(checkbox("v:soundsgood/t:expert/h:[5]mscomp/h:[0]bypass/[0][symbol:mscomp_bypass]mscomp bypass"),
                ms_enc
                : B_band_Compressor_N_chan(Nba,Nch)
                : ms_dec
               ) ;

B_band_Compressor_N_chan(B,N) =
  si.bus (N) <: si.bus (2 * N)
  : ( (crossover:gain_calc), si.bus(N) )
  : apply_gain
  : outputGain
with {
  crossover =
    par(i, N, an.analyzer (6, crossoverFreqs)
              // : ro.cross (B)
       );

  apply_gain =
    (ro.interleave(N, B+1))
    : par(i, N, ro.cross(B),_)
    : par(i, N, shelfcascade ((crossoverFreqs)))
  ;

  // TODO: use co.peak_compression_gain_N_chan_db when it arrives in the current faust version
  compressor(N,prePost,strength,thresh,att,rel,knee,link) = peak_compression_gain_N_chan_db (strength,thresh,att,rel,knee,prePost,link,N);

  gain_calc = (strength_array, thresh_array, att_array, rel_array, knee_array, link_array, si.bus(N*B))
              : ro.interleave(B,6+N)
              : par(i, B, compressor(N,prePost)) // : si.bus (N * Nr_bands)
              : par(b, B, par(c, N, meter(b+1, c+1)));


  outputGain = par(i, N, _*mscomp_outGain);

  /* TODO: separate %b%c in symbol name so that it is a valid C/C++ variable-name (ideally an underscore) %b_%c
   * meanwhile this is safe since there are only 8 bands (1..9) and 2 channels.
   */
  meter(b,c) =
    _<: attach(_, (max(-3):min(0):vbargraph(
                     // "v:soundsgood/t:expert/h:[6]mscomp_meter/[%b.%c][unit:dB][tooltip: gain reduction in db][symbol:msredux%b%c]mscomp redux band %b chn %c", -3, 0)
                     "v:soundsgood/t:expert/h:[6]mscomp_meter/[%b.%c][unit:dB][tooltip: gain reduction in db][symbol:msredux%b%c]", -3, 0)
                  ));

  /* higher order low, band and hi shelf filter primitives */
  ls3(f,g) = fi.svf.ls (f, .5, g3) : fi.svf.ls (f, .707, g3) : fi.svf.ls (f, 2, g3) with {g3 = g/3;};
  bs3(f1,f2,g) = ls3(f1,-g) : ls3(f2,g);
  hs3(f,g) = fi.svf.hs (f, .5, g3) : fi.svf.hs (f, .707, g3) : fi.svf.hs (f, 2, g3) with {g3 = g/3;};

  /* Cascade of shelving filters to apply gain per band.
   *
   * `lf` : list of frequencies
   * followed by (count(lf) +1) gain parameters
   */
  shelfcascade(lf) = fbus(lf), ls3(first(lf)) : sc(lf)
  with {
    sc((f1, f2, lf)) = fbus((f2,lf)), bs3(f1,f2) : sc((f2,lf)); // recursive pattern
    sc((f1, f2))     = _, bs3(f1,f2) : hs3(f2);                // halting pattern
    fbus(l)          = par(i, outputs(l), _);                  // a bus of the size of a list
    first((x,xs))    = x;                                      // first element of a list
  };

  /* Cross over frequency range */
  fl = vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[1]low band/[7][symbol:mscomp_low_crossover][scale:log][unit:Hz]low crossover", 60, 20, 4000, 1);
  fh = vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[2]high band/[7][symbol:mscomp_high_crossover][scale:log][unit:Hz]high crossover", 8000, 5000, 20000, 1);

  /* Compressor settings */
  strength_array = vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[1]low band/[1][unit:%][symbol:mscomp_low_strength]low strength", 10, 0, 100, 1)*0.01,vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[2]high band/[1][unit:%][symbol:mscomp_high_strength]high strength", 10, 0, 100, 1)*0.01:LinArray(B);
  thresh_array = target + vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[1]low band/[2][unit:dB][symbol:mscomp_low_threshold]low tar-thresh", -2, -12, 12, 0.5),target + vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[2]high band/[2][unit:dB][symbol:mscomp_high_threshold]high tar-thresh", -6, -12, 12, 0.5):LinArray(B);
  att_array = (vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[1]low band/[3][unit:ms][symbol:mscomp_low_attack]low attack", 15, 0, 100, 0.1)*0.001,vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[2]high band/[3][unit:ms][symbol:mscomp_high_attack]high attack", 3, 0, 100, 0.1)*0.001):LogArray(B);
  rel_array = (vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[1]low band/[4][unit:ms][symbol:mscomp_low_release]low release", 150, 1, 1000, 1)*0.001,vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[2]high band/[4][unit:ms][symbol:mscomp_high_release]high release", 30, 1, 1000, 1)*0.001):LogArray(B);
  knee_array = (vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[1]low band/[5][unit:dB][symbol:mscomp_low_knee]low knee", 12, 0, 30, 0.1),vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[2]high band/[5][unit:dB][symbol:mscomp_high_knee]high knee", 12, 0, 30, 0.1)):LinArray(B);
  link_array = (vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[1]low band/[6][unit:%][symbol:mscomp_low_link]low link", 60, 0, 100, 1)*0.01,vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[2]high band/[6][unit:%][symbol:mscomp_high_link]high link", 30, 0, 100, 1)*0.01):LinArray(B);
  crossoverFreqs = LogArray(B-1,fl,fh);
  mscomp_outGain = vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[3]out/[3][unit:dB][symbol:mscomp_output_gain]makeup", 1, -6, 6, 0.5):ba.db2linear;

  // make a linear array of values, from bottom to top
  LinArray(N,bottom,top) = par(i,N,   ((top-bottom)*(i/(N-1)))+bottom);
  // make a log array of values, from bottom to top
  LogArray(N,bottom,top) = par(i,N,   pow((pow((t/b),1/(N-1))),i)*b)
  with {
    b = bottom:max(ma.EPSILON);
    t = top:max(ma.EPSILON);
  };


  prePost = 1;
};

// LIMITER
limiter_rms_bp = bp2(checkbox("v:soundsgood/t:expert/h:[7]limiter/[0]limiter bypass[symbol:limiter_bypass]"),limiter_rms);
limiter_rms = co.RMS_FBFFcompressor_N_chan(strength,thresh,att,rel,knee,0,1,fffb,limiter_meter,2) : post_gain with{
  strength = vslider("v:soundsgood/t:expert/h:[7]limiter/[1][unit:%][symbol:limiter_strength]limiter strength", 80, 0, 100, 1) *0.01;
  thresh = target + vslider("v:soundsgood/t:expert/h:[7]limiter/[2][symbol:limiter_threshold][unit:dB]limiter tar-thresh",6,-12,12,1);
  att = vslider("v:soundsgood/t:expert/h:[7]limiter/[3][unit:ms][symbol:limiter_attack]limiter attack",1,0,100,1)*0.001;
  rel = vslider("v:soundsgood/t:expert/h:[7]limiter/[4][unit:ms][symbol:limiter_release]limiter release",40,1,400,1)*0.001;
  knee = vslider("v:soundsgood/t:expert/h:[7]limiter/[5][symbol:limiter_knee][unit:dB]limiter knee",8,0,12,1);

  fffb = vslider ("v:soundsgood/t:expert/h:[7]limiter/[6][unit:%][symbol:limiter_fffb]limiter ff-fb",50,0,100,1)*0.01;
  // post_gain
  post_gain = par(i,Nch,_ * limiter_postgain) with {

  };

  limiter_postgain = vslider("v:soundsgood/t:expert/h:[7]limiter/[8][unit:dB][symbol:limiter_makeup]limiter makeup", init_limiter_postgain,-10,+10,0.5) : ba.db2linear;
  limiter_meter = _ <: attach(ba.linear2db : vbargraph("v:soundsgood/t:expert/h:[7]limiter/[9][unit:dB][symbol:limiter_gain_reduction]limiter gain reduction",-12,0));
};


// BRICKWALL
brickwall_bp = bp2(checkbox("v:soundsgood/t:expert/h:[8]brickwall/[1][symbol:brickwall_bypass]brickwall bypass"),brickwall);

brickwall = limiter_lad_N(N, limiter_lad_lookahead, limiter_lad_ceil, limiter_lad_attack, limiter_lad_hold, limiter_lad_release) with{

  N=2;

  twopi = 2 * ma.PI;

  limiter_lad_lookahead = 0.01;
  limiter_lad_ceil = init_brickwall_ceiling : ba.db2linear;
  limiter_lad_attack = .01 / twopi;
  limiter_lad_hold = .1;
  limiter_lad_release = 1 / twopi;

  // lookahead limiter (N-channel)
  limiter_lad_N(N, LD, ceiling, attack, hold, release) =
    si.bus(N) <: par(i, N, @ (LD * ma.SR)),
    (scaling <: si.bus(N)) : ro.interleave(N, 2) : par(i, N, *)
  with {
    scaling = ceiling / max(amp_profile, ma.EPSILON) : min(1) : brickwall_meter;
    amp_profile = par(i, N, abs) : maxN(N) : ba.peakholder(hold * ma.SR) : att_smooth(attack) : rel_smooth(release);
    att_smooth(time, in) = si.smooth(ba.tau2pole(time), in);
    rel_smooth(time, in) = an.peak_envelope(time, in);
    maxN(1) = _;
    maxN(2) = max;
    maxN(N) = max(maxN(N - 1));
  };
  brickwall_meter = _ <: attach(ba.linear2db : abs : vbargraph("v:soundsgood/t:expert/h:[8]brickwall/[8][unit:dB][symbol:brickwall_gain_reduction]brickwall gain reduction",0,12));

};

// LIMITER NO LATENCY
brickwall_no_latency_bp = bp2(checkbox("v:soundsgood/t:expert/h:[8]brickwall/[1][symbol:brickwall_bypass]brickwall bypass"),brickwall_no_latency);
brickwall_no_latency =
  co.FFcompressor_N_chan(1,threshLim,att,rel,knee,0,link,meter_brickwall,2)
with {

  threshLim = vslider("v:soundsgood/t:expert/h:[8]brickwall/[3]brickwall ceiling[unit:dB][symbol:brickwall_ceiling]",init_brickwall_ceiling,-6,-0,0.1);
  att = 0;
  rel = vslider("v:soundsgood/t:expert/h:[8]brickwall/[4]brickwall release[unit:ms][symbol:brickwall_release]",init_brickwall_release,5,100,1) *0.001;
  knee = 0;
  link = 1;
  meter_brickwall =
    _<: _,( ba.linear2db:vbargraph("v:soundsgood/t:expert/h:[8]brickwall/lim[unit:dB][symbol:brickwall_limit]",-20,0)) : attach;

  // The following code is in the libraries in the dev version of faust, but not yet in the latest release:
  // TODO: use co.FFcompressor_N_chan
  FFcompressor_N_chan(strength,thresh,att,rel,knee,prePost,link,meter,N) =
    si.bus(N) <: (peak_compression_gain_N_chan_db(strength,thresh,att,rel,knee,prePost,link,N),si.bus(N)) : ro.interleave(N,2) : par(i,N,(meter: ba.db2linear)*_);

};

// +++++++++++++++++++++++++ LUFS METER +++++++++++++++++++++++++

lk2 = par(i,2,kfilter : zi) :> 4.342944819 * log(max(1e-12)) : -(0.691) with {
  // maximum assumed sample rate is 192k
  maxSR = 192000;
  sump(n) = ba.slidingSump(n, Tg*maxSR)/n;
  envelope(period, x) = x * x :  sump(rint(period * ma.SR));
  //Tg = 0.4; // 3 second window for 'short-term' measurement
  Tg = 3;
  zi = envelope(Tg); // mean square: average power = energy/Tg = integral of squared signal / Tg

  kfilter = ebu.prefilter;
};

lufs_meter_in(l,r) = l,r <: l, attach(r, (lk2 : vbargraph("v:soundsgood/h:easy/[2][unit:dB][symbol:lufs_in]in lufs-s",-70,0))) : _,_;
lufs_meter_out(l,r) = l,r <: l, attach(r, (lk2 : vbargraph("v:soundsgood/h:easy/[7][unit:dB][symbol:lufs_out]out lufs-s",-70,0))) : _,_;

lk2_var(length) =
  par(i,2,kfilter : envelope(length)) :> 4.342944819 * log(max(1e-12)) : -(0.691) with {
  // maximum assumed sample rate is 192k
  maxSR = 192000;
  sump(n) = ba.slidingSump(n, Tg*maxSR)/n;
  // mean square: average power = energy/Tg = integral of squared signal / Tg
  envelope(period, x) = x * x :  sump(rint(period * ma.SR));
  //Tg = 0.4; // 3 second window for 'short-term' measurement
  Tg = 3;


  kfilter = ebu.prefilter;
};

/* ******* 8< *******/
// TODO: use co.peak_compression_gain_N_chan_db when it arrives in the current faust version
peak_compression_gain_mono_db(strength,thresh,att,rel,knee,prePost) =
  abs : ba.bypass1(prePost,si.onePoleSwitching(att,rel)) : ba.linear2db : gain_computer(strength,thresh,knee) : ba.bypass1((prePost !=1),si.onePoleSwitching(rel,att))
with {
  gain_computer(strength,thresh,knee,level) =
    select3((level>(thresh-(knee/2)))+(level>(thresh+(knee/2))),
            0,
            ((level-thresh+(knee/2)) : pow(2)/(2*max(ma.EPSILON,knee))),
            (level-thresh))
    : max(0)*-strength;
};

peak_compression_gain_N_chan_db(strength,thresh,att,rel,knee,prePost,link,1) =
  peak_compression_gain_mono_db(strength,thresh,att,rel,knee,prePost);

peak_compression_gain_N_chan_db(strength,thresh,att,rel,knee,prePost,link,N) =
  par(i, N, peak_compression_gain_mono_db(strength,thresh,att,rel,knee,prePost))
  <: (si.bus(N),(ba.parallelMin(N) <: si.bus(N))) : ro.interleave(N,2) : par(i,N,(it.interpolate_linear(link)));

/* ******* >8 *******/
