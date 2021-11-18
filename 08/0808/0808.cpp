/* 
	11/11/2021 David Carlos Garza

	8.7
	Read five names into a vector<string> name, then prompt the user for
	the ages of the people named and store the ages in a vector<double> age.
	Then print out the five (name[i],age[i]) pairs. Sort the names (sort(name
	.begin(),name.end())) and print out the (name[i],age[i]) pairs. The tricky
	part here is to get the age vector in the correct order to match the sorted
	name vector. Hint: Before sorting name, take a copy and use that to 
	make a copy of age in the right order after sorting name.

	8.8
	Then, do that exercise again but allowing an arbitrary number of names.

*/
#include "../../std_lib_facilities.h"

// Function to print out elements of name and age vector 

void print(vector<string>& n, vector<double>& a) {
	// Check that both vectors are the same length
	if (n.size() != a.size())
		error("Name and age list not same length");

	// Print elements with header
	cout << "Name\tAge" << endl;
	
	for (int i = 0; i < a.size(); i++)
	{
		cout << n[i] << "\t" << a[i]<< endl;
	}
}
//---------------------------------------------------------

// Function that takes name vector by reference and fills it with data from the user
void input_name(vector<string>& n) {
	// Loop through the input line reading data until a q is seen
	string temp;

	while(true){
		cin >> temp;
		if (temp == "q")
			break;

		n.push_back(temp);
	}
}
//---------------------------------------------------------

// Function that takes age vector by reference and fills it with data from the user
void input_age(vector<double>& a) {
	// Loop through the input line reading data until a 0 is seen
	double temp;

	while (true) {
		cin >> temp;
		if (temp == 0)
			break;

		a.push_back(temp);
	}
}
//---------------------------------------------------------

// Function to sort both vectors in the right order

void table_sort(vector<string>& x, vector<double>& y) {
	// Temporary vectors to hold for storting
	vector<string> temp_x;
	vector<double> temp_y;

	temp_x = x;
	temp_y = y;

	// Sort the name vector alphabetically
	sort(x.begin(), x.end());

	// Loop down the original name vector and find the matching name in the sorted vector, copy age into the corrosponding index for age.
	for (int i=0; i < temp_x.size(); i++) {
		for (int j=0; j < x.size(); j++) {
			if (temp_x[i] == x[j])
				y[j] = temp_y[i];
		}
	}
}

//---------------------------------------------------------

int main()
try {
	// Create vectors to hold names and ages
	vector<string> name;
	vector<double> age;

	// Prompt user for input
	cout << "Enter names with spaces, enter q to quit:";
	input_name(name);
	cout << "Enter the ages, enter 0 to quit:";
	input_age(age);

	// Print names and ages in current order
	print(name, age);

	// Sort both name and age and print out new order
	table_sort(name, age);
	print(name, age);

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