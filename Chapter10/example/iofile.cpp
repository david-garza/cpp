#include"../../std_lib_facilities.h"

struct Reading {
	int hour;
	double temperature;
};

int main()
try {
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ist{ iname }; //ist reads from the file named iname
	if (!ist) error("can't open input file ", iname);

	string oname;
	cout << "Please enter name of output file: ";
	cin >> oname;
	ofstream ost{ oname }; //ost writes to a file named oname
	if (!ost)error("can't open output file:", oname);

	vector<Reading> temps; //store the readings here
	int hour;
	double temperature;
	while (ist >> hour >> temperature) {
		if (hour < 0 || 23 < hour) error("hour out of range");
		temps.push_back(Reading{ hour,temperature });
	}

	for (int i = 0; i < temps.size(); ++i)
		ost << '(' << temps[i].hour << ',' << temps[i].temperature << ")\n";
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception!\n";
	return 2;
}