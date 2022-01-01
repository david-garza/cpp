#pragma once

#include "../../dcg.h"

namespace Weather 
{

	constexpr int not_a_reading = -999;
	constexpr int not_a_month = -999;

	struct Day {
		vector<double> hour{ vector<double>(24,not_a_reading) };
	};

	struct Month {
		int month{ not_a_month };
		vector<Day> day{ 32 };
	};

	struct Year {
		int year;
		vector<Month> month{ 12 };
	};

	struct Reading {
		int day;
		int hour;
		double temperature;
	};

	// Input operators for each structure
	istream& operator>>(istream& is, Reading& r);
	istream& operator>>(istream& is, Month& m);
	istream& operator>>(istream& is, Year& y);

	// Helper functions
	void end_of_loop(istream& ist, char term, const string& message);

	constexpr int implausible_min = -200;
	constexpr int implausible_max = 200;

	bool is_valid(const Reading& r);

	int month_to_int(string s);
	string int_to_month(int i);

	void print_year(ostream& os, Year y);

} // End weather