
#include "../../dcg.h"
#include "weather.h"

namespace Weather {

	istream& operator>>(istream& is, Reading& r)
		// read a temperature reading from is into r
		// format: ( 3 4 9.7)
		// check format, but don't bother with data validity
	{
		char ch1;
		if (is >> ch1 && ch1 != '(') // could it be a Reading?
		{
			is.unget();
			is.clear(ios_base::failbit);
			return is;
		}

		char ch2;
		int d;
		int h;
		double t;
		is >> d >> h >> t >> ch2;
		if (!is || ch2 != ')') error("bad reading"); // messed-up reading
		r.day = d;
		r.hour = h;
		r.temperature = t;
		return is;
	}
	//-------------------------------------------------------------------------
	istream& operator>>(istream& is, Month& m)
		// read a month form is into m
		// format: {month feb ... }
	{
		char ch = 0;
		if (is >> ch && ch != '{')
		{
			is.unget();
			is.clear(ios_base::failbit); // we failed to read a Month
			return is;
		}

		string month_marker;
		string mm;
		is >> month_marker >> mm;
		if (!is || month_marker != "month") error("bad start of month");
		m.month = month_to_int(mm);
		int duplicates = 0;
		int invalids = 0;
		for (Reading r; is >> r;)
		{
			if (is_valid(r))
			{
				if (m.day[r.day].hour[r.hour] != not_a_reading)
					++duplicates;
				m.day[r.day].hour[r.hour] = r.temperature;
			}
			else
				++invalids;
		}
		if (invalids) error("invalid readings in  month", invalids);
		if (duplicates) error("duplicate readings in month", duplicates);
		end_of_loop(is, '}', "bad end of month");
		return is;
	}
	//-------------------------------------------------------------------------
	istream& operator>>(istream& is, Year& y)
		// read a year from is into y
		// format: {year 1972 ...}
	{
		char ch;
		is >> ch;
		if (ch != '{')
		{
			is.unget();
			is.clear(ios::failbit);
			return is;
		}

		string year_marker;
		int yy;
		is >> year_marker >> yy;
		if (!is || year_marker != "year") error("bad start of year");
		y.year = yy;

		while (true)
		{
			Month m; //get a clean m each time around
			if (!(is >> m)) break;
			y.month[m.month] = m;
		}
		end_of_loop(is, '}', "bad end of year");
		return is;
	}
	//-------------------------------------------------------------------------
	void end_of_loop(istream& ist, char term, const string& message)
	{
		if (ist.fail()) // use therm as terminator and/or separator
		{
			ist.clear(); 
			char ch;
			if (ist >> ch && ch == term) return; // all is fine
			error(message);
		}
	}
	//-------------------------------------------------------------------------
	bool is_valid(const Reading& r)
		// a rought test of data validity
	{
		if (r.day < 1 || 31 < r.day) return false;
		if (r.hour < 0 || 23 < r.hour) return false;
		if (r.temperature < implausible_min || implausible_max < r.temperature) return false;
		return true;
	}
	//-------------------------------------------------------------------------
	// Month intger table
	vector<string> month_input_tbl = {
		"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"
	};
	//-------------------------------------------------------------------------
	int month_to_int(string s)
		// is s the name of a month? If so return its index [0:11] otherwise -1
	{
		for (int i = 0; i < 12; ++i) if (month_input_tbl[i] == s)return i;
		return -1;
	}
	//-------------------------------------------------------------------------
	string int_to_month(int i)
	{
		if (i == not_a_month) return "-999";
		if (i < 0 || 12 <= i) error("bad month index");
		return month_input_tbl[i];
	}
	void print_year(ostream& os, Year y)
	{
		for (Month m : y.month) // Loops through each month in the year
		{
			for (int i{ 1 }; i < m.day.size(); i++) // Loops through each day of the month
			{
				for (int j{ 0 }; j < 24; j++) //Loops through each hour of the day
				{
					// Comment out the if statement if you want not_a_reading observations to also print
					if (m.day[i].hour[j] == not_a_reading) continue; 
					os << y.year << '\t'
						<< int_to_month(m.month) << '\t'
						<< i << '\t' // Current day
						<< j << '\t' // Current hour
						<< m.day[i].hour[j] << '\n'; //temperature value
				}
			}
		}
	}
}