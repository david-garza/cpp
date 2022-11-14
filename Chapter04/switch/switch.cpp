// Program to demo the switch option, program will crash if units are string.

#include "..\..\std_lib_facilities.h"

int main() {

	//Declare variables
	const double cm_per_inch = 2.54; // number of centimeters in an inch
	int length = 1; // length in inches or centimeters
	char unit = 'a'; // character object to handle which unit is given

	// Prompt user to enter in either and inch or cm
	cout << "Please enter a length followed by a unit (c or i):\n"; // User can enter values such as 25i
	cin >> length >> unit;

	// This switch now checks for both i and c units, and gives and error message to units that are not valid
	switch (unit)
	{
	case'i':
		cout << length << "in == " << cm_per_inch * length << "cm\n";
		break;

	case'c':
		cout << length << "cm == " << length / cm_per_inch << "in\n";
		break;

	default:
		cout << "Unit '" << unit << "' is not a valid unit.\n";
		break;
	}
	
	keep_window_open();
	return(0);
}