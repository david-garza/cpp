
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
#include"Money.h"
#include<iostream>
#include<iosfwd>
#include<xstring>

using namespace std;

namespace Money {
	// Constructors
	Money::Money()
		:amount{ 0 },cur{Currency::USD}
	{
	}

	Money::Money(Currency cr, double dac)
		:amount{}, cur{cr}
	{
		// Convert and truncate the double to cents
		long int c{ 0 };
		c = dac * 100;

		// Rounding rule; first convert dac to cents then evaluate the fractional part of cents
		dac *= 100;
		double frac{ 0 };
		frac = dac - int(dac);
		
		// Test for negative and postive occurances of the fractional value
		if (frac <= -0.5) c--;
		if (frac >= 0.5) c++;

		amount = c;
	}

	ostream& operator<<(ostream& os, const Currency& cc)
	{
		switch (cc)
		{
		case Currency::EUR:
			return os << "EUR";
		case Currency::GBP:
			return os << "GBP";
		case Currency::JPY:
			return os << "JPY";
		case Currency::USD:
			return os << "USD";
		}
	}

	Money operator+(const Money& a, const Money& b)
	{
		if (a.getcur() != b.getcur()) throw Money::Invalid{};
		
		double sum = a.getamount() + b.getamount();

		return Money(a.getcur(),sum/100);
	}

	Money operator-(const Money& a, const Money& b)
	{
		if (a.getcur() != b.getcur()) throw Money::Invalid{};

		double sum = a.getamount() - b.getamount();

		return Money(a.getcur(), sum / 100);;
	}

	Money operator*(const Money& mm, double d)
	{
		double product = (double(mm.getamount()) * d)/100;
		return Money(mm.getcur(), product);
	}

	Money operator/(const Money& mm, double d)
	{
		double divsor = (double(mm.getamount()) / 100) / d;
		return Money(mm.getcur(),divsor);
	}

	istream& operator>>(istream& is, Money& mm)
	{
		char ch1, ch2, ch3;
		string s;
		double d{ 0 };
		Currency c{Currency::USD};

		is >> ch1 >> ch2 >> ch3 >> d;
		s += ch1;
		s += ch2;
		s += ch3;

		if (!is) return is;

		if (s == "EUR") c = Currency::EUR;
		else if (s == "GBP") c = Currency::GBP;
		else if (s == "JPY") c = Currency::JPY;
		else if (s == "USD") c = Currency::USD;
		else {
			is.clear(ios_base::failbit);
			return is;
		}

		mm = Money(c, d);
		return is;
	}

	ostream& operator<<(ostream& os, const Money& mm)
	{
		if (mm.getamount() == 0)
			return os << mm.getcur() << "0.00";
		else if (mm.getamount() > 0) {
			if(mm.getcent()<10)
				return os << mm.getcur() << mm.getdollar() << ".0" << mm.getcent();
			else
				return os << mm.getcur() << mm.getdollar() << '.' << mm.getcent();
		}	
		else if (mm.getamount() < 0) {
			if(mm.getcent() < 10)
				return os << mm.getcur() << '(' << mm.getdollar() << ".0" << mm.getcent() << ')';
			else
				return os << mm.getcur() << '(' << mm.getdollar() << '.' << mm.getcent() << ')';
		}
			
	}

} // End Money Namespace