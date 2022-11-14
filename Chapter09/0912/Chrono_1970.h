#pragma once
// Date class represents date as a unix date, i.e. number of days since 1970

#include "../../dcg.h"
namespace Chrono {

	class Date {
	public:
		class Invalid {};	// Throws errors

		Date(long int uu);	// Constructor to initalize an intger value date
		Date();				// Default constructor initalize u = 0;

		// Non-modifying functions
		long int day_number() const { return u; }

		// Modifying functions
		void add_day(long int n);

	private:
		long int u;			// Long integer to hold dates since Jan 1, 1970
	};

	// Functions from 9.8
	bool is_date(long int n);
	
	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);

	ostream& operator<<(ostream& os, const Date& d);

	enum class Day {
		sunday, monday, tuesday, wednesday, thursday, friday, saturday
	};
	
	Day day_of_week(const Date& d);
	Date next_sunday(Date d);
	Date next_weekday(Date d);
} // End Chrono