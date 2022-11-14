// Drill 08 03 demonstrating namespaces

#include <iostream>

// Define the namespaces and pring functions
namespace X {
	int var;
	void print();
}

void X::print() {
	std::cout << var << std::endl;
}

namespace Y {
	int var;
	void print();
}

void Y::print() {
	std::cout << var << std::endl;
}

namespace Z {
	int var;
	void print();
}

void Z::print() {
	std::cout << var << std::endl;
}

int main() {
	X::var = 7;
	X::print(); // print X's var

	using namespace Y;
	var = 9;
	print(); // print Y's var

	{
		using Z::var;
		using Z::print;
		var = 11;
		print(); // print Z's var
	}

	print(); // print Y's var
	X::print(); // print X's var

	char c;
	std::cin >> c;
	return 0;
}