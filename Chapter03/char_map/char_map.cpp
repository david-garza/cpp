// Allows user to enter an integer and return the character value with it.

#include "../std_lib_facilities.h"

int main() {
	
	double d = 0; // Intialize the double type

	while (cin >> d) { // Loop use ^c to exit

		int i = d; // Read the double type and change to an int type
		char c = i; // Read the int type into a character type
		int i2 = c; // converts the integer type into a character

		cout << "double type == " << d << '\n'
			<< "integer type == " << i << '\n'
			<< "Character to integer type == " << i2 << '\n'
			<< "char(" << c << ")\n";
	}
	

	return(0);
}