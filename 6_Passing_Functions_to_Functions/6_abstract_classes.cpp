//
// Created by Jin Zhu on 11/1/18.
//
#include <iostream>
using namespace std;
//class containing pure virtual function is an abstract class
//cannot instantiate abstract class
class Animal{
public:
    //pure virtual : no implementation
    //Pure virtual function must be declared ending with "= 0" and it can only be declared in abstract class.
    virtual void speak() = 0;
    virtual void run() = 0;
};

//Dog is abstract class, since it hasn't provided
//concrete implementation for ALL the virtual function
class Dog: public Animal{
public:
    virtual void speak(){
        cout<<"Woof!"<<endl;
    }

};

//concrete implementation for ALL the virtual function
class Labrador: public Dog{
public:
    Labrador(){
        cout<<"new labrador"<<endl;
    }
    virtual void run(){
        cout<< "Labrador running"<<endl;
    }
};


void test(Animal &a){
    a.run();
}
int main(){
    //cannot instantiate abstract class
    // Animal animal;
    // Dog dog;
    Labrador lab;
    lab.run();
    lab.speak();

    Labrador labs[5];

    //Can create an array of pointers to objects for an abstract class.
    Animal *animals[5];
    animals[0] =  &lab;

    animals[0]->speak();

    test(lab);//polymorphism, calls the corresponding subclass
    return 0;
}