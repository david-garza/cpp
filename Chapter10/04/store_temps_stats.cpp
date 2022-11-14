/* 

David Carlos Garza

12/24/2021

10.04
Modify the store_temps.cpp program for exercise 2 to include a tem-
perature suffix c for Celsius or f for Fahrenheit temperatures. Then mod-
ify the temp_stats.cpp program to test each temperature, converting the
Celsius reading to Fahrenheit before putting them into the vector.

*/
#include "../../dcg.h"
#include "data.h"
#include "io_functions.h"
#include "stat_functions.h"
#include "control_flow.h"

int main()
try {
	// For storing temperature readings
	vector<Reading> readings;
	
	// Ask user if they want to read, write, or exit program
	user_prompt(readings);
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