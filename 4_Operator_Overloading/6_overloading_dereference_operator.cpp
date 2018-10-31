//
// Created by Jin Zhu on 10/31/18.
//

//overload dereference operator as conjugate
//conjugate of a complex number is same real, opposite sign for imaginary
#include <iostream>
#include "Complex.h"
using namespace std;
using namespace caveofprogramming;

int main(){
    Complex c1(2, 4);
    //overload * for conjugate
    cout <<*c1<<endl;

    cout <<*c1 + Complex(4, 3)<<endl;

    return 0;
}