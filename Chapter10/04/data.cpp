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

This file holds the defintions for the data and data structures

*/
#include "../../dcg.h"
#include "data.h"

void fill_temps(vector<Reading>& vr)
{
	int hour{ 0 };
	double temp{ 0 };
	char unit{ 'f' };
	for (int i = 0; i < 50; i++)
	{
		temp = 10 * sin(i) + 60;
		vr.push_back({ hour,temp,unit });

		if (hour == 23)
			hour = 0;
		else
			hour++;
	}
}

void print_temps(ostream& os, vector<Reading>& vr)
{
	for (Reading r : vr)
		os << r << '\n';
}

ostream& operator<<(ostream& os, Reading& r)
{
	return os << r.hour << ' ' << r.temperature << ' ' << r.unit;
}

istream& operator>>(istream& is, Reading& r)
{
	return is >> r.hour >> r.temperature >> r.unit;
}
