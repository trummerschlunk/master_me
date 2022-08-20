// -*-Faust-*-

declare name "Soundsgood";
declare version "1.0";
declare author "Klaus Scheuermann";
declare license "GPLv3";

// double precision -double needed!

ebu = library("lib/ebur128.dsp");
import("stdfaust.lib");

// init values

Nch = 2; //number of channels

init_noisegate_threshold = -70; // not used in voc version

init_leveler_target = -18;
init_leveler_maxboost = 40;
init_leveler_maxcut = 40;
init_leveler_gatethreshold = -45;
init_leveler_speed = .05;

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
    : phase_invert_L , phase_invert_R
    //: correlate_meter
    : correlate_correct_bp

    : gate_bp

    : (
        leveler_sc(target)

        : (sc_compressor
           : eq_bp

           : mscomp8i_bp
             // : kneecomp_bp

           : limiter_rms_bp
             // : brickwall_bp

           : brickwall_no_latency

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
  g = vslider("v:soundsgood/t:expert/h:[1]pre-processing/[1][symbol:in_gain]input gain",0,-100,24,1) : ba.db2linear;
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
gate = ef.gate_stereo(gate_thresh,gate_att,gate_hold,gate_rel) with{
  gate_thresh = vslider("v:soundsgood/t:expert/h:[2]gate/[2][unit:dB][symbol:gate_threshold]gate threshold",-90,-90,0,1);
  gate_att = vslider("v:soundsgood/t:expert/h:[2]gate/[3][symbol:gate_attack]gate attack",0,0,0.1,0.01);
  gate_hold = vslider("v:soundsgood/t:expert/h:[2]gate/[4][symbol:gate_hold]gate hold",0.1,0,1,0.1);
  gate_rel = vslider("v:soundsgood/t:expert/h:[2]gate/[5][symbol:gate_release]gate release",0.5,0,5,0.1);
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


// LEVELER


leveler_sc(target) =

    //_,_,_,_ : !,!,_,_ <: _,_,_,_ :      //make ff

    feedforward_feedback :

    ro.crossnn(N)
    : B,(B <: B,B : (lk2 :max(-70)), + : (calc*(1-bp)+bp) : _ <: B)
        :
        ro.interleave(N,2) : par(i,N,*)
with {
    N = 2;
    B = si.bus(N);

    calc(lufs,sc) = (lufs : (target - _) : lp1p(leveler_speed_gated(sc)) : limit(limit_neg,limit_pos) : leveler_meter_gain : ba.db2linear) , sc : _,!;

    bp = checkbox("v:soundsgood/t:expert/h:[3]leveler/[1]leveler bypass[symbol:leveler_bypass]") : si.smoo;

    limit(lo,hi) = min(hi) : max(lo);

    leveler_speed_gated(sc) = (ef.gate_gain_mono(leveler_gate_thresh,0.1,0,0.1,abs(sc)) <: attach(_, (1-_) : meter_leveler_gate)) : _ * leveler_speed;


    //leveler_meter_lufs = vbargraph("v:soundsgood/h:easy/[1][unit:dB]leveler lufs-s",-70,0);
    leveler_meter_gain = vbargraph("v:soundsgood/h:easy/[4]Leveler gain[symbol:leveler_gain]",-50,50);
    meter_leveler_gate = vbargraph("v:soundsgood/t:expert/h:[3]leveler/[6]leveler gate[symbol:leveler_gate]",0,1);

    leveler_speed = vslider("v:soundsgood/t:expert/h:[3]leveler/[4][scale:log]leveler speed[symbol:leveler_speed]", init_leveler_speed, .005, 0.15, .005);
    leveler_gate_thresh = vslider("v:soundsgood/t:expert/h:[3]leveler/[5]leveler gate threshold[unit:dB][symbol:leveler_gate_threshold]", init_leveler_gatethreshold,-90,0,1);
    limit_pos = vslider("v:soundsgood/t:expert/h:[3]leveler/[7]leveler max +[symbol:leveler_max_plus]", init_leveler_maxboost, 0, 60, 1);
    limit_neg = vslider("v:soundsgood/t:expert/h:[3]leveler/[8]leveler max -[symbol:leveler_max_minus]", init_leveler_maxcut, 0, 60, 1) : ma.neg;
    fffb = 0; //vslider ("v:soundsgood/t:expert/h:[3]leveler/[9][symbol:leveler_fffb]leveler ff-fb",0,0,1,0.1);
    lp1p(cf) = si.smooth(ba.tau2pole(1/(2*ma.PI*cf)));

    feedforward_feedback = B,(B<:B,B) : par(i,2,_*fffb), par(i,2,_* (1-fffb)),B : (_,_,_,_:>_,_),_,_;
};

// EQ with bypass
eq_bp = bp2(checkbox("v:soundsgood/t:expert/h:[4]eq/[1][symbol:eq_bypass]eq bypass"),eq);
eq = hp_eq : tilt_eq : side_eq_b with{
  // HIGHPASS
  hp_eq = par(i,2,fi.highpass(1,freq)) with {
    freq = vslider("v:soundsgood/t:expert/h:[4]eq/h:[1]highpass/[1]eq highpass freq [unit:Hz] [scale:log] [symbol:eq_highpass_freq]", 5, 5, 1000,1);
  };

  // TILT EQ STEREO
  tilt_eq = par(i,2,_) : par(i,2, fi.lowshelf(N, -gain, freq) : fi.highshelf(N, gain, freq)) with{
      N = 1;
      gain = vslider("v:soundsgood/t:expert/h:[4]eq/h:[2]tilt eq/[1]eq tilt gain [unit:db] [symbol:eq_tilt_gain]",0,-6,6,0.5);
      freq = 630; //vslider("v:soundsgood/t:expert/h:[4]eq/h:[2]tilt eq/[2]eq tilt freq [unit:Hz] [scale:log] [symbol:eq_tilt_freq]", 630, 200, 2000,1);
  };



  // SIDE EQ
  side_eq_b =  ms_enc : _,band_shelf(freq_low,freq_high,eq_side_gain) : ms_dec with{

      //band_shelf(freq1 ,freq2 ,gain) = fi.low_shelf(0-gain,freq1): fi.low_shelf(gain,freq2);
      band_shelf(freq1 ,freq2 ,gain) = fi.svf.ls(freq1,0.7,0-gain): fi.svf.ls(freq2,0.7,gain);

      freq_low = eq_side_freq - eq_side_freq*eq_side_width : max(50);
      freq_high = eq_side_freq + eq_side_freq*eq_side_width : min(8000);

      eq_side_gain = vslider("v:soundsgood/t:expert/h:[4]eq/h:[3]side eq/[1]eq side gain [unit:db] [symbol:eq_side_gain]",0,0,12,0.5);
      eq_side_freq = vslider("v:soundsgood/t:expert/h:[4]eq/h:[3]side eq/[2]eq side freq [unit:Hz] [scale:log] [symbol:eq_side_freq]", 600,200,5000,1);
      eq_side_width = vslider("v:soundsgood/t:expert/h:[4]eq/h:[3]side eq/[3]eq side bandwidth [symbol:eq_side_bandwidth]", 1,0.5,4,0.5);

  };
};




// SIDE CHAIN COMPRESSOR

sc_compressor =
    (
        feedforward_feedback :


        (ms_enc,ms_enc):
        (((RMS_compression_gain_N_chan_db(strength,thresh,att,rel,knee,0,link,N)),si.bus(N) )
         : ro.interleave(N,2) : par(i,N,(meter : post_gain : ba.db2linear*(1-dw_bypass)+dw_bypass)*_))
        : ms_dec)

with {
    N = 2;
    B = si.bus(2);
    bypass = checkbox("v:soundsgood/t:expert/h:[5]kneecomp/[0][symbol:kneecomp_bypass]kneecomp bypass"):si.smoo;
    strength = vslider("v:soundsgood/t:expert/h:[5]kneecomp/[1][symbol:kneecomp_strength]kneecomp strength", 0.1, 0, 1, 0.1);
    thresh = target + vslider("v:soundsgood/t:expert/h:[5]kneecomp/[2][symbol:kneecomp_threshold][unit:dB]kneecomp tar-thresh",init_kneecomp_thresh,-12,6,1);
    att = vslider("v:soundsgood/t:expert/h:[5]kneecomp/[3][symbol:kneecomp_attack][unit:ms]kneecomp attack",40,1,100,1)*0.001;
    rel = vslider("v:soundsgood/t:expert/h:[5]kneecomp/[4][symbol:kneecomp_release][unit:ms]kneecomp release",200,1,1000,1)*0.001;
    knee = vslider("v:soundsgood/t:expert/h:[5]kneecomp/[5][symbol:kneecomp_knee]kneecomp knee",6,0,30,1);
    link = vslider("v:soundsgood/t:expert/h:[5]kneecomp/[6][symbol:kneecomp_link]kneecomp link", 0.6, 0, 1, 0.1);
    fffb = vslider ("v:soundsgood/t:expert/h:[5]kneecomp/[7][symbol:kneecomp_fffb]kneecomp ff-fb",0.5,0,1,0.1);
    dw = vslider ("v:soundsgood/t:expert/h:[5]kneecomp/[9][symbol:kneecomp_drywet]kneecomp dry/wet",100,0,100,1) * 0.01;

    dw_bypass = (1-bypass) * dw;

    meter = _<: _,( vbargraph("v:soundsgood/t:expert/h:[5]kneecomp/[unit:dB]",-6,0)) : attach;

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
        (vslider("v:soundsgood/t:expert/h:[5]kneecomp/[8][symbol:kneecomp_makeup][unit:dB]kneecomp makeup", init_kneecomp_postgain,-10,+10,0.5) :si.smoo);



};


// MSCOMP8 Interpolated (Bart Brouns)
mscomp8i_bp = bp2(checkbox("v:soundsgood/t:expert/h:[5]mscomp/h:[0]bypass/[1][symbol:mscomp_bypass]mscomp bypass"),mscomp8i(target));

mscomp8i(target) =

    ms_enc
  : Eight_band_Compressor_N_chan(2)
  : ms_dec
;


Eight_band_Compressor_N_chan(N) =
   crossover
  : compressors
  : mixer
  : outputGain
with {
  inputGain = par(i, N, _*inGain);
  crossover =
    (
      (crossoverFreqs<:par(i, Nr_crossoverFreqs, _<:si.bus(N)))
     ,si.bus(N)
    )
    <: ro.interleave(N,Nr_bands)
    :  par(i, N, fi.crossover8LR4)
    :  ro.interleave(Nr_bands,N);
  compressors =
    (strength_array , thresh_array , att_array , rel_array , knee_array , link_array, ro.interleave(N,Nr_bands))
    : ro.interleave(Nr_bands,6+N)
    : par(i, Nr_bands, compressor(meter(i+1),N,prePost)) ;
  mixer = si.bus(N*Nr_bands):>si.bus(N);
  outputGain = par(i, N, _*mscomp8i_outGain);

  compressor(meter,N,prePost,strength,thresh,att,rel,knee,link) =
    co.FFcompressor_N_chan(strength,thresh,att,rel,knee,prePost,link,meter,N);

  //meter(i) = _<:(_, (ba.linear2db:max(-40):min(0):vbargraph("v:soundsgood/t:expert/h:[6]mscomp_meter/[%i][unit:dB]%i[tooltip: gain reduction in dB]", -3, 0))):attach;
  meter(i) = _<:(_, (ba.linear2db:max(-40):min(0):vbargraph("v:soundsgood/t:expert/h:[6]mscomp_meter/[%i][unit:dB][tooltip: gain reduction in dB]", -3, 0))):attach;


  crossoverFreqs = vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[1]low band/[1][symbol:mscomp_low_crossover][scale:log]low crossover", 60, 20, 20000, 1),vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[2]high band/[1][symbol:mscomp_high_crossover][scale:log]high crossover", 8000, 20, 20000, 1):LogArray(Nr_crossoverFreqs);
  //crossoverFreqs = 60,8000 :LogArray(Nr_crossoverFreqs);
  strength_array = vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[1]low band/[2][symbol:mscomp_low_strength]low strength", 0.1, 0, 8, 0.1),vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[2]high band/[2][symbol:mscomp_high_strength]high strength", 0.3, 0, 8, 0.1):LinArray(Nr_bands);
  thresh_array = target + vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[1]low band/[3][symbol:mscomp_low_threshold]low thresh", -2, -12, 12, 0.5),target + vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[2]high band/[3][symbol:mscomp_high_threshold]high thresh", -6, -12, 12, 0.5):LinArray(Nr_bands);
  att_array = (vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[1]low band/[4][symbol:mscomp_low_attack]low attack", 15, 0, 100, 0.1)*0.001,vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[2]high band/[4][symbol:mscomp_high_attack]high attack", 3, 0, 100, 0.1)*0.001):LogArray(Nr_bands);
  rel_array = (vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[1]low band/[5][symbol:mscomp_low_release]low release", 150, 1, 1000, 1)*0.001,vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[2]high band/[5][symbol:mscomp_high_release]high release", 30, 1, 1000, 1)*0.001):LogArray(Nr_bands);
  knee_array = (vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[1]low band/[6][symbol:mscomp_low_knee]low knee", 12, 0, 30, 0.1),vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[2]high band/[6][symbol:mscomp_high_knee]high knee", 12, 0, 30, 0.1)):LinArray(Nr_bands);
  link_array = (vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[1]low band/[7][symbol:mscomp_low_link]low link", 0.6, 0, 1, 0.1),vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[2]high band/[7][symbol:mscomp_high_link]high link", 0.3, 0, 1, 0.1)):LinArray(Nr_bands);
  mscomp8i_outGain = vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[3]out/[3][symbol:mscomp_output_gain]output gain", 1, -6, 6, 0.5):ba.db2linear;

  // make a linear array of values, from bottom to top
  LinArray(N,bottom,top) = par(i,N,   ((top-bottom)*(i/(N-1)))+bottom);
  // make a log array of values, from bottom to top
  LogArray(N,bottom,top) = par(i,N,   pow((pow((t/b),1/(N-1))),i)*b)
  with {
    b = bottom:max(ma.EPSILON);
    t = top:max(ma.EPSILON);
  };

  // make a bottom and a top version of a parameter
  BTlo(b,t) = BT(b,t):LogArray(Nr_bands);
  BTli(b,t) = BT(b,t):LinArray(Nr_bands);
  Nr_bands = 8;
  Nr_crossoverFreqs = Nr_bands-1;
  prePost = 1;
  maxGR = -30;
};


// LIMITER
limiter_rms_bp = bp2(checkbox("v:soundsgood/t:expert/h:[7]limiter/[1]limiter bypass[symbol:limiter_bypass]"),limiter_rms);
limiter_rms = co.RMS_FBFFcompressor_N_chan(strength,thresh,att,rel,knee,0,1,fffb,limiter_meter,2) : post_gain with{
    strength = vslider("v:soundsgood/t:expert/h:[7]limiter/[2][symbol:limiter_strength]limiter strength", 0.8, 0, 1, 0.1);
    thresh = target + vslider("v:soundsgood/t:expert/h:[7]limiter/[3][symbol:limiter_threshold][unit:dB]limiter tar-thresh",6,-12,12,1);
    att = vslider("v:soundsgood/t:expert/h:[7]limiter/[4][symbol:limiter_attack]limiter attack",1,0,100,1)*0.001;
    rel = vslider("v:soundsgood/t:expert/h:[7]limiter/[5][symbol:limiter_release]limiter release",40,1,400,1)*0.001;
    knee = vslider("v:soundsgood/t:expert/h:[7]limiter/[6][symbol:limiter_knee][unit:dB]limiter knee",8,0,12,1);

    fffb = vslider ("v:soundsgood/t:expert/h:[7]limiter/[6][symbol:limiter_fffb]limiter ff-fb",0.5,0,1,0.1);
    // post_gain
    post_gain = par(i,Nch,_ * limiter_postgain) with {

    };

    limiter_postgain = vslider("v:soundsgood/t:expert/h:[7]limiter/[8]limiter makeup[unit:dB][symbol:limiter_makeup]", init_limiter_postgain,-10,+10,0.5) : ba.db2linear;
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
