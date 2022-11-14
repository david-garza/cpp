#pragma once
// Simple Date class from chapte 9 section 8 stripped only to store a simple date.
#include "../../dcg.h"
namespace Chrono {

	enum class Month {
		jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};

	class Date {
	public:
		class Invalid {};

		Date(int y, Month m, int d);	// Check for valid date an initialize
		Date();							// default constructor

		//nonmodifying operations:
		int day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }
	private:
		int y;
		Month m;
		int d;
	};

	bool is_date(int y, Month m, int d); //true for valid date

	std::ostream& operator<<(std::ostream& os, const Date& d);
}