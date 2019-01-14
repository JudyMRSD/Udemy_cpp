//
// Created by Jin Zhu on 11/1/18.
//

#include <iostream>
using namespace std;
/*  without virtual keyword in parent
class Parent{
public:
    void print(){
        cout << "parent" <<endl;
    }
};

class Child: public Parent{
public:
    void print(){
        cout<<"child"<<endl;
    }
};

int main(){
    Child c1;
    Parent &p1 = c1;
    p1.print();//parent,  since there is no virtual keyword

    return 0;
}
*/


class Parent{
private:
    int one;
public:

    //when define copy constructor, we loose the default constructor
    //child class needs to run the constructor of the parent class
    //in order to be instantiated
    Parent(): one(0){
        cout<<"default constructor"<<endl;
    }
    //copy constructor
    Parent(const Parent &other): one(0){
        one = other.one; //cannot copy two here, object slicing:  the part of child (member two) is sliced away
        cout<<"copy parent"<<endl;
    }
    /*
     * A virtual function a member function which is declared within base class
     * and is re-defined (Overriden) by derived class.
     */
    virtual void print(){
        cout << "parent" <<endl;
    }

};

class Child: public Parent{
private:
    int two;
public:
    Child(): two(0){
        cout<<"constructor child"<<endl;
    }
    void print(){
        cout<<"child"<<endl;
    }
};

int main(){
    Child c1;
    Parent &p1 = c1;//correct method will be called for the corresponding object
    p1.print();//prints child

    //A copy constructor is a member function which initializes an object using another object of the same class. 
    //copy constructor is called When an object is constructed based on another object of the same class
    //upcasting a child object to parent object
    Parent p2 = Child();//copy initialization, two get sliced away
    p2.print();

    return 0;
}