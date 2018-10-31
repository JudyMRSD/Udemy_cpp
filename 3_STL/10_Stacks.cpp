//
// Created by Jin Zhu on 10/31/18.
//

#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

class Test{
private:
    string name;
public:

    vector<int> *vec_p = new vector<int>(3);
    vector<int> vec;
    Test(string name): name(name){
        cout<<"constructor called for "<< name << endl;
        *vec_p = {1, 2, 3};
        vec = {7, 8,  9};
    }
    ~Test(){
        cout<<"destructor"<<endl;
    }
    void print(){
        cout<< name <<endl;
        for(int i = 0; i<vec_p->size(); i++){
            cout<<(*vec_p)[i]<<" ";
        }
        for(int i = 0; i<vec.size(); i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }
};


void fill_and_iterate(){
    stack<Test> testStack; // last in first out
    cout<<"before push Mike"<<endl;
    testStack.push(Test("Mike"));//destroy original Test("Mike"), and create a shallow copy of it within the stack
    cout<<"after push Mike"<<endl;

    /*
     * wrong code: object is destroyed

    Test &test1 = testStack.top();//only store the reference to the existing object that's in the stack
    testStack.pop();//object got destructed
    test1.print();//reference refers to destroyed object
     */

    //iterate through stack by removing elements from it
    while(testStack.size() > 0){
        Test &test = testStack.top();
        test.print();
        testStack.pop();
    }
    cout<<endl;
}

void shallow_copy(){
    //testStack.top() returns a reference to the object that's in the stack
    //= operator: shallow copy, copy values of instance variables into test2
    Test t("Rob");
    stack<Test> testStack;
    testStack.push(t);
    Test test2 = testStack.top();
    test2.print();//4 5 6 17 18 19

    //objects containing pointer members are shallow-copied by default operator=
    *(t.vec_p) = {4,5,6};
    t.vec = {17,18,19};
    cout<<"object t was changed"<<endl;
    t.print();
    Test test3 = testStack.top();
    cout<<"stack holds a copy of object t: deep copy of vec, but a shallow copy of vec_p since it's a pointer"<<endl;
    test3.print();//4 5 6 7 8 9

    cout<<endl;

}
int main(){
    fill_and_iterate();
    shallow_copy();

}
