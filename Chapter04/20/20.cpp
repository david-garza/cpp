/* Create a program that allows a user to search an exiting database by unique name
Conditions are:
If the name is found, then display the name and the score.
If no name is not found, show the error message name not found
*/ 

#include "../../std_lib_facilities.h"

int main() {
	string name;
	vector<string> names = {"David","Alex","Carmen","Carlos","Gizmo","Mia"};
	vector<int> scores = {35,50,50,45,65,86};
	bool entry = true;
	
	int index;
	// Start data entry loop
	while (entry==true)
	{
		cout << "Please enter a name to search: ";
		cin >> name;
		// Test the entered name
		if (name == "NoName") { // Test to see if ending condition
			entry = false;
		}
		else {
			bool found = false;
			for (int i = 0; i < names.size();++i) { // Search the list of names to against provide name, print name and score if found
				if (names[i] == name) {
					index = i;
					found = true;
					break;
				}
			}
			if (found == true) {
				cout << names[index] << ' ' << scores[index] << endl;
				found = false;
			}
			else if (found == false) {
				cout << "Name not found!" << endl;
			}
		}
		
	}
	keep_window_open("q");
	return 0;
}