// vectors

#include "std_lib_facilities.h"

int main() {

    // vector<int> v = { 5, 7, 6, 5, 4 };

    // vector<string> philospher = { "Kant", "Plato", "Hume", "Kierkegaard" };

    // vector<int> vi(6);

    // for(int i = 0; i < philospher.size();++i) {
    //     cout << philospher[i] << '\n';
    // }

    // for(int x : v) 
    //     cout << x << '\n';

    // vector<double> temps;
    // for(double temp; cin >> temp;) 
    //     temps.push_back(temp);

    // // compute mean temperature
    // double sum = 0;
    // for (double x: temps) sum += x;
    // cout << "Average temperature: " << sum/temps.size() << '\n';

    // // compute mean
    // sort(temps);
    // cout << "Median temperature: " << temps[temps.size()/2] << '\n';

    vector<string> words;
    for(string temp; cin >> temp;)
        words.push_back(temp);
    cout << "Number of words " << words.size() << '\n';

    sort(words);

    for(int i = 0; i < words.size(); ++i) {
        if(i == 0 || words[i - 1]!=words[i])
            cout << words[i] << "\n";
    }

    return 0;
}