// This task is to find all of the primes between 1 and 100 using the Sieve of Eratosthenes method.
// The idea is that you start with an array of numbers, then start crossing them out by multiples of the next number.

#include "..\..\std_lib_facilities.h"

int main() {
	vector<int> numbers(101,1); // A boolean vector of 101 numbers, 0 to 100. 1 means prime. Can't use a boolean vector here for some reason, the error occurs in the header file not here
	numbers[0] = 0;
	numbers[1] = 0; // Sets 0 and 1 to compount numbers, false == 0.

	// Loop down the number vector
	for (int i=0; i*i < numbers.size(); i++) {
		// Test for prime, then peform cross out operations
		if (numbers[i] == 1) {
			for (int j = i + i; j < numbers.size(); j += i)
				numbers[j] = 0;
		}
	}
	
	// Print out the true values only, primes
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == 1) {
			cout << i << endl;
		}
	}

	keep_window_open();
	return(0);
}