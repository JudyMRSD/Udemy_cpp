//
// Created by Jin Zhu on 1/27/19.
//

#include <iostream>
using namespace std;

class Test{
private:
    int one{1};
    int two{2};

public:
    void run(){
        int three{3};
        int four{4};
        //auto pLambda = [this, &]()      & pass local variables by reference
        //use this to capture all instance variables: one, two
        auto pLambda = [this, three, four](){
            cout<< one <<endl;
            cout<< two <<endl;

            cout<< three <<endl;
            cout<< four <<endl;

        };
        //call the lambda function
        pLambda();
    }
};

int main(){
    Test test;
    test.run();
    return 0;
}