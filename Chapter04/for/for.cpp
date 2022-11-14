// Program to demo the for loop statement, demos by printing an ascii character map

#include "..\..\std_lib_facilities.h"

int main() {

	for (int i = 0; i < 26; i++) // For loop statement to print out the ascii character set
	{
		cout << char('a' + i) << '\t' << int('a' + i) << '\t' << char('A' + i) << '\t' << int('A' + i)<<'\n';
	}
	keep_window_open();
	return(0);
}