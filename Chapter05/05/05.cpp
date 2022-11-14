/* Exercise 5, add the ability to covert from Kelvin to celsius */
#include "../../std_lib_facilities.h"

/* Function to convert from celsius to kelvin */
double ctok(double c) {

	if (c < -273.15) {
		error("Value entered results in a value below absolute 0!");
	}

	double k = c + 273.15;
	return k;
}
/* Function to convert from kelvin to celsius */
double ktoc(double k) {
	if (k < 0) {
		error("Value entered results in a value below absolute 0!");
	}
	double c = k - 273.15;
	return c;
}

int main()
try {
	double input = 0;
	cout << "Please enter a value: ";
	cin >> input;
	cout << "Plese select conversion:\n1: Celsius to Kelvin\n2: Kelvin to Celsius\nSelection: ";
	char selection;
	cin >> selection;
	
	switch (selection)
	{
	case'1':
		cout << ctok(input) << endl;
		break;
	case '2':
		cout << ktoc(input) << endl;
		break;
	default:
		cout << "Not a valid selection!\n";
		break;
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