// -*-Faust-*-

declare name "Soundsgood";
declare version "1.0";
declare author "Klaus Scheuermann";
declare license "GPLv3";

// double precision -double needed!

const = library("lib/constants.dsp");
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





// main
process =

    si.bus(2)
    : dc_filter(2)

    : gate
    : correlate_meter
    : correlate_correct_bp

    : leveler(target)

    : mscomp8i(target)

    : limiter
    : brickwall

    : lufs_meter

    : si.bus(2)

;


// DC FILTER
dc_filter(N) = par(i,N,fi.dcblockerat(dc_filter_freq))
with {
  dc_filter_freq = 10.0;
};

// GATE
gate = ef.gate_stereo(gate_thresh,gate_att,gate_hold,gate_rel);


// LEVELER
leveler(target) = B <:    B    ,   (B <: B,B : lk2, + : calc : _ <: B) : ro.interleave(N,2) : par(i,N,*)
    with {
    N = 2;
    B = si.bus(N);

    calc(lufs,sc) = (lufs : leveler_meter_lufs : (target - _) : lp1p(leveler_speed_gated(sc)) : limit(limit_neg,limit_pos) : leveler_meter_gain : ba.db2linear) , sc : _,!;


    // target = vslider("[3]target[unit:dB]", init_leveler_target,-50,0,1);

    //limit_pos = vslider("[5]max +", init_leveler_maxboost, 0, 60, 1);
    //limit_neg = vslider("[6]max -", init_leveler_maxcut, 0, 60, 1) : ma.neg;
    limit(lo,hi) = min(hi) : max(lo);

    //leveler_speed = vslider("[4]speed", init_leveler_speed, .005, 0.15, .005);
    //leveler_gate_thresh = vslider("[8]lev gate thresh[unit:dB]", init_leveler_gatethreshold,-90,0,1);

    leveler_speed_gated(sc) = (gate_gain_mono(leveler_gate_thresh,0.1,0,0.1,abs(sc)) <: attach(_, (1-_) : meter_leveler_gate)) : _ * leveler_speed;
    //leveler_speed_gated(sc) = sc : (peak_expansion_gain_N_chan(1,leveler_gate_thresh,20,0.1,0.05,0.3,6,1,1) <: attach(_, (1-_) : meter_leveler_gate)) : _ * leveler_speed;

    // from library:
    gate_gain_mono(thresh,att,hold,rel,x) = x : extendedrawgate : an.amp_follower_ar(att,rel) with {
        extendedrawgate(x) = max(float(rawgatesig(x)),holdsig(x));
        rawgatesig(x) = inlevel(x) > ba.db2linear(thresh);
        minrate = min(att,rel);
        inlevel = an.amp_follower_ar(minrate,minrate);
        holdcounter(x) = (max(holdreset(x) * holdsamps,_) ~-(1));
        holdsig(x) = holdcounter(x) > 0;
        holdreset(x) = rawgatesig(x) < rawgatesig(x)'; // reset hold when raw gate falls
        holdsamps = int(hold*ma.SR);
    };

    // from Bart Brouns expander
    peak_expansion_gain_N_chan(strength,thresh,range,att,hold,rel,knee,prePost,link,1) =
      level(hold) : peak_expansion_gain_mono(strength,thresh,range,att,rel,knee,prePost);
    peak_expansion_gain_mono(strength,thresh,range,attack,release,knee,prePost,level) =
      level:ba.bypass1(prePost,si.lag_ud(attack,release)) :ba.linear2db : gain_computer(strength,thresh,range,knee) : ba.bypass1((prePost !=1),si.lag_ud(att,rel))
    with {
      gain_computer(strength,thresh,range,knee,level) =
        ( select3((level>(thresh-(knee/2)))+(level>(thresh+(knee/2)))
                 , (level-thresh)
                 , ((level-thresh-(knee/2)):pow(2) /(min(ma.EPSILON,knee*-2)))
                 , 0
                 )  *abs(strength):max(range)
                                   * (-1+(2*(strength>0)))
        );
      att = select2((strength>0),release,attack);
      rel = select2((strength>0),attack,release);
    };

    level(hold,x) =
      x:abs; //:ba.slidingMax(hold*ma.SR,192000*maxRelTime);



};




// LIMITER
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

    // metering
    //meter_limiter_lad_N = _ <: attach(ba.linear2db : vbargraph("[8][unit:dB]GR",-12,0));

};


// BRICKWALL
brickwall = limiter_lad_N(N, limiter_lad_lookahead, limiter_lad_ceil, limiter_lad_attack, limiter_lad_hold, limiter_lad_release)
    with{

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

    // metering

};



// +++++++++++++++++++++++++ LUFS METER +++++++++++++++++++++++++

