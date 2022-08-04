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
	int* arr = new int[size];
	// Count array to hold the values counted
	int count[19]= { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	// Fills array with equation given from exercise
	for (int i = 0; i < size; i++){
		arr[i] = floor(9*sin(i));
		// Checks which number to count
		for(int j = -9; j < 10; j++){
			if(j == arr[i]){
				// Adds to count
				int k = j + 9;
				count[k] += 1;
			}
		}
	}

	// Prints values
	for (int i = 0; i < 19; i++){
		// Prints out values
		std::cout << i-9 << " " << count[i] << "\n";
	}

	// Deallocates the array
	delete[] arr;
	return 0;
}
