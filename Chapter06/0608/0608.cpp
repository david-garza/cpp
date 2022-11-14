/*
	Date: 02/25/2021
	Author: David Carlos Garza
	Purpose: This exercise modifies the game "Bulls and Cows" to use letters instead of numbers.

	Rules of Game
		Goal: The player tries to guess the correct order of 4 non-repeating letters

		Guess: The player submits 4 non repeating letters.

		Response: The output is number of bulls, number of cows, or win.
			Bull: Number of characters  guessed correctly and in the correct order
			Cow:  Number of correct characters but not in the correct order.
			Win: 4 Bulls

		Flow of game: The game keep looping until the user gets all 4 cows or enters qqqq.

*/
//----------------------------------------------------------------------------------------------------------------------------------------
#include "../../std_lib_facilities.h"
/*
	Introduction text, title and rules.
*/
void intro() 
{
	cout << "Bull and Cows!\n\n";
	cout << "Goal: Guess the sequence of 4 non-repeating letters\n\n";
	cout << "Scoring:\nBull = a letter guessed correctly in the right order\nCow = a letter correctly but not in the right order\n\n";
	cout << "Winning: A score of 4 bulls means you have correctly quessed the letters and their sequence!\n\n";
	cout << "Please enter your first quess below or 'qqqq' to exit.\n";
}
//----------------------------------------------------------------------------------------------------------------------------------------
/*
	Create a class that holds the scores together
*/
class Tally 
{
public:
	int bull; // The number of bulls scored in the guess
	int cow; // The number of cows scored in the guess
	Tally(int b, int c)
		:bull(b), cow(c) {} 
};
//----------------------------------------------------------------------------------------------------------------------------------------

/*
	Define a function to determine if their are duplicates in the quess, copied from problem 0512.
		True: Repeat was detected
		False: Elements are unique 
*/
bool duplicate(vector<char> x)
{
	sort(x); //Sorts the elements in order so they can be compared

	if (x[0] == x[1] || x[1] == x[2] || x[2] == x[3]) {
		return true;
	}
	else {
		return false;
	}
}
//----------------------------------------------------------------------------------------------------------------------------------------
/*
	Define a function that computes number of bulls and cows of the guess. Copied from 0512. Modified to use the user defined class.
		x is the user guess, y is the answer
*/
Tally bovine(vector<char> x, vector<char> y) 
{ 
	Tally score(0,0);

	for (int i = 0; i < 4; i++) // Loops down the user provided guess
	{
		for (int j = 0; j < 4; j++) // Loops down each element of the answer to compare to the guess
		{
			if (x[i] == y[j] && i == j) // Values match and share the same loction are a bull.
			{
				score.bull++;
			}
			else if (x[i] == y[j]) // Values match but don't share the same loction are a cow.
			{
				score.cow++;
			}
		}
	}
	
	return score;
}
//----------------------------------------------------------------------------------------------------------------------------------------

int main()
try 
{
	// Title and rules of the game.
	intro();

	// variables to hold the answer and the guess.
	vector<char> answer{ 'a','b','c','d' };
	vector<char> guess(4);
	
	// Loop that keeps prompting the player if they quess wrong.
	while (true)
	{
		cout << '>';
		cin >> guess[0] >> guess[1] >> guess[2] >> guess[3];

		// Break the loop if the user wants to exit
		if (guess[0]=='q' && guess[1]=='q' && guess[2]=='q' && guess[3]=='q')
			break;

		// Test for duplicates in the submitted quess and let user know to try again
		if (duplicate(guess))
		{
			cout << "Repeated letters! Please try another guess.\n";
			continue;
		}

		// Test the guess against the answer and tally the results.
		Tally score = bovine(guess, answer);
		
		// Display the results of the guess
		if (score.bull == 4)
		{
			cout << "You got 4 bulls! Great work";
			break;
		}
		else
			cout << "You got " << score.bull << " bulls and " << score.cow << " cows. Try again.\n";
	}
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception!\n";
	return 2;
}