#pragma once
#include "../../dcg.h"

namespace Rational {
	class Rational {
	public:
		// Object to throw exceptions i.e. divide by zero errors
		class Invalid {};

		// Constructors
		Rational();
		Rational(int nn, int dd);

		// non-modifying functions
		int numerator() const { return n; }
		int denominator() const { return d; }
	private:
		int n;
		int d;
	};

	// Helper function error checking
	bool is_denominator(int nn);

	// Mathematical operators
	Rational operator+(const Rational& a, const Rational& b);
	Rational operator-(const Rational& a, const Rational& b);
	Rational operator*(const Rational& a, const Rational& b);
	Rational operator/(const Rational& a, const Rational& b);

	// Eqality operators
	bool operator==(const Rational& a, const Rational& b);
	bool operator!=(const Rational& a, const Rational& b);

	// Output operator
	ostream& operator<<(ostream& os, const Rational& rr);

	// Conversoin function
	double numeric(Rational& rr);

} // End namespace rational