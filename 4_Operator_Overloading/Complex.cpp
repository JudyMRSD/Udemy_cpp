//
// Created by Jin Zhu on 10/31/18.
//

#include "Complex.h"


namespace caveofprogramming{
// call getReal() on const c, need to use double getReal() const
ostream &operator<<(ostream &out, const Complex &c){
    out << "(" <<c.getReal() <<","<<c.getImaginary()<<")";
    return out;
}

Complex operator+(const Complex &c1, const Complex &c2){
    return Complex(c1.getReal() + c2.getReal(), c1.getImaginary()+c2.getImaginary());
}
//add compelx with double
Complex operator+(const Complex &c1, double d){
    return Complex(c1.getReal() + d, c1.getImaginary());
}

Complex operator+(double d, const Complex &c1){
    return Complex(c1.getReal() + d, c1.getImaginary());
}

//member of Complex class
bool Complex::operator==(const Complex &other)const{
    return real == other.real && imaginary == other.imaginary;
}
//define (not equal) using (equal)
bool Complex::operator!=(const Complex &other)const{
    // ‘this’ pointer is a constant pointer that holds the memory address of the current object.
    //need to dereference this
    return !(*this==other);
}
//overload dereference operator as conjugate
//conjugate of a complex number is same real, opposite sign for imaginary
Complex Complex::operator*() const{
    return Complex(real, -imaginary);
}




Complex::Complex(): real(0), imaginary(0){

}

Complex::Complex(double real, double imaginary):real(real), imaginary(imaginary){

}

//Copy operator
Complex::Complex(const Complex &other){
    cout<<"Copy"<<endl;
    real = other.real;
    imaginary = other.imaginary;
}

//Assignment operator
const Complex &Complex::operator = (const Complex &other){
    cout<<"assignment operator"<<endl;
    real = other.real;
    imaginary = other.real;
    return *this;
}
}/*namespace caveofprogramming*/
