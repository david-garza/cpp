// Excercise 3.2, the requirement is to write a code that converts miles to kilometers, uses 1 mile = 1.609 kilometers

#include "../std_lib_facilities.h"

int main() {

	double mile; // Miles to be provided by user

	cout << "Please enter miles: "; // Prompt user for miles 
	cin >> mile;

	cout << mile << " miles is " << mile * 1.609 << " kilometers.\n"; // Perform calculation and return the result to the user.
	
	return(0);
}