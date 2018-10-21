//
// Created by Jin Zhu on 10/20/18.
//

// bad_alloc is a subclass of standard exception class
#include <iostream>
#include <exception>
using namespace std;


void goesWrong(){
    bool error1Detected = true;
    bool error2Detected = false;

    if(error1Detected){
        throw bad_alloc();
    }
    //if error1Detected ==false, the following will run
    if(error2Detected){
        throw exception();
    }

}



int main(){
    try{
        goesWrong();
    }
    //need to catch subclass before catch parent class
    /*
     * If both base and derived classes are caught as exceptions
     * then catch block of derived class must appear before the base class.
     *
     * If we put base class first then the derived class catch block will never be reached.
     * because of polymorphism, the base class bad_alloc IS of class exception, catch(exception &e)
     * will be executed if the code is before catch(bad_alloc &e)
    */
    catch(bad_alloc &e){
        cout<<"Catching bad alloc"<<e.what()<<endl;
    }
    //parent class excepetion
    catch(exception &e){
        cout<<"Catching exception: "<<e.what()<<endl;
    }

    return 0;
}

