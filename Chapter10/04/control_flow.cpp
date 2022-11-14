#include "control_flow.h"
#include "io_functions.h"
#include "stat_functions.h"

void user_prompt(vector<Reading>& readings)
{
	// Prompt user if they want to create a file or read a file
	const char write{ 'w' };
	const char read{ 'r' };
	const char exit{ 'q' };
	char answer{ '0' };
	while (answer != exit) {
		try {
			cout << "Read or write (r/w/q)?: ";
			cin >> answer;

			switch (answer)
			{
			case write:
				fill_temps(readings);
				output_file(readings);
				readings.clear();
				continue;
			case read:
				read_file(readings);
				print_sats(readings);
				readings.clear();
				continue;
			case exit:
				break;
			default:
				error("Invalid entry");
			}
		}
		catch (exception& e) {
			cerr << "error: " << e.what() << '\n';
			answer = '0';
		}
	}
}
