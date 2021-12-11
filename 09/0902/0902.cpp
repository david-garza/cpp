/* 
	David Carlos Garza
	11/20/2021

	9.2
	Design and implement a Name_pairs class holding (name, age) pairs where
	name is a string and age is a double. Represent that as a vector<string>
	(called name) and a vector<double> (called age) member. Provide an in-
	put operation read_names() that reads a series of names. Provide a read_
	ages() operation that prompts the user for an age for each name. Provide
	a print() operation that prints out the (name[i],age[i]) pairs (one per line)
	in the order determined by the name vector. Provide a sort() operation
	that sorts the name vector in alpahbetical order and reorganizes the age
	vector to match. Implement all "operations" as member functions. Test
	the class (of course: test early and often).

	9.3
	Replace Name_pair::print() with a (global) operator << and define ==
	and != for Name::pairs.

*/
#include "../../std_lib_facilities.h"
namespace Namedb {
	class Name_pairs {
	public:
		Name_pairs();// Default constructor for the class
		void read_names();		// reads a series of names
		void read_ages();		// prompts the user for an age for each name
		void sort();			// sorts the name vector in alpahbetical order and reorganizes the age vector to match
		string write_name(int i) { return name[i]; }	// function to access the names
		double write_age(int i) { return age[i]; }		// function to access the age
		int size() { return name.size(); }				// returns the size of the name
	private:
		vector<string> name;	// Vector to hold list of names
		vector<double> age;		// Vector to hold list of ages corrsponding to names (same index)
	};

	// Helper functions and operator overloading
	ostream& operator<<(ostream& os, Name_pairs& np);
	bool operator==(Name_pairs& a, Name_pairs& b);
	bool operator!=(Name_pairs& a, Name_pairs& b);
}								// End Namedb

namespace Namedb {
	// Default constructor
	Name_pairs::Name_pairs()
		:name{}, age{} {}

	void Name_pairs::read_names() {
		string temp;

		while (cin) {
			cin >> temp;
			if (temp == "q") break;
			name.push_back(temp);
		}
	}

	void Name_pairs::read_ages() {
		double temp;

		for (int i{ 0 }; i < name.size(); i++) {
			cout << name[i] << " age: ";
			cin >> temp;
			age.push_back(temp);
		}

	}

	void Name_pairs::sort() {
		// Temporary vectors to hold for storting
		vector<string> temp_x;
		vector<double> temp_y;

		temp_x = name;
		temp_y = age;

		// Sort the name vector alphabetically
		std::sort(name.begin(), name.end());

		// Loop down the original name vector and find the matching name in the sorted vector, copy age into the corrosponding index for age.
		for (int i = 0; i < temp_x.size(); i++) {
			for (int j = 0; j < name.size(); j++) {
				if (temp_x[i] == name[j])
					age[j] = temp_y[i];
			}
		}
	}
	ostream& operator<<(ostream& os, Name_pairs& np)
	{
		np.sort();

		for (int i = 0; i < np.size(); i++) {
			os << np.write_name(i) << '\t' << np.write_age(i) << endl;
		}
		return os;
	}
	bool operator==(Name_pairs& a, Name_pairs& b)
	{
		if (a.size() != b.size()) return false;

		for (int i{ 0 }; i < a.size(); i++) {
			if (a.write_name(i) != b.write_name(i) || a.write_age(i) != b.write_age(i)) return false;
		}
		return true;
	}
	bool operator!=(Name_pairs& a, Name_pairs& b)
	{
		return !(a == b);
	}
}	// End Namedb

int main()
try {
	Namedb::Name_pairs list1;
	Namedb::Name_pairs list2;
	list1.read_names();
	list1.read_ages();
	cout << list1;
	list2.read_names();
	list2.read_ages();
	cout << list2;

	if (list1 == list2) cout << "List are the same" << endl;
	else if (list1 != list2)cout << "List are different" << endl;

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