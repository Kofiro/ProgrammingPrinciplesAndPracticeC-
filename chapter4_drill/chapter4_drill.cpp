

#include "std_lib_facilities.h"

int main() {

    
    double num;
    //vector<double> nums;
    //double smaller_num = 0.0;
    //double larger_num = 0.0;
    double smallest_sofar = 100000.0;
    double largest_sofar = 0.0;
    string unit;
    int count = 0;
    double sum = 0.0;
    while(cin >> num >> unit) {
        // Drill 1.
        if (num == '|') {
            
            
        
            break;
        }

        // Drill 7. cin >> num >> unit
        cout << "Your entered " << num << unit << "\n";
        if(unit == "cm") {
            cout << "num " << num  << unit << " == " << (num / 100) << "m" << '\n';
        } else if (unit == "m") {
            cout << "num " << num  << unit << " == " << (num * 100) << "cm" << '\n';
        } else if (unit == "in") {
            cout << "num " << num  << unit << " == " << (num * 2.54) << "cm" << '\n';
        } else if(unit == "ft") {
             cout << "num " << num  << unit << " == " << (num * 12) << "in" << '\n';
        }

        if(unit == "y" || unit == "yard" || unit == "meter" || unit == "km" || unit == "gallons" || unit == "") {
            cout << "Does not accept these as proper unit representations" << '\n';
        }

        // Drill .9
        count += 1;
        sum += num;


        // Drill 6.
        if(num < smallest_sofar) {
            smallest_sofar = num;

            //cout << "Num " << num  << " is smallest so far " << '\n'; 
        } else if (num > largest_sofar) {
            largest_sofar = num;

            //cout << "Num " << num << " is largest so far" << '\n';
        }
        
        // Dril 1. - 5.
        // nums.push_back(num);

        // if(nums.size() % 2 == 0) {
        //     if(nums[0] < nums[1]) {
        //         smaller_num = nums[0];
        //         larger_num = nums[1];
        //     } else if(nums[0] > nums[1]) {
        //         smaller_num = nums[1];
        //         larger_num = nums[0];
        //     } 
            
        //     if(nums[0] == nums[1]) {
        //         cout << "the numbers are equal" << '\n';
                
        //     } else {
        //         cout << "the smaller value is: " << smaller_num << " and the larger value is : " << larger_num << '\n';
                
        //         double diff = larger_num - smaller_num;
        //         if (diff < (1.0/100)) {
        //             cout << "the numbers are almost equal" << '\n';
        //         }
        //     }

            
        //     // for(int x : nums)
        //     //     cout << "we entered " << x << '\n';
            

        //     nums.clear();
        // }
    }

    cout << "Num " << smallest_sofar  << " is smallest so far " << '\n'; 
    cout << "Num " << largest_sofar << " is largest so far" << '\n';
    cout << "Sum of numbers is " << sum <<  " with total number of values " << count << "\n";
    
    return 0;

}