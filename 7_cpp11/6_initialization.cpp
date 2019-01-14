#include <iostream>
#include <vector>
using namespace std;

int main(){
    int value{5};
    cout <<value <<endl;

    string text{"hello"};
    cout<< text <<endl;

    //array initialize use {}
    int numbers[]{1,2,3};
    cout<<numbers[1]<<endl;

    //initialize use new
    int *pInts = new int[3]{7,9,8};
    cout<<pInts[1]<<endl;
    delete pInts;


    //initialize to default value , 0 for int, empty string for string
    int value1{};
    cout<<value1<<endl;

    int *pSomething{&value};
    cout<<"*pSomething"<<*pSomething<<endl; //dereference


    int *pSomething2{};//equivalent to int* pSomething = nullptr
    cout<<pSomething2<<endl;

    int numbers1[5]{};
    cout<<numbers1[1]<<endl;//initialize to zeros

    //initialize struct
    struct{
        int value;
        string text;
    }s1{5, "Hi"};

    //initialize vector
    vector<string> strings{"one","two"};
    cout<<strings[2]<<endl;
    return 0;
}

