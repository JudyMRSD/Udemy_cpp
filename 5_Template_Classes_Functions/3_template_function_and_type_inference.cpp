//
// Created by Jin Zhu on 11/1/18.
//
#include <iostream>
using namespace std;

template<class T>
void print(T n){
    cout <<"Template version: "<<n<<endl;
}

void print(int value){
    cout<<"Non template version"<<value<<endl;
}

template<class T>
void show(){
    cout<<T()<<endl;
}
int main(){
    /*
     * case 1: function has input argument, c++ will do type inference
     */
    print<string>("Hello");//template version
    print("Hi there");//template version

    //<> indicate use a template version, c++ will do type inference
    print<int>(5);
    print<>(6);
    //without<> use non template version if both template and non template exist
    print(6);

    /*
     * case 2: no input argument, c++ cannot do type inference
     */
    //show();  //does not work
    show<double>();

    return 0;
}