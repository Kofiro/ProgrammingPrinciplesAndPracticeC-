// chapter 7; Completing a program
// simple calculator


// The grammer is used when parsing the calculators input
// a token is a sequence of characters 
// parsing is reading a stream of tokens in accordance to a grammar (done by a parser or a syntax analyzer)
// Grammar for our simple calculator is below
// Expression -> Term; Expression '+' Term; Expression '-' Term;
// Term -> Primary; Term * Primary; Term / Primary; Term % Primary;
// Primary -> Number; "(" Expression ")"; -Primary, +Primary
// Number -> a floating point literal?
/**
 * 
 * Revision history:
 *      Revised by Kofi Austin November 2026
 *      Revised by Bjarne Stroustrup May 2007
 *      Originally written by Bjarne Stroustrup 
 *                              Spring 2004
 * 
 * This program implements a basic expression calculator
 * Input from cin; output to cout
 * The grammer for input is:
 * Statement:
 *      Expression
 *      Print
 *      Quit
 * Print:
 *        ;
 * Quit:
 *        q
 * 
 * Expression:
 *      Term
 *      Expression + Term
 *      Expression - Term
 *  
 * Term:
 *      Primary
 *      Term * Primary
 *      Term / Primary
 *      Term % Primary
 * 
 * Primary:
 *      Number
 *      (Expression)
 *      -Primary
 *      +Primary
 * 
 * Number:
 *      floating-point literal
 * 
 * Input comes from cin through the Token_stream called ts.
 */

#include "std_lib_facilities.h"


// a constant to identify if a token is a number or not, if t.kind == number, then it is a number Token
const char number = '8';
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= ";
const char name = 'a';      // name token
const char let = 'L';       // declaration token
const string declkey = "let";   // declaration keyword

// user-defined type
// class token, represents operators, numeric values such as 42 and 3.14 and parenthesis
// a class to represent the "kind" of token and the value it has
class Token {
public:
    char kind;
    double value;
    string name;
    Token(char ch): kind(ch), value(0) {}
    Token(char ch, double val): kind(ch), value(val) {}
    Token(char ch, string n): kind(ch), name(n) {}
    Token(){}
};

class Token_stream {
public:
             // make a Token_stream that reads from cin
    Token get();            // get a Token
    void putback(Token t);  // put a Token back
    void ignore(char c);    // discard characters up to and including char c
private:
    
    bool full {false};  // is there a Token in the buffer?
    Token buffer;   // here is where we keep a Token put back using putback()
};

Token Token_stream::get(){
    //cout << "entered::Token_stream get()\n";
    if(full) {          // do we already have a Token ready?
        full = false;   
        //cout << "Token_stream::buffer is full return buffer's value of " << buffer.value << '\n';
        return buffer;  // remove Token from buffer
    }
    char ch;
    cin >> ch;  // >> skips whitespace(space, newline, tab,etc.)
    switch(ch) {
        case print: // for "print"
        case quit: // for "quit"
        case '(': 
        case ')': 
        case '+': 
        case '-': 
        case '*': 
        case '/': 
        case '!':
        case '{': 
        case '}': 
        case '%':    
        case '=':                   
            return Token(ch);   // let each character represent itself
        case '.':   // for decimals e.g 1.4, 2.2, etc.
        case '0': case '1': case '2': case '3': case '4': 
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);    // put digit back into input stream
            double val;
            cin >> val;
            return Token(number, val);
        }
        default:
            if(isalpha(ch)) {
                string s;
                s += ch;
                while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch;
                cin.putback(ch);
                //cin >> s;
                if(s == declkey) return Token(let);     // declaration keyword
                return Token{name, s};
            }
            error("Bad token");
    }
}
void Token_stream::putback(Token t) {
    if(full) error("putback() into a full buffer");
    buffer = t;     // copy t to buffer
    full = true;    // buffer is now full
}

/// @brief Token_stream's ignore function
/// @param c represents the kind of Token
void Token_stream::ignore(char c) {
    // first, look in buffer
    if(full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    // now search input
    char ch = 0;
    while(cin >> ch){
        if (ch == c) return;
        
    }

}

// Variables for built-in constants as well as giving user a better way of expressing calculations
// 
class Variable {
public:
    string name;
    double value;
};

vector<Variable> var_table;

/// @brief 
/// @param s 
/// @return returns the value of the variable named s 
double get_value(string s) {
    for(const Variable& v: var_table)
        if(v.name == s) return v.value;
    error("get: undefined variable ", s);
}


// set the variable named s to d
void set_value(string s, double d) {
    for(Variable& v : var_table) {
        if (v.name == s) {
            v.value = d;
            return;
        }
    }
    error("set: undefined variable ", s);
}


// a higher production(rule) of the grammar
double statement();
double expression();
double term();
double primary();

int factorial(int num);

void clean_up_mess();

//Token get_token();

Token_stream ts;


void calculate() {
    while(cin) {
        try {
            cout << prompt;
            Token t = ts.get();
            while(t.kind == print) t = ts.get();
            if(t.kind == quit) return;
            ts.putback(t);
            cout << result << statement() << '\n';
        } catch(exception& e) {
            cerr << e.what() << '\n';
            clean_up_mess();
        }
    }
}

int main() {
    
    try {
        cout << "Welcome to our simple calculator.\nPlease enter expressions using floating-point numbers.\n";
        cout << "You can add, subtract, multiply or divide numbers with (+,-,*,/) respectively\n";
        calculate();
        keep_window_open();
    } catch(runtime_error& e) {
        cerr << e.what() << '\n';
        keep_window_open("~~");
        // cout << "Please enter the character ~ to close the window\n";
        // for(char ch; cin >> ch;)
        //     if(ch== '~') return 1;
        return 1;
    } 
    catch(exception& e) {
        cerr << e.what() << '\n';
        keep_window_open("~~");
        return 1;
    } catch(...) {
        keep_window_open("~~");
        return 2;
    }
    

    return 0;
}

void clean_up_mess() {
    cout << "entered::clean_up_mess " << '\n';
    // while(true) {
    //     Token t = ts.get();
    //     if(t.kind == print) return;
    // }
    ts.ignore(print);
}

// deal with numbers and parenthesis
double primary() {
    //cout << "entered::primary()\n";
    Token t = ts.get();
    switch(t.kind) {
        case '(':   // handle '(' expression ')'
            {
                double d = expression();
                t = ts.get();
                if(t.kind!=')') error("')' expected");
                return d;
            }
        // adding curly-brackets as well {}
        case '{':
        {
            double d = expression();
            t = ts.get();
            if(t.kind != '}') error("'}' expected");
            return d;
        }
        
        case number:            // if t.kind == number constant it is a number
            return t.value;     // return the number's value
        case '-':
            return - primary();
        case '+':
            return primary();
        default:
            error("primary expected");
    }

}


// deal with *,/ and %
double term() {
    //cout << "entered::term()\n";
    double left = primary();
    Token t = ts.get();
    while(true) {
        switch(t.kind) {
            case '!': {
            
                left = factorial((int)left);
                t = ts.get();
                break;
                
            }
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/':
            {
                double d = primary();
                if(d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
            case '%':                // added modulo for int and floating-point (fmod, floating-point modulo)
            {
                double d = primary();
                if(d == 0) error ("divide by zero");
                left = fmod(left,d);
                t = ts.get();
                

                // below is the solution if we made it strictly for int values
                // int i1 = narrow_cast<int>(left);
                // int i2 = narrow_cast<int>(primary());
                // if(i2 == 0) error("divide by zero");
                // left = i1%i2;
                // t = ts.get();

                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}



// deal with + and -
double expression() {
    //cout << "entered::expression()\n";
    double left = term(); // read and evaluate an term
    Token t = ts.get();  // get the next token
    while(true) {
        switch(t.kind) {
            case '+':
                left += term(); // evaluate Term and add
                t = ts.get();
                break;
            case '-':
                left -= term(); // evaluate Term and subtract
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;    // finally: no more + or -; return the answer
        }
        
    }
}

// is var already in var_table
bool is_declared(string var) {
    for(const Variable& v: var_table) {
        if(v.name == var) return true;
    }
    return false;
}

// add {var, val} to var_table
double define_name(string var, double val) {
    if(is_declared(var)) error(var, " declared twice");
    var_table.push_back(Variable{var, val});
    return val;
}

// assume we have seen "let"
// handle: name = expression
// declare a variable called "name" with the initial value "expression"
double declaration() {
    Token t = ts.get();
    if(t.kind != name) error ("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if(t2.kind != '=') error("= missing in declaration of", var_name);

    double d = expression();
    define_name(var_name, d);
    return d;
}

double statement() {
    Token t = ts.get();
    switch(t.kind) {
        case let:
            return declaration();
        default:
            ts.putback(t);
            return expression();
    }
}

int factorial(int num) {
    if(num == 0 || num == 1) {
        return 1;
    }
    return num * factorial(num - 1);
}
