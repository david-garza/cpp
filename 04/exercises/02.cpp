// Exercise 2, modify the temperature code to compute a median when there is an even number of items.

#include "..\..\std_lib_facilities.h"

int main() {
	vector<double>temps; // temperatures
	double temp;
	
	while (cin >> temp)
		temps.push_back(temp); // Load the read values into the vector

	// Compute the mean temperature
	double sum = 0;
	for (int i = 0; i < temps.size(); i++)
		sum += temps[i];
	cout << "Average tempeature: " << sum / temps.size() << endl;

	// Compute the median temperature
	sort(temps.begin(), temps.end());

	if(temps.size() % 2==1) // Test for odd
		cout << "Median tempeature: " << temps[temps.size() / 2] << endl;

	if (temps.size() % 2 == 0) { // Test for even
		cout << "Median tempeature: " << (temps[temps.size() / 2] + temps[(temps.size() / 2)-1])/2.0 << endl;
	}
		
	keep_window_open();
	return(0);
}