//
// Created by Jin Zhu on 10/31/18.
//
#include <iostream>
using namespace std;
// cpp need to see class definition and implementation together
// better to define the template classes without header file
template<class T>

class Test{
private:
    T obj;
public:
    Test(T obj){
        this->obj = obj;
    }
    void print(){
        //assume type T is defined for cout <<   <<endl
        cout << obj << endl;
    }
};

int main(){
    Test<string> test1("Hello");
    test1.print();
}

