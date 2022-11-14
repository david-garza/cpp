#include "../../dcg.h"
#include "data.h"

double mean(vector<Reading>& r)
{
	// Read the temp portion of reading data strucure
	vector<double> x;
	for (Reading rding : r)
		x.push_back(rding.temperature);

	// compute mean
	double sum{ 0 };
	for (double d : x)
		sum += d;

	return sum / x.size();
}

double median(vector<Reading>& r)
{
	// Read the temp portion of reading data strucure
	vector<double> x;
	for (Reading rding : r)
		x.push_back(rding.temperature);

	// Compute the median temperature
	sort(x.begin(), x.end());

	if (x.size() % 2 == 1) // Test for odd
		return x[x.size() / 2];

	if (x.size() % 2 == 0)  // Test for even
		return (x[x.size() / 2] + x[(x.size() / 2) - 1]) / 2.0 ;	
}

void print_sats(vector<Reading>& r) 
{
	cout << "Temperature Statittcs\n";
	cout << "Mean:\t" << mean(r) << '\n';
	cout << "Median:\t" << median(r) << '\n';
}