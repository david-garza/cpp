// Excercise 3.6, the purpose is to read in 3 values and output them in order

#include "../std_lib_facilities.h"

int main() {

	// Delcare variables
	double val1;
	double val2;
	double val3;
	double temp;

	// Prompt user for two values
	cout << "Plese enter three values seperated by a spaces, then press enter: ";
	cin >> val1 >> val2 >> val3;

	// Test the first two values and shuffle their positions if they not in the right order

	if (val1 > val2) {
		temp = val1;
		val1 = val2;
		val2 = temp;
	}

	// Test the second and third postions and switch their positions if they are out of order

	if (val2 > val3) {
		temp = val2;
		val2 = val3;
		val3 = temp;
	}

	// Test the first two values again given that val3 may be out of order now that it was moved in block above

	if (val1 > val2) {
		temp = val1;
		val1 = val2;
		val2 = temp;
	}

	// Output the values
	cout << val1 << ", " << val2 << ", " << val3 << '\n';
	
	return(0);
}