lk2 = par(i,2,kfilter : zi) :> 10 * log10(max(ma.EPSILON)) : -(0.691) with {
  //Tg = 0.4; // 3 second window for 'short-term' measurement
  Tg = 3;
  zi = an.ms_envelope_rect(Tg); // mean square: average power = energy/Tg = integral of squared signal / Tg

  //kfilter = fi.highpass(1, 60) : fi.high_shelf(4, 1800);
  // Highpass:
  // At 48 kHz, this is the right highpass filter (maybe a Bessel or Thiran filter?):
  A48kHzHP = ( /* 1.0, */ -1.99004745483398, 0.99007225036621); B48kHzHP = (1.0, -2.0, 1.0);
  highpass48kHz = fi.iir(B48kHzHP,A48kHzHP);
  //highpass = fi.highpass(2, 40); // Butterworth highpass: roll-off is a little too sharp
  highpass = fi.highpass(1, 60); // From Klaus 2022-05
  //highpass = highpass48kHz; // From the spec


  A48kHzShelf = ( /* 1.0, */ -1.69065929318241, 0.73248077421585);  B48kHzShelf = (1.53512485958697, -2.69169618940638, 1.19839281085285);
  shelf48kHz = fi.iir(B48kHzShelf,A48kHzShelf);
  // shelf = fi.high_shelf(4, 1430); // Original JOS choice
  // shelf = fi.high_shelf(4, 1800); // From Klaus 2022-05
  shelf = shelf48kHz; // From the spec

  kfilter = highpass : shelf;
};

lufs_meter(l,r) = l,r <: l, attach(r, (lk2 : vbargraph("h:soundsgood/h:easy/[9][unit:dB]out-lufs-s",-40,0))) : _,_;









//envelope via lp by Dario Sanphilippo
lp1p(cf, x) = fi.pole(b, x * (1 - b)) with {
    b = exp(-2 * ma.PI * cf / ma.SR);
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
};

// stereo correction based on correlation
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
};

// stereo correction bypass checkbox
correlate_correct_bp = ba.bypass2(bypass_correlate_correct, correlate_correct);





// GUI soundsgood

leveler_meter_lufs = vbargraph("h:soundsgood/h:easy/[1][unit:dB]lufs-s",-70,0);
target = vslider("h:soundsgood/h:easy/[2]Target[unit:dB]", init_leveler_target,-50,0,1);
leveler_meter_gain = vbargraph("h:soundsgood/h:easy/[3]gain",-50,50);
leveler_speed = vslider("h:soundsgood/t:expert/h:[1]leveler/[4]speed", init_leveler_speed, .005, 0.15, .005);
leveler_gate_thresh = vslider("h:soundsgood/t:expert/h:[1]leveler/[5]gate-thr[unit:dB]", init_leveler_gatethreshold,-90,0,1);
meter_leveler_gate = vbargraph("h:soundsgood/t:expert/h:[1]leveler/[6]gate",0,1);
limit_pos = vslider("h:soundsgood/t:expert/h:[1]leveler/[7]max +", init_leveler_maxboost, 0, 60, 1);
limit_neg = vslider("h:soundsgood/t:expert/h:[1]leveler/[8]max -", init_leveler_maxcut, 0, 60, 1) : ma.neg;

gate_thresh = vslider("h:soundsgood/t:expert/h:gate/[1]thr",-90,-90,0,1);
gate_att = vslider("h:soundsgood/t:expert/h:gate/[2]att",0,0,0.1,0.01);
gate_hold = vslider("h:soundsgood/t:expert/h:gate/[3]hold",0.1,0,1,0.1);
gate_rel = vslider("h:soundsgood/t:expert/h:gate/[4]rel",0.5,0,5,0.1);

meter_correlate_meter = vbargraph("h:soundsgood/t:expert/h:correlation/correlation",-1,1);
bypass_correlate_correct = checkbox("h:soundsgood/t:expert/h:correlation/corr-bp");










limiter_postgain = vslider("h:soundsgood/t:expert/h:[4]limiter/[2]post-gain[unit:dB]", init_limiter_postgain,-10,+10,0.5) : ba.db2linear;
limiter_meter = _ <: attach(ba.linear2db : abs : vbargraph("h:soundsgood/t:expert/h:[4]limiter/[1][unit:dB]gr",0,12));

brickwall_meter = _ <: attach(ba.linear2db : abs : vbargraph("h:soundsgood/t:expert/h:[5]brickwall/[8][unit:dB]gr",0,12));

// lufs_meter = vbargraph("[unit:dB]LUFS",-70,0);














// MSCOMP8 Interpolated (Bart Brouns)


mscomp8i(target) =

    midside
  : Eight_band_Compressor_N_chan(2)
  : midside
;



