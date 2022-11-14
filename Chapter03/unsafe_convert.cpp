// This program demonstrates the unsafe conversion, large ints into small chars

#include "../std_lib_facilities.h"

int main() {
	
	int a = 20000; //Try to set a large intger value

	char c = a; // Convert the integer to character, the memory space for character should be less than a large integer

	int b = c; // This reads the truncated character back into the integer type, this will show what the value is.

	if (a != b) // a not equal b
		cout << "oops!: " << a << "!=" << b << '\n';
	else
		cout << "Wow! We have large characters\n";

	return(0);
}