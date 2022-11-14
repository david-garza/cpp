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

*/


#include "../../dcg.h"
#include "Chrono_2.h"

int main()
try {

	Chrono::Date test( 2021,Chrono::Month::nov,26 );
	
	cout << Chrono::next_weekday(test);
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