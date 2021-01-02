// Program to demo the while loop statement, demos by printing an ascii character map

#include "..\..\std_lib_facilities.h"

int main() {

	//Declare variables
	int i = 0;

	while (i < 255) {

		cout << i << '\t' << char(i) << '\n';
		++i;

	}

	keep_window_open();
	return(0);
}