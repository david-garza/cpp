// Practice problem in chapter 4 demonstrating if else statements the first version had an error in it

#include "..\..\std_lib_facilities.h"

int main() {

	const double cm_per_inch = 2.54; // number of centimeters in an inch
	int length = 1; // length in inches or centimeters
	char unit = 0; // character object to handle which unit is given

	// Prompt user to enter in either and inch or cm
	cout << "Please enter a length followed by a unit (c or i):\n"; // User can enter values such as 25i
	cin >> length >> unit;

	// This if else block now checks for both i and c units, and gives and error message to units that are not valid

	if (unit == 'i')
		cout << length << "in == " << cm_per_inch * length << "cm\n";

	else if (unit == 'c')
		cout << length << "cm == " << length / cm_per_inch << "in\n";
	else
		cout << "Unit '" << unit << "' is not a valid unit.\n";

	/*  Perform the calculation (initial statment only tested for i
	
	if (unit == 'i')
		cout << length << "in == " << cm_per_inch * length << "cm\n";
	else
		cout << length << "cm == " <<   length / cm_per_inch << "in\n";
	*/
	keep_window_open(); // This keeps the window open if calling it from the GUI
	return(0);
}

