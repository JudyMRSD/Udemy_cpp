//
// Created by Jin Zhu on 11/6/18.
//

#include <iostream>
#include "ring.h"
using namespace std;

int main(){
    ring<int>::iterator it;
    it.print();


//    ring<string> textring(3); //a buffer of 3 strings
//
//    textring.add("one");
//    textring.add("two");
//    textring.add("three");
//    textring.add("four");//should see "four" overwritten first element in the ring
//
//    for(int i = 0; i<textring.size(); i++){
//        cout << textring.get(i) <<endl;
//    }

    /*
     * output should be
     * four
     * one
     * two
     */



    return 0;
}

