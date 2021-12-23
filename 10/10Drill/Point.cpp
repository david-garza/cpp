/*
 Drill from chapter 10.
*/
#include "../../dcg.h"
#include"Point.h"

ostream& operator<<(ostream& os, const Point& p) {
	return os << p.x << ',' << p.y;
}

istream& operator>>(istream& is, Point& p)
{
	double x{0};
	double y{0};
	char c;
	is >> x >> c >> y;
	if (!is) return is;
	if (c != ',') {
		is.clear(ios_base::failbit);
		return is;
	}

	p = Point{ x,y };

	return is;
}
