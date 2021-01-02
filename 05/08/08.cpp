/* Exercise 5.08. Prompt the user for a number, then prompt for a list of numbers. */
/* Sum the list up to the number first provided. */
#include "../../std_lib_facilities.h"
/* Function to sum a given number of items at the start of a vector */
int sum(int x, vector<int> y) {
	int sum = 0;
	for (int i = 0; i < x; i++) {
		sum += y[i];
	}
	return sum;
}
/* Function to write out the number of items that were summed*/
void print(int x, vector<int> y) {
	for (int i = 0; i < x; i++) {
		cout << y[i] << ' ';
	}
}
int main()
try {
	/* Prompt for number of values to sum */
	cout << "Please enter the number of values to sum: ";
	int index;
	cin >> index;
	/*Prompt for list of numbers*/
	cout << "Please enter a list of integers (press '|' to stop): ";
	vector<int> list;
	int number;
	/*Loop the input loop*/
	while (cin >> number) {
		list.push_back(number);
	}
	/* Error check the size of the vector against the index value */
	if (index > list.size()) {
		error("The number of values to sum is greater than the list length!");
	}
	/* Print the results */
	cout << "The sum of the first " << index << " numbers ( ";
	print(index, list);
	cout << ") is " << sum(index, list) << '.' << endl;
	keep_window_open("q");
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open("q");
	return 1;
}
catch (...) {
	cerr << "Unknown exception!\n";
	keep_window_open("q");
	return 2;
}