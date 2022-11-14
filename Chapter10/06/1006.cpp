/* 

David Carlos Garza
1/1/2022

1006

Define a Roman_int class for holding Roman numerals (as ints) with a
<< and >>. Provide Roman_int with an as_int() member that returns the
int value, so that if r is a Roman_int, we can write cout << "Roman"
<< r << " equals " << r.as_int() << '\n\;.

*/
#include "../../dcg.h"
#include "Roman.h"

int main()
try {
	string test1{"M"};
	string test2{"MM"};
	string test3{"C"};
	cout << test1 << ' ' << Roman::rn_to_int(test1) << '\n';
	cout << test2 << ' ' << Roman::rn_to_int(test2) << '\n';
	cout << test3 << ' ' << Roman::rn_to_int(test3) << '\n';
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception!\n";
	return 2;
}