#pragma once
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

This file holds the declarations for the data and data structures

*/

#include "../../dcg.h"

struct Reading
{
	int hour;
	double temperature;
};

ostream& operator<<(ostream& os, Reading& r);
istream& operator>>(istream& is, Reading& r);

void fill_temps(vector<Reading>& vr);

void print_temps(ostream& os, vector<Reading>& vr);