//
// Created by Jin Zhu on 10/20/18.
//
#include <iostream>
using namespace std;

class CanGoWrong{
public:
    CanGoWrong(){
        char *pMemory = new char[999999999999999];
        delete[] pMemory;
    }
};

int main(){
    try{
        CanGoWrong wrong;
    }
    catch(bad_alloc &e){
        //what() gets string identifying exception
        cout<<"Caught exception: "<<e.what()<<endl;
    }

    cout<<"Still running"<<endl;
    return 0;
}