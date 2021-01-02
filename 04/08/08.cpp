// Counts the number of grains if they are doubled for each square the chess board. Assuming square 1 has one grain of rice. square 2 has 2, square 3 has 4, etc.

#include "..\..\std_lib_facilities.h"

int main() {
	int rice = 1;
	int square = 1;
	int limit = 1;

	cout << "Please enter the max value of rice to compute to: ";
	cin >> limit;
	while (rice <= limit) {
		cout << "Current square: " << square << endl;
		cout << "Current rice count: " << rice << endl;
		square++;
		rice *= 2;
	}
	
	cout << "Final square: " << square << endl;
	cout << "Final rice count: " << rice << endl;

	keep_window_open();
	return(0);
}