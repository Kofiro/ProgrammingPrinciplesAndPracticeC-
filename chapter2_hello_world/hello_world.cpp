/**
 * 
 *  g++ compiler command to build and run program
 * 
 * g++ -I "C:\Users\kofir\Documents\C++\Practice" "chapter2_hello_world\hello_world.cpp" -o hello_world  
 */

#include "std_lib_facilities.h"

int main() {
   cout << "Please enter your first name (followed by 'enter'):\n";
   string first_name = "???";
   int age = 0;
   cin >> first_name >> age;
   double ageInMonths = 0;
   string last_name = " Nitsudube";
   ageInMonths = 12 * age; // 12 months = 1 year, 12 * age would equal how many months 
   first_name += last_name;
   cout << "Hello, " << first_name << "(age " << age << ")" << "!\n";
   cout << "You are " << ageInMonths << " months old\n";
   cout << "You did it";
   return 0;
}