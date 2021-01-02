/* Excercise 5.11 write out the Fibonacci sequence */
#include "../../std_lib_facilities.h"

int main()
try {
	int index;
	cout << "Enter the number of Fibonacci numbers: ";
	cin >> index;
	if (index > 46) {
		error("Value exceeds memory bounds! Please enter a value 46 or less.");
	}
	vector<int> fib;
	for (int i = 0; i < index; i++)
	{
		if (i == 0||i==1) {
			fib.push_back(1);
		}
		else {
			fib.push_back(fib[i - 2] + fib[i - 1]);
		}
	}
	for (int i : fib) {
		cout << i << endl;
	}
	keep_window_open();
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