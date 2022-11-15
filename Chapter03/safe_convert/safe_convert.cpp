// This program demonstrates the same conversion from char to int. Int can be converted back to char.

#include "../std_lib_facilities.h"

int main() {
	
	char c = 'x'; // Assign x to the character type c

	int i1 = c; // The charcter value c is assigned to the intger type i1
	int i2 = 'x'; // The value x is assigned directly to the intger type i2

	char c2 = i1; // assigns the integer value to the character type

	cout << c << ' ' << i1 << ' ' << c2 << '\n'; // c is type char, i1 is type integer, c2 is type char 

	return(0);
}