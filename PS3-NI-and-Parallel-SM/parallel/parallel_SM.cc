/*------------------ 
Harri Pahirathan
CSCD92
PS3-NI-and-Parallel-SM Parallel
1003371549
-------------------*/

#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <omp.h>
#include "ticktock.h"
#include "ticktock.cc"

using namespace std;

// Function to calculate the Left Sum
double left_sum(double N){
	// Variables given to us
	double H, xi, sum;
	H = 1 / N;
	xi = 0;
	// Holds the left sums
	sum = 0;
	int i;
	// Parralize the code using memory from initial x and H holding fraction of parition
	#pragma omp parallel for shared(xi, H, N) private(i) reduction(+:sum)
	for(i = 0; i < (int)N; i++){
		xi = i*H;
		sum += (4/(1 + (pow(xi, 2))))*H;
	}
	return sum;
}

int main(){
	// The value of the parition
        double N = 4000000;
	// Will be the count mechanic
        TickTock time;
        std::cout << "Start of program\n";
        std::cout << "Number of N: " << N << std::endl;
        time.tick();
	double tot = left_sum(N);
        std::cout << "The Left Riemann Sum Value: " << tot << std::endl;
	// Stops the time
        time.tock("Code took: ");
	// Numerical error
	double pi = 2 * acos(0.0);
	std::cout << "Numerical Error(Difference pi and sum): " << pi - tot << std::endl;
        return 0;
}
