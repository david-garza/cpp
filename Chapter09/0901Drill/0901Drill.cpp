/* 
	11/18/2021

	Drills from chapter 9 evolving date structure to formal class with helper functions

	First drill is example 9.4.1
		
*/
#include "../../std_lib_facilities.h"

// simple Date (too simple?)

struct Date {
	int y; // year
	int m;	// mont in year
	int d; // day of month
};
//-----------------------------

// helper functions
void init_day(Date& dd, int y, int m, int d)
{
	if (d < 1 || d>31)
		error("Day value out of range!");
	if (m < 1 || m>12)
		error("Month value of of range!");

	dd.y = y;
	dd.m = m;
	dd.d = d;
}
//-----------------------------

// Increase day value by n number of days
void add_day(Date& dd, int n) {
	dd.d += n;
}
//-----------------------------

// Mystery output stream and defining operator
ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.y
		<< ',' << d.m
		<< ',' << d.d << ')';
}
//-----------------------------
int main()
try {
	int y;
	int m;
	int d;
	Date today; // a date variable (a named object)

	while (cin) 
	try {
		
		cin >> y >> m >> d;
		init_day(today, y, m, d);
		cout << today;
		add_day(today, 1);
		cout << today;
	}
	catch (exception& e) {
		cerr << e.what() << '\n';
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