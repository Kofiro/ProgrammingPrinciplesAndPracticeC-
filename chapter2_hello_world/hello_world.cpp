/**
 * 
 *  g++ compiler command to build and run program
 * 
 * g++ -I "C:\Users\kofir\Documents\C++\Practice" "chapter2_hello_world\hello_world.cpp" -o hello_world  
 */

#include "../../std_lib_facilities.h"

int main() {
   cout << "Please enter your first name (followed by 'enter'):\n";
   string first_name;
   cin >> first_name;
   cout << "Hello, " << first_name << "!\n";
   cout << "You did it";
   return 0;
}