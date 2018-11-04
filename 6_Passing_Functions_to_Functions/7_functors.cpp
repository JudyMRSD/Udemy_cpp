//
// Created by Jin Zhu on 11/4/18.
//

#include <iostream>
using namespace std;




//abstract base class
struct Test{
    //pure virtual function
    virtual bool operator()(string &text)=0;
    virtual ~Test(){}
};
/*
 * struct: all methods and variables public by default
 * class: all methods and variables are private
 */

//function objects: functors
struct MatchTest: public Test{
    //overlad round bracket () operator
    bool operator()(string &test){
        return test == "lion";
    }
};

void check(string text, Test &test){
    if(test(text)){
        cout <<" Text matches ! "<<endl;
    }else{
        cout <<" No Match"<<endl;
    }
}

int main(){
    MatchTest m;
    check("lion", m);

    return 0;
}