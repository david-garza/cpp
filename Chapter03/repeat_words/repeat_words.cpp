// this checks for repeat words entered in the command line

#include "../std_lib_facilities.h"

int main() {
	
	string previous = " "; //Previous word; initialized to "not a word"
	string current; // current word entered in at the command prompt

	while (cin >> current) {

		if (previous == current) // Test to see if the words are equal.
			cout << "repeated word: " << current << '\n';
		previous = current;

	}
	return(0);
}