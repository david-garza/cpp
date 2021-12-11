#include "../../dcg.h"
#include "Rational.h"

// Constructors to create rational numbers
Rational::Rational::Rational()
	:n{0},d{1}
{
}

Rational::Rational::Rational(int nn, int dd)
	:n{nn},d{dd}
{
	if (!is_denominator(dd)) throw Invalid{};
}

// Helper function
bool Rational::is_denominator(int nn)
{
	if (nn == 0) return false;
	else return true;
}

Rational::Rational Rational::operator+(const Rational& a, const Rational& b)
{
	int n;
	int d;

	n = a.numerator() * b.denominator() + b.numerator() * a.denominator();
	d = a.denominator() * b.denominator();

	return Rational(n,d);
}

Rational::Rational Rational::operator-(const Rational& a, const Rational& b)
{
	int n;
	int d;

	n = a.numerator() * b.denominator() - b.numerator() * a.denominator();
	d = a.denominator() * b.denominator();

	return Rational(n, d);
}

Rational::Rational Rational::operator*(const Rational& a, const Rational& b)
{
	int n;
	int d;

	n = a.numerator() * b.numerator();
	d = a.denominator() * b.denominator();

	return Rational(n,d);
}

Rational::Rational Rational::operator/(const Rational& a, const Rational& b)
{
	int n;
	int d;

	n = a.numerator() * b.denominator();
	d = a.denominator() * b.numerator();

	return Rational(n,d);
}

bool Rational::operator==(const Rational& a, const Rational& b)
{
	int term1{ 0 };
	int term2{ 0 };

	// Cross multiply
	term1 = a.numerator() * b.denominator();
	term2 = b.numerator() * a.denominator();

	return term1==term2;
}

bool Rational::operator!=(const Rational& a, const Rational& b)
{
	return !(a==b);
}

// output operator
ostream& Rational::operator<<(ostream& os, const Rational& rr)
{
	return os << rr.numerator() << '/' << rr.denominator();
}

double Rational::numeric(Rational& rr)
{
	return double(rr.numerator()) / double(rr.denominator());
}

