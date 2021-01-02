// Excercise 3.8, The purpose is to test whether a number is even or odd.

#include "../std_lib_facilities.h"

int main() {

	// Delcare variables
	int val1;
	
	// Prompt user for two values
	cout << "Plese enter an integer: ";
	cin >> val1;

	if (val1 % 2 == 0)
		cout << val1 << " is even";

	if (val1 % 2 == 1)
		cout << val1 << " is odd";

	return(0); 
}