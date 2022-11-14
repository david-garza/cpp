/* 
David Carlos Garza

1002
Write a program that creates a file of data in the form of the temperature
Reading type defined in 10.5. For testing, fill the file with at least 50
"temperature readings." Call this program store_temps.cpp and the file it
creates raw_temps.txt.

Data format "h temp" where h is between 0 and 23, temp is in F

0 73.5
1 65.3

*/

#include "../../dcg.h"
#include "data.h"
#include "io_functions.h"


int main()
try {
	vector<Reading> temps;

	fill_temps(temps);

	output_file(temps);
	
	
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