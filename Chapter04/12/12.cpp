// This task is to find all of the primes between 1 and max value entered in by user

#include "..\..\std_lib_facilities.h"

int main() {
	vector<int> primes(1,2);
	bool prime = true; // flags the current number being tested
	int max;

	cout << "Please enter a max value to calculate primes to: ";
	cin >> max;

	for (int i = 3; i <= max; i++)
	{
		for (int j = 0; j < primes.size(); j++)
		{
			if (i%primes[j] == 0)
				prime = false;
		}
		if (prime == true){
			primes.push_back(i);
		}
		else if (prime == false) {
			prime = true;
		}
	}
	
	for (int i = 0; i < primes.size(); i++)
	{
		cout << primes[i] << endl;
	}
	keep_window_open();
	return(0);
}