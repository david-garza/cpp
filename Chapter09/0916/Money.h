#pragma once
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
#include<iosfwd>

using namespace std;

namespace Money {

	enum class Currency 
	{
		GBP,EUR,JPY,USD
	};

	ostream& operator<<(ostream& os, const Currency& cc);

	class Money {
	public:
		// Error throwing
		class Invalid{};

		//Constructors
		Money();
		Money(Currency cr, double dac); // Double entered represents dollars and cents (dac)

		//Non-modifying functions
		long int getamount() const { return amount; }
		long int getdollar() const { return abs(amount)/ 100; }
		long int getcent() const { return abs(amount) % 100; }
		Currency getcur() const { return cur; }
	private:
		Currency cur;
		long int amount;
	};

	
	// Money +,- Money
	Money operator+(const Money& a, const Money& b);
	Money operator-(const Money& a, const Money& b);

	// Money *,/ double; No Money*Money or Money/Money operations; operations return money
	// Division has to be money first always?
	Money operator*(const Money& mm, double d);
	Money operator/(const Money& mm, double d);

	// iostream operators
	istream& operator>>(istream& is, Money& mm);
	ostream& operator<<(ostream& os, const Money& mm);
	
} // End Money