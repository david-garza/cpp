#include"../../dcg.h"
#include"Chrono_2.h"

namespace Chrono {

	Date::Date(int yy, Month mm, int dd)
		:y{ yy }, m{ mm }, d{ dd }
	{
		if (!is_date(yy, mm, dd)) throw Invalid{};
	}

	const Date& default_date()
	{
		static Date dd{ 2001,Month::jan,1 };
		return dd;
	}

	Date::Date()
		:y{default_date().year()},
		m{ default_date().month() },
		d{ default_date().day() }
	{
	}

	void Date::add_day(int n)
	{
		for(int i{0};i<n;i++)
			switch (m)
			{
				// Check for end of month and reset to 1st day of next month
				case Month::jan:
					if (d == 31)
					{
						m = Month::feb;
						d = 1;
					}
					else
						d += 1;
					break;
				case Month::feb:
					if (d == 28 && leapyear(y))
						d += 1;
					else if (d == 28 && !leapyear(y) || d == 29)
					{
						m = Month::mar;
						d = 1;
					}
					else
						d += 1;
					break;
				case Month::mar:
					if (d == 31)
					{
						m = Month::apr;
						d = 1;
					}
					else
						d += 1;
					break;
				case Month::apr:
					if (d == 30)
					{
						m = Month::may;
						d = 1;
					}
					else
						d += 1;
					break;
				case Month::may:
					if (d == 31)
					{
						m = Month::jun;
						d = 1;
					}
					else
						d += 1;
					break;
				case Month::jun:
					if (d == 30)
					{
						m = Month::jul;
						d = 1;
					}
					else
						d += 1;
					break;
				case Month::jul:
					if (d == 31)
					{
						m = Month::aug;
						d = 1;
					}
					else
						d += 1;
					break;
				case Month::aug:
					if (d == 31)
					{
						m = Month::sep;
						d = 1;
					}
					else
						d += 1;
					break;
				case Month::sep:
					if (d == 30)
					{
						m = Month::oct;
						d = 1;
					}
					else
						d += 1;
					break;
				case Month::oct:
					if (d == 31)
					{
						m = Month::nov;
						d = 1;
					}
					else
						d += 1;
					break;
				case Month::nov:
					if (d == 30)
					{
						m = Month::dec;
						d = 1;
					}
					else
						d += 1;
					break;
				case Month::dec:
					if (d == 31)
					{
						y += 1;
						m = Month::jan;
						d = 1;
					}
					else
						d += 1;
					break;
			}
	}

	bool is_date(int y, Month m, int d)
	{
		// assume that y is valid

		if (d <= 0) return false;
		if (m < Month::jan || Month::dec < m) return false;

		int days_in_month{ 31 };

		switch (m)
		{

		case Month::feb:
			days_in_month = (leapyear(y))?29:28;
			break;
		case Month::apr:
		case Month::jun:
		case Month::sep:
		case Month::nov:
			days_in_month = 30;
			break;
		}
		if (days_in_month < d) return false;

		return true;
	}

	bool leapyear(int y)
	{
		// an integer multiple of 4 (except for years evenly divisible by 100,
		// but not by 400)

		int div_4 = y % 4;
		int div_100 = y % 100;
		int div_400 = y % 400;

		if (div_4 == 0 && div_400 == 0)
			return true;
		if (div_4 == 0 && div_100 == 0)
			return false;
		if (div_4 == 0)
			return true;
		// All other years are not leap year
		return false;
	}

	bool operator==(const Date & a, const Date & b)
	{
		return a.year()==b.year()
			&& a.month()==b.month()
			&& a.day()==b.day();
	}

	bool operator!=(const Date & a, const Date & b)
	{
		return !(a==b);
	}

	std::ostream & operator<<(std::ostream & os, const Date & d)
	{
		return os << '(' << d.year()
			<< ',' << int(d.month())
			<< ',' << d.day() << ')';
	}

	Day day_of_week(const Date & d)
	{
		Date ref;
		Day day{ Day::monday };

		while (true)
		{
			if(ref==d)
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

	// Use ISO definition of week of the year, starts first Sunday of the year
	int week_of_year(const Date & d)
	{
		int week{ 0 };
		Date ref(d.year(), Month::jan, 1);

		switch (day_of_week(ref))
		{
		case Day::monday:
		case Day::tuesday:
		case Day::wednesday:
			week = 1;
			break;
		default:
			break;
		}

		while (true) {
			
			if (day_of_week(ref) == Day::monday)
				++week;
			if (ref == d)
				if (week == 0)
					return week_of_year({ d.year() - 1, Month::dec,31 });
				else
					return week;
			else
				ref.add_day(1);
		}
		
	}

	
} // End Chrono