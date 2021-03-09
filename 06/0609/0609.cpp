/*
	Date: 03/01/2021
	Author: David Carlos Garza
	Purpose: Exercie 06.09 read digits as characters then covert them to ints.
	
	Specifications:
	1. Read either 1,2,3, or 4 digits as characters.
	2. Convert them to ints
	
	Example input: 123 (read as characters)
	Example output: 123 is 1 hundred and 2 tens and 3 ones (numbers should be ints)
*/
#include "../../std_lib_facilities.h"

// Object that holds the value and the place value of the digit
class Number 
{
public:
	int thousands; // Value in the thousands place
	int hundreds;  // Value in the hundreds place
	int tens; // Value in the tens place
	int ones; // Value in the ones place
	Number(int thou, int hund, int ten, int one)
		:thousands(thou), hundreds(hund), tens(ten), ones(one) {}
};
//------------------------------------------------------------------------------------------------

// Function that converst a character vector into a number object. '5'-'0'==5.
Number convert(vector<char> x)
{
	Number num(0, 0, 0, 0); // Define number object
	
	if (x.size() == 1) // If-then block adjusts the place holder values depending on the number of digits entered defined by vector size.
	{
		num.ones = x[0] - '0';
		return num;
	}
	else if (x.size() == 2)
	{
		num.tens = x[0] - '0';
		num.ones = x[1] - '0';
		return num;
	}
	else if (x.size() == 3)
	{
		num.hundreds = x[0] - '0';
		num.tens = x[1] - '0';
		num.ones = x[2] - '0';
		return num;
	}
	else if (x.size() == 4)
	{
		num.thousands = x[0] - '0';
		num.hundreds = x[1] - '0';
		num.tens = x[2] - '0';
		num.ones = x[3] - '0';
		return num;
	}
	else // If more than 4 digits are entered, throw an error.
		error("Too many digits entered!");

}
//------------------------------------------------------------------------------------------------
/* 
	Prints the output to the screen. Should be of the following format:
	123 is 1 hundred and 2 tens and 3 ones.

	Requirements:
	1. Do not print leading 0s.
*/
void print(Number x)
{
	
	if (x.thousands == 0 && x.hundreds == 0 && x.tens == 0 && x.ones == 0) // Check for an all 0 condition
		cout << x.ones << " is zero!\n";

	else if (x.thousands == 0 && x.hundreds == 0 && x.tens == 0) // Single digit number.
		cout << x.ones << " is " << x.ones << " ones.\n";

	else if(x.thousands == 0 && x.hundreds == 0) // Two digit number
		cout << x.tens << x.ones << " is " << x.tens << " tens and " << x.ones << " ones.\n";

	else if(x.thousands == 0) // Three digit number
		cout << x.hundreds << x.tens << x.ones << " is " << x.hundreds << " hundreds and " << x.tens << " tens and " << x.ones << " ones.\n";

	else // Four digit number.
		cout << x.thousands << x.hundreds << x.tens << x.ones << " is " << x.thousands << " thousands and " << x.hundreds << " hundreds and " << x.tens << " tens and " << x.ones << " ones.\n";
}

//------------------------------------------------------------------------------------------------
/*
	Function to check if the inputs are all numbers, throws an error if not. Only throws an error.
*/

void check(vector<char> x)
{
	for (int i = 0; i < x.size(); i++)
	{
		switch (x[i])
		{
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			continue;
		default:
			error("Numerical digits expected!");
			break;
		}
			
	}
}
//------------------------------------------------------------------------------------------------
// Main controls the inputs and the quit condition of the program.
int main()
try 
{
	cout << "Please enter a number between 1 to 4 digits and end it with '.'\nEnter 'q' to exit.\n\n";
	
	while (true) // Keeps looping until either an error occurs or the user enters 'q' to exit the program.
	{
		// Provide and input prompt for the user then read the characters from the line.
		cout << ">";
		char temp;
		cin >> temp; 

		// Checks for exit condition or NULL value entered, put back the character if the loop not broken.
		if (temp == 'q') 
			break;
		else if (temp == '.')
			error("No digits entered!");

		cin.putback(temp); 

		// Loop to read in digits to the character vector called digits, terminates when '.' encountered.
		vector<char> digits; 

		while (true) 
		{
			cin >> temp;
			if (temp == '.') 
				break;
			else
				digits.push_back(temp); 
		}

		// Check the quailty of inputed values
		check(digits);

		//Convert character vector into a number object
		Number num = convert(digits); 

		// Print the results
		print(num);
	}
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception!\n";
	return 2;
}