/*------------------ 
Harri Pahirathan
CSCD92
Part 2 Matrix and Eigenvalues
1003371549
-------------------*/

// Libraries
#include <iostream>
#include <fstream>
#include <cmath>
#include <lapacke.h>
using namespace std;
// Dimension Constants
const int N=10, LDA=N;

int main(){
	// Read file into array
	std::fstream mat("eigenvaluesA.txt");
	// Array holder
	double arr[N*LDA];
	// For eigenvalue return
	lapack_int eig;
	// Holds the computed eigenValues
	double wr[N]; 
	// Adds values from text to array
	for (int i = 0; i < 100; i++){
		mat >> arr[i];
		// QUICK PRINT TO SEE IF IT DID IT
		std::cout << arr[i];
	}
	// Call using lapack to find eigenvalues
	eig = LAPACKE_dsyev(LAPACK_COL_MAJOR, 'N', 'V', N, arr, LDA, wr);
	// Print the values from the function call
	for (int i = 0; i < N; i++){
		std::cout << wr[i] << std::endl;
	} 
        return 0;
}
