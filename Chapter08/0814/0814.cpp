/* 
	11/15/2021 David Carlos Garza

	8.14
	Can we declare a non-reference function argument const (e.g., void
	f(const int);)? What might that mean? Why might we want to do that?
	Why don't people do that often? Try it; write a couple of small programs
	to see what works.

*/

#include "../../std_lib_facilities.h"

void f(const int);
// Function that returns an int vector with the length of each string in a vector string
void f(const int n)
{
	cout << n << endl;
	cout << n - 3 << endl;
	
}

//--------------------------------------------------------------------------


int main()
try {
	int test{ 3 };

	f(3);
	f(4);
	f(test);
	
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