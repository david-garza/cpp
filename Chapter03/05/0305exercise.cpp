// Excercise 3.4, the requirement is to read in two doubles and then perform the following operations on them
// Determine smallest, largest, sum, difference, product, and ratio.

#include "../std_lib_facilities.h"

int main() {

	// Delcare variables
	double val1;
	double val2;

	// Prompt user for two values
	cout << "Plese enter two values seperated by a space, then press enter: ";
	cin >> val1 >> val2;

	// Determine which value is the largest

	if (val1 > val2)
		cout << "Largest: " << val1 << "\nSmallest: " << val2<< '\n';

	if (val2 > val1)
		cout << "Largest: " << val2 << "\nSmallest: " << val1<< '\n';

	// Sum the values
	cout << "Sum: " << val1 + val2 << '\n';
	
	// Difference of the values
	cout << "Difference: " << val1 - val2 << '\n';

	// Product of values
	cout << "Product: " << val1 * val2 << '\n';

	// Ratio of values
	cout << "Ratio: " << val1 / val2 << '\n';

	return(0);
}