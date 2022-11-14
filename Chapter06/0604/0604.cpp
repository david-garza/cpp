/* 
	Date: 2/2/2021
	Author: David C. Garza
	Purpose: This exercise is to teach how to create a class. The bas program uses the code from exercise 04.19. Simple database to record names and test scores. Parts of this program have been
	copied and pasted from the 04.19 assignment. Updated template uses the error catching template.

	Requirements: 
	1. Record name and test score
	2. Data must be saved into an user defined class object
	3. Name can't repeat
	4. Exit condition is Noname 0. 
	5. Names must be unique, throw an error if the name is not unique
	6. List names and test scores after Noname 0 has been enerted. 

*/
#include "../../std_lib_facilities.h"

//---------------------------------------------------------------------
// Object to store names and values together.

class Name_value 
{
public:
	string name; // Hold the names
	int score; // Hold the scores for each name
	Name_value(string n, int s) // Crete a name_value using a name and score.
		:name(n), score(s) {}
};
//---------------------------------------------------------------------

//---------------------------------------------------------------------
// Function that prints the list of the vector
void print(vector<Name_value> x) 
{
	
	// Print out list of students and scores.
	cout << '\n';
	for (int i = 0; i < x.size(); ++i)
	{
		cout << x[i].name << ' ' << x[i].score << '\n';
	}
}
//---------------------------------------------------------------------

//---------------------------------------------------------------------
// Functoin that checks for the uniqueness of names, throws and error if name is duplicated
void unique(vector<Name_value> x) 
{
	// Duplicate the list so it can be compared to itself
	vector<Name_value> list1{ x };
	vector<Name_value> list2{ x };

	for (int i = 0; i < list1.size(); ++i)
	{
		for (int j = 0; j < list2.size(); ++j)
		{
			if (list1[i].name == list2[j].name && i != j) // Check for the condition on repeated name. We the condition that the indexs are not the same given that the two list are copies of each other.
			{
				cout << "Duplicated name: " << list1[i].name << '\n';
				error(" A name is duplicated in the list. Names cannot be repeated.");
			}
		}
	}
}
//---------------------------------------------------------------------


int main()
try 
{
	
	vector<Name_value> student;
	string name;
	int score;

	// Instructions
	cout << "Please enter a name and score, each name must be unique\nTerminate input by entering 'NoName 0'\n";

	while (true)
	{
		// Provide prompt to enter values.
		cout << '>';
		cin >> name >> score;

		if (name == "NoName"&&score == 0) break; // Exit the loop  requirement.

		student.push_back(Name_value(name,score)); // Read data into the vector 
	}

	// Test the uniqueness of the names
	unique(student);
	// call print to print the scores
	print(student);
	
	return 0;
}
catch (exception& e) 
{
	cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...) 
{
	cerr << "Unknown exception!\n";
	return 2;
}