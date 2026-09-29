// Chapter5 exceptions

#include "std_lib_facilities.h"


class Bad_area {};

int area(int length, int width) {
    if(length <= 0 || width <= 0) throw Bad_area{};

    return length * width;
}


int framed_area(int x, int y) {
    constexpr int frame_width = 2;
    if(x - frame_width <= 0|| y - frame_width <= 0) return -1;
        //error("non-postive area() argument aclled by framed_area()");
    return area(x - frame_width, y - frame_width);
}

// void error(string s) {
//     throw runtime_error(s);
// }

// void error(string s1, string s2) {
//     throw runtime_error(s1 + s2);
// }

int main() {
    // try {
    //     int x = -1;
    //     int y = 2;
    //     int z = 4;

    //     int area1 = area(x,y);
    //     int area2 = framed_area(1, z);
    //     int area3 = framed_area(y, z);
    //     double ratio = area1/area3;
    // }
    // catch(Bad_area) {
    //     cout << "Oops! bad arguements to area()\n";
    // }
    try {
        vector<int> v;
        for(int x; cin >> x;)
            v.push_back(x);
        
        for(int i = 0; i <= v.size();++i) 
            cout << "v[" << i << "] == " << v[i] << '\n';

       
        
        return 0;

    }
    catch(out_of_range) {
        cerr << "Oops! Range error\n";
    }
    catch(exception& e) {
        cerr << "runtime error: " << e.what() << '\n';
        keep_window_open();
        return 1;   // indicates failure
    }
    catch(...) {
        cout << "Exception: something went wrong. Unknown exception!\n";
        keep_window_open();
        return 2;
    }
    //return 0;
}