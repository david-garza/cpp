#pragma once

/*
 Drill from chapter 10.
*/
#include "../../dcg.h"

struct Point
{
	double x;
	double y;
};

ostream& operator<<(ostream& os, const Point& p);
istream& operator>>(istream& is, Point& p);