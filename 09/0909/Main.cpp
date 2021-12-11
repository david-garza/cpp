#include "Main.h"

Library::Library ini_library()
{
	vector<Library::Book> test_book{
		{ "1-2-3-A","Programming","Stroustrup, Bjarne",Library::Genre::nonfiction,2014 },
		{ "0-7-4-F","Farewell to Arms","Fry, Phillip J.",Library::Genre::biography,3035 },
		{ "0-1-0-1","Bite My Shiny Ass","Rodriguez, Bender",Library::Genre::children,3032 },
		{ "9-9-1-Z","Dangers of Space Travel","HAL 9000",Library::Genre::fiction,2021 }
	};

	vector<Library::Patron> test_patron{
		{"Garza, David",1},
		{"Clinton, Bill",2},
		{"Biden, Joe",3},
		{"Washington, George",4}
	};

	Library::Library library;

	// Add books
	for (Library::Book b : test_book)
		library.add_book(b);

	// Add patrons
	for (Library::Patron p : test_patron)
		library.add_patron(p);

	return library;
}
