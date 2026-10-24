// Chapter 5 pre and post conditions

#include "std_lib_facilities.h"

int area(int length, int width) {
    if(length <= 0 || width <= 0) error("area() pre-condition");
    int a = length * width;
    if(a <= 0) error("area() post-condition");
    return a;
}

int main() {

    // this passes the pre-condition but fails the post-condition
    //int areaReturned = area(INT_MAX, 2);


    int areaReturned = area(1, 3);

    cout << "Area returned is " << areaReturned << "\n";

    return 0;
}