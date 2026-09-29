// chapter 5 syntax and type errors

#include "std_lib_facilities.h"


char ask_user(string question) {
    cout << question << "? (yes or no)\n";
    string answer = "";
    cin >> answer;
    if(answer == "y" || answer == "yes") return 'y';
    if(answer == "n" || answer == "no") return 'n';
    return 'b'; // b for bad answer
}

int area(int length, int width) {
    if(length <= 0 || width <= 0) return -1; //error("non-positive area() argument");
    return length * width;
}

int framed_area(int x, int y) {
    constexpr int frame_width = 2;
    if(x - frame_width <= 0|| y - frame_width <= 0) return -1;
        //error("non-postive area() argument aclled by framed_area()");
    return area(x - frame_width, y - frame_width);
}

int f(int x, int y, int z) {

    
    int area1 = area(x, y);
    if(area1 <= 0) error("non-positve area");
    cout << "area1 is " << area1 << " \n";
    int area2 = framed_area(1, z);
    cout << "area2 is " << area2 << "\n";
    

    int area3 = framed_area(y, z);
    cout << "area3 is " << area3 << "\n";
    double ratio = double(area1)/area3;
    cout << "ratio is " << ratio << "\n";
    

    return 0;
}

int main() {

    int x = 3;
    int y = 4;
    int z = 4;

    f(x, y, z);


    // int s1 = area(7, 2);
    // int s2 = area(7, 2);
    // int s3 = area(7, 3);   
    // int s4 = area(7, 1);
    
    // cout << "s4? "  << s4 << " compiled? " << '\n';

    // int x0 = area(7, 3); //arena(7);
    // int x1 = area(7, 2);
    // int x2 = area(5, 2);



    return 0;
}
