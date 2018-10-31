//
// Created by Jin Zhu on 10/21/18.
//
#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> numbers;
    /*
     * add to end or front
     */
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_front(0);
    /*
     * Insert an element
     */
    list<int>::iterator it = numbers.begin();
    it++;
    numbers.insert(it, 100);
    cout<< "Inserted Element After: "<<*it<<endl;
    /*
     * Erase an element
     */
    list<int>::iterator eraseIt = numbers.begin();
    eraseIt++;
    //return an iterator after the element that you erased
    eraseIt = numbers.erase(eraseIt);
    cout<<"Erased Element Before: "<<*eraseIt<<endl;

    /*
     * insert and erase in a for loop
     */
    //0->1->2

    it = numbers.begin();

    while(it!=numbers.end()){
        if(*it  == 2){
            numbers.insert(it, 1234);//0->1->1234->2
        }
        if(*it == 1){
            //erase(it) will invalidate the iterator, so need to reassign to `it` using it = numbers.erase(it)
            //it now points to the element after what is erased
            //effectively increament the iterator
            it = numbers.erase(it);//0->1234->2

        }
        //only increament when no erase is done
        else{
            it++;
        }
    }

    //0->1234->2    at this point, element 1 is erased
    /*
     * loop through list
     * cannot use index, need to use iterator
     */
    for(list<int>::iterator it = numbers.begin(); it!=numbers.end(); it++){
        cout<<"element "<< *it<<endl;
    }



}