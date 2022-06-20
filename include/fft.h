#ifndef _FFT_H_
#define _FFT_H_

#include <own_complex.h>

// procedura licząca tranformatę Fouriera.
void fft_forward(shared Complex *data, shared Complex* out, size_t N);

// procedura licząca tranformatę odwrtoną Fouriera.
void fft_backward(shared Complex *data, size_t N);

void fft_filter(double threshold, shared Complex *data, size_t N);

#endif