/* Exercise 3, error checking of code snippet. Added error checking when values are less than absolute 0. */
#include "../../std_lib_facilities.h"

/* Function to convert from celsius to kelvin */
double ctok(double c) {

	if (c < -273.15) {
		error("Value entered results in a value below absolute 0!");
	}

	double k = c + 273.15;
	return k;
}

int main()
try {
	double c = 0;
	cin >> c;
	double k = ctok(c);
	cout << k << endl;
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