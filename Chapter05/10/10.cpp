/* Exercise 5.10. Prompt the user for a number, then prompt for a list of numbers. */
/* Sum the list up to the number first provided. */
/* Modified to take doubles and added a differences */
#include "../../std_lib_facilities.h"
/* Function to sum a given number of items at the start of a vector */
double sum(int x, vector<double> y) {
	double sum = 0;
	for (int i = 0; i < x; i++) {
		sum += y[i];
	}
	return sum;
}
/* Function to write out the number of items that were summed*/
void print(int x, vector<double> y) {
	for (int i = 0; i < x; i++) {
		cout << y[i] << ' ';
	}
}
/*Function to find the difference between each element */
vector<double> difference(int x, vector<double> y) {
	vector<double> diff;
	for (int i = 0; i < x-1; i++) {
		diff.push_back(y[i + 1] - y[i]);
	}
	return diff;
}
/* Function to print out the differences */
void print_diff(vector<double> x) {
	for (int i : x) {
		cout << i << ' ';
	}
}
int main()
try {
	/* Prompt for number of values to sum */
	cout << "Please enter the number of values to sum: ";
	int index;
	cin >> index;
	if (index < 2) {
		error("Difference vector can't be created!");
	}
	/*Prompt for list of numbers*/
	cout << "Please enter a list of numbers (press '|' to stop): ";
	vector<double> list;
	double number;
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
	cout << "The difference between each number is ( ";
	print_diff(difference(index,list));
	cout << ")." << endl;
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