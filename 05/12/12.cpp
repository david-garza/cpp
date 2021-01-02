/* 05.12 Excercise
Bulls and Cows game. User must guess the order of 4 non-repeating integers. Number guessed correctly is a cow,
number guessed in correct position is a bull. */

#include "../../std_lib_facilities.h"

vector<int> bovine(vector<int> x, vector<int> y) { /*x is the guess, y is the answer */

	/* Check for cows first, element bull second cow*/
	vector<int> sum = {0,0};

	for (int i = 0; i < 4; i++) /* Loop across each element of x */
	{
		for (int j = 0; j < 4; j++) /* Loop acroos each element of y*/
		{
			if (x[i] == y[j] && i==j) {
				sum[0]++;
			}
			else if (x[i] == y[j]) {
				sum[1]++;
			}
		}
	}
	return sum;
}

bool ch_repeat(vector<int> x) { /* Check for repeat elements in guess */
	sort(x); /*Sorts the elements in order*/

	if (x[0] == x[1] || x[1] == x[2] || x[2] == x[3]) {
		return true;
	}
	else {
		return false;
	}
}

bool ch_range(vector<int> x) { /*Check range of digits in answer*/
	
	for (int i = 0; i < 4; i++) {
		if (x[i] < 0 || x[i] > 9) {
			return false;
		}
	}
	return true;
}

bool ch_exit(vector<int> x) { /*Check for exit condtion to end the loop */
	if (x[0] == x[1] && x[1] == x[2] && x[2] == x[3]) {
		return true; /* Condition met to exit */
	}
	else
		return false;
}
int main()
try {
	vector<int> answer = { 1,2,3,4 };
	/* Guessing loop */
	while (true) {
		/*Ask user to input guess */
		cout << "To exit game enter same digit 4 times"<<endl;
		cout << "Please enter 4 digits seperated by space: ";
		vector<int> guess(4);
		cin >> guess[0] >> guess[1] >> guess[2] >> guess[3];

		/* Check for exit */
		if (ch_exit(guess) == true) {
			break;
		}

		/*Check for repeat digits */
		if (ch_repeat(guess) == true) {
			cout << "Digits repeat try again" << endl;
			continue;
		}
		/*Check for range of digits*/
		if (ch_range(guess) == false) {
			cout << "Digits out of range try again" << endl;
			continue;
		}

		/* Call bovine function to compare the inputs */
		vector<int> result;
		result = bovine(guess, answer);

		/*Print results of bovine*/
		cout << "Bull " << result[0] << " Cow " << result[1] << endl;

		/*Break loop */
		if (result[0] == 4) {
			cout << "You WIN!" << endl;
			break;
		}
	}
	keep_window_open("q");
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Unknown exception!\n";
	keep_window_open();
	return 2;
}