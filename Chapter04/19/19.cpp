/* Create a program that acts like simple database. It records names and scores.
Conditions are:
One word for name and one score per name
Each name is unique
Terminate input with "NoName 0".
*/ 

#include "../../std_lib_facilities.h"

int main() {
	string name;
	int score;
	vector<string> names;
	vector<int> scores;
	bool entry = true;
	bool unique = true;
	// Read in the scores from user
	cout << "Please enter names and score, terminate using \"NoName 0\": ";
	cin >> name >> score;
	names.push_back(name);
	scores.push_back(score);
	while (entry==true)
	{
		cout << "Please enter names and score, terminate using \"NoName 0\": ";
		cin >> name >> score;
		// Check for uniqueness of name
		for (string i : names) {
			if (i == name) {
				unique = false;
			}
		}
		if (name == "NoName"&&score == 0) { // Test to see if ending condition
			entry = false;
		}
		else if (unique == false) { //Test to see if name is not unique
			cout << "Name is not unique! Please try again!" << endl;
			unique = true;
		}
		else { // All other situations should allow writing to the vector
			names.push_back(name);
			scores.push_back(score);
		}
	}
	// Print names and scores
	for (int i = 0; i < names.size(); ++i) {
		cout << names[i] << ' ' << scores[i] << endl;
	}
	keep_window_open("q");
	return 0;
}