/* 
	11/13/2021 David Carlos Garza

	8.9
	Write a function that given two vector<double>s price and weight com-
	putes a value (an "index") that is the sum of all price[i]*weight[i]. Make
	sure to have weight.size()==price.size().


*/
#include "../../std_lib_facilities.h"
// Compare length of vectors
void checksize(vector<double> x, vector<double> y) {
	if (x.size() != y.size())
		error("List not equal!");
}
//---------------------------------------------------------

// To compute an index

double index(vector<double>& x, vector<double>& y) {
	checksize(x, y);
	double total{ 0 };

	for (int i = 0; i < x.size(); i++)
		total = total + x[i] * y[i];

	return total;
}

//---------------------------------------------------------

int main()
try {

	vector<double> weight{ 1,2,3 };
	vector<double> price{ .5,.5,.5 };

	cout << index(weight, price);
	
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