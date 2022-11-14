/* 
	11/13/2021 David Carlos Garza

	8.10
	Write a function maxv() that returns the largets element of a vector
	argument.

*/
#include "../../std_lib_facilities.h"

// Find the largest element of a vector
double maxv(vector<double> x) {
	double max = x[0];

	for (double i : x)
		if (i > max)
			max = i;

	return max;
}
//--------------------------------------

int main()
try {

	vector<double> weight{ 1,2,3.7,20.4,1,0,-3.5 };
	
	cout << maxv(weight);

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