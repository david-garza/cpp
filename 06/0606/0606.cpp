/* 
	Date: 02/24/2021
	Author: David Carlos Garza

	Purpose: Excercise 06.06. Create a program that can verify if simple sentences are grammatically correct.
*/
#include "../../std_lib_facilities.h"

// Define several functions now and defined further below.

bool noun(); 
bool verb();
bool conjuction(); 
bool period();
//-----------------------------------------------------------------------------------------------------------

/* Define the sentence function that triggers the testing of words
	1. Test function noun()
		True: indicates sentence passed the grammer check print "OK"
		False: indicates sentence failed the grammer check print "Not OK"
*/	

void sentence()
{
	if (noun())
		cout << "OK\n";
	else
		cout << "Not OK\n";
}
//-----------------------------------------------------------------------------------------------------------

/* Define noun
	Test: Check if the word is noun
		False: Return False
		True: Call verb()
*/

bool noun()
{
	// Read character from iostream
	string word;
	cin >> word;
	vector<string> nouns{ "birds","fish","C++" };

	// Test to see if it is a noun
	if (word == nouns[0] || word == nouns[1] || word == nouns[2])
		return verb();
	else
		return false;
}
//-----------------------------------------------------------------------------------------------------------

/* Define verb
	Test if word is a verb
		False: Return false
		True: Call period()
*/

bool verb()
{
	// Read character from iostream
	string word;
	cin >> word;
	vector<string> verbs{ "rules","fly","swim" };

	// Test to see if it is a verb
	if (word == verbs[0] || word == verbs[1] || word == verbs[2])
		return period();
	else
		return false;
}
//-----------------------------------------------------------------------------------------------------------

/* Define period
	Test if word is a period
		True: Return True
		False: Call conjunction()
*/
bool period()
{
	// Read character from iostream
	char word;
	cin >> word;

	// Test to see if it is a period
	if (word=='.')
		return true;
	else
	{
		cin.putback(word); // The character needs to be returned to the iostream so that conjuction can evaluate it.
		return  conjuction();
	}
		
}
//-----------------------------------------------------------------------------------------------------------
/* Define conjunction
	Test if word is a conjuction
		True: Call noun
		False: Return false
	
*/
bool conjuction()
{
	// Read character from iostream
	string word;
	cin >> word;
	vector<string> conjuctions{ "and","or","but" };

	// Test to see if it is a conjuction
	if (word==conjuctions[0] || word==conjuctions[1] || word==conjuctions[2])
		return noun();
	else
		return false;
}
//-----------------------------------------------------------------------------------------------------------

int main()
try 
{
	cout << "Please enter a sentence using the combination of nouns, verbs, and conjuctions below:\n";
	cout << "Format: 'Noun Verb .' or 'Noun Verb Conjuction Noun Verb .' \n\n";
	cout << "Nouns:\nbirds\nfish\nC++\n\n";
	cout << "Verbs:\nrules\nfly\nswim\n\n";
	cout << "Conjuctions:\nand\nor\nbut\n\n";
	cout << '>';

	// Test the sentence grammer
	sentence();
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