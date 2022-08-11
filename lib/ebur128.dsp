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

freq2k(f_c) = tan((ma.PI * f_c)/ma.SR);

stage1 = fi.tf22t(b0,b1,b2,a1,a2)
with {
  f_c = 1681.7632251028442; // Hertz
  gain = 3.9997778685513232; // Decibel
  K = freq2k(f_c);
  V_0 = pow(10, (gain/20.0));

  denominator = 1.0 + sqrt(2.0)*K + K^2;
  b0 = (V_0 + sqrt((2.0*V_0))*K + K^2) / denominator;
  b1 = 2.0*(K^2 - V_0) / denominator;
  b2 = (V_0 - sqrt(2.0*V_0)*K + K^2) / denominator;

  a1 = 2*(K^2 - 1) / denominator;
  a2 = (1 - sqrt(2.0)*K + K^2) / denominator;
};

stage2 = fi.tf22t(b0,b1,b2,a1,a2)
with {
  f_c = 38.135470876002174; // Hertz
  Q = 0.5003270373223665;
  K = freq2k(f_c);

  denominator = (K^2) * Q + K + Q;
  b0 = Q / denominator;
  b1 = -2*Q / denominator;
  b2 = b0;

  a1 = (2*Q * (K^2 - 1)) / denominator;
  a2 = ((K^2) * Q - K + Q) / denominator;
};

prefilter = stage1 : stage2;


// Normalize such that 997Hz has unity gain 1.0.  Otherwise a sinewave
// of ~1000Hz would gain 0.66dB. This is additional to the
// ITU-recommendation biquads! 997Hz is the closest prime number to
// 1000Hz.
normalize997 = *(0.9273671710547968);

ebur128 = prefilter : normalize997;
