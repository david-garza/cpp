// A number quessing game. User guesses a number between 1 -100. This program will use int

#include "..\..\std_lib_facilities.h"

int main() {
	string answer; // Answer to the question
	int guess = 50; // The current guess, starts at 50
	int low = 0; // The lowest possible number in the remaining range
	int high = 101; // The highest possible number in the remaining range
	int counter = 0; // guess counter
	

	cout << "Please think of a number between 1-100, enter y when ready. ";
	cin >> answer;

	while (low != guess||high != guess) { // This number keeps looping to ask the questions
		cout << "Is your number less than, greater than, or equal to: " << guess << " ? (<,>,=) ";
		cin >> answer;

		// Perform the test
		if (answer == "<"|| answer == ">"|| answer == "=") {
			counter++; // Loop counter

			if (answer == "<") {
				high = guess;
				guess -= ((guess - low) / 2);
			}
			else if (answer == ">") {
				low = guess;
				guess += (high - guess) / 2;
			}
			else if (answer == "=") {
				low = guess;
				high = guess;
			}
		}
		else
			cout << "You did not enter a valid response, please try again." << endl;
	}
	
	cout << "Your number is: " << guess << endl;
	cout << "Number of guesses: " << counter << endl;
	
	keep_window_open();
	return(0);
}