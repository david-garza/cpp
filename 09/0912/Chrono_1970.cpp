#include"../../dcg.h"
#include"Chrono_1970.h"

// Date class represents date as a unix date, i.e. number of days since 1970

namespace Chrono {
	// Constructors
	Date::Date(long int uu)
		:u{ uu }
	{
		if (!is_date(uu)) throw Invalid{};
	}

	Date::Date()
		:u{0}
	{
	}

	// Member functions
	void Date::add_day(long int n)
	{
		u += n;
	}

	// Helper functions
	bool is_date(long int n)
	{
		if(n<0) return false;
		else return true;
	}

	// operators
	bool operator==(const Date & a, const Date & b)
	{
		return a.day_number()==b.day_number();
	}

	bool operator!=(const Date & a, const Date & b)
	{
		return !(a==b);
	}

	ostream & operator<<(ostream & os, const Date & d)
	{
		return os << d.day_number();
	}

	// Calendar helper functions
	Day day_of_week(const Date& d) {
		Date ref;
		Day day{ Day::thursday };

		while (true)
		{
			if (ref == d)
				return day;
			else
			{
				ref.add_day(1);

				switch (day)
				{
				case Day::sunday:
					day = Day::monday;
					break;
				case Day::monday:
					day = Day::tuesday;
					break;
				case Day::tuesday:
					day = Day::wednesday;
					break;
				case Day::wednesday:
					day = Day::thursday;
					break;
				case Day::thursday:
					day = Day::friday;
					break;
				case Day::friday:
					day = Day::saturday;
					break;
				case Day::saturday:
					day = Day::sunday;
					break;
				}
			}
		}
	}

	Date next_sunday(Date d)
	{
		// Checks to see if tomorrow is a Sunday
		d.add_day(1);
		if (day_of_week(d) == Day::sunday) return d;
		
		// Loop to increase the day until a Sunday occurs
		while (true) {
			if (day_of_week(d) == Day::sunday) return d;
			else
				d.add_day(1);
		}
		
	}

	Date next_weekday(Date d) {
		if (day_of_week(d) == Day::saturday)
		{
			d.add_day(2);
			return d;
		}
		else if (day_of_week(d) == Day::friday)
		{
			d.add_day(3);
			return d;
		}
		else
		{
			d.add_day(1);
			return d;
		};
	}
} // End Chrono