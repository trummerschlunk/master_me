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
init_leveler_speed = .03;

init_kneecomp_thresh = 0;
init_kneecomp_postgain = 0;

init_limiter_lad_ceil = -2;
init_limiter_postgain = 0;

init_brickwall_ceiling = -1;


target = vslider("v:soundsgood/h:easy/[2]Target[unit:dB]", init_leveler_target,-50,0,1);


// main
process =
    //tone_generator :
    lufs_meter_in
    : dc_filter(2)

    : gate_bp
    : correlate_meter
    : correlate_correct_bp

    : (
        leveler_sc(target)

        : eq_bp

        : mscomp8i_bp
        : kneecomp_bp

          // : limiter_bp
          // : brickwall_bp

        : lufs_meter_out
    )~(si.bus(2))
;

// stereo bypass with si.smoo fading
bp2(sw,pr) =  _,_ <: _,_,pr : (_*sm,_*sm),(_*(1-sm),_*(1-sm)) :> _,_ with {
    sm = sw : si.smoo;
};


// DC FILTER
dc_filter(N) = par(i,N,fi.dcblockerat(dc_filter_freq))
with {
  dc_filter_freq = 10.0;
};


// stereo to m/s encoder
ms_enc = _*0.5,_*0.5 <: +, -;
// m/s to stereo decoder
ms_dec = _,_ <: +, -;



// GATE
gate_bp = bp2(checkbox("v:soundsgood/t:expert/h:[1]gate/[1]gate bypass"),gate);
gate = ef.gate_stereo(gate_thresh,gate_att,gate_hold,gate_rel) with{
  gate_thresh = vslider("v:soundsgood/t:expert/h:[1]gate/[2][unit:dB]gate threshold",-90,-90,0,1);
  gate_att = vslider("v:soundsgood/t:expert/h:[1]gate/[3]gate attack",0,0,0.1,0.01);
  gate_hold = vslider("v:soundsgood/t:expert/h:[1]gate/[4]gate hold",0.1,0,1,0.1);
  gate_rel = vslider("v:soundsgood/t:expert/h:[1]gate/[5]gate release",0.5,0,5,0.1);
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

    meter_correlate_meter = vbargraph("v:soundsgood/t:expert/h:[2]correlation/correlation meter",-1,1);
};

// stereo correction based on correlation
correlate_correct_bp = bp2(checkbox("v:soundsgood/t:expert/h:[2]correlation/[1]correlate correct bypass"), correlate_correct);
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
    corr_pos1 = avg(t, (corr(t,l,r) > (1-th))) : smoothing /*: vbargraph("[5]1",0,1)*/;
    corr_neg1 = avg(t, corr(t,l,r) < (-1+th)) : smoothing /*: vbargraph("[9]-1",0,1)*/;
    corr_0 = avg(t, ((corr(t,l,r) < th) & (corr(t,l,r) > (0-th)))) : smoothing /*: vbargraph("[7]0",0,1)*/;
    corr_pos = avg(t, ((corr(t,l,r) > (0+th)) & (corr(t,l,r) < (1-th)))) : smoothing /*: vbargraph("[6]>0,<1",0,1)*/;
    corr_neg = avg(t, ((corr(t,l,r) > (-1+th)) & (corr(t,l,r) < (0-th)))) : smoothing /*: vbargraph("[8]>-1,<0",0,1)*/;

    smoothing = lp1p(2) ;

    out_pos1 = ((l * corr_pos1 + r * corr_pos1) /2) , ((l * corr_pos1 + r * corr_pos1) /2);
    out_neg1 = ((l * corr_neg1 + (-r) * corr_neg1) /2) , ((l * corr_neg1 + (-r) * corr_neg1) /2);
    out_0 = (l * corr_0 + r * corr_0) , (l * corr_0 + r * corr_0);
    out_pos = l * corr_pos , r * corr_pos;
    out_neg = l * corr_neg , r * corr_neg; // old: out_neg = l * corr_neg , (0-(r * corr_neg));

    lp1p(cf) = si.smooth(ba.tau2pole(1/(2*ma.PI*cf)));
};




// LEVELER
leveler_sc_bp = bp2(checkbox("v:soundsgood/t:expert/h:[3]leveler/[1]leveler bypass"),leveler_sc(target));


leveler_sc(target) =
    ro.crossnn(N)
    : B,(B <: B,B : lk2, + : (calc*(1-bp)+bp) : _ <: B)
        :
        ro.interleave(N,2) : par(i,N,*)
