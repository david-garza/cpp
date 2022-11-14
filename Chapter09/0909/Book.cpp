/*
	Definitons for book class
	David Carlos Garza
	11/21/2021
*/

#include"../../dcg.h"
#include"Book.h"


namespace Library {
	// Constructors
	Book::Book()
		:isbn{}, title{}, author{}, copyright{}, status{false} {}
	Book::Book(std::string is, std::string tit, std::string au, Genre gen, int copri)
		: isbn{ is }, title{ tit }, author{ au }, gen{ gen } , copyright{ copri }, status{ false }
	{
		if (!is_ispn(get_isbn())) throw Invalid{};
	}

	// Helper functions

	// Function to test ISBN format; should be n-n-n-x
	bool is_ispn(std::string s)
	{
		//Check the size of the ISBN
		if (s.size() != 7) return false;

		// Check for the 3 numerical digits
		for (int i{ 0 }; i < 5; i += 2)
		{
			if (!isdigit(s[i])) return false;
		}

		// Check dashes
		for (int i{ 1 }; i < 6; i += 2)
			if (s[i] != '-') return false;

		// Last digit can be either a digit or a capital alpha
		if (isdigit(s[6])||isalpha(s[6])) return true;

		return false;
	}
	//------------------------------------------------------

	// Operators to compare ISBN
	bool operator==(const Book& a, const Book& b)
	{
		return a.get_isbn() == b.get_isbn();
	}

	bool operator!=(const Book& a, const Book& b)
	{
		return !(a == b);
	}

	// Operator for output stream
	std::ostream& operator<<(std::ostream& os, const Book& a)
	{
		return os << a.get_title() << std::endl
			<< a.get_author() << std::endl
			<< a.get_isbn() << std::endl
			<< int(a.get_genre()) << std::endl;
	}
	//------------------------------------------------------
	Patron::Patron()
		:name{}, id{ }, fee{ 0 }{}
	Patron::Patron(std::string s, int i)
		:name{ s }, id{ i }, fee{ 0 }{}

	bool is_fee(Patron& p)
	{
		if (p.get_fee() > 0) return true;
		else return false;	
	}

	std::ostream& operator<<(std::ostream& os, const Patron& p)
	{
		return os << p.get_name() << std::endl
			<< p.get_id() << std::endl
			<< p.get_fee() << std::endl;
	}
	
	// Books are accesed via ISBN number and Patrons by library card number
	void Library::checkout(std::string isbn, int id, Chrono::Date d)
	{
		Patron pt;
		Book bt;
		// Check for patron and fees
		bool is_patron{ false };
		for (Patron p : patrons) {
			
			if (p.get_id() == id)
			{
				if (p.get_fee() > 0)
					throw Invalid_fee{};
				is_patron = true;
				pt = p;
				pt;
				break;
			}
		}
		// Throw error if patron not found
		if (is_patron == false) throw Invalid_patron{};

		// Check for book 
		bool is_book{ false };
		for (Book b : books)
			if (b.get_isbn()==isbn)
			{
				is_book = true;
				bt = b;
				break;
			}

		// Throw error if book not found
		if (is_book == false) throw Invalid_book{};

		// Enter transaction
		Transaction temp;
		temp.date = d;
		temp.item = bt;
		temp.person = pt;

		transactions.push_back(temp);

	}

	void Library::set_fee(int id, double f)
	{
		for (int i{ 0 }; i < patrons.size(); i++) 
		{
			if (patrons[i].get_id() == id)
			{
				patrons[i].set_fee(f);
				break;
			}
		}
			
	}

	vector<Patron> Library::owe_fee() const
	{
		vector<Patron> payee;

		for (Patron p : patrons)
			if (p.get_fee() > 0) payee.push_back(p);

		return payee;
	}

} // End Library namespace