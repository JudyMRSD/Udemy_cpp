//
// Created by Jin Zhu on 1/27/19.
//
#include <iostream>
using namespace std;

int main(){
    int one = 1;
    int two = 2;
    int three = 3;
    //[](){cout<<"Hello"<<endl;}  define lambda function    ()  call lambda function
    [](){cout<<"Hello"<<endl;}();

    //capture one and two by value
    [one, two](){cout<<one<<", "<<two <<endl;}();

    //capture all local variables by value use equal sign
    [=](){cout<<one<<", "<<two <<endl;}();

    //capture all local variables by value, but capture three by reference
    [=, &three](){three = 7; cout<<one<<", "<<two <<endl;}();
    cout<<three<<endl;

    //capture all local variables by reference
    [&](){two = 7; cout<<one<<", "<<two <<endl;}();
    cout<<two<<endl;

    //default capture all local variables by reference, capture two and three by value
    [&, two, three](){one = 7; cout<<one<<", "<<two <<endl;}();
    cout<<one<<endl;

    return 0;

}
