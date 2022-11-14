// Create a program that can determine the mode of a set of numbers.

#include "../../std_lib_facilities.h"

int main() {
	vector<int> data;
	// Prompt the user to enter a list of positive integers and load them to a vector
	cout << "Please enter a list of integers and then press enter: ";

	for (int i; cin >> i;) // Very compact way to write the input loop.
		data.push_back(i);
	sort(data); //Places the data in numerical order

	// Perform the count
	vector<int> unique;
	vector<int> count;
	int j = 0;
	for (int i = 0; i < data.size(); ++i) {

		if (i == 0) { // Intilize the unique and counting vectors
			unique.push_back(data[i]);
			count.push_back(1);
		}
		else if (data[i] == unique[j]) { //Increment the count
			++count[j];
		}
		else if (data[i] != unique[j]) { // Reset the for the next unique value
			unique.push_back(data[i]);
			count.push_back(1);
			++j;
		}
	}
	
	// Determine the value that is the largest in count
	int max;
	for (int i = 0; i < count.size(); ++i) {
		if (i == 0) {
			max = count[i];
		}
		if (count[i] > max) {
			max = count[i];
		}
	}

	// Test to determine if there is a mode or several modes
	if (max == 1) {
		cout << "No mode in the data" << endl;
	}
	else
	{
		vector<int>index;
		for (int i = 0; i < count.size(); ++i) { // Loop through and collect the index of each element of count that is equal to the max value
			if (count[i] == max) {
				index.push_back(i);
			}
		}
		for (int i = 0; i < index.size(); ++i) { // Use the index to report the value of each unique value that had the max count
			cout << "Mode(s): " << unique[index[i]] << " with " << max << " occurances" << endl;
		}
	}
	keep_window_open("q");
	return 0;
}