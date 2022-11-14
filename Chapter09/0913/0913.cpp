/* 
	David Carlos Garza
	12/6/2021

	9.13
	Design and implement a rational number class, Rational. A rational
	number has two parts: a numerator and a denominator, for example, 5/6
	(five-sixths, also known as approximately .83333). Look up the definition
	if you need to. Provide assignment, addition, subtraction, multiplication,
	division, and equality operators. Also, provide a converstion to double.
	Why would people want to use a Rational class?

*/
#include "../../dcg.h"
#include "Rational.h"

int main()
try {
	try {
		Rational::Rational frac1{1,4};
		Rational::Rational frac2{1,4};

		cout << frac1 << '+' << frac2 << '=' << frac1 + frac2 << endl;
		cout << frac1 << '-' << frac2 << '=' << frac1 - frac2 << endl;
		cout << frac1 << '*' << frac2 << '=' << frac1 * frac2 << endl;
		cout << frac1 << '/' << frac2 << '=' << frac1 / frac2 << endl;
		cout << frac1 << "==" << frac2 << '=' << (frac1 == frac2) << endl;
		cout << frac1 << "!=" << frac2 << '=' << (frac1 != frac2) << endl;
	}
	
	catch (Rational::Rational::Invalid) {
		cerr << "Denominator is 0" << endl;
	}
	
	
	
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