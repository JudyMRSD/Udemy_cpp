//
// Created by Jin Zhu on 10/20/18.
//


#include <iostream>
#include <exception>

using namespace std;

//Derive your exception class from stl exception class
class MyException: public exception{
public:
    //overriding what() method
    //throw() means does not throw an exception
    //const throw() means this method will not throw an exception, allows compiler to optimize the code
    virtual const char* what() const throw(){
        return "Someting bad happened!";
    }
};

class Test{
public:
    void goesWrong(){
        throw MyException();
    }
};

//override what() method
int main(){
    Test test;
    try{
        test.goesWrong();
    }
    catch(MyException &e){
        cout<< e.what()<<endl;
    }
    return 0;
}