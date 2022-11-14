#pragma once
/* 
	Declarations for Library package
	David Carlos Garza
	11/21/2021

*/

#include "../../dcg.h"
#include "Chrono.h"

namespace Library {
	// Enumerated class for Genre
	enum class Genre {
		fiction, nonfiction, periodical, biography, children
	};

	// Class to create Book Objects
	class Book {
	public:
		// Throw exceptions
		class Invalid {};

		// Constructors
		Book();
		Book(std::string, std::string, std::string, Genre, int);

		// non-modifying functions
		std::string get_isbn() const { return isbn; }
		std::string get_title() const { return title; }
		std::string get_author() const { return author; }
		Genre get_genre() const { return gen; }
		int get_copyright() const { return copyright; }
		bool ischeckedout() const { return status; }

		// modifying functions
		void checkout() { status = true; }
		void checkin() { status = false; }
	private:
		std::string isbn;		// n-n-n-x; n is 0-0 and x is 0-9 a-z
		std::string title;
		std::string author;
		Genre gen;
		int copyright;
		bool status;			// checked out is true
	};

	// Helper functions
	bool is_ispn(std::string);

	// Operators to compare ISBN
	bool operator==(const Book&, const Book&);
	bool operator!=(const Book&, const Book&);

	// Operator for output stream
	std::ostream& operator<<(std::ostream&, const Book&);

	// Patron class to hold information on library patrons
	class Patron {
	public:
		//Constructor to build the patron class
		Patron();
		Patron(std::string, int);

		// Non modifying functions
		std::string get_name() const { return name; }
		int get_id() const { return id; }
		double get_fee() const { return fee; }

		// Modifying function
		void set_fee(double f) { fee = f; }
	private:
		std::string name;
		int id;
		double fee;
	};

	// Helper functions for Patron
	bool is_fee(Patron&);

	std::ostream& operator<<(std::ostream&, const Patron&);

	class Library {
	public:
		// Error throwing
		class Invalid_fee {}; // Patron owes fees
		class Invalid_patron {}; // Patron not found
		class Invalid_book {}; // Book not found

		// Modifying functions
		void add_book(Book b) { books.push_back(b); }
		void add_patron(Patron p) { patrons.push_back(p); }
		void checkout(std::string isbn, int id,Chrono::Date d); // Assume that string 
		void set_fee(int id,double f);

		// Non-modifying functions
		vector<Patron> owe_fee() const;

	private:
		vector<Book> books;
		vector<Patron> patrons;
		struct Transaction {
			Book item;
			Patron person;
			Chrono::Date date;
		};
		vector<Transaction> transactions;
	};
	
} // End Library namespace