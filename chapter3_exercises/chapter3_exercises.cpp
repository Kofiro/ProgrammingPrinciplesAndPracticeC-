/**
 * 
 *  compile command
 *  g++ -I "C:\Users\kofir\Documents\C++\Practice\ProgrammingPrinciplesAndPracticeC++\res" "chapter3_exercises\chapter3_exercises.cpp" -o "bin\chapter3_exe.exe"
 */



#include "std_lib_facilities.h"

int main() {

    cout << "Enter 3 integer values to be ordered\n";
    int first_val = 0;
    int second_val = 0;
    int third_val = 0;
    int numCount = 0;
    int current_val = 0;
    int smallest = 0;
    int largest = 0;
    int temp_num = 0;
    while ( numCount < 3) {
        cin >> current_val;
        ++numCount;
    
        if(current_val > largest) {
            // we set the smallest variable once (that's if numCount < 2) makes sure it runs only once when numCount = 2
            // since numCount is pre-incremented with ++numCount
            if(numCount < 2) {  
                smallest = current_val;
            } 
            temp_num = largest;
            largest = current_val;
        } else if (current_val < largest) {
            
            if (current_val > smallest) {
                cout << "current_val > smallest\n";
               
                temp_num = current_val;
            }
            else if(current_val < smallest){
                cout << "current_val < smallest\n";
                temp_num = smallest;
                smallest = current_val;
            }
          
        } 

        first_val = smallest;
        second_val = temp_num;
        third_val = largest;
        
        cout << "first val: " << first_val << " second val: " << second_val << " third val: " << third_val << "\n";
       
    }

    cout << "from smallest to largest count is " << first_val << " " << second_val << " " <<  third_val << "\n";
    return 0;
}