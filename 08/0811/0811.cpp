/* 
	11/13/2021 David Carlos Garza

	8.11
	Write a function that finds the smallest and the laregest element of vector
	argument and also computes the mean and the median. Do not use global
	variables. Either return a struct containing the results or pass them back
	through referene arguments. Which two ways of returning several 
	result values do you prefer and why?
	

*/
#include "../../std_lib_facilities.h"

// Structure to hold stats
struct Stat_data
{
	double max;
	double min;
	double mean;
	double median;
	Stat_data();
	Stat_data(double a, double b, double c, double d);
};
//--------------------------------------
Stat_data::Stat_data()
	:max{}, min{}, mean{}, median{} {}
Stat_data::Stat_data(double a, double b, double c, double d)
	:max{ a }, min{ b }, mean{ c }, median{d} {}


// Find the largest element of a vector
double maxv(vector<double>& x) {
	double max = x[0];

	for (double i : x)
		if (i > max)
			max = i;

	return max;
}
//--------------------------------------

// Find the smallest element of a vector
double minv(vector<double>& x) {
	double min = x[0];

	for (double i : x)
		if (i < min)
			min = i;

	return min;
}
//--------------------------------------

// Find mean of a vector
double mean(vector<double>& x) {
	double sum{ 0 };
	for (double i : x)
		sum += i;

	return sum / x.size();
}
//--------------------------------------

// Find the median of a vector
double median(vector<double> x) {
	sort(x.begin(), x.end());

	if (x.size() % 2 == 1) // Test for odd
		return x[x.size() / 2];

	else if (x.size() % 2 == 0)  // Test for even
		return (x[x.size() / 2] + x[(x.size() / 2) - 1]) / 2.0;

}
//--------------------------------------

// Find all 4 statistics of a vector of a vector
Stat_data summary(vector<double>& x) {
	Stat_data temp(maxv(x), minv(x), mean(x), median(x));
	/*
	temp.max = maxv(x);
	temp.min = minv(x);
	temp.mean = mean(x);
	temp.median = median(x);
	*/
	
	return temp;
}
//--------------------------------------

// Function to print results to screen

void print(double min, double max, double mean, double median) {
	cout << "Min:\t" << min << endl;
	cout << "Max:\t" << max << endl;
	cout << "Mean:\t" << mean << endl;
	cout << "Median:\t" << median << endl;
}
//--------------------------------------

// Function to compute all 4 statistics of a vector using pass by reference
void summaryr(vector<double>& x, double& min, double& max, double& avg, double& med) {
	max = maxv(x);
	min = minv(x);
	avg = mean(x);
	med = median(x);
}
//--------------------------------------
int main()
try {

	vector<double> weight{ 1,2,3,100 };
	
	// Compute stats using a structure oboject to return all 4 statistics
	Stat_data stats;

	stats = summary(weight);
	print(stats.min, stats.max, stats.mean, stats.median);

	// Return using passe by reference variables
	double minr;
	double maxr;
	double meanr;
	double medianr;

	summaryr(weight, minr, maxr, meanr, medianr);
	print(minr, maxr, meanr, medianr);



	keep_window_open("q");
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open("q");
	return 1;
}
catch (...) {
	cerr << "Unknown exception!\n";
	keep_window_open("q");
	return 2;
}