// MSon = checkbox("MS on");



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

  meter(i) = _<:(_, (ba.linear2db:max(-40):min(0):vbargraph("h:soundsgood/t:expert/h:mscomp_meter/[%i][unit:dB]%i[tooltip: gain reduction in dB]", -3, 0))):attach;

  // inGain = CG(hslider("[1]input gain", 0, -30, 30, 0.1)):ba.db2linear;
  //crossoverFreqs = BT(vslider("[1]freq", 60, 20, 20000, 1),vslider("[1]freq", 8000, 20, 20000, 1)):LogArray(Nr_crossoverFreqs);
  crossoverFreqs = vslider("h:soundsgood/t:expert/h:mscomp/h:[1]lo/[1]freq", 60, 20, 20000, 1),vslider("h:soundsgood/t:expert/h:mscomp/h:[2]hi/[1]freq", 8000, 20, 20000, 1):LogArray(Nr_crossoverFreqs);
  //strength_array = BTli(vslider("[2]strength", 0.1, 0, 8, 0.1),vslider("[2]strength", 0.3, 0, 8, 0.1));
  strength_array = vslider("h:soundsgood/t:expert/h:mscomp/h:[1]lo/[2]strength", 0.1, 0, 8, 0.1),vslider("h:soundsgood/t:expert/h:mscomp/h:[1]hi/[2]strength", 0.3, 0, 8, 0.1):LinArray(Nr_bands);
  //thresh_array = BTli(target + vslider("[3]thresh", -2, -12, 12, 0.5),target + vslider("[3]thresh", -6, -12, 12, 0.5));
  thresh_array = target + vslider("h:soundsgood/t:expert/h:mscomp/h:[1]lo/[3]thresh", -2, -12, 12, 0.5),target + vslider("h:soundsgood/t:expert/h:mscomp/h:[1]hi/[3]thresh", -6, -12, 12, 0.5):LinArray(Nr_bands);
  //att_array = BTlo(vslider("[4]att", 15, 0, 100, 0.1)*0.001,vslider("[4]att", 0.1, 0, 100, 0.1)*0.001);
  att_array = (vslider("h:soundsgood/t:expert/h:mscomp/h:[1]lo/[4]att", 15, 0, 100, 0.1)*0.001,vslider("h:soundsgood/t:expert/h:mscomp/h:[1]hi/[4]att", 0.1, 0, 100, 0.1)*0.001):LogArray(Nr_bands);
  //rel_array = BTlo(vslider("[5]rel", 150, 1, 1000, 1)*0.001,vslider("[5]rel", 25, 1, 1000, 1)*0.001);
  rel_array = (vslider("h:soundsgood/t:expert/h:mscomp/h:[1]lo/[5]rel", 150, 1, 1000, 1)*0.001,vslider("h:soundsgood/t:expert/h:mscomp/h:[1]hi/[5]rel", 25, 1, 1000, 1)*0.001):LogArray(Nr_bands);
  //knee_array = BTli(vslider("[6]knee", 12, 0, 30, 0.1),vslider("[6]knee", 12, 0, 30, 0.1));
  knee_array = (vslider("h:soundsgood/t:expert/h:mscomp/h:[1]lo/[6]knee", 12, 0, 30, 0.1),vslider("h:soundsgood/t:expert/h:mscomp/h:[1]hi/[6]knee", 12, 0, 30, 0.1)):LinArray(Nr_bands);
  //link_array = BTli(vslider("[7]link", 0.5, 0, 1, 0.1),vslider("[7]link", 0.5, 0, 1, 0.1));
  link_array = (vslider("h:soundsgood/t:expert/h:mscomp/h:[1]lo/[7]link", 0.5, 0, 1, 0.1),vslider("h:soundsgood/t:expert/h:mscomp/h:[1]hi/[7]link", 0.5, 0, 1, 0.1)):LinArray(Nr_bands);
  mscomp8i_outGain = vslider("h:soundsgood/t:expert/h:mscomp/h:[3]out/[3]output gain", 1, -6, 6, 0.5):ba.db2linear;
  // make a linear array of values, from bottom to top
  LinArray(N,bottom,top) = par(i,N,   ((top-bottom)*(i/(N-1)))+bottom);
  // make a log array of values, from bottom to top
  LogArray(N,bottom,top) = par(i,N,   pow((pow((t/b),1/(N-1))),i)*b)
  with {
    b = bottom:max(ma.EPSILON);
    t = top:max(ma.EPSILON);
  };

  CG(x) = vgroup("[1]controls", x);
  MG(x) = hgroup("h:soundsgood/t:expert/h:mscomp/[2]gain reduction", x);
  // make a bottom and a top version of a parameter
  BT(b,t) = CG(hgroup("[2]", hgroup("[1]bottom", b),hgroup("[2]top", t)));
  BTlo(b,t) = BT(b,t):LogArray(Nr_bands);
  BTli(b,t) = BT(b,t):LinArray(Nr_bands);
  Nr_bands = 8;
  Nr_crossoverFreqs = Nr_bands-1;
  prePost = 1;
  maxGR = -30;
};


//--------------------`midside`-------------------
// Conversion from left and rigth channel to mid and side
// channel. Note that `midside : midside` equals the identity function
// `si.bus(2)`.
//
// #### Usage
//
// ```
// left, right : midside : mid, side
// mid, side : midside : left, right
// ```

// Author: Jakob Dübel
midside = si.bus(2) <: +(_, _), -(_, _) : /(sqrt(2)), /(sqrt(2));