with {
    N = 2;
    B = si.bus(N);

    calc(lufs,sc) = (lufs : (target - _) : lp1p(leveler_speed_gated(sc)) : limit(limit_neg,limit_pos) : leveler_meter_gain : ba.db2linear) , sc : _,!;

    bp = checkbox("v:soundsgood/t:expert/h:[3]leveler/[1]leveler bypass") : si.smoo;

    limit(lo,hi) = min(hi) : max(lo);

    leveler_speed_gated(sc) = (ef.gate_gain_mono(leveler_gate_thresh,0.1,0,0.1,abs(sc)) <: attach(_, (1-_) : meter_leveler_gate)) : _ * leveler_speed;


    //leveler_meter_lufs = vbargraph("v:soundsgood/h:easy/[1][unit:dB]leveler lufs-s",-70,0);
    leveler_meter_gain = vbargraph("v:soundsgood/h:easy/[3]Leveler gain",-50,50);
    meter_leveler_gate = vbargraph("v:soundsgood/t:expert/h:[3]leveler/[6]leveler gate",0,1);

    leveler_speed = vslider("v:soundsgood/t:expert/h:[3]leveler/[4][scale:log]leveler speed", init_leveler_speed, .005, 0.15, .005);
    leveler_gate_thresh = vslider("v:soundsgood/t:expert/h:[3]leveler/[5]leveler gate threshold[unit:dB]", init_leveler_gatethreshold,-90,0,1);
    limit_pos = vslider("v:soundsgood/t:expert/h:[3]leveler/[7]leveler max +", init_leveler_maxboost, 0, 60, 1);
    limit_neg = vslider("v:soundsgood/t:expert/h:[3]leveler/[8]leveler max -", init_leveler_maxcut, 0, 60, 1) : ma.neg;

    lp1p(cf) = si.smooth(ba.tau2pole(1/(2*ma.PI*cf)));
};

// EQ with bypass
eq_bp = bp2(checkbox("v:soundsgood/t:expert/h:[4]eq/[1]eq bypass"),eq);
eq = hp_eq : tilt_eq : side_eq with{
  // HIGHPASS
  hp_eq = par(i,2,fi.highpass(1,freq)) with {
    freq = vslider("v:soundsgood/t:expert/h:[4]eq/h:[1]highpass/[1]eq highpass freq [unit:Hz] [scale:log]", 5, 5, 1000,1);
  };

  // TILT EQ STEREO
  tilt_eq = par(i,2,_) : par(i,2, fi.lowshelf(N, -gain, freq) : fi.highshelf(N, gain, freq)) with{
      N = 1;
      gain = vslider("v:soundsgood/t:expert/h:[4]eq/h:[2]tilt eq/[1]eq tilt gain [unit:db]",0,-6,6,0.5);
      freq = vslider("v:soundsgood/t:expert/h:[4]eq/h:[2]tilt eq/[2]eq tilt freq [unit:Hz] [scale:log]", 630, 200, 2000,1);
  };

  // SIDE EQ
  side_eq = ms_enc : (_, eq) : ms_dec with{
      eq = fi.peak_eq(eq_gain,eq_freq,eq_bandwidth);

      eq_gain = vslider("v:soundsgood/t:expert/h:[4]eq/h:[3]side eq/[1]eq side gain [unit:db]",0,0,6,0.5);
      eq_freq = vslider("v:soundsgood/t:expert/h:[4]eq/h:[3]side eq/[2]eq side freq [unit:Hz] [scale:log]", 630, 100, 3000,1);
      eq_bandwidth = vslider("v:soundsgood/t:expert/h:[4]eq/h:[3]side eq/[3]eq side bandwidth [unit:Hz] [scale:log]", 50, 10, 3000,1);

  };
};

// MSCOMP8 Interpolated (Bart Brouns)
mscomp8i_bp = bp2(checkbox("v:soundsgood/t:expert/h:[5]mscomp/h:[0]bypass/[1]mscomp bypass"),mscomp8i(target));

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


  //crossoverFreqs = vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[1]low band/[1]mscomp low freq", 60, 20, 20000, 1),vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[2]high band/[1]freq", 8000, 20, 20000, 1):LogArray(Nr_crossoverFreqs);
  crossoverFreqs = 60,8000 :LogArray(Nr_crossoverFreqs);
  strength_array = vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[1]low band/[2]low strength", 0.1, 0, 8, 0.1),vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[2]high band/[2]high strength", 0.3, 0, 8, 0.1):LinArray(Nr_bands);
  thresh_array = target + vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[1]low band/[3]low thresh", -2, -12, 12, 0.5),target + vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[2]high band/[3]high thresh", -6, -12, 12, 0.5):LinArray(Nr_bands);
  att_array = (vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[1]low band/[4]low attack", 15, 0, 100, 0.1)*0.001,vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[2]high band/[4]high attack", 0.1, 0, 100, 0.1)*0.001):LogArray(Nr_bands);
  rel_array = (vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[1]low band/[5]low release", 150, 1, 1000, 1)*0.001,vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[2]high band/[5]high release", 25, 1, 1000, 1)*0.001):LogArray(Nr_bands);
  knee_array = (vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[1]low band/[6]low knee", 12, 0, 30, 0.1),vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[2]high band/[6]high knee", 12, 0, 30, 0.1)):LinArray(Nr_bands);
  link_array = (vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[1]low band/[7]low link", 0.5, 0, 1, 0.1),vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[2]high band/[7]high link", 0.5, 0, 1, 0.1)):LinArray(Nr_bands);
  mscomp8i_outGain = vslider("v:soundsgood/t:expert/h:[5]mscomp/h:[3]out/[3]output gain", 1, -6, 6, 0.5):ba.db2linear;

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


