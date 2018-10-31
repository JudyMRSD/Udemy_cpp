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
        cout<<" Copy Constructor Running "<<endl;
        name = other.name;
        age = other.age;
    }

    void print(){
        cout<< "key " <<name << " : val "<< age <<endl;
    }
};

int main(){
    map<int, Person> people;
    people[50] = Person("Mike", 40);// assign operator `= ` is a shallow copy
    people[1] = Person("Raj", 30);
    people[2] = Person("Vicky", 20);

    people.insert(make_pair(55, Person("Bob", 45)));//deep copy

    //traverse in the order of keys 1, 2, 50
    for(map<int, Person>::iterator it = people.begin(); it!=people.end(); it++){
        cout << it->first<<"---"<<flush;
        it->second.print();
    }
    return 0;
}

