//
// Created by Jin Zhu on 1/27/19.
//

# include <iostream>
using namespace std;

int main(){
    int cats = 5;
    [cats]() mutable {
        //only  changes a copy of it
        cats = 8;
        cout<<cats<<endl;
    }();

    cout <<cats <<endl;//still 5 
}