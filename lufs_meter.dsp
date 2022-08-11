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






// main
process =
    //tone_generator :
    si.bus(2)

    : lufs_meter

    : si.bus(2)

;

// tone_generator
tone_generator = os.osc(f) * g <: _,_ with{
  g = vslider("tone_gen_gain",-50, -70,0,1):ba.db2linear;
  f = vslider("tone_gen_freq[unit:Hz] [scale:log]",1000,20,20000,1);
};


// +++++++++++++++++++++++++ LUFS METER +++++++++++++++++++++++++

lk2 = par(i,2,kfilter : zi) :> 10 * log10(max(ma.EPSILON)) : -(0.691) with {
  //Tg = 0.4; // 3 second window for 'short-term' measurement
  Tg = 3;
  zi = an.ms_envelope_rect(Tg); // mean square: average power = energy/Tg = integral of squared signal / Tg

  kfilter = ebu.prefilter;
};

lufs_meter(l,r) = l,r <: l, attach(r, (lk2 : vbargraph("[unit:dB]out-lufs-s",-70,0))) : _,_;
