//
// Created by Jin Zhu on 11/4/18.
//
#include <iostream>
#include <typeinfo> //to use typeid
using namespace std;

int main(){
    int value;
    cout<<typeid(value).name()<<endl;//i  stands for integer
    /*
     * Since C++ supports function overloading, additional information
     * has to be added to function names (called name mangling)
     * to avoid conflicts in binary code.
     */
    string value2;
    cout<<typeid(value2).name()<<endl;//NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE


    /*
     * decltype : declear variables of an existing type
     * decltype(value) return string type
     */
    decltype(value2) name = "Bob";//string name = "Bob"

    cout<<typeid(value).name()<<endl;
    cout<< name <<endl;
}