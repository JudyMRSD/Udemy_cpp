//
// Created by Jin Zhu on 11/1/18.
// same concept as 2_Example_Use_Function_Pointers, just a simpler code

#include<stdio.h>
using namespace std;

void A()
{
    printf("Hello");
}
//ptr takes no input and return void
// void(*ptr)()  is a pointer to a function
void B(void(*ptr)())
{
    //do not need to dereference, since if you are calling a function, it's not ambiguous that it needs to be dereferenced
    //(*ptr)();//also works
    ptr();//call-back function that "ptr" points to

}

int main(){
    void (*p)() = A;//declare a function pointer that takes no input and return void
    B(p);

    //this one statement is same as the previous 2
    //name of a function returns a pointer
    B(A);
}

