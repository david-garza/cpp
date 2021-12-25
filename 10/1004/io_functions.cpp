/*
David Carlos Garza

1002
Write a program that creates a file of data in the form of the temperature
Reading type defined in 10.5. For testing, fill the file with at least 50
"temperature readings." Call this program store_temps.cpp and the file it
creates raw_temps.txt.

Data format "h temp" where h is between 0 and 23, temp is in F

0 73.5
1 65.3

*/

#include "../../dcg.h"
#include "data.h"
#include "io_functions.h"

void output_file(vector<Reading>& temps)
{
	cout << "Output file name: ";
	string ofname;
	cin >> ofname;

	ofstream ost{ ofname };

	if (!ost) error("can't open file");

	print_temps(ost, temps);
}

void read_file(vector<Reading>& vr)
{
	cout << "Input file name: ";
	string ifname;
	cin >> ifname;

	ifstream ist{ ifname };

	if (!ist) error("can't open file");

	// Read data and write to rdgs reading vector
	Reading tmp;
	while (true) {
		ist >> tmp;

		if (!ist) {
			if (ist.bad()) error("disk read error");
			
			if (ist.fail()) {
				if (ist.eof()) break;
			}
			else error("Unexpected format");
				
		}
		else {
			if (tmp.unit == 'f') {
				tmp.temperature = ftoc(tmp.temperature);
				tmp.unit = 'c';
				vr.push_back(tmp);
			}
			else
				vr.push_back(tmp);	
		}			
	}
}

double ftoc(double f)
{
	return (f-32)*5/9;
}


