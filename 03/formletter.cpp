// This program is the end chapter drill for Bjarne Stroustrup's book. The requirement is to create a form letter

#include "../std_lib_facilities.h"

int main() {
	// Variables used in program
	string first_name; //first_name is a variable of the string time
	string friend_name; // Second person to the letter.
	char friend_sex = 0; //Will record the sex of the friend
	int age = 0; // Age of the person getting the letter

	//Inputs for letter
	
	cout << "Please enter the name of the person you are writing to (followed by 'enter'):\n"; // Prompt asking for person being addressed
	cin >> first_name; 
	cout << "Please enter the name of shared friend:\n"; // Prompt for second name
	cin >> friend_name;
	cout << "Please enter the sex of the shared friend (m/f):\n"; //Prompt user for the sex of the friend
	cin >> friend_sex; 
	cout << "Please enter the age of the person you are writing to:\n"; // Prompt to enter the age of the recieptent
	cin >> age;
	if (age <= 0) // Error check the age
		error("Age is out of bounds");
	if (age >= 110)
		error("Age is out of bounds");

	
	// Body of the letter
	cout << "\nDear " << first_name << ",\n\n"; // Greeting of letter
	cout << "\tHow are you? I am fine. I miss you. I have been traveling the world! I wish you could have joined me.\n\tSorry that I am such a terrible friend. Maybe in another lifetime.\n";
	cout << "\tHave you seen " << friend_name << " lately? ";

	// Block to use the proper pronoun

	if (friend_sex == 'm')
		cout << "If you see "<< friend_name<< " please ask him to call me.\n";

	if (friend_sex == 'f')
		cout << "If you see " << friend_name << " please ask her to call me.\n";

	cout << "\tI hear you just had a birthday and you are " << age << " years old. ";

	// Block to use the proper age statment

	if (age <= 12)
		cout << "Next year you will be " << age + 1 << ".";
	if (age == 17)
		cout << "Next year you will be able to vote.";
	if (age > 70)
		cout << "I hope you are enjoying retirement.";

	// Salutation
	cout << "\n\nSincerely,\n\n\nDavid Carlos Garza";

	cout << "\n";
	return(0);
}