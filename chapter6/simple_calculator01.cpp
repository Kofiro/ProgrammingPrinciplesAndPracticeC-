// chapter 6; Writing a program
// simple calculator


// The grammer is used when parsing the calculators input
// a token is a sequence of characters 
// parsing is reading a stream of tokens in accordance to a grammar (done by a parser or a syntax analyzer)
// Grammar for our simple calculator is below
// Expression -> Term; Expression '+' Term; Expression '-' Term;
// Term -> Primary; Term * Primary; Term / Primary; Term % Primary;
// Primary -> Number; "(" Expression ")";
// Number -> a floating point literal?

#include "std_lib_facilities.h"

// user-defined type
// class token, represents operators, numeric values such as 42 and 3.14 and parenthesis
// a class to represent the "kind" of token and the value it has
class Token {
public:
    char kind;
    double value;
    Token(char ch): kind(ch), value(0) {}
    Token(char ch, double val): kind(ch), value(val) {}
    Token(){}
};

class Token_stream {
public:
             // make a Token_stream that reads from cin
    Token get();            // get a Token
    void putback(Token t);  // put a Token back

private:
    
    bool full {false};  // is there a Token in the buffer?
    Token buffer;   // here is where we keep a Token put back using putback()
};

Token Token_stream::get(){
    if(full) {          // do we already have a Token ready?
        full = false;   
        return buffer;  // remove Token from buffer
    }
    char ch;
    cin >> ch;  // >> skips whitespace(space, newline, tab,etc.)
    switch(ch) {
        case ';': // for "print"
        case 'q': // for "quit"
        case '(': case ')': case '+': case '-': case '*': case '/':
            return Token(ch);
        case '.':   // for decimals e.g 1.4, 2.2, etc.
        case '0': case '1': case '2': case '3': case '4': 
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);    // put digit back into input stream
            double val;
            cin >> val;
            return Token('8', val);
        }
        default:
            error("Bad token");
    }
}
void Token_stream::putback(Token t) {
    if(full) error("putback() into a full buffer");
    buffer = t;     // copy t to buffer
    full = true;    // buffer is now full
}




double expression();
double term();
double primary();
//Token get_token();

Token_stream ts;

int main() {
    
    try {
        double val = 0;
        while(cin) {
            //cout << "=" << expression() << '\n';
            Token t = ts.get();

            if(t.kind == 'q') break;    // 'q' for quit

            if(t.kind == ';')   // ';' for "print now"
                cout << "=" << val << '\n';
            else
                ts.putback(t);
            val = expression();
        }
        keep_window_open();
    } catch(exception& e) {
        cerr << e.what() << '\n';
        keep_window_open();
        return 1;
    } catch(...) {
        cerr << "exception\n";
        keep_window_open();
        return 2;
    }
    

    return 0;
}


// read characters and compose tokens
// Token get_token() {
//     char ch;
//     cin >> ch;  // >> skips whitespaces

//     switch(ch) {
//         case '(': case ')':case '+': case '-': case '*': case '/':
//             return Token(ch);
//         case '.':
//         case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
//         {
//             cin.putback(ch);    // put digit back into the input stream
//             double val;
//             cin >> val;         // read a floating point number
//             return Token('8', val); // let '8' represent a number
//         }
//         default:
//             error("Bad token");
//     }
// }


// deal with numbers and parenthesis
double primary() {
    Token t = ts.get();
    switch(t.kind) {
        case '(':   // handle '(' expression ')'
            {
                double d = expression();
                t = ts.get();
                if(t.kind!=')') error("')' expected");
                return d;
            }
        case '8':       // we use '8' to represent a number
            return t.value; // return the number's value
        default:
            error("primary expected");
    }
}


// deal with *,/ and %
double term() {
    double left = primary();
    Token t = ts.get();
    while(true) {
        switch(t.kind) {
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
            // case '%':                // eliminate for future addition
            //     left %= primary();
            //     t = get_token();
            //     break;
            default:
                ts.putback(t);
                return left;
        }
    }
}



// deal with + and -
double expression() {
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
