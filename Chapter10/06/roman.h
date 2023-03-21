/* 
Function declarations for the roman numeral read and evaluation functions 
Date: 3/20/2023

*/
#pragma once
#include "../../dcg.h"

namespace Rome {
	
	// Variables to keep track of the totals
	/* Read string and evaluate values */
	int sum{ 0 };
	int i_count{ 0 };
	int i_val{ 1 };
	int v_count{ 0 };
	int v_val{ 5 };
	int x_count{ 0 };
	int x_val{ 10 };

	// Functions to read and evaluate the roman numerals
	int i_read(char rn);
	int v_read(char rn);
	int x_read(char rn);

} // End of Rome namespace