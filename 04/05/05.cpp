// Exercise to write a simple calculator, 5 functions /, *, -, %, +

#include "..\..\std_lib_facilities.h"

int main() {
	double number1; // First number
	double number2; // Second number
	char operation = 0; // Operation to perform on each number
	int inumber1;
	int inumber2;

	while (operation != '|') {
		cout << "Please enter two numbers and an operator sperated by spaces: ";
		cin >> number1 >> number2 >> operation;

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
			inumber1 = number1;
			inumber2 = number2;
			cout << "The modulus of " << inumber1 << " and " << inumber2 << " is " << inumber1 % inumber2 << endl;
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