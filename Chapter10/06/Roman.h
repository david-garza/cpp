#pragma once
/*

David Carlos Garza
1/1/2022

1006

Define a Roman_int class for holding Roman numerals (as ints) with a
<< and >>. Provide Roman_int with an as_int() member that returns the
int value, so that if r is a Roman_int, we can write cout << "Roman"
<< r << " equals " << r.as_int() << '\n\;.

*/

#include "../../dcg.h"

namespace Roman {
	class Roman_int
	{
	public:
		// Constructors
		Roman_int();			// Defaults to 1! Since there is no 0 Roman numeral
		Roman_int(string rn);	// Constructor to read a strings like 'MM'
		Roman_int(int an);		// Constructor to reac intger values

		// Nonmodifying function
		int as_int() const { return value; } 
	private:
		int value;
	};

	// Operators
	ostream& operator<<(ostream& os, Roman_int& r);

	// Helper functions
	bool valid_int(const int & n);		// Determines if the intger fits the range of the possible roman numerals
	bool valid_rn(string& rn);	// Determiens if the string provide is a valid roman numeral per several test

	// Verify that symbol is a roman symbol
	bool is_rn_char(char& c);

	// Convert int to Roman Numeral
	string int_to_rn(const int & n);
	// Convert Roman Numeral to int
	int rn_to_int(string& rn);

} // End Roman_num space