/* 
	11/19/2021

	Drills from chapter 9 evolving date structure to formal class with helper functions

	First drill is example 9.4.2 and 9.4.3
		
*/
#include "../../std_lib_facilities.h"

// simple Date (control access)

class Date {	
public:
	class Invalid {};			// to be used as exception
	Date(int y, int m, int d);	// check for a valid date and initialize
	void add_day(int n);		// increase the Date by n days
	int month() { return m; }
	int day() { return d; }
	int year() { return y; }
private:
	int y, m, d;				// year, month, day
	bool is_valid();			// return true if dat is valid
};
//-----------------------------

// Define is_valid()
bool Date::is_valid() 
{
	if (m < 1 || m > 12) return false;
		
	if (d < 1 || d > 31) return false;
		
}
//-----------------------------
// Constructor for Date
Date::Date(int y, int m, int d)
	:y{ y }, m{ m }, d{ d } 
{
	if (!is_valid()) throw Invalid{};
}
//-----------------------------

// Define add_day
void Date::add_day(int n)
{
	d += n;
}
//-----------------------------

// Mystery output stream and defining operator
ostream& operator<<(ostream& os, Date& d)
{
	return os << '(' << d.year()
		<< ',' << d.month()
		<< ',' << d.day() << ')';
}
//-----------------------------
int main()
try {
	try {
		Date today{ 2021,11,19 };
		cout << today << endl;
		Date tomorrow = today;

		tomorrow.add_day(1);
		cout << tomorrow << endl;
	}
	catch (Date::Invalid) {
		error("invalid date");
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