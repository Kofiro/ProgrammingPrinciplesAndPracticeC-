// Chapter 5.7 Logic Errors

#include "std_lib_facilities.h"

int main() {

    vector<double> temps;

    for(double temp; cin>> temp;)
        temps.push_back(temp);

    double sum = 0;
    double high_temp = 0;
    double low_temp = 0;

    for(int x : temps) {
        if(x > high_temp) high_temp = x;    // find high
        if(x < low_temp) low_temp = x;  // find low
        sum += x;                       // compute sum
    }

    cout << "High temperature: "  <<  high_temp << '\n';
    cout << "Low temperature: " << low_temp << '\n';
    cout << "Average temperature: " << sum/temps.size() << '\n';

    return 0;
}