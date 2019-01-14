#include <iostream>
#include "ring.h"
using namespace std;

int main() {

    ring<string> textring(3); //a buffer of 3 strings

    textring.add("one");
    textring.add("two");
    textring.add("three");
    textring.add("four");//should see "four" overwritten first element in the ring

    for (int i = 0; i < textring.size(); i++) {
        cout << textring.get(i) << endl;
    }

    //range based loop
    for(ring<string>::iterator it = textring.begin(); it!=textring.end(); it++){
        cout<< *it <<endl;
    }
    cout<<endl;

    for(string value : textring){
        cout << value <<endl;
    }
}