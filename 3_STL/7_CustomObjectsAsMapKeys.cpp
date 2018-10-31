//
// Created by Jin Zhu on 10/21/18.
//
#include <iostream>
#include <map>
using namespace std;

class Person{
private:
    string name;
    int age;
public:
    //when you define your own constructor
    //the constructor without parameter also need to be defined, otherwise will have error "no matching constructor for initialization of 'Person'"
    Person(): name(""), age(0){

    }
    //constructor that accepts inputs
    Person(string name, int age):
            name(name), age(age){
    }
    //copy constructor
    Person(const Person& other){
        name = other.name;
        age = other.age;
    }
    //const: print cannot change the instance variables
    void print() const {
        cout<< name << " : "<< age <<flush;
    }
    //the operator should not modify the current Person object (const function): The idea of const functions is not allow them to modify the object on which they are called.
    //nor the other Person object that is passed in (const Person &other)
    bool operator<(const Person &other)const{
        if (name == other.name){
            return age < other.age;
        }else{
            return name < other.name;
        }
    }
};

int main(){

    map<Person, int> people;
    people[Person("Mike", 40)] = 40;// assign operator `= ` is a shallow copy
    people[Person("Mike", 333)] = 30;// updated the value in map
    people[Person("Sue", 30)] = 30;
    people[Person("Raj", 20)] = 20;

    //traverse in the order of keys 1, 2, 50
    for(map<Person, int>::iterator it = people.begin(); it!=people.end(); it++){
        cout << it->second<<"---"<<flush;
        it->first.print();
        cout<<endl;
    }
    return 0;
}

