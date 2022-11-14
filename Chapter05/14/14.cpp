/* 5.14 Attempt to read days of week an value added to a vector
Example input: Tuesday 23 Friday 56 Tuesday -3 Thursday 99 

Output each day of the week with a summed total for each day.

Accept common forms of the day  */
#include "../../std_lib_facilities.h"

// function to read in days of the week and verify if they are listed in the standard dictionary, returns 1=true or 0=false vector.
/*vector<int> dictionary(vector<string> x) {
	vector<string> daynames = { "M","Tu","W","Tr","F","Sa","Su","m","tu","w","tr","f","sa","su","Mon","Tue","Wed","Thu","Fri","Sat","Sun","mon","tue","wed","thu","fri","sat","sun", 
	"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday","monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
	vector<int> flag(x.size());

	// Loop that moves down each element of incoming vector
	for (int i = 0; i < x.size(); i++)
	{
		// Loop that compares the current element to each element in the dictionary
		for (int j = 0; j < daynames.size(); j++)
		{
			// If the current element is in the dictionary, then the flag vector is set to 1
			if (x[i] == daynames[j]) {
				flag[i]=1;
				break;
			}
		}
	}
	return(flag);
}*/

// This function returns the total counts by 
vector<int> counttotals(vector<string> d, vector<int> v) {
	vector<int> count(8);
	vector<string> monday = {"M","m","Mon","mon","Monday","monday"};
	vector<string> tuesday = {"Tu","tu","Tue","tue","Tuesday","tuesday"};
	vector<string> wednesday = {"W","w","Wed","wed","Wednesday","wednesday"};
	vector<string> thursday = {"Tr","tr","Thu","thu","Thursday","thursday"};
	vector<string> friday = {"F","f","Fri","fri","Friday","friday"};
	vector<string> saturday = {"Sa","sa","Sat","sat","Saturday","saturday"};
	vector<string> sunday = {"Su","su","Sun","sun","Sunday","sunday"};
	bool flag = false;

	// Loop to evaluate what is held in d string wise
	for (int i = 0; i < d.size(); i++) {
	
		// Check for monday values in the string and add the value to the count
		for (int j = 0; j < monday.size(); j++) {
			if (d[i] == monday[j]) {
				count[1]=count[1]+v[i];
				flag = true;
				break;
			}
		}
		// Check for tuesday values in the string and add the value to the count
		for (int j = 0; j < tuesday.size(); j++) {
			if (d[i] == tuesday[j]) {
				count[2] = count[2] + v[i];
				flag = true;
				break;
			}
		}
		// Check for wednesday values in the string and add the value to the count
		for (int j = 0; j < wednesday.size(); j++) {
			if (d[i] == wednesday[j]) {
				count[3] = count[3] + v[i];
				flag = true;
				break;
			}
		}
		// Check for thursday values in the string and add the value to the count
		for (int j = 0; j < thursday.size(); j++) {
			if (d[i] == thursday[j]) {
				count[4] = count[4] + v[i];
				flag = true;
				break;
			}
		}
		// Check for friday values in the string and add the value to the count
		for (int j = 0; j < friday.size(); j++) {
			if (d[i] == friday[j]) {
				count[5] = count[5] + v[i];
				flag = true;
				break;
			}
		}
		// Check for Saturday values in the string and add the value to the count
		for (int j = 0; j < saturday.size(); j++) {
			if (d[i] == saturday[j]) {
				count[6] = count[6] + v[i];
				flag = true;
				break;
			}
		}
		// Check for Sunday values in the string and add the value to the count
		for (int j = 0; j < sunday.size(); j++) {
			if (d[i] == sunday[j]) {
				count[7] = count[7] + v[i];
				flag = true;
				break;
			}
		}
		if (flag == false) {
			++count[0];
		}
		flag = false;
	}
	return(count);
}

int main()
try {
	// Read input 
	cout << "Please enter seven days and values format as \"Day Value\": ";
	vector<string> days;
	vector<int> values;
	string temp_days;
	int temp_values;
	vector<int> results;

	// Loop to read in day values pairs, assuming a seven day week
	while (cin >> temp_days >> temp_values) {
		days.push_back(temp_days);
		values.push_back(temp_values);
	}

	results = counttotals(days, values);

	// Outputs the input in 2 column table
	cout << "Mon: " << results[1] << "\nTue: " << results[2] << "\nWed: " << results[3] << "\nThu: " << results[4] << "\nFri: " << results[5] << "\nSat: " << results[6] << "\nSun: " << results[7]
		<<"\n\nErrors: " << results[0] << "\n\n";
	
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