/*------------------ 
Harri Pahirathan
CSCD92
Part 2 FFT
1003371549
-------------------*/

// Libraries
#include <iostream>
#include <complex>
#include <fftw3.h>
#include <cmath>
#include "fft-plan.h"
#include "fft-plan.cc"
using namespace std;

// Macros
#define REAL 0
#define IMAG 1

int main(){
	// Output file of std
	freopen("output.txt", "a", stdout);
	// Define size of array
	int n = 10;
	//fftw_complex *xp, *yp;
	//  Create input and out complex arrays
	//xp = fftw_complex x[n];
	//yp = fftw_complex y[n];
	fftw_complex x[n];
	fftw_complex y[n];
	// Fill x complex array	
	for (int i = 0; i < n; i++){
		x[i][REAL] = i + 1;
		x[i][IMAG] = 0;
	}
	// Create plan to run FFTW
	fft_setup(n, x, y);
	// Output the following complex equations after FFTW
	std::cout << "FFT = " << std::endl;
	for (int i = 0; i < n; i++){
		std::cout << y[i][REAL] << "+ (" << y[i][IMAG] << ")i" << std::endl;
	}
	std::cout << "Printed out: " << n << " Number of Complex equation after FFT 1 dimensional" << std::endl;
	std::cout << "FINISHED\n";
	return 0;

}
