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
#include "roman.h"

int main()
try {
	char ch{ };

	while (ch!='q')
	{
		cout << "Please input a value: ";
		
		cin >> ch;

		switch (ch)
		{
		case 'q':
			break;
		case 'I': case 'V':
			cin.putback(ch);
			cout << "Value: " << Rome::ones_sum() << endl;
			break;
		case 'X': case 'L':
			cin.putback(ch);
			cout << "Value: " << Rome::tens_sum() << endl;
			break;
		default:
			cout << "Unknown Value" << endl;
			break;
		}	
		
	}
	
	cout << "Program exited";

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