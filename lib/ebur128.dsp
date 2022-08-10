// -*-Faust-*-

// ISC License

// Copyright (c) 2022 Jakob Dübel

// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.

// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
// REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
// INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
// LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
// OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
// PERFORMANCE OF THIS SOFTWARE.

declare name "ITU-R BS.1770-4 prefilter";
declare version "1.0";
declare author "Jakob Dübel";
declare license "ISC";

// A filter very close to "Recommendation ITU-R BS.1770-4"
// (https://www.itu.int/rec/R-REC-BS.1770). "Close to", because the
// document, page 4-5, states filter coefficients for a specific
// sample rate of 48kHz. Here, we construct the biquads for arbitrary
// samplerates.

import("stdfaust.lib");


stage1 = fi.tf22t(b0,b1,b2,a1,a2)
with {
  f_0 = 1681.974450955533;
  G = 3.999843853973347;
  Q = 0.7071752369554196;
  K = tan((ma.PI * f_0)/ma.SR);
  Vh = pow(10, (G/20.0));
  Vb = pow(Vh, (0.4996667741545416));

  Ksq = K * K;
  KQ = K/Q;

  a0 = 1 + KQ + Ksq;
  b0 = (Vh + Vb*KQ + K^2)/(a0);
  b1 = 2*((Ksq - Vh)/(a0));
  b2 = (Vh - Vb*KQ + K^2)/(a0);
  a1 = 2*((Ksq - 1)/(a0));
  a2 = (1 - KQ + Ksq)/(a0);
};

stage2 = fi.tf22t(b0,b1,b2,a1,a2)
with {
  f_0 = 38.13547087602444;
  Q = 0.5003270373238773;
  K = tan((ma.PI * f_0)/ma.SR);
  Ksq = K * K;
  KQ = K/Q;
  
  b0 = 1;
  b1 = -2;
  b2 = 1;
  a1 = 2*((Ksq - 1)/(1 + KQ + Ksq));
  a2 = (1 + KQ + Ksq)/(1 - KQ + Ksq);
};

prefilter = stage1 : stage2;


// Normalize such that 997Hz has unity gain 1.0.  Otherwise a sinewave
// of ~1000Hz would gain 0.06742813dB. This is additional to the
// ITU-recommendation biquads! 997Hz is the closest prime number to
// 1000Hz.
normalize997 = *(0.9922671036981437);

ebur128 = prefilter : normalize997;
