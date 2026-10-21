// Chapter 5.7 Logic Errors

#include "std_lib_facilities.h"

int main() {

    constexpr int min_temp = -1000;
    constexpr int max_temp = 1000;
    //vector<double> temps;
    
    double sum = 0;
    double high_temp = min_temp;
    double low_temp = max_temp;
    int no_of_temps = 0;


    for(double temp; cin>> temp;) {
        //temps.push_back(temp);
        ++no_of_temps;  // count temperatures
        sum += temp;
        if(temp > high_temp) high_temp = temp;
        if(temp < low_temp) low_temp = temp;
    }

    // for(int x : temps) {
    //     if(x > high_temp) high_temp = x;    // find high
    //     if(x < low_temp) low_temp = x;  // find low
    //     sum += x;                       // compute sum
    // }

    cout << "High temperature: "  <<  high_temp << '\n';
    cout << "Low temperature: " << low_temp << '\n';
    cout << "Average temperature: " << sum/no_of_temps << '\n';

    return 0;
}