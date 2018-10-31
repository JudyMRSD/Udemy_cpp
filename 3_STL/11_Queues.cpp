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

    Test(string name): name(name){
        cout<<"constructor called for "<< name << endl;

    }
    ~Test(){
        cout<<"destructor"<<endl;
    }
    void print(){
        cout<< name <<endl;

    }
};


void fill_and_iterate(){
    queue<Test> testQueue; // first in first out
    cout<<"before push Mike"<<endl;
    testQueue.push(Test("Mike"));//destroy original Test("Mike"), and create a shallow copy of it within the stack
    testQueue.push(Test("Sam"));
    cout<<"after push Mike"<<endl;

    while(testQueue.size() > 0){
        Test &test = testQueue.front();
        test.print();
        testQueue.pop();
    }
    cout<<endl;
}



int main(){
    fill_and_iterate();
}
