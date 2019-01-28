//
// Created by Jin Zhu on 1/27/19.
//
#include <iostream>
using namespace std;

class Test{
    //default value
    int id{3};
    string name{"Mike"};

public:
    //create default constructor
    Test() = default;
    //copy constructor
    Test(const Test&other) = default;
    Test &operator=(const Test &other) = default;
    //overwrite with implicit
    Test(int id):
        id(id){
    }
    void print(){
        cout<< id <<" : "<<name<<endl;
    }
};

int main(){
    Test test;
    test.print();

    Test test1(77);
    test1.print();
    //copy constructor
    Test test2 = test1;
    //assignment
    test2 = test;
    return 0;
}

