// This program takes characters entered at the command line and stores them to a string variable. Version 2

#include "../std_lib_facilities.h"

int main() {
	cout << "Please enter your first name and age:\n";
	string first_name ="???"; //string variable for the name, set the value of the variable 
	int age = -1; //integer variable for the age, set the value of the variable
	cin >> first_name >> age; //read the string followed by the integer
	cout << "Hello, " << first_name << " (age " << age << ")\n";
	cout << "Your age in months is: " << age * 12; // First time fun with operators
	return(0);
}