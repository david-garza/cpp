/* 
	11/11/2021 David Carlos Garza

	8.5
	Write versions of the functions from exercise 5, but with vector<string>.

*/
#include "../../std_lib_facilities.h"

// Function to print out a vector with strings and label them 

void print(string s, vector<string>& v) {
	cout << s << endl;

	// Loop over the elements of the vector
	for (string i : v)
		cout << i << endl;
}
//---------------------------------------------------------

// Function reverse a vector using pass by value
vector<string> reverse_v(vector<string> v) {

	// j is a counter that starts at the last element and counts down
	int j;
	j = v.size()-1;

	// Loop only half of the vector to swap the elements, looping the full length reverses the swap of the first half of the vector
	for (int i = 0; i <v.size()/2; i++)
	{
		swap(v[i], v[j]);
		j--;
	}

	return v;
}
//---------------------------------------------------------

// Function reverse a vector using pass by reference
void reverse_r(vector<string>& v) {

	// j is a counter that starts at the last element and counts down
	int j;
	j = v.size() - 1;

	// Loop only half of the vector to swap the elements, looping the full length reverses the swap of the first half of the vector
	for (int i = 0; i < v.size() / 2; i++)
	{
		swap(v[i], v[j]);
		j--;
	}

}

//---------------------------------------------------------


int main()
try {
	// Test vector for this program
	vector<string> test{ "Aardvark","Bat","Cat","Donkey","Eel"};

	print("test", test);

	// Pass by reverse_v requires a vector to save too
	vector<string> reverse1;
	reverse1 = reverse_v(test);
	print("reverse_v", reverse1);

	// Pass by reverse_r does not require a new vector to save too
	reverse_r(test);
	print("reverse_r", test);

	keep_window_open("q");
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open("q");
	return 1;
}
catch (...) {
	cerr << "Unknown exception!\n";
	keep_window_open("q");
	return 2;
}