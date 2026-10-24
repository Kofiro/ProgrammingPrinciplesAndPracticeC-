// chapter 5 exercises

#include "std_lib_facilities.h"

double ctok(double c) {

    // 4.
    if(c < -273.15)
        error("celsius to kelvin error, celsius should be above -273.15");

    // 2.
    // error commented out
    // int k = c + 273.15;
    double k = c + 273.15;

    // error commented out
    //return int
    return k;
}

double ftoc(double f) {
    double c = (f - 32)/(9/5);
    return c;
}

// celsius to fahrenheit converter
double ctof(double c) {

    double f = c * 9/5 + 32.0f;
    return f;
}

// 8. exercise 8
void read_and_store() {
    int total_num = 0;
    cout << "Please enter the number of values you want to sum?" << '\n';
    cin >> total_num;
    vector<int> numbers;

    cout << "\nPlease enter some integers (press '|' to stop):\n";

    for(string num_text; cin >> num_text;) {
        if(num_text == "|") {
            break;
        }

        stringstream ss;
        ss << num_text;
        int num = 0;
        ss >> num;

        numbers.push_back(num);
    }

    // the sum of the first n numbers,  pre-condition check
    if(total_num > numbers.size()) {
        error("User asked for a sum of more numbers than there are in the vector");
    }

    int total_sum = 0;
    for(int i = 0; i < total_num; ++i) {
        total_sum += numbers[i];
    }

    cout << "The sum of the first " << total_num << " numbers (";
    for(int i = 0;i < total_num;++i) {
        cout << " " << numbers[i];
    }
    cout << " ) is " << total_sum;
}

double fibonacci(int id, int max_num) {
    double f[max_num+1];

    f[0] = 0;
    f[1] = 1;

    for(int i = 2; i <= max_num;++i) {
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[id];
    
}


// number generator for bulls and cows

int generate_num() {

    return ((rand() % 9) + 1);
}


void bulls_and_cow() {
    srand(time(NULL));

    vector<int> numbers;

    int num_count = 4;
    
    for(int i = 0; i < num_count;++i) {
        numbers.push_back(generate_num());
    }

    // uncomment for debug purposes
    // for(int x : numbers) 
    //     cout << x;

    int digit_count; // to keep track of digits
    for(int i = 0; i < num_count;++i) {
        digit_count = 0;
        for(int j = 0; j < num_count;++j) {
            if(numbers[i] == numbers[j]) {
                digit_count++;

                // if we have more of this digit
                // generate a new digit
                if(digit_count > 1) {
                    numbers[j] = generate_num();
                    
                    digit_count--;
                    i = j = 0;
                }
            }
        }

        
    }

    // uncomment for debug purposes
    // cout << "Numbers after removing duplicates\n";
    // for(int x : numbers) 
    //     cout << x;
    vector<int> guesses;
    bool guessed_right = false;
    cout << "Guess the numbers\n";

    int bull_count = 0;
    int cow_count = 0;
    int num_of_tries = 0;
    // while we haven't guessed right enter the numbers
    while(!guessed_right) {
        int guess_count = 4;
        for(int num; cin >> num;) {
            guesses.push_back(num);
            guess_count--;
            if(guess_count == 0) {
                bull_count = cow_count = 0;
                cout << "we have four numbers\n";
                for(int i = 0; i < num_count; ++i) {
                    for(int j = 0; j < num_count;++j) {
                        // if indices are the same and both guess and numbers are the same
                        // then we have the correct digit at the right position
                        if(guesses[i] == numbers[j] && i == j) {
                            bull_count++;
                        } else if(i != j && guesses[i] == numbers[j]) {     // we got a right digit but in a wrong position
                            cow_count++;
                        }
                    }
                }
                num_of_tries++;
                if(num_of_tries > 10) {
                    cout << "You were trying to guess the number\n";
                    for(int x : numbers)
                        cout << x;

                    cout << "\ngoodluck\n";
                }
                guesses.clear();
                cout << bull_count << " bull and " << cow_count << " cow\n";
                break;
            }
        }

        if(bull_count == 4) {
            cout << "You guessed all correctly\n";
            cout << "You were trying to guess the number\n";
                    for(int x : numbers)
                        cout << x;

            guessed_right = true;
        }
    }

}


int main() {


    // celsius to kelvin converter
    // double c = 0;
    // // cin >> d;
    // cin >> c;
    
    // double k = ctok(c); // error had ctok("c");
    // cout << k << '\n'; // error had Cout

    //question 8.
    //read_and_store();

    //question 11.
    // int max_count = 10;
    // for(int i = 0; i < max_count; i++) {

    //     cout << fibonacci(i, max_count) << endl;
    // }

    //12.
    bulls_and_cow();

    return 0;
}