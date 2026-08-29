/**
 * 
 *  g++ compiler command to build and run program
 * 
 *
 * 
 *  g++ -I "C:\Users\kofir\Documents\C++\Practice\ProgrammingPrinciplesAndPracticeC++\res" "chapter3_objects_types_values\objects_types.cpp" -o "bin\objects_types.exe"
 */


//#include "../../std_lib_facilities.h"; used to be in a grandparent directory
#include "std_lib_facilities.h"

int main() {
   // double x {2.7};
    // int y {x}; error int might narrow; double x = 2.7 would have allowed this but with {} compiler gives warning
   // string previous = " ";
   // string current;
   // int number_of_words = 0;
   // while (cin >> current) {
   //  ++number_of_words;
   //  if(previous == current)
   //      cout << "word number " << number_of_words 
   //           << " repeated word: " << current << '\n';
   //  previous = current;
   //}

   cout << "Input your operation and operands in the format + num num or operation operand operand \n";
   char symbol = ' ';
   float op1 = 0.0f;
   float op2 = 0.0f;

   cin >> symbol;
   cin >> op1;
   cin >> op2;

   float result;

   if(symbol == '+') {
      result = op1 + op2;
   } else if(symbol == '-') {
      result = op1 - op2;
   } else if (symbol == '*') {
      result = op1 * op2;
   } else if (symbol == '/') {
      result = op1 / op2;
   }

   cout << "Your result is " << result << '\n';

   return 0;
}