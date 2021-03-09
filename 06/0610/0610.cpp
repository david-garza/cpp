/* 
	Date: 03/08/2021
	Author: David Carlos Garza
	Purpose: Exerecise 0610

	Requirements: This program computes either a permutation or combination based on 2 user provided values, N the population size and k the sample size.

	General Program Flow:
		1. Prompt user to enter values
		2. Read values and validate values
		3. Prompt user to either compute permutation or combination
		4. Print values
		5. Loop till exit condtion.

*/
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "../../std_lib_facilities.h"
/*
	Introduction and instruction function. Only prints introduction and instructions on how to use the program. Occurs before main loop.
*/
void intro()
{
	cout << "This program computes either the number of permutations or combinations given n the population size and k the sample size to draw from the population.\n\n";
	cout << "Expected input is 2 integers seperated by a space, e.g. 'n k'\n\n";
	cout << "Enter 'q' to exit program\n\n"; 
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
	Factorial
		Function to compute the factorial of a integer. 0! is equal to 1 by defintion. Any other value is number multiplied a decreasing values.

		Example 4! = 4*3*2*1 = 24

		Used in permutation function and the combination function (by chaining via the permuation function)

*/
long double factorial(int x)
{
	if (x == 0)
		return 1;
	else
	{
		long double fact{ 1 };
		for (int i = 1; i <= x; i++)
		{
			fact *= i;
		}
		return fact;
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
	Perm
		Function to compute the number of permuations given the n the population size and k the sample size. Order matters (1,2,3) != (3,2,1).
*/
long double perm(int n, int k)
{
	return factorial(n) / factorial(n - k);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
	Comb
		Function to compute the number of permuationa given n the population size and k the sample size.  Order does not matter (1,2,3) = (3,2,1)
*/
long double comb(int n, int k)
{ 
	return perm(n, k) / factorial(k);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
	Result
		Function that ask the user which computation they want to perform then prints the results
		1. Ask user which algorithm they want
		2. Select the correct algorithm
		3. 4 print the results
*/
void result(int n, int k)
{
	// Prompt user for selection
	cout << "Enter 'c' for combination or 'p' for permutation\n";
	cout << '>';
	char ch;
	cin >> ch;

	// Use switch to compute selected algorithm
	switch (ch)
	{
	case 'c':
		cout << comb(n, k) << " combinations\n";
		break;
	case 'p':
		cout << perm(n, k) << " permutations\n";
		break;
	default:
		error("Expected 'c' or 'p'.");
	}
	
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------


/*
	Main program loop.
*/
int main()
try
{
	intro(); //Prints intro and instructions.

	while (true)
	{
		// Check for exit condition to exit program
		cout << '>';
		char ch;
		cin >> ch;
		if (ch == 'q')
			break;
		cin.putback(ch);

		// Read numerical values
		int n;
		int k;
		cin >> n >> k;

		// Validate input intger input, need to modify this to valiate if it numeric input?
		if (k > n)
			error("sample size is larger than population size");

		// Call result program to determine which algortim to use and print results.
		result(n,k);
	}
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open("q");
	return 1;
}
catch (...) {
	cerr << "Unknown exception!\n";
	keep_window_open("q");
	return 2;
}