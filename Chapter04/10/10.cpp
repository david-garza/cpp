// This projet is to create the game rock, paper, scissors. 
//

#include "..\..\std_lib_facilities.h"

int main() {
	// Declare the variables and initilize them
	char selection = 0;
	int i = 0; //Loop counter to go down the vector of options
	vector<int> score(3); // vector the record the scores
	vector<char> computer(20);
	computer[0] = 'r';
	computer[1] = 'p';
	computer[2] = 'r';
	computer[3] = 'p';
	computer[4] = 'r';
	computer[5] = 'r';
	computer[6] = 'r';
	computer[7] = 'r';
	computer[8] = 'r';
	computer[9] = 'p';
	computer[10] = 's';
	computer[11] = 'p';
	computer[12] = 's';
	computer[13] = 's';
	computer[14] = 's';
	computer[15] = 'p';
	computer[16] = 's';
	computer[17] = 's';
	computer[18] = 'p';
	computer[19] = 'p';

	while (true) {
		// Menu to prompt user for selection
		cout << "Rock, Paper, Scissors!\n";
		cout << "Please select your play by chosing the letters below:\n";
		cout << "r. Rock\n" << "p. Paper\n" << "s. Scissors\n" << "q. Exit\n";
		cin >> selection;

		//Select game action by using a switch statement
		switch (selection)
		{
		case 'r':
			if (computer[i] == 'r') {
				cout << "Computer played ROCK and you played ROCK: TIE!" << endl;
				score[2]++;
			}
			if (computer[i] == 'p') {
				cout << "Computer played PAPER and you played ROCK: YOU LOST =(" << endl;
				score[1]++;
			}
			if (computer[i] == 's') {
				cout << "Computer played SCISSORS and you played ROCK: YOU WIN!!!" << endl;
				score[0]++;
			}
			break;
		case 'p':
			if (computer[i] == 'r') {
				cout << "Computer played ROCK and you played PAPER: YOU WIN!!!" << endl;
				score[0]++;
			}
			if (computer[i] == 'p') {
				cout << "Computer played PAPER and you played PAPER: TIE!" << endl;
				score[2]++;
			}
			if (computer[i] == 's') {
				cout << "Computer played SCISSORS and you played PAPER: YOU LOST =(" << endl;
				score[1]++;
			}
			break;
		case 's':
			if (computer[i] == 'r') {
				cout << "Computer played ROCK and you played SCISSORS: YOU LOST =(" << endl;
				score[1]++;
			}
			if (computer[i] == 'p') {
				cout << "Computer played PAPER and you played SCISSORS: YOU WIN!!!" << endl;
				score[0]++;
			}
			if (computer[i] == 's') {
				cout << "Computer played SCISSORS and you played SCISSORS: TIE!" << endl;
				score[2]++;
			}
			break;
		case 'q':
			cout << "Thank you for playing!\n";
			cout << "Final Score:\nWINS: " << score[0] << "\nLOSSES: " << score[1] << "\nTIES: " << score[2] << endl;
			keep_window_open();
			return 0;
			break;
		default:
			cout << "Not a valid entry, please try again!\n";
			break;
		}
		if (i == computer.size() - 1) // Resets the computer selection vector and prevents from generating an out of bounds error if the person plays more than 20 times
			i = 0;
		else
			i++; // Selects the next computer play
	}

}