// This program takes characters entered at the command line and stores them to a string variable.

#include "../std_lib_facilities.h"

int main() {
	cout << "Please enter your first name (followed by 'enter'):\n";
	string first_name; //first_name is a variable of the string time
	cin >> first_name; //read characters into first_name, the computer only reads up to the first space, anything after that is lost
	cout << "Hello, " << first_name << "!\n"; //This outputs the first name entered to the command line.
	return(0);
}