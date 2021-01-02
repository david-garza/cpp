// This task is to find all of the primes between 1 and 100000 using the Sieve of Eratosthenes method.
// The idea is that you start with an array of numbers, then start crossing them out by multiples of the next number.

#include "..\..\std_lib_facilities.h"

int main() {
	vector<int> numbers(1000000,1); // A boolean vector of 1000000 numbers
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
	
	// Load the found primes to a vector called primes.
	vector<int>primes;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == 1) {
			primes.push_back(i);
		}
	}
	// Prompt the user to ask for how many primes they would like to view
	int n;
	cout << "Please enter how many primes you would like to display: ";
	cin >> n;
	if (n > 78498)
		cout << "There are only 78498 primes in the list, please select a smaller value!";
	else
		for (int i = 0; i < n; i++)
			cout << primes[i] << endl;

	keep_window_open();
	return(0);
}