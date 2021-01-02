// Excercise 3.11, The purpose is to create a coin counter and tabulate total in cents and dollars

#include "../std_lib_facilities.h"

int main() {

	// Declare variables
	int penny;
	int nickel;
	int dime;
	int quarter;
	int halfdollar;
	double value;

	// Prompt user for each number of coins
	cout << "How many pennies do you have? ";
	cin >> penny;

	cout << "How many nickels do you have? ";
	cin >> nickel;

	cout << "How many dimes do you have? ";
	cin >> dime;
	
	cout << "How many quarters do you have? ";
	cin >> quarter;

	cout << "How many half dollars do you have? ";
	cin >> halfdollar;

	// Determine the value of all of the coins

	value = penny * 1 + nickel * 5 + dime * 10 + quarter * 25 + halfdollar * 50;

	// Print the results to the screen
	cout << "\nYou have " << penny << " pennies.\n";
	cout << "You have " << nickel << " nickles.\n";
	cout << "You have " << dime << " dimes.\n";
	cout << "You have " << quarter << " quarters.\n";
	cout << "You have " << halfdollar << " half dollars.\n\n";
	cout << "Your coins total to " << value << " cents or " << value / 100 << " dollars.";

	return(0); 
}