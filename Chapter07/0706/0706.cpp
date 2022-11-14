
/*
	David Carlos Garza

	Exercise 07.06
	- Added '_' to be included in variable names
	- Added '=' operator to change the value of a variable that has been assigned using 'let'
		x=5; well reassign the value of x to 5. Modified function primary to allow this. Allows to redefine a variable in the middle of an expression.
	- Added a constant flag to the variable table. Constants can not be updated using set_value.
	- Added allow the user to add constants
	- Updated the data structure to include class Symbol_table with member vector table, update functions accordingly
	- Allowed Token_stream::get() to return Token(print) when it encounter a '\n'
	- Add a help feature, activates on 'H' and 'h'
*/

#include "../../std_lib_facilities.h"

//------------------------------------------------------------------------------

const char number = '8'; //t.kind==number means that t is a number Token
const char quit = 'q'; //t.kind==quit means that t is a quit Token
const char print = '\n'; //t.kind==print means that t is a print Token
const string prompt = "> ";
const string result = "= "; 
const char name = 'a'; // name token
const char let = 'L'; // declaration token
const char constant = 'C'; // constant token
const string declkey = "let"; // declaration keyword for variables
const string constkey = "const"; // constant keyword for constants
const char help1 = 'h';
const char help2 = 'H';

//------------------------------------------------------------------------------

// Help menu
void help() {
	cout << "Calculator Help" << endl << endl;
	cout << "Supported mathametical operations: +,-,*,/,%, and ()." << endl << endl;
	cout << "Variable and constant operations:" << endl << endl;
	cout << "\tDeclare variable: "<< declkey << " x = 3 or " << declkey << " y = 8/2" << endl;
	cout << "\tReassign variable: x = 20" << endl;
	cout << "\tDeclare constant: " << constkey << " g = -9.81" << endl << endl;
	cout << "Enter '" << quit << "' to exit." << endl;
}
//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
	string name;
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
	Token(char ch, string n)  // Make a token from char and a name
		:kind(ch), name(n) {}
};

//------------------------------------------------------------------------------

class Token_stream {
public: 
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
	void ignore(char c); // discard characters up to and including a c
private:
	bool full;        // is there a Token in the buffer?
	Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0) {}  // no Token in buffer

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    } 

    char ch;

	cin.get(ch); // Read one character at a time

	while (ch == ' ') cin.get(ch); // skip empty spaces

    switch (ch) {
	case help1:
	case help2:
		return Token{ help1 };
    case print:
    case quit:
	case '=':
	case '(': 
	case ')': 
	case '+': 
	case '-': 
	case '*': 
	case '/': 
	case '%':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {    
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token(number,val);   
        }
    default:
		if (isalpha(ch)) { // find charactors and assign them as names, declarations, and constant declarations
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch=='_')) s += ch; // cin.get reads one character at a time, test that part of the name and concates it to string s
			cin.putback(ch); // put it back into the cin stream
			if (s == declkey) return Token{ let };
			if (s == constkey) return Token{ constant };
			return Token{ name,s };
		}
        error("Bad token");
    }
}

//------------------------------------------------------------------------------

void Token_stream::ignore(char c)
//c represents the kind of token
{
	// first look in the buffer:
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	// now search input
	char ch = 0;
	while (cin >> ch)
		if (ch == c) return;
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

// Define an object called variable with name and value of variable

class Variable {
public:
	string name;
	double value;
	bool constant{false}; // Flag to indicate if it is constant or can be changed true = constant
};

//------------------------------------------------------------------------------

// Create an object with member that is the vector table and the functions that operate on that table

class Symbol_table {
public:
	vector<Variable> var_table;
	double get(string s);
	void set(string s, double d);
	bool is_declared(string var);
	double define_name(string var, double val, bool constant);
};

//------------------------------------------------------------------------------

// Look up a variable by name in the var_table and return the value

double Symbol_table::get(string s)
{
	for (const Variable& v : var_table)
		if (v.name == s) return v.value;
	error("get: undefined variable ", s);
}

//------------------------------------------------------------------------------

// update a variable's value, test variable and constant flag, throw error if attempting to reset a constant

void Symbol_table::set(string s, double d)
{
	for (Variable& v : var_table) {
		if (v.name == s && v.constant == true) {
			error("set: can't reset constant ", s);
		}
		else if (v.name == s && v.constant == false) {
			v.value = d;
			return;
		}
	}
	error("set: undefined variable ", s);
}

//------------------------------------------------------------------------------

// is the varible name already in the var_table?

bool Symbol_table::is_declared(string var)
{
	for (const Variable& v : var_table)
		if (v.name == var) return true;
	return false;
}

//------------------------------------------------------------------------------

// Add a variable to the table

double Symbol_table::define_name(string var, double val,bool constant)
{
	if (is_declared(var)) error(var, " declared twice");
	var_table.push_back(Variable{ var,val,constant });
	return val;
}

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// Create a variable called table to store the variables and constants

Symbol_table table;

// Grammer rule to understand declarations, assumes we have seen "let", handle: name=expression, declare a variable called "name" with the initial value "expression"

double declaration()
{
	Token t = ts.get();
	if (t.kind != name)error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=')error("= missing in declaration of ", var_name);

	double d = expression();
	table.define_name(var_name, d,false);
	return d;
}

//------------------------------------------------------------------------------

// Grammer rule to understand the setting of constants, assumes that we have seen "const"

double set_constant()
{
	Token t = ts.get();
	if (t.kind != name)error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=')error("= missing in declaration of ", var_name);

	double d = expression();
	table.define_name(var_name, d, true);
	return d;
}

//------------------------------------------------------------------------------

// Handles declarations, variable reassignments, and expressions

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case constant:
		return set_constant();
	case let:
		return declaration();
	default:
		ts.putback(t);
		return expression();
	}
}

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
        {    
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    case number:            
        return t.value;  // return the number's value
	case name:
	{
		Token t1 = ts.get(); // Read the next token to look for assignment token and assign new value, otherwise return the value of the variable.
		if (t1.kind == '=') {
			double d = expression();
			table.set(t.name, d);
			return d;
		}
		ts.putback(t1);
		return table.get(t.name);
	}
	case '-':
		return - primary();
	case '+':
		return primary();
    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            {    
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d; 
                t = ts.get();
                break;
            }
		case '%':
			{
				double d = primary();
				if (d == 0) error("%: divide by zero");
				left = fmod(left, d);
				t = ts.get();
				break;
			}
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

// Clean up error function

void clean_up_mess()
{
	ts.ignore(print);
}

//------------------------------------------------------------------------------

// Calculate that performs actual calculations

void calculate() 
{
	while (cin) 
	try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get(); //eat ';'
		if (t.kind == quit) return;
		if (t.kind == help1) {
			help();
			continue;
		}
		ts.putback(t);
		cout << result << statement() << '\n';
	}
	catch (exception& e) {
		cerr << e.what() << '\n';
		clean_up_mess();
	}
}

//------------------------------------------------------------------------------

int main()
try
{
	// predefined names
	table.define_name("pi", 3.1415926535,true);
	table.define_name("e", 2.7182818284, true);

	calculate();
	keep_window_open("~~"); // Close window
	return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
	keep_window_open("~~"); // Close window
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
	keep_window_open("~~"); // Close window
    return 2;
}

//------------------------------------------------------------------------------
