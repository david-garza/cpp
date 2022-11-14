// Create a program to solve the quadratic equation Ax^2+Bx+C. Returns two solutions or no solutions

#include "../../std_lib_facilities.h"

int main() {
	//Prompt user for the A, B, C coefficients
	cout << "Please enter the A, B, C coefficients\nAx^2+Bx+C:" << endl;
	double a;
	double b;
	double c;
	cin >> a >> b >> c;
	// Perform the caculations
	double x0;
	double x1;
	if (b*b - 4 * a*c == 0) {
		x0 = (-b + sqrt(b*b - 4 * a*c)) / (2 * a);
		cout << "Only one solution exist: " << x0 << endl;
	}
	else if (b*b - 4 * a*c < 0) {
		cout << "No real roots exist!" << endl;
	}
	else {
	x0 = (-b + sqrt(b*b - 4 * a*c)) / (2 * a);
	x1 = (-b - sqrt(b*b - 4 * a*c)) / (2 * a);
	// Print the results
	cout << "x1 = " << x0 << " x2 = " << x1 << endl;
	}
	keep_window_open("q");
	return 0;
}