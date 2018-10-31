//
// Created by Jin Zhu on 10/21/18.
//
#include <iostream>
#include <vector>
using namespace std;


int main(){
    /*
     * add more elements to the vector, will create an array that's bigger, and copy over all the elements
     */
    //a vector manages an array internally
    vector<double> numbers(20);
    //vector size: actual elements added to the vector
    //vector capacity: internal array
    cout<<"Size: "<<numbers.size()<<endl;
    int capacity = numbers.capacity(); // size of the internally array
    cout<<"Capacity: "<< capacity<<endl;
    for(int i = 0; i<10000; i++){
        if(numbers.capacity()!=capacity){
            capacity = numbers.capacity();
            //capacity increaments exponentially with number of elements in the vector
            cout<<"Capacity : "<< capacity << endl;
        }
        numbers.push_back(i);
    }

    /*
     * clear: remove all the elements, size changes, capacity of the internal array doesn't change
     */
    numbers.clear();
    cout<<"Size"<<numbers.size()<<endl;
    cout<<"Capacity"<<numbers.capacity()<<endl;
    /*
     * resize , capacity remains unchanged
     * Resizes the container so that it contains n elements.
     * If n is smaller than the current container size, the content is reduced to its first n elements,
     * removing those beyond (and destroying them)
     */
    numbers.resize(100);
    cout<<"Size"<<numbers.size()<<endl;
    cout<<"Capacity"<<numbers.capacity()<<endl;
    /*
     * reserve: internal array capacity changes, size doesn't
     */
    numbers.reserve(1000000);
    cout<<"Size"<<numbers.size()<<endl;
    cout<<"Capacity"<<numbers.capacity()<<endl;
    return 0;
}

