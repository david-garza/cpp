// This program either converst strings to number or numbers to strings

#include "..\..\std_lib_facilities.h"

int main() {
	string input;
	vector<string> words(10);
	words[0] = "zero";
	words[1] = "one";
	words[2] = "two";
	words[3] = "three";
	words[4] = "four";
	words[5] = "five";
	words[6] = "six";
	words[7] = "seven";
	words[8] = "eight";
	words[9] = "nine";

	cout << "Please enter digts as either numerals or words: ";
	while (cin >> input) {
		if (input == "0")
			cout << words[0] << '\n';
		else if (input == "1")
			cout << words[1] << '\n';
		else if (input == "2")
			cout << words[2] << '\n';
		else if (input == "3")
			cout << words[3] << '\n';
		else if (input == "4")
			cout << words[4] << '\n';
		else if (input == "5")
			cout << words[5] << '\n';
		else if (input == "6")
			cout << words[6] << '\n';
		else if (input == "7")
			cout << words[7] << '\n';
		else if (input == "8")
			cout << words[8] << '\n';
		else if (input == "9")
			cout << words[9] << '\n';
		else if (input == "zero")
			cout << "0\n";
		else if (input == "one")
			cout << "1\n";
		else if (input == "two")
			cout << "2\n";
		else if (input == "three")
			cout << "3\n";
		else if (input == "four")
			cout << "4\n";
		else if (input == "five")
			cout << "5\n";
		else if (input == "six")
			cout << "6\n";
		else if (input == "seven")
			cout << "7\n";
		else if (input == "eight")
			cout << "8\n";
		else if (input == "nine")
			cout << "0\n";
		else
			cout << "NA\n";
	}


	keep_window_open();
	return(0);
}