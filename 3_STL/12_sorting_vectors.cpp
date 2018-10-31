//
// Created by Jin Zhu on 10/31/18.
//

#include <iostream>
#include <vector>
using namespace std;

class Test{
    int id;
    string name;
public:
    Test(int id, string name): id(id), name(name){}

    void print(){
        cout<< id << ": "<<name<<endl;
    }

    /*Method 1. overloading < operator
     //the method is const: doesn't change instance variables
    //input is const: const Test& other
    bool operator<(const Test& other) const{
        return name < other.name;
    }
     *
     */
    //friend allows to access private members
    friend bool comp(const Test &a, const Test &b);
};

bool comp(const Test &a, const Test &b){
    //need to access private numbers by putting the function prototype inside
    //the class and use keyword friend
    return a.name < b.name;
}
int main(){
    vector<Test> tests;

    tests.push_back(Test(5, "Mike"));
    tests.push_back(Test(10, "Sue"));
    tests.push_back(Test(10, "Sam"));
    //Method 1. overloading < operator
    //sort(tests.begin(), tests.end());

    //Method 2. use function pointer comp
    sort(tests.begin(), tests.end(), comp);
    //sort first 2 elements
    //sort(tests.begin(), tests.begin()+2, comp);

    for(int i = 0; i<tests.size(); i++){
        tests[i].print();
    }
    return 0;
}
