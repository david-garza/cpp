/* 
David Garza

12/23/2021

1003
Write a program that reads the data from raw_temps.txt created in ex-
ercise 2 into a vector and then calculates the mean and median tempera-
tures in your data set. Call this program temp_stats.cpp.

*/

#include "../../dcg.h"
#include "data.h"
#include "io_functions.h"
#include "stat_functions.h"

int main()
try {

	vector<Reading> readings;

	read_file(readings);

	cout << "Temperature Stats\n";
	cout << "Mean:\t" << mean(readings) << '\n';
	cout << "Median:\t" << median(readings);

	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception!\n";
	return 2;
}