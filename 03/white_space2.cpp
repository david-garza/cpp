// Demonstrates the + operator on strings, catonation

#include "../std_lib_facilities.h"

int main() {
	cout << "Please enter your first name and last name:\n";
	string first; //variable for first name
	string last; //variable for last name
	string name; //variable to hold the combined name

	cin >> first >> last; //input line

	name = first + ' ' + last;

	cout << "Hello, " << name << '\n'; // Output the string that has combined the first and last name

	return(0);
}