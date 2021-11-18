#include "declarations.h"

// Pass by value swap
void swap_v(int a, int b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

// Pass by reference
void swap_r(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

// Pass by constant reference, this values because it tries to modify a constant
/*
void swap_cr(const int& a, const int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
*/