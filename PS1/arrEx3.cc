/*------------------ 
Harri Pahirathan
CSCD92
Part 1 Exercise 3
1003371549
-------------------*/

// Libraries
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// Creates array with 100,000
	int size = 100000;
	int arr = new int[size];
	// Fills array with equation given from exercise
	for (int i = 0; i < size; i++){
		arr[i] = floor(9*sin(i));
	}
	// Deallocates the array
	delete[] arr;
	return 0;
}
