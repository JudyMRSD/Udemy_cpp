//
// Created by Jin Zhu on 11/1/18.
//
#include <iostream>
using namespace std;

//declare a pointer to a function (instead of a pointer to a variable)
//virtual table is a table of function pointers
void test(){
    cout<< "Hello" <<endl;
}

void test2(int value){
    cout<< "Hello" <<value<<endl;
}

int main(){
    test();
    /*
     This is what's actually going on:

    //a pointer to a function with void return and no parameters
    void (*pTest)();
    //address symble &   name of function   don't need () since () is for calling a function
    pTest = &test;
    //call the function by dereference it , use () operator to call the function
    //(*pTest) dereference function first , then call it
    (*pTest)();


     */

    /*
     * simplified syntax
     *
     //name of a function is a pointer to a function
    pTest = test;//the name of a function is a pointer to that function
    pTest();//do not need to dereference, since if you are calling a function, it's not ambiguous that it needs to be dereferenced
     */

    //initialize when declaring it
    void(*pTest)() = test;
    void(*pTest2)(int) = test2;


    pTest();
    pTest2(5);

    return 0;
}