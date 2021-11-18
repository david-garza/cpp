/* 
	11/8/2021 David Carlos Garza

	The following program exerciesed 8.2, 8.3, and 8.4 given they are the same program but modifications to the same problem

	8.2
	Write a function print() that prints a vector of ints to cout. Give it two arguments: a string for "labeling" the output and a vector.

	8.3 
	Create a vector of Fibonacci numbers and print them using the function
	from exercise 8.2. To create the vector, write a function, fibonacci(x,y,v,n),
	where integers x and y are ints, v is an empty vector<int>, and n is the
	number of elements to put into v; v[0] will be x and v[1] will be y. A Fibo-
	nacci number is one that is part of a sequence where each element is the
	sum of the two previous ones. For example, starting with 1 and 2, we get
	1, 2, 3, 5, 8, 13, 21, .... Your fibonacci() function should make such a 
	sequence starting with x and y arguments.

	8.4
	An int can hold integers only up to a maximum number. Find an approx-
	imation of tht maximum number by using fibonacci().
	Solution, run current program with n=200.

*/
#include "../../std_lib_facilities.h"

// Function to print out a vector with ints and label them 

void print(string s, vector<int>& v) {
	cout << s << endl;

	// Loop over the elements of the vector
	for (int i : v)
		cout << i << endl;
}
//---------------------------------------------------------

// Function to fill an empty vector with fibonacci numbers

void fibonacci(int x, int y, vector<int>& v, int n) {
	v.push_back(x);
	v.push_back(y);

	for (int i = 2; i <= n - 1; ++i) {
		v.push_back(v[i - 2] + v[i - 1]);
	}
}

//---------------------------------------------------------

int main()
try {
	
	vector<int> v; // Empty vector to fill with fibonacci numbers
	string s{ "Results" };
	int x;
	int y;
	int n;

	cout << "> ";
	cin >> x >> y >> n;
	 
	fibonacci(x, y, v, n);
	print(s, v);

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