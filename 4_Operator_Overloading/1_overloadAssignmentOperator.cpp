#include <iostream>
using namespace std;


class Test{
private:
    int id;
    string name;
public:
    Test(): id(0), name(""){

    }

    Test(int id, string name): id(id), name(name){

    }

    void print(){
        cout<<id<<": "<<name<<endl;
    }
    //without operator overloading, c++  = is by default shallow copy
    //name : operator=
    //return type: const reference    const Test &
    const Test &operator=(const Test &other){
        cout<<"Assignment running"<<endl;

        id = other.id;
        name = other.name;

        return *this;//*this    dereference this
    }

    Test(const Test &other){
        cout<<"Copy constructor running"<<endl;
        //use the custom assignment operator
        *this = other;
    }
};


int main() {
    Test test1(10, "Mike");
    test1.print();

    Test test2(20, "Bob");

    test2 = test1;
    cout<<"Print test2: "<<flush;

    test2.print();

    Test test3;
    //name : equals operator =
    //return type: const reference   e.g. test3 = test2 = test1  the value should not change during this chaining
    test3.operator=(test2);//test3 = test2
    cout<<"Print test3: "<<flush;
    test3.print();

    cout<<endl;

    //= copy initialization , implicit copy constructor
    //create an object and do not give it an initial value, just immediately assign an already declared value
    Test test4 = test1;
    test4.print();

    return 0;
}