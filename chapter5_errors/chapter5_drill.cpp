// chapter 5 drill

#include "std_lib_facilities.h"

int main() {

    try {
        // code here

        // 13.
        // vector<char> v(5); 
       
        // for (int i=0;i<v.size(); ++i) 
        //     cout << "Success!\n";
        

        // 15.
        // string s ="Success!\n"; 
        // for (int i=0; i<=6; ++i) 
        //     cout << s[i];

        string s = "Success!\n"; 
        for (int i=0; i<10; ++i) cout << s[i];

        keep_window_open();

        return 0;
    }
    catch(exception& e) {
        cerr << "error: " << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch(...) {
        cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2;
    }


    return 0;
}