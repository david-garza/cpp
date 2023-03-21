/* 

David Carlos Garza
1/1/2022

1006

Define a Roman_int class for holding Roman numerals (as ints) with a
<< and >>. Provide Roman_int with an as_int() member that returns the
int value, so that if r is a Roman_int, we can write cout << "Roman"
<< r << " equals " << r.as_int() << '\n\;.

Updated 3/20/2023

*/
#include "../../dcg.h"

int main()
try {
	string input;

	cin >> input;

	while (true)
	{
		if (input == "q")
			break;

		
	}
	
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