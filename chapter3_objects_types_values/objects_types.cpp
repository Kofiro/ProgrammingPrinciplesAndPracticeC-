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
   string previous = " ";
   string current;
   while (cin >> current) {
    if(previous == current)
        cout << "repeated word: " << current << '\n';
    previous = current;
   }
   return 0;
}