// Main program source to run swap functions

/*
	Swapping conditions tested // replace ? by v, r, or cr

	int x = 7;
	int y = 9;
	swap_?(x,y); // Only swap_r swapped x and y
	swap_?(7,9); // No successful swap
	const int cx = 7;
	const int cy = 9;
	swap_?(cx,cy); // No successful swap
	swap_?(7.7,9.9); // No successful swap
	double dx = 7.7;
	double dy = 9.9;
	swap_?(dx,dy); // No successful swap
	swap_?(7.7,9.9);
*/

#include "declarations.h"
#include <iostream>

int main() {
	int x = 7;
	int y = 9;
	
	std::cout << "x " << x << " y " << y << std::endl;

	// Swap function to test
	swap_r(x, y);

	std::cout << "x " << x << " y " << y << std::endl;

	char cc;
	std::cin >> cc;

	return 0;
}