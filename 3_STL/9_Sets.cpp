#include <iostream>
#include <set>
using namespace std;
/*
 * set of integers
 */
void test_set(){
    set<int> numbers;//set only stores unique elements

    numbers.insert(30);
    numbers.insert(20);
    numbers.insert(20);

    for(set<int>::iterator it = numbers.begin(); it!=numbers.end(); it++){

        cout<< *it <<endl;
    }

    //check if an element is in the set
    set<int>::iterator itFind = numbers.find(30);

    if(itFind != numbers.end()){
        cout<<"Found: "<< *itFind <<endl;
    }

    //count will only be 0 or 1 for set
    if(numbers.count(30)){
        cout<<"Number found"<<endl;
    }

}
/*
 * set of custom objects
 */
class Test{
    //Immutable objects should be const-qualified
    int id;
    string name;
public:
    //default constructor
    Test(): id(0), name(){
    }
    Test(int id, string name): id(id), name(name){
    }
    //print should not modify instance variables
    void print() const {
        cout<< id << ": "<< name<<endl;
    }

    //overloat operator < , since Set is ordered

    //const &Test
    //use const since we don't want to modify the object that's passed in
    //use & because we don't want to copy the object when we pass it in


    //the second const here: it doesn't modify the objects it's called on
    //operator== is not used by std::set. Elements a and b are considered equal iff !(a < b) && !(b < a)
    bool operator<(const Test &other) const{
        // < is implemneted for strings
        return name < other.name;
    }
};


void test_custom_set(){
    set<Test> tests;
    tests.insert(Test(10, "Mike"));
    tests.insert(Test(222, "Mike"));//this insert won't happen, since the the two strings(keys) are equal
    for(set<Test>::iterator it = tests.begin(); it!=tests.end(); it++){
        //If the set object is const-qualified, the function returns a const_iterator. Otherwise, it returns an iterator.
        it->print();
    }
}

int main(){
    test_set();
    test_custom_set();
    return 0;
}