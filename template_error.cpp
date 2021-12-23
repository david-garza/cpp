/* Base template with exception catching */
#include "../../dcg.h"

int main()
try {
	
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown exception!\n";
	return 2;
}