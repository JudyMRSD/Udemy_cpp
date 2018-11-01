//
// Created by Jin Zhu on 11/1/18.
//
#include <iostream>
using namespace std;


//void print(int n){
//    cout<< n << endl;
//}


//There is no difference between the keywords class and typename in a type template parameter declaration.
template<class T> //template<typename T>
void print(T n){
    cout << n <<endl;
}


int main(){
    print<string>("Hello");
    print<int>(5);

    //type inference, C++ looks at the argument and infers the type of argument
    print("Hi there");
    return 0;
}