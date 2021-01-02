// this checks for repeat words entered in the command line; use ^c to kill the process
// This has been modified to count the number of words before the repeat.

#include "../std_lib_facilities.h"

int main() {
	
	int counter = 0; // The word counter index
	string previous = " "; //Previous word; initialized to "not a word"
	string current; // current word entered in at the command prompt

	while (cin >> current) {

		++counter; // Increment the counter index
		if (previous == current) // Test to see if the words are equal. The test is case sensitive. She != she.
			cout <<"word number " << counter << " repeated word: " << current << '\n';
		previous = current;

	}
	return(0);
}