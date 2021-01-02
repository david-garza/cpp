// Program to demo vectors by comparing a vector of words against a banned list of words

#include "..\..\std_lib_facilities.h"


int main() {
	vector<string> words;
	vector<string> censor(3); // word to be censored
	string word; // Temporary word to be entered at the prompt
	censor[0] = "apple";
	censor[1] = "pear";
	censor[2] = "pineapple";

	//Prompt user to enter in a list of words and read them to a vector
	cout << "Please enter a list of words spererated by spaces: ";

	// Loop through the input
	while (cin >> word)
		words.push_back(word);

	// Sort the vector list
	sort(words.begin(), words.end());

	// Print the vector word list
	for (int i = 0; i < words.size(); i++)
	{
		// Test for the banned word 

		if (words[i] == censor[0]|| words[i] == censor[1]|| words[i] == censor[2]) // Try three OR operators in a row
		{
			cout << "CENSORED!\n";
		}
		else
		{
			cout << words[i] << '\n';
		}
	}

	keep_window_open();
	return(0);
}