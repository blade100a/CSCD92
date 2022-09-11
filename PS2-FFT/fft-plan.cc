// Packages
#include <iostream>
#include <complex>
#include <fftw3.h>
#include <cmath>
#include "fft-plan.h"
using namespace std;

void fft_setup(int n, fftw_complex x[], fftw_complex y[]){
	std::cout << "STARTED PLAN\n";
	// Create plan to run FFTW
        fftw_plan plan = fftw_plan_dft_1d(n, x, y, FFTW_FORWARD, FFTW_ESTIMATE);
        std::cout << "EXECUTED PLAN\n";
	// Execute the plan
        fftw_execute(plan);
	std::cout << "DESTROYED PLAN\n";
        // Destroy plan after one execute
        fftw_destroy_plan(plan);
}
