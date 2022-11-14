/* 
	11/15/2021 David Carlos Garza

	8.12
	Improve print_until_s() from 5.5.2 Test it. What makes a good set of
	test cases? Give Reasons. Then, write a print_until_ss() that prints until it
	sees a second occurance and its quite argument.

*/
#include "../../std_lib_facilities.h"

void print_until_s(vector<string> v, string quit)
{
	for (string s : v) {
		if (s == quit) return;
		cout << s << endl;
	}
	error("No stop comment found!");
}

void print_until_ss(vector<string> v, string quit)
{
	bool flag{ false };
	for (string s : v) {
		if (s == quit&&flag==true) return;
		if (s == quit) flag = true;
		cout << s << endl;
	}
	error("No stop comment found!");
}
int main()
try {

	string quit{ "q" };
	vector<string> input{ "cat","dog",quit,"fish","turtle",quit};

	print_until_s(input, quit);
	print_until_ss(input, quit);
	keep_window_open("q");
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open("q");
	return 1;
}
catch (...) {
	cerr << "Unknown exception!\n";
	keep_window_open("q");
	return 2;
}