/* 
David Carlos Garza
 12/28/2021

 Write the function print_year() mentioned in 10.11.2.

*/
#include "../../dcg.h"
#include "weather.h"

int main()
try {

	// open an input file:
	cout << "Please enter input file name\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs) error("can't open input file", iname);

	ifs.exceptions(ifs.exceptions() | ios_base::badbit); // throw for bad()

	//open an output file:
	cout << "Please enter output file name\n";
	string oname;
	cin >> oname;
	ofstream ofs{ oname };
	if (!ofs) error("can't open output file", oname);

	// read an arbitrary number of years:
	vector<Weather::Year> ys;
	while (true)
	{
		Weather::Year y; // get a freshly initialized Year each time around
		if (!(ifs >> y))break;
		ys.push_back(y);
	}

	cout << "read " << ys.size() << " years of readings\n";

	for (Weather::Year y : ys) print_year(ofs, y);
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