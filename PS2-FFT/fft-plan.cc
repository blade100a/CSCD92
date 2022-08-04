// Packages
#include <iostream>
#include <complex>
#include <fftw3.h>
#include <cmath>
#include "fft_plan.h"

void fft_setup(int n, fftw_complex x, fftw_complex y){
	// Create plan to run FFTW
        fftw_plan plan = fftw_plan_dft(n, x, y, FFTW_FORWARD, FFTW_ESTIMATE);
        // Execute the plan
        fftw_execute(plan);
        // Destroy plan after one execute
        fftw_destroy_plan(plan);
}
