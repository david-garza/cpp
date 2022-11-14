/* 
	12/12/2021

	1001
	Write a program that produces the sume of all the number in a file of
	whitespace-separated integers.

*/
#include "../../dcg.h"

int main()
try {
	cout << "Please provide file name: ";
	string iname;
	cin >> iname;

	ifstream ist{ iname };
	if (!ist) error("Can't open file\n");
	int sum{ 0 };
	int temp{ 0 };
	
	while (true) {
		ist >> temp;
 
		if (!ist) {
			if (ist.eof())
				break;
			else if (ist.fail()) {
					cout << "Unexpected termination of data\n";
					break;
			}
			else if (ist.bad()) error("Bad disk read\n");
				
		}
		sum += temp;
	}

	cout << sum;
	
	
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