// KNEE COMPRESSOR
kneecomp_bp = bp2(checkbox("v:soundsgood/t:expert/h:[7]kneecomp/[1]kneecomp bypass"),kneecomp(target));
kneecomp(target) = ms_enc : co.RMS_FBcompressor_peak_limiter_N_chan(strength,thresh,threshLim,att,rel,knee,link,meter,meterLim,2): post_gain  : ms_dec  with {

    strength = vslider("v:soundsgood/t:expert/h:[7]kneecomp/[1]kneecomp strength", 1, 0, 1, 0.1);
    thresh = target + vslider("v:soundsgood/t:expert/h:[7]kneecomp/[unit:dB][2]kneecomp threshold",init_kneecomp_thresh,-30,0,1);
    threshLim =
        // +6;
        vslider("v:soundsgood/t:expert/h:[7]kneecomp/[unit:dB][3]threshLim",0,-30,0,1);
    att = vslider("v:soundsgood/t:expert/h:[7]kneecomp/[3]kneecomp attack[unit:ms]",10,1,100,1)*0.001;
    rel = vslider("v:soundsgood/t:expert/h:[7]kneecomp/[4]kneecomp release[unit:ms]",100,1,1000,1)*0.001;
    knee = vslider("v:soundsgood/t:expert/h:[7]kneecomp/[5]kneecomp knee",12,0,60,1);
    link = vslider("v:soundsgood/t:expert/h:[7]kneecomp/[6]kneecomp link", 0.5, 0, 1, 0.1);
    meter = _<: _,( ba.linear2db:vbargraph("v:soundsgood/t:expert/h:[7]kneecomp/comp[unit:dB]",-20,0)) : attach;
    meterLim =
        // _;
        _<: _,( ba.linear2db:vbargraph("v:soundsgood/t:expert/h:[7]kneecomp/lim[unit:dB]",-20,0)) : attach;

    //post_gain
    post_gain = par(i,2,_ * g) with {
        g =  vslider("v:soundsgood/t:expert/h:[7]kneecomp/[9]kneecomp makeup[unit:dB]", init_kneecomp_postgain,-10,+10,0.5) : ba.db2linear;
    };

};


// LIMITER
limiter_bp = bp2(checkbox("v:soundsgood/t:expert/h:[7]limiter/[1]limiter bypass"),limiter);

limiter = limiter_lad_N(2,limiter_lad_lookahead, init_limiter_lad_ceil : ba.db2linear, limiter_lad_attack, limiter_lad_hold, limiter_lad_release) : post_gain with{

    N=2;

    limiter_lad_lookahead = 0;
    limiter_lad_attack = 0.001;
    limiter_lad_hold = 0.005;
    limiter_lad_release = 0.02;

    // lookahead limiter (N-channel)
    limiter_lad_N(N, LD, ceiling, attack, hold, release) =
        si.bus(N) <: par(i, N, @ (LD * ma.SR)),
            (scaling <: si.bus(N)) : ro.interleave(N, 2) : par(i, N, *)
        with {
            scaling = ceiling / max(amp_profile, ma.EPSILON) : min(1) : limiter_meter;
            amp_profile = par(i, N, abs) : maxN(N) : ba.peakholder(hold * ma.SR) : att_smooth(attack) : rel_smooth(release);
            att_smooth(time, in) = si.smooth(ba.tau2pole(time), in);
            rel_smooth(time, in) = an.peak_envelope(time, in);
            maxN(1) = _;
            maxN(2) = max;
            maxN(N) = max(maxN(N - 1));
        };

    // post_gain
    post_gain = par(i,Nch,_ * limiter_postgain) with {

    };

    limiter_postgain = vslider("v:soundsgood/t:expert/h:[7]limiter/[3]limiter makeup[unit:dB]", init_limiter_postgain,-10,+10,0.5) : ba.db2linear;
    limiter_meter = _ <: attach(ba.linear2db : abs : vbargraph("v:soundsgood/t:expert/h:[7]limiter/[2][unit:dB]limiter gain reduction",0,12));
};


// BRICKWALL
brickwall_bp = bp2(checkbox("v:soundsgood/t:expert/h:[8]brickwall/[1]brickwall bypass"),brickwall);

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
    brickwall_meter = _ <: attach(ba.linear2db : abs : vbargraph("v:soundsgood/t:expert/h:[8]brickwall/[8][unit:dB]brickwall gainreduction",0,12));

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

lufs_meter_in(l,r) = l,r <: l, attach(r, (lk2 : vbargraph("v:soundsgood/h:easy/[0][unit:dB]in lufs-s",-70,0))) : _,_;
lufs_meter_out(l,r) = l,r <: l, attach(r, (lk2 : vbargraph("v:soundsgood/h:easy/[9][unit:dB]out lufs-s",-70,0))) : _,_;
