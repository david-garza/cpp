// This program demonstrates the various math operators used in C++

#include "../std_lib_facilities.h"

int main() {
	
	cout << "Please enter a number: "; //Prompt user for a number

	int n; // The variable object to hold the number
	double y;
	int z;

	cin >> n; // Read the number from the command prompt

	y = n; // Can't use << or >> to assign variables, must use =. This assign must occur for operations that can not be applied to int such as sqrt(). % can only be applied to int.

	cout << "n == " << n
		<< "\nn+1 == " << n + 1 // Don't use ++, this increments the variable and changes its value
		<< "\nthree times n == " << 3 * n
		<< "\ntwice n == " << n + n
		<< "\nn squared == " << n * n
		<< "\nhalf of n == " << n / 2
		<< "\nmodulo 5 of n == " << n % 5
		<< "\nsquare root of n == " << sqrt(y)
		<< endl; // Another way to say newline, "end of line"

	return(0);
}