#pragma once
// Added other functions for section 9.8

#include "../../dcg.h"
namespace Chrono {

	enum class Month {
		jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};

	class Date {
	public:
		class Invalid {};

		Date(int y, Month m, int d);	// Check for valid date an initialize
		Date();							// default constructor

		// nonmodifying operations:
		int day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }

		// modifying operations:
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);
	private:
		int y;
		Month m;
		int d;
	};

	// Helper functions
	bool is_date(int y, Month m, int d);	//true for valid date
	bool leapyear(int y);					// true if y is a leap year

	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);

	std::ostream& operator<<(std::ostream& os, const Date& d);

	enum class Day {
		sunday, monday, tuesday, wednesday, thursday, friday, saturday
	};

	Day day_of_week(const Date& d);
	Date next_Sunday(const Date& d);
	Date next_weekday(Date d);
	int week_of_year(const Date& d);
	
}