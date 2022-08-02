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
	fftw_plan plan = fftw_plan_dft(n, x, y, FFTW_FORWARD, FFTW_ESTIMATE);
	// Execute the plan
	fftw_execute(plan);
	// Destroy plan after one execute
	fftw_destroy_plan(plan);
	// ??????? not sure the need 
	fftw_cleanup();
	// Output the following complex equations after FFTW
	cout << "FFT = " << endl;
	for (int i = 0; i < n; i++){
		if (y[i][IMAG] < 0)
			cout << y[i][REAL] << "-" << abs(y[i][IMAG]) << "i" << endl;
		else
			cout << y[i][REAL] << "+" << y[i][IMAG] << "i" << endl;
	}
	return 0;

}
