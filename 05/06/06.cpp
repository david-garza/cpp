/* Exercise 6, read a temperature and covert it to the other two scales */
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
/* Function to convert from celsius to fahrenheit */
double ctof(double c) {
	if (c < -273.15) {
		error("Value entered results in a value below absolute 0!");
	}
	double f = (9.0 / 5.0)*c + 32.0;
	return f;
}
/* Function to convert from celsius to fahrenheit */
double ftoc(double f) {
	if (f < (9.0 / 5.0)*-273.15 + 32.0) {
		error("Value entered results in a value below absolute 0!");
	}
	double c = (f - 32.0)*(5.0 / 9.0);
	return c;
}

int main()
try {
	double input = 0;
	cout << "Please enter a value: ";
	cin >> input;
	cout << "Plese select units:\n1: Celsius\n2: Kelvin\n3: Fahrenheit\nSelection: ";
	char selection;
	cin >> selection;
	
	switch (selection)
	{
	case'1':
		cout << ctok(input) << " K" << endl;
		cout << ctof(input) << " F" << endl;
		break;
	case'2':
		cout << ktoc(input) << " C" << endl;
		cout << ctof(ktoc(input)) << " F" << endl;
		break;
	case'3':
		cout << ftoc(input) << " C" << endl;
		cout << ctok(ftoc(input)) << " K" << endl;
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