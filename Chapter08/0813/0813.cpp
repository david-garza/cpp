/* 
	11/15/2021 David Carlos Garza

	8.13
	Write a function that takes a vector<string> argument and returns a
	vector<int> containing the number of characters in each string. Also
	find the longest and shortest string and the lexicographically first and
	last string. How many separate functions would you use for these tasks?
	Why?

*/

#include "../../std_lib_facilities.h"

// Function that returns an int vector with the length of each string in a vector string

vector<int> element_size(vector<string>& s)
{
	vector<int> answer;

	for (string i : s)
		answer.push_back(i.size());

	return answer;
}
//--------------------------------------------------------------------------

// Function to print vector<int>
void print_vi(vector<int>& v) 
{
	cout << "Length of string elements" << endl;
	for (int i : v)
		cout << i << endl;
}
//--------------------------------------------------------------------------

// Function to find the shorest string
string shortest(vector<string>& s)
{
	int min = s[0].size();
	string small = s[0];

	for(string i:s)
		if (i.size() < min) {
			min = i.size();
			small = i;
		}

	return small;
}
//--------------------------------------------------------------------------

// Function to find the longest string
string longest(vector<string>& s)
{
	int max = s[0].size();
	string large = s[0];

	for (string i : s)
		if (i.size() > max) {
			max = i.size();
			large = i;
		}

	return large;
}
//--------------------------------------------------------------------------

vector<string> alpha(vector<string> s)
{
	vector<string> temp(2);
	sort(s.begin(),s.end());
	
	temp[0] = s[0];
	temp[1] = s[s.size() - 1];
	return temp;
}

int main()
try {

	
	vector<string> input{ "cat","dog","bat","fish","turtle","horse","zebra","armadillo"};

	vector<int> temp;
	temp = element_size(input);
	print_vi(temp);

	string small;
	small = shortest(input);
	cout << "Shorest:\t" << small << endl;

	string large;
	large = longest(input);
	cout << "Longest:\t" << large << endl;

	vector<string> firstlast;
	firstlast = alpha(input);
	cout << "First:\t" << firstlast[0] << endl;
	cout << "Last:\t" << firstlast[1] << endl;

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