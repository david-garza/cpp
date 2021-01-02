// Counts the number of grains if they are doubled for each square the chess board. Assuming square 1 has one grain of rice. square 2 has 2, square 3 has 4, etc. 64 bit can compute all the way.

#include "..\..\std_lib_facilities.h"

int main() {
	int irice = 1;
	double drice = 1.0;
	int square = 1;

	for (int i=0; i < 64; i++) {
		cout << "Current square: " << square << endl;
		cout << "Current int rice count: " << irice << endl;
		cout << "Current double rice count: " << drice << endl;
		square++;
		irice *= 2;
		drice *= 2;
	}
	
	keep_window_open();
	return(0);
}