//
// Created by Jin Zhu on 10/31/18.
//

#ifndef INC_4_OPERATOR_OVERLOADING_COMPLEX_H
#define INC_4_OPERATOR_OVERLOADING_COMPLEX_H

#include <iostream>
using namespace std;

namespace caveofprogramming{

class Complex{
private:
    double real;
    double imaginary;

public:
    Complex();
    Complex(double real, double imaginary);
    //copy constructor
    Complex(const Complex &other);
    //equals operator
    const Complex &operator = (const Complex &other);
    //const, will not change the object it's called on
    double getReal() const{
        return real;
    }

    double getImaginary() const{
        return imaginary;
    }

    bool operator==(const Complex &other)const;
    bool operator!=(const Complex &other)const;
    //return a new object of type Complex
    Complex operator*() const;
};

ostream &operator<<(ostream &out, const Complex &c);
//const: 5 + 7 will not change the input 5, 7
Complex operator+(const Complex &c1, const Complex &c2);

//double here doesn't have to be by reference , since double itself is small
Complex operator+(const Complex &c1, double d);

Complex operator+(double d, const Complex &c1);



}/*namespace caveofprogramming*/



#endif
