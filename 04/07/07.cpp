// create a calculator that only works on integer values, either numeric or word shall work

#include "..\..\std_lib_facilities.h"

int integer_maker(string input) {
	vector<string> words(10);
	words[0] = "zero";
	words[1] = "one";
	words[2] = "two";
	words[3] = "three";
	words[4] = "four";
	words[5] = "five";
	words[6] = "six";
	words[7] = "seven";
	words[8] = "eight";
	words[9] = "nine";

	if (input == "0")
		return 0;
	else if (input == "1")
		return 1;
	else if (input == "2")
		return 2;
	else if (input == "3")
		return 3;
	else if (input == "4")
		return 4;
	else if (input == "5")
		return 5;
	else if (input == "6")
		return 6;
	else if (input == "7")
		return 7;
	else if (input == "8")
		return 8;
	else if (input == "9")
		return 9;
	else if (input == "zero")
		return 0;
	else if (input == "one")
		return 1;
	else if (input == "two")
		return 2;
	else if (input == "three")
		return 3;
	else if (input == "four")
		return 4;
	else if (input == "five")
		return 5;
	else if (input == "six")
		return 6;
	else if (input == "seven")
		return 7;
	else if (input == "eight")
		return 8;
	else if (input == "nine")
		return 9;
}

int main() {
	int number1; // First number
	int number2; // Second number
	char operation = 0; // Operation to perform on each number
	string input1;
	string input2;

	while (operation != '|') {
		cout << "Please enter two digits, either as a numeric or words, and an operator sperated by spaces: ";
		cin >> input1 >> input2 >> operation;
		//Need to call the function that coverts the 
		number1 = integer_maker(input1);
		number2 = integer_maker(input2);
		switch (operation)
		{
		case '+':
			cout << "The sum of " << number1 << " and " << number2 << " is " << number1 + number2 << endl;
			break;
		case '-':
			cout << "The difference of " << number1 << " and " << number2 << " is " << number1 - number2 << endl;
			break;
		case '*':
			cout << "The product of " << number1 << " and " << number2 << " is " << number1 * number2 << endl;
			break;
		case '/':
			cout << "The divisor of " << number1 << " and " << number2 << " is " << number1 / number2 << endl;
			break;
		case '%':
			cout << "The modulus of " << number1 << " and " << number2 << " is " << number1 % number2 << endl;
			break;
		case '|':
			cout << "Exit successful!\n";
			break;
		default:
			cout << "No valid operator selected.\n";
			break;
		}
	}
	
	keep_window_open();
	return(0);
}