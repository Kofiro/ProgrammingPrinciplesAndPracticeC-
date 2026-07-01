/**
 * 
 *  compile command
 *  g++ -I "C:\Users\kofir\Documents\C++\Practice\ProgrammingPrinciplesAndPracticeC++\res" "chapter4_statem_func\chapter4_statem_func.cpp" -o "bin\chapter4_statm_func.exe"
 */



#include "std_lib_facilities.h"

int main() {

    constexpr double cm_per_inch = 2.54;
    constexpr double yen_per_dollar = 0.0062;   // number of yen in a dollar
    constexpr double kroner_per_dolllar = 0.10;
    constexpr double pounds_per_dollar = 1.33;

    double currency = 1;
    char unit = 0;

    cout << "Please enter a currency followed by a unit (y, k or p, u for usdollar) for yen, kroner or pounds:\n";
    cin >> currency >> unit;
    // if(unit == 'y')
    //     cout << currency << "yen to dollars " << yen_per_dollar * currency << " dollars\n";
    // else if(unit == 'k')
    //     cout << currency << "kroner to dollars " << kroner_per_dolllar * currency << " dollars\n";
    // else if(unit == 'p')
    //     cout << currency << "pounds to dollars " << pounds_per_dollar * currency << " dollars\n";
    // else 
    //     cout << "Sorry don't know this unit\n";

    switch(unit)
    {
        case 'y':
            cout << currency << "yen to dollars " << yen_per_dollar * currency << " dollars\n";
            break;
        case 'k':
            cout << currency << "kroner to dollars " << kroner_per_dolllar * currency << " dollars\n";
            break;
        case 'p':
            cout << currency << "pounds to dollars " << pounds_per_dollar * currency << " dollars\n";
            break;
        default:
            cout << "Sorry don't know this unit\n";
            break;
    }

    return 0;
}