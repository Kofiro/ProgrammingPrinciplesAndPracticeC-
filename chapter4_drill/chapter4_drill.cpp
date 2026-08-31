

#include "std_lib_facilities.h"

int main() {

    
    double num;
    vector<double> nums;
    double smaller_num;
    double larger_num;
    while(cin >> num) {
        if (num == '|') {
            break;
        }
        
        nums.push_back(num);

        if(nums.size() % 2 == 0) {
            if(nums[0] < nums[1]) {
                smaller_num = nums[0];
                larger_num = nums[1];
            } else if(nums[0] > nums[1]) {
                smaller_num = nums[1];
                larger_num = nums[0];
            } 
            
            if(nums[0] == nums[1]) {
                cout << "the numbers are equal" << '\n';
                
            } else {
                cout << "the smaller value is: " << smaller_num << " and the larger value is : " << larger_num << '\n';
                
                double diff = larger_num - smaller_num;
                if (diff < (1.0/100)) {
                    cout << "the numbers are almost equal" << '\n';
                }
            }

            
            // for(int x : nums)
            //     cout << "we entered " << x << '\n';
            

            nums.clear();
        }
    }
    return 0;
}