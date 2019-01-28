//
// Created by Jin Zhu on 1/27/19.
//
#include <iostream>
using namespace std;

//lambda expression is compatible with function pointers
//         func has a void return type
void test(void (*pFunc)()){
    pFunc();
}

int main(){
    //lambda expression,  anonymous function
    //    [](){code};
    //func stores the reference to this anonymous funcction
    auto func = [](){cout<<"Hi"<<endl;};
    func();
    //pass a lambda function to a function
    test(func);
    //directly pass the lambda function to a function
    test([](){cout<<"Hi"<<endl;});
    return 0;
}
