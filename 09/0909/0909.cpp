/* 
	David Carlos Garza
	11/21/2021

	9.5
	This exercise and the next few require you to design and implement a
	Book class, such as you can imagine as part of a software for a library. Class
	Book should have members for ISBN, title, author, and copyright
	date. Also store data on whether or not the book is checked out. Create
	functions for returning those data values. Create functions for checking
	a book in and out. Do simple validation of data entered into a Book; for 
	example, accept ISBNs only of the form n-n-n-x where n is an integer and
	x is a digit or letter. Store an ISBN as a string.

	9.6
	Add operators for the Book class. Have the == operator check wether
	the ISBN numbers are the same for two books. Have != also compare
	the ISBN numbers. Have a << print out the title, author, and ISBN on
	separate lines.

	9.7
	Create an enumerated type for the Book class called Genre. Have the
	types be fiction, nonfiction, periodical, biography, and children. Give
	each book a Genre and make appropriate changes to the Book construc-
	tor and member functions.

	9.8
	Create a Patron class for the library. The class will have a user's name,
	library card number, and library fees (if owed). Have functions that access
	this data, as well as function to set the fee of the user. Have a helper
	function that returns a Boolean (bool) depending on whether or not the
	user owes a fee.

	9.9
	Create Library class. Include vectors of Books and Patrons. Include a
	struct called Transaction. Have it include a Book, a Patron, and a Date
	from the chapter. Make a vector of Transactions. Create functions to add
	books to the library, add patrons to the library, and check out books.
	Whenever a user checks out a book, have the library make sure that both
	the user and the book are in the library. If they aren't, report an error.
	Then check to make sure that the user owes no fees. If the user does,
	report an error. It not, create a Transaction, and place it in the vector of
	Transactions. Also write a function that will return a vector that contains
	the names of all Patrons who owe fees.

	Reference book
	("1-2-3-A","Programming","Stroustrup, Bjarne",Genre::nonfiction,2014)
*/

#include"../../dcg.h"
#include"Book.h"
#include"Main.h"

int main()
try {
	
	Library::Library library;

	// Initate libray object with test data
	library = ini_library();

	// Stop point to view contents of library after ini debugging only
	library;
	Chrono::Date today{ 2021,Chrono::Month::nov,26 };
	try {
		library.set_fee(2, 1.50);
		library.set_fee(3, 100);
		library.checkout("1-2-3-A", 1, today);
		
		vector<Library::Patron> payee;
		payee=library.owe_fee();
		payee;
	}
	catch (Library::Library::Invalid_fee) {
		cerr << "User owes fee" << endl;
	}

	catch (Library::Library::Invalid_book) {
		cerr << "Book not in catalog" << endl;
	}
	catch (Library::Library::Invalid_patron) {
		cerr << "Patron not in catalog" << endl;
	}

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