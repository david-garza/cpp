#include"../../dcg.h"
#include"Chrono.h"

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

	bool is_date(int y, Month m, int d)
	{
		// assume that y is valid

		if (d <= 0) return false;
		if (m < Month::jan || Month::dec < m) return false;

		int days_in_month{ 31 };

		switch (m)
		{

		case Chrono::Month::feb:
			days_in_month = 28;
			break;
		case Chrono::Month::apr:
		case Chrono::Month::jun:
		case Chrono::Month::sep:
		case Chrono::Month::nov:
			days_in_month = 30;
			break;
		}
		return true;
	}

	std::ostream & operator<<(std::ostream & os, const Date & d)
	{
		return os << '(' << d.year()
			<< ',' << int(d.month())
			<< ',' << d.day() << ')';
	}

} // End Chrono