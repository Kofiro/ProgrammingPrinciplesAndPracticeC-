/**
 * 
 *  compile command
 *  g++ -I "C:\Users\kofir\Documents\C++\Practice\ProgrammingPrinciplesAndPracticeC++\res" "chapter4_iteration\chapter4_iteration.cpp" -o "bin\chapter4_iteration.exe"
 */



#include "std_lib_facilities.h"

int square(int i) {
    return i * i;
}

// implementing square without using the multiplication operator
int custom_square(int x) {
    int result = 0;
    for(int i = 0; i < x; ++i) {
        result += x;
    }
    return result;
}

int main() {

    char a = 'a';
    int alphabet_count = 26;
    //int i = 0;
    char a_char = 'a';
    // while(i < alphabet_count) {
    //     cout << (char)(a_char + i) <<  '\t' << (int)(a_char + i) << '\n';
    //     ++i;
    // }
    for(int i = 0; i < alphabet_count;++i)
        cout << (char)(a_char + i) <<  '\t' << (int)(a_char + i) << '\n';

    int num = 5;
    cout << "Square of " << num << " = " << custom_square(num) << '\n'; 

    return 0;
}