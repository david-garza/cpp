// Compares two different strings, uses the if statement

#include "../std_lib_facilities.h"

int main() {
	
	cout << "Please enter two words\n"; //Prompt user for a number

	string first; //Variables for each word
	string second;

	cin >> first >> second; //Read the two words from the command line

	if (first == second) 
		cout << "The words are the same\n"; // Deterimes if the two strings are equal

	if (first < second)
		cout << first << " is alphabetically before " << second << '\n'; // determines if first comes before second

	if (first > second)
		cout << first << " is alphabetically after " << second << '\n'; // determins if first comes after second
	
	return(0);
}