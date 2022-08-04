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
using namespace std;

// Macros
#define REAL 0
#define IMAG 1

int main(){
	// Define size of array
	int n = 3;
	//  Create input and out complex arrays
	fftw_complex x[n];
	fftw_complex y[n];
	// Fill x complex array	
	for (int i = 0; i < n; i++){
		x[i][REAL] = i + 1
		x[i][IMAG] = 0;
	}
	// Create plan to run FFTW
	fft_setup(n. x, y);
	// Output the following complex equations after FFTW
	std::cout << "FFT = " << std::endl;
	for (int i = 0; i < n; i++){
		if (y[i][IMAG] < 0)
			std::cout << y[i][REAL] << "-" << abs(y[i][IMAG]) << "i" << std::endl;
		else
			std::cout << y[i][REAL] << "+" << y[i][IMAG] << "i" << std::endl;
	}
	return 0;

}
