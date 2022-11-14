// Program to demo function calls

#include "..\..\std_lib_facilities.h"

int square(int x) {
	
	// Declare variables
	int sum=0;

	// Determine a square by using addition and not multiplication
	for (int i = 0; i < x; i++)
	{
		sum += x;
	}

	return sum;
}


int main() {
	// Create a table of squares

	for (int i = 0; i < 25; i++)
	{
		cout << i << '\t' << square(i) << '\n';
	}
	
	keep_window_open();
	return(0);
}