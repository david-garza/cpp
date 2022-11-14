/*

David Carlos Garza
1/1/2022

1006

Define a Roman_int class for holding Roman numerals (as ints) with a
<< and >>. Provide Roman_int with an as_int() member that returns the
int value, so that if r is a Roman_int, we can write cout << "Roman"
<< r << " equals " << r.as_int() << '\n\;.

Reference:

I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000

Using standard notation without a bar or box to multiply by 1,000 or 10,000.
The range for numbers will be 1 >= value < 4000.
*/
#include"Roman.h"
#include "../../dcg.h"

namespace Roman {
	// Helpful variables
	constexpr int int_upper{ 4000 };
	constexpr int int_lower{ 0 };
	// Vector table of roman charactors
	vector<char> roman_num_tbl{
		'I','V','X','L','C','D','M'
	};
	//---------------------------------------------------------------
	// Default constructor defauls to 1, no 0 Roman numeral
	Roman_int::Roman_int()
		:value{1}
	{}

	// Roman num intilized by arbaic numeral
	Roman_int::Roman_int(int an)
		:value{an}
	{
		if (!valid_int(an)) error("Integer value out of range");
	}
	//---------------------------------------------------------------
	// Operators for Roman_int
	ostream& operator<<(ostream& os, Roman_int& r)
	{
		return os << int_to_rn(r.as_int());
	}
	//---------------------------------------------------------------
	// Helper functions
	// Determines if the intger fits the range of the possible roman numerals
	bool valid_int(const int & n)
	{
		if (int_lower < n && n < int_upper) return true;
		else return false;
	}
	//---------------------------------------------------------------
	bool valid_rn(string& rn)
	{
		if (rn.size() > 12) return false;						// Assumes that the longest roman numeral is 3333 MMMCCCXXXIII
		for (char cc : rn) if (!is_rn_char(cc)) return false;	// Checks the characters listed to see if they are roman numerals
		return true;
	}
	//---------------------------------------------------------------
	// Test to see if character is a roman numeral character
	bool is_rn_char(char& c)
	{
		for (char rn : roman_num_tbl) if (c == rn) return true;
		return false;
	}
	//---------------------------------------------------------------
	string int_to_rn(const int & n)
	{
		string roman_numeral;

		// Checks to see if the value is in range
		if (!valid_int(n)) error("Value out of range");

		int reminder{ 0 };		// Holds left over values after each roman numeral option
		int print_number{ 0 };	// Number of times the symbol needs to be printed

		// 1000 place holder
		print_number = n / 1000;
		reminder = n % 1000;
		for (int i{ 0 }; i < print_number; i++) roman_numeral += 'M';

		// 900 rule
		print_number = reminder / 900;
		reminder = reminder % 900;
		if (print_number == 1) roman_numeral += "CM";

		// 500 rule
		print_number = reminder / 500;
		reminder = reminder % 500;
		if (print_number == 1) roman_numeral += 'D';

		// 100 place holder
		print_number = reminder / 100;
		reminder = reminder % 100;
		if (print_number == 4) roman_numeral += "CD";
		else for (int i{ 0 }; i < print_number; i++) roman_numeral += 'C';

		// 90 rule
		print_number = reminder / 90;
		reminder = reminder % 90;
		if (print_number == 1) roman_numeral += "XC";

		// 50 rule
		print_number = reminder / 50;
		reminder = reminder % 50;
		if (print_number == 1) roman_numeral += 'L';

		// 10 place holder
		print_number = reminder / 10;
		reminder = reminder % 10;
		if (print_number == 4) roman_numeral += "XL";
		else for (int i{ 0 }; i < print_number; i++) roman_numeral += 'X';

		// 9 Rule
		print_number = reminder / 9;
		reminder = reminder % 9;
		if (print_number == 1) roman_numeral += "IX";

		// 5 rule
		print_number = reminder / 5;
		reminder = reminder % 5;
		if (print_number == 1) roman_numeral += 'V';

		// 1 place holder
		print_number = reminder / 1;
		reminder = reminder % 1;
		if (print_number == 4) roman_numeral += "IV";
		else for (int i{ 0 }; i < print_number; i++) roman_numeral += 'I';

		return roman_numeral;
	}
	// returns an integer from a string of roman numerals
	int rn_to_int(string& rn)
	{
		int sum{ 0 }; // holds addition of roman numeral combinations
		if (!valid_rn(rn)) error("Unexpected format");
		int index{ 0 }; // To keep track of loction on string

		// M Rule
		int m_sum{0};
		for (int i{ 0 }; i < rn.size(); i++) 
		{
			if (rn[i] != 'M')
			{
				index = i;
				break; // Exits the M loop
			}
			if (rn[i] == 'M')
			{
				m_sum += 1000;
				index = ++i;
				if (m_sum == 4000) error("Unexpected M");
			}
		}
		sum += m_sum;

		// rest of the rules ...

		return sum;
	}
} //End Roman_num