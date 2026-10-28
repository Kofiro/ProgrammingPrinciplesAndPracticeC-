// chapter 6; Writing a program
// simple calculator

#include "std_lib_facilities.h"

// user-defined type
// class token, represents operators, numeric values such as 42 and 3.14 and parenthesis
// a class to represent the "kind" of token and the value it has
class Token {
public:
    char kind;
    double value;
};

// read characters and compose tokens
Token get_token() {

}


// deal with + and -
double expression() {
    double left = term(); // read and evaluate an term
    Token t = get_token();  // get the next token
    while(true) {
        switch(t.kind) {
            case '+':
                left += term(); // evaluate Term and add
                t = get_token();
                break;
            case '-':
                left -= term(); // evaluate Term and subtract
                t = get_token();
                break;
            default:
                return left;    // finally: no more + or -; return the answer
        }
        
    }
}

// deal with *,/ and %
double term() {
    double left = primary();
    Token t = get_token();
    while(true) {
        switch(t.kind) {
            case '*':
                left *= primary();
                t = get_token();
                break;
            case '/':
            {
                double d = primary();
                if(d == 0) error("divide by zero");
                left /= d;
                t = get_token();
                break;
            }
            // case '%':                // eliminate for future addition
            //     left %= primary();
            //     t = get_token();
            //     break;
            default:
                return left;
        }
    }
}


// deal with numbers and parenthesis
double primary() {
    Token t = get_token();
    switch(t.kind) {
        case '(':   // handle '(' expression ')'
            {
                double d = expression();
                t = get_token();
                if(t.kind!=')') error("')' expected");
                return d;
            }
        case '8':       // we use '8' to represent a number
            return t.value; // return the number's value
        default:
            error("primary expected");
    }
}

int main() {
    cout << "Please enter expression (we can handle +,-,*,and /)\n";
    cout << "add an x to end expression (e.g., 1+2*3x): ";
    int lval = 0;
    int rval;
    cin >> lval;    // read leftmost operand
    if(!cin)error("no first operand");
    for(char op; cin>>op;){  // read operator and right-hand operand repeatedly

        if(op!='x') cin >> rval;
        switch(op) {
            case '+':
                lval += rval;
                break;
            case '-':
                lval -= rval;
                break;
            case '*':
                lval *= rval;   // multiply: lval = lval * rval;
                break;
            case '/':
                lval /= rval;   // divide: lval = lval/rval;
                break;
            default:
                cout << "Result: " << lval << '\n';
                keep_window_open();
                return 0;
        }


    }
    error("bad expression");

    

    return 0;
}