/* 
	David Garza
	12/7/2021

	0914
	Design and implement a Money class for calculations involving dollars
	and cents where arithmetic has to be accurate to the last cent using the
	4/5 rounding rule (.5 of a cent rounds up; anything less than .5 rounds
	down). Represent a monetary amount as a number of cents in a long int,
	but input and output as dollars and cents, e.g. $123.45. Do not worry 
	about amounts that don't fit into a long int.

	0915
	Refine the Money class by adding a currency (given as a constructor ar-
	gument). Accept a floating-point initializer as long as it can be exactly
	represented as a long int. Don't accept illegal operations. For example,
	Money*Money doesn't make sense, and USD1.23+DKK5.00 makes sense
	only if you provide a conversion table defining the conversion factor be-
	tween U.S. dollars (USD) and Danish kroner (DKK).

	0916
	Define an input operator (>>) that reads monetary amounts with cur-
	rency denominations, such as USD1.23 and DKK5.00, into a Money vari-
	able. Also define a corresponding output operator (<<).
*/
#include<iostream>
#include<ostream>
#include<vcruntime_exception.h>
#include"Money.h"

using namespace std;

int main()
try {

	Money::Money mm;
	cin >> mm;
	cout << mm;
	return 0;
}
catch (Money::Money::Invalid) {
	cerr << "error: Mixed currency operations";
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception!\n";
	return 2;
}