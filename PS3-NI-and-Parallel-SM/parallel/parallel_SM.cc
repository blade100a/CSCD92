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
	double H, sum;
	H = 1 / N;
	// Holds the left sums
	sum = 0;
	int i;
	// Parralize the code using memory from initial x and H holding fraction of parition
	#pragma omp parallel for default(none) shared(H, N) private(i) reduction(+:sum)
	for(i = 0; i < (int)N; i++){
		double xi = i*H;
		sum += (4/(1 + (pow(xi, 2))))*H;
	}
	return sum;
}

int main(){
	// The value of the parition
        double N = 100000000;
	// File for output of stdout
	freopen("output_p.txt", "a", stdout);
	// Will be the count mechanic
	TickTock time;
	time.tick();
	double tot;
	omp_set_dynamic(0);
	omp_set_num_threads(16);
	#pragma omp shared(tot)
	{
        	std::cout << "Start of program\n";
        	std::cout << "Number of N: " << N << std::endl;
		tot = left_sum(N);
        	std::cout << "The Left Riemann Sum Value: " << tot << std::endl;
	}
	// Stops the time
        time.tock("Code took: ");
	// Numerical error
	double pi = 2 * acos(0.0);
	std::cout << "Numerical Error(Difference pi and sum): " << pi - tot << std::endl;
	std::cout << "\n";
        return 0;
}
