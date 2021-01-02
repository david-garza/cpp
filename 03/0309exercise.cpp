// Excercise 3.9, The purpose is to output the word of a number for integers between 1 - 4

#include "../std_lib_facilities.h"

int main() {

	// Declare variables
	int x;

	// Prompt user for input
	cout << "Please enter an integer value: ";
	cin >> x;

	// Test and read out the number

	if (x == 0)
		cout << "zero";

	if (x == 1)
		cout << "one";

	if (x == 2)
		cout << "two";

	if (x == 3)
		cout << "there";

	if (x == 4)
		cout << "four";

	if (x < 0)
		cout << "I haven't learned that number yet!";

	if (x > 4)
		cout << "I haven't learned that number yet!";

	return(0); 
}