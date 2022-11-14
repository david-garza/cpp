#include "Functions.h"

// Read user defined points
void read_points(vector<Point>& pp)
{
	Point temp_point{ 0,0 };
	for (int i{ 0 }; i < 7; i++) {
		cout << "Enter point x,y: ";
		cin >> temp_point;
		if (cin.fail()) {
			cin.clear(); // Resets the cin to allow reading of new data
			continue;
		}
		pp.push_back(temp_point);
	}
}

// Prints points to screen
void print_points(const vector<Point>& pp)
{
	for (Point p : pp)
		cout << p << '\n';
}

// Ouput to a file
void ouput_points_file(const vector<Point>& pp)
{
	cout << "Please enter a file name : ";
	string oname;
	cin >> oname;
	ofstream ost{ oname };
	if (!ost) error("can't open file ", oname);
	for (Point p : pp)
		ost << p << '\n';
}
// Read points from a file
void input_points_file(vector<Point>& pp)
{
	cout << "Please enter a file name : ";
	string iname;
	cin >> iname;
	ifstream ist{ iname };
	if (!ist) error("can't open file ", iname);
	
	for (Point p; ist >> p;)
		pp.push_back(p);
}

void compare_vectors(const vector<Point>& a, const vector<Point>& b)
{
	// Check size
	if (a.size() != b.size()) {
		cout << "Lengths are different!";
		return;
	}
	for (int i{ 0 }; i < a.size(); i++)
		if (a[i].x != b[i].x || a[i].y != b[i].y) {
			cout << "Elements are different!";
			return;
		}

	cout << "Data match";
}
