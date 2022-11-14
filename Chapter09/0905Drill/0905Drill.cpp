/* 
	11/20/2021

	Drills from chapter 9 evolving date structure to formal class with helper functions

	Version from chapter section 9.7.4
		
*/
#include "../../std_lib_facilities.h"

// enum class for month
enum class Month {
	jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
};
//-----------------------------

// Define class year to for error catching
class Year {
	static const int min = 1800;
	static const int max = 2200;
public:
	class Invalid {};
	Year(int x) :y{ x } { if (x < min || max <= x)throw Invalid{}; }	// Constructore to create year
	int year() const { return y; }
private:
	int y;
};
//-----------------------------

// simple Date (use Month type)
class Date {
public:
	Date(Year y, Month m, int d);			// check for valid date and initialize
	void add_day(int n);					// increase the Date by n days
	Month month() const { return m; }		// Added constant to funct
	int day() const { return d; }
	int year() const { return y.year(); }
	class Invalid {};
private:
	Year y;							// Year
	Month m;						// Month as type month class
	int d;							// day
	bool is_valid();				// return true if dat is valid
};
//-----------------------------

// Constructor for Date
Date::Date(Year y, Month m, int d)
	:y{ y }, m{ m }, d{ d }
{
	if (!is_valid()) throw Invalid{};
}
//-----------------------------

// Define is_valid()
bool Date::is_valid()
{
	if (d < 1 || d > 31) return false;
}
//-----------------------------

// Define add_day
void Date::add_day(int n)
{
	d += n;
}
//-----------------------------

// Mysterious ostream
ostream& operator<<(ostream& os,const Date& d)
{
	return os << '(' << d.year()
		<< ',' << int(d.month())
		<< ',' << d.day() << ')';
}
//-----------------------------
int main()
try {
	try {
		Date today{ Year{2021},Month::apr,20 };
		cout << today << endl;
		Date tomorrow = today;

		tomorrow.add_day(1);
		cout << tomorrow << endl;
	}
	catch (Date::Invalid) {
		error("invalid day");
	}
	catch (Year::Invalid) {
		error("invalid Year");
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