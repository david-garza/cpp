/* Create a program that allows a user to search an exiting database by score
Conditions are:
If the score is found, then display the name and the score.
If no score is not found, show the error message score not found
*/ 

#include "../../std_lib_facilities.h"

int main() {
	int score;
	vector<string> names = {"David","Alex","Carmen","Carlos","Gizmo","Mia"};
	vector<int> scores = {35,50,50,45,65,86};
	bool entry = true;
	bool found = false;
	vector<int> index;
	// Start data entry loop
	while (entry==true)
	{
		cout << "Please enter a score to search: ";
		cin >> score;
		// Test the entered name
		if (score == -1) { // Test to see if ending condition
			entry = false;
		}
		else {
			for (int i = 0; i < scores.size();++i) { // Search the list of scoress to against provide score, print name and score if found
				if (scores[i] == score) {
					index.push_back(i);
					found = true;
				}
			}
			if (found == true) {
				for (int i : index) {
					cout << names[i] << ' ' << scores[i] << endl;
				}
				found = false;
				index.resize(0);
			}
			else if (found == false) {
				cout << "Score not found!" << endl;
			}
		}
		
	}
	keep_window_open("q");
	return 0;
}