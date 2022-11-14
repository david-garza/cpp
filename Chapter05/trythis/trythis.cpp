// Program to test the try this section in chapter 5

#include "../../std_lib_facilities.h"

int main() 
{
	
	vector<double> temps; // temperatures

	for (double temp; cin >> temp;) // read and put into temps
		temps.push_back(temp);

	double sum = 0;
	double high_temp = 0;
	double low_temp = 0;

	for (double x : temps) {
		if (x > high_temp) high_temp = x; //find high
		if (x < low_temp) low_temp = x; // find low
		sum += x;
	}
	cout << "High temp: " << high_temp << endl;
	cout << "Low temp: " << low_temp << endl;
	cout << "Average: " << sum / temps.size() << endl;

	keep_window_open("q");
	return 0;
}