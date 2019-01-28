//
// Created by Jin Zhu on 1/27/19.
//

#include <iostream>
using namespace std;

void testGreet(void (*greet)(string)){
    greet("Bob");
}

void runDivide2(double (*divide)(double a, double b)){
    auto rval = divide(9, 3);
    cout << rval << endl;
}
int main(){
    auto pGreet = [](string name){cout<<"hi"<<name<<endl;};
    pGreet("Mike");

    testGreet(pGreet);
    //c++ can refer return type for lambda expression
    auto pDivide = [](double a, double b){
        return a/b;
    };

    //two different return types: return 0 (int)  vs return a/b (double)
    //need to specify return type as    trailing return type  ->double
    auto pDivide2 = [](double a, double b) -> double{
        if(b == 0.0){
            return 0;
        }
        return a/b;
    };

    cout<< pDivide(10.0, 5.0)<<endl;

    cout<< pDivide2(10.0, 0) <<endl;

    runDivide2(pDivide);

    return 0;
}
