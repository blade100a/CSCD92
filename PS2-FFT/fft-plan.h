#ifndef MYFFTSETUP_H_
#define MYFFTSETUP_H_
// Packages
#include <iostream>
#include <complex>
#include <fftw3.h>
#include <cmath>

// Defining my prototype
void fft_setup(int n, fftw_complex x[], fftw_complex y[]);

#endif
