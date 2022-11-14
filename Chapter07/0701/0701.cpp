
/*
	David Carlos Garza

	Exercise 07.01 Update calculator to allow '_' in names of variables.
	- Variable must start with an alpha
*/

#include "../../std_lib_facilities.h"

//------------------------------------------------------------------------------

const char number = '8'; //t.kind==number means that t is a number Token
const char quit = 'q'; //t.kind==quit means that t is a quit Token
const char print = ';'; //t.kind==print means that t is a print Token
const string prompt = "> ";
const string result = "= "; 
const char name = 'a'; // name token
const char let = 'L'; // declaration token
const string declkey = "let"; // declaration keyword

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
:full(false), buffer(0)    // no Token in buffer
{
}

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
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
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
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch=='_')) s += ch; // cin.get reads one character at a time, test that part of the name and concates it to string s
			cin.putback(ch); // put it back into the cin stream
			if (s == declkey) return Token{ let };
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

// Define and object called variable with name and value of variable

class Variable {
public:
	string name;
	double value;
};

//------------------------------------------------------------------------------

// Vector table to store variable values

vector<Variable> var_table;

//------------------------------------------------------------------------------

// Look up a variable by name in the var_table and return the value

double get_value(string s)
{
	for (const Variable& v : var_table)
		if (v.name == s) return v.value;
	error("get: undefined variable ", s);
}

//------------------------------------------------------------------------------

// update a variable's value

void set_value(string s, double d)
{
	for(Variable& v:var_table)
		if (v.name == s) {
			v.value = d;
			return;
		}
	error("set: undefined variable ", s);
}

//------------------------------------------------------------------------------

// is the varible name already in the var_table?

bool is_declared(string var)
{
	for (const Variable& v : var_table)
		if (v.name == var) return true;
	return false;
}

//------------------------------------------------------------------------------

// Add a variable to the table

double define_name(string var, double val)
{
	if (is_declared(var)) error(var, " declared twice");
	var_table.push_back(Variable{ var,val });
	return val;
}

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// Grammer rule to understand declarations, assumes we have seen "let", handle: name=expression, declare a variable called "name" with the initial value "expression"

double declaration()
{
	Token t = ts.get();
	if (t.kind != name)error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=')error("= missing in declaration of ", var_name);

	double d = expression();
	define_name(var_name, d);
	return d;
}

//------------------------------------------------------------------------------

// High level grammer to handle either declaration or expressions

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
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
		return get_value(t.name);
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
	define_name("pi", 3.1415926535);
	define_name("e", 2.7182818284);

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
