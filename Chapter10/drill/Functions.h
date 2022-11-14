#pragma once
/*
 Drill from chapter 10.
*/

#include "../../dcg.h"
#include "Point.h"

// // Read user defined points
void read_points(vector<Point>& pp);
void print_points(const vector<Point>& pp);
void ouput_points_file(const vector<Point>& pp);
void input_points_file(vector<Point>& pp);
void compare_vectors(const vector<Point>& a, const vector<Point>& b);