/* 
 Drill from chapter 10.
*/
#include "../../dcg.h"
#include "Point.h"
#include "Functions.h"

int main()
try {
	vector<Point> original_points;
	read_points(original_points);
	print_points(original_points);
	ouput_points_file(original_points);

	vector<Point> procesed_points;
	input_points_file(procesed_points);
	print_points(procesed_points);

	compare_vectors(original_points, procesed_points);

	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception!\n";
	return 2;
}