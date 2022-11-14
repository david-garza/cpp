/* Excercise 5.07: Provide roots for the quadratic equation, with error checking */
#include "../../std_lib_facilities.h"

/*Function for squaring numbers*/
double square(double x) {
	return x * x;
}
/* Function to test determinate */
double determinate(double a, double b, double c) {
	if (0 > square(b) - 4 * a*c) {
		error("Coefficients provided produce imaginary roots!");
	}
	return square(b) - 4 * a*c;
}
/* Quadratic formula 1*/
double root1(double a, double b, double c) {
	return (-b + sqrt(determinate(a,b,c))) / (2 * a);
}
/* Quadratic formula 2*/
double root2(double a, double b, double c) {
	return (-b - sqrt(determinate(a,b,c))) / (2 * a);
}
int main()
try {
	double a;
	double b;
	double c;
	cout << "Please enter coefficients: ";
	cin >> a >> b >> c;
	cout << root1(a, b, c) << endl;
	cout << root2(a, b, c) << endl;
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