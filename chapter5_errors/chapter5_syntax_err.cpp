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
    if(length <= 0 || width <= 0) error("non-positive area() argument");
    return length * width;
}

int framed_area(int x, int y) {
    constexpr int frame_width = 2;
    if(x - frame_width <= 0|| y - frame_width <= 0)
        error("non-postive area() argument aclled by framed_area()");
    return area(x - frame_width, y - frame_width);
}

int main() {

    int x = -1;
    int y = 2;
    int z = 4;

    if(x <= 0) error("non-positive x");
    if(y <= 0) error("non-positive y");

    int area1 = area(x, y);

    if(z <= 2)
        error("non-positive 2nd area() argument called by framed_area()");
    int area2 = framed_area(1, z);
    if(y <= 2||z <= 2)
        error("non-positive area() argument called by framed_area()");

    int area3 = framed_area(y, z);
    double ratio = double(area1)/area3;

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
