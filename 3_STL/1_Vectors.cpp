#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<string> strings(5);//vector of 5 strings

    strings.push_back("one");

    strings[3] = "dog";
    cout<<strings[3]<<endl;
    cout<<strings.size()<<endl;//A vector is a dynamically-sized sequence of objects
    //loop through all elements in vector
    for(int i = 0; i<strings.size(); i++){
        cout << "item i"<<strings[i] <<endl;
    }
    cout<<"----------iterator-----------"<<endl;
    //strings.begin():  iterator object points to the first element
    //can use const iterator to avoid chanign the element
    for (vector<string>::iterator it = strings.begin(); it!=strings.end(); it++){
        //dereference the iterator to get the element
        cout << "item i"<< *it<<endl;
    }
    return 0;
}