// Asks the user to provide the first and last name, this is one attempt in trying to handle the white space issue

#include "../std_lib_facilities.h"

int main() {
	cout << "Please enter your first name and last name:\n";
	string first; //variable for first name
	string last; //variable for last name
	cin >> first >> last; //input line
	cout << "Hello, " << first << ' ' << last << '\n'; // ' ' is used to inster the single character white space between the first and last name
	return(0);
}