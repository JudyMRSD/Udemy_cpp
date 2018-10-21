#include <iostream>
using namespace std;


void mightGoWrong(){
    bool error1 = false;//set error to true when something happens
    bool error2 = false;
    bool error3 = true;

    if(error1){
        throw 8;//error code;
    }
    //if error 1 = true, the following will not occur since the function stops once error 1 occured
    if(error2){
        throw "something went wrong error 2";
    }
    if(error3){
        //this is throwing an object
        throw string("Something went wrong error 3");
    }
}

void useMightGoWrong(){
    //error from mightGoWrong() will be thrown to usesMightGoWrong()
    //if mightGoWrong is called directly by main, the error will be thrown to main()
    mightGoWrong();
}


int main() {

    try{
        useMightGoWrong();
    }
    //catch the error code e=8
    catch(int e){
        cout<<"Error code: "<<e <<endl;
    }
    catch(char const * e){
        cout<<"Error message: "<<e<<endl;
    }
    //catch the object with a reference
    catch(string &e){
        cout<<"String error message: "<<e<<endl;
    }

    cout<<"Still running "<<endl;
    return 0;
}