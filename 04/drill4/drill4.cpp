// Drill 4

#include "..\..\std_lib_facilities.h"

double convert(double x, string unit) {
	if (unit == "ft") {
		x *= 30.48;
	}
	else if (unit == "in") {
		x *= 2.54;
	}
	else if (unit == "m") {
		x *= 100;
	}

	return x;
}

int main() {

	// Define the variables
	double number;
	double smallest;
	double largest;
	double sum;
	int count;
	string unit;
	bool setup = false;
	vector<double> numbers;

	
	while (setup == false) { // I have to keep looping until the smallest and largest are set, otherwise they will cause runtime error later
		// Start the first iteration to set all the values
		cout << "Please enter a length with units: ";
		cin >> number >> unit;

		 // Divert program flow if the units are valid
		if (unit == "ft" || unit == "in" || unit == "m" || unit == "cm") {
			number = convert(number, unit); // Call the convert function
			smallest = number; // Set the smallest and largest numbers
			largest = number;
			sum = number;
			count = 1;
			cout << "The value is: " << number << " cm" << '\n'; //Output the value if units are valid
			setup = true; // This exits the loop confirming that the units are correct.
			numbers.push_back(number); // Load the number up into the vector
		}
		else
			cout << "Units not valid!\n";
	}
	
	// Loop to keep asking for values
	cout << "Please enter a length with units: ";
	while (cin>>number>>unit) {

		// Divert program flow again based on correct units
		if (unit == "ft" || unit == "in" || unit == "m" || unit == "cm") {
			number = convert(number, unit); // Call the convert function
			cout << "The value is: " << number << " cm" << '\n';

			// Determine if number is either the smallest or largest
			if (number < smallest) {
				smallest = number;
				cout << "The smallest length so far: " << smallest << "cm\n";
			}
			if (number > largest) {
				largest = number;
				cout << "The largest length so far: " << largest << "cm\n";
			}
			sum += number; //Add to the sum
			count++; // Increase the count
			numbers.push_back(number); // Load the number into the vector
		}
		else
			cout << "Units not valid!\n";
		
		cout << "Please enter a length with units: ";
	}

	cout << "N: " << count << "\nMin: " << smallest << " cm\nMax: " << largest << " cm\nSum:" << sum<<" cm"<<endl;

	cout << "Values entered: " << endl;
	sort(numbers.begin(), numbers.end());
	for (int i = 0; i < numbers.size(); i++) //Loop to print out elements of the vector
	{
		cout << numbers[i] << " cm" << endl; // Print out the values
	}
	keep_window_open();
	return(0);
}