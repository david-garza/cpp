// Excercise 3.10, The purpose is to create a 4 function calculator

#include "../std_lib_facilities.h"

int main() {

	// Declare variables
	string operation;
	double x1;
	double x2;

	// Prompt user for operation and value
	cout << "Please enter and operation (+,-,*,/) and then two numbers, each seperated by spaces: ";
	cin >> operation >> x1 >> x2;

	// Test the operator and perform the operation

	if (operation == "+")
		cout << x1 + x2;

	if (operation == "-")
		cout << x1 - x2;

	if (operation == "*")
		cout << x1 * x2;

	if (operation == "/")
		cout << x1 / x2;

	return(0); 
}