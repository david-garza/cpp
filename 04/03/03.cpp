// Exercise 3 from chapter 4, perform basic statistics on a stream of numbers enetered into a vector
// Compute sum, smallest and largest, mean.

#include "..\..\std_lib_facilities.h"

int main() {
	double distance; //Set up the variable for the input values
	vector<double> distances; // Vector to store the entered values
	double sum=0;

	cout << "Please enter distances along route: ";

	while (cin >> distance) {
		distances.push_back(distance); // Load the values into a vector
	}
	
	// Min and Max
	sort(distances.begin(), distances.end());
	cout << "Min: " << distances[0] << endl;
	cout << "Max: " << distances[distances.size()-1] << endl; // Have to subtract 1, other wise I will cause a memory violation error, elements start at 0 count

	for (int i = 0; i < distances.size(); i++) // Loop to sum the elements of the vector
	{
		sum += distances[i];
	}

	// Compute average
	cout << "Mean: " << sum / distances.size() << endl;
	cout << "Sum: " << sum << endl;

	keep_window_open();
	return(0);
}