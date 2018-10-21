//
// Created by Jin Zhu on 10/20/18.
//
#include <iostream>
using namespace std;





//need to turn off the padding if we want to write to a file
#pragma pack(push, 1)//align the data in 1 bite
struct Person{
    //Pointers hold memory addresses.
    //string name;//a pointer to the string object is stored in stack, new operator allocates memory on heap
    char name[50];//char array of 50 characters maximum
    int age;//4 bites
    double weight;//8 bites
};
#pragma pack(pop) // turn off pack




int main(){
    //without #pragma pack(push, 1)
    //c++ pads structs to make it more efficient for memory 50 + 4 + 8  + 2 bits extra padding = 64
    cout<< sizeof(Person)<<endl;//50 + 4 + 8 = 62
    return 0;
}