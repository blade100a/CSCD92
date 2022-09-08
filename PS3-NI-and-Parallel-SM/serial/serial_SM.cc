/*------------------ 
Harri Pahirathan
CSCD92
PS3-NI-and-Parallel-SM Serial
1003371549
-------------------*/

#include <cmath>
#include <iostream>
#include <iomanip>
#include "ticktock.h"
#include "ticktock.cc"
#include <string>

using namespace std;

double eq(double x){
	return (4/(1 + (pow(x, 2))));
}

int left_sum(double N){
	double H, xi, sum;
	H = 1 / N; 
	xi = 0;
	sum = 0;
	for(int i = 0; i < N; i++){
		xi = i*H;
		sum += eq(xi);
	}
	return sum;
}

int main(){
	double N = 4000000;
	TickTock time;
	std::cout << "Start of program\n";
	std::cout << "Number of N: " << N << std::endl;
	time.tick();
	std::cout << "The Left Riemann Sum Value: " << left_sum(N) << std::endl;
	time.tock("Code took: ");
	return 0; 
}
