//
// Created by Jin Zhu on 10/31/18.
//
#include <iostream>
#include "Complex.h"
using namespace std;
using namespace caveofprogramming;


int main(){
    Complex c1(3, 4);
    Complex c2(2, 3);
    Complex c3 = c1 + c2;

    cout << c1 + c2 <<endl;
    cout << c1 + c2 + c3<<endl;

    //complex + double
    Complex c4(4, 2);
    Complex c5 = c4 + 7;
    cout << c5 <<endl; //(11, 2), added 7 to the real part

    //real + complex
    cout << 3.2 + c4 <<endl;
    return 0;
}