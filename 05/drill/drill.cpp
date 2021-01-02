/* Chapter 5 drill, test 25 code snippets for errors */
/* Code should run and print: Success! */
#include "../../std_lib_facilities.h"

int main()
try {
	/*Code to be entered and tested below*/
	vector<int> v(5);
	int x = 2;
	v[4] = 5;
	cout << v[4];
	v[0] = 1 / (x - 2);
	cout << v[0];
	/*End Code Test*/
	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Unknown exception!\n";
	keep_window_open();
	return 2;
}