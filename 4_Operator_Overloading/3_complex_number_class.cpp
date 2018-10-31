//
// Created by Jin Zhu on 10/31/18.
//

#include <iostream>
#include "Complex.h"
using namespace std;
using namespace caveofprogramming;

int main(){
    Complex  c1(2,3);
    Complex c2 = c1; //will run the copy constructor
    Complex c3 = c2;

    cout<< c2 << " "<<c3<<endl;
    return 0;
}