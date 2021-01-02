// This program takes characters entered at the command line and stores them to a string variable.

#include "../std_lib_facilities.h"

int main() {
	cout << "Please enter your first name and age:\n";
	string first_name; //string variable for the name
	int age; //integer variable for the age
	cin >> first_name; //read the first set of characters on the command line up to the white space
	cin >> age; //read the second set of characters on the command line
	cout << "Hello, " << first_name << " (age" << age << ")\n";
	return(0);
}