/* 
	David Carlos Garza
	11/27/2021

	9.10
	Implement leapyear() from section 9.8.

	9.11
	Design and implement a set of useful helper functions for the Date class
	with functions such as next_workday() (assume that any day that is not
	a Saturday or a Sunday is a workday) and week_of_year() (assume that
	week 1 is the week with January 1 in it and that the first day of a week is
	a Sunday.

	9.12
	Change the representation of a Date to be the number of days since January
	1, 1970 (known as day 0), represented as a long int, and re-implement the
	functions from section 9.8. Be sure to reject dates outside the range we can
	represent that way (feel free to reject days before day 0, i.e., no negative
	days).


*/


#include "../../dcg.h"
#include "Chrono_1970.h"

int main()
try {

	Chrono::Date date{ 18966 };

	date = Chrono::next_sunday(date);
	cout << date;

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