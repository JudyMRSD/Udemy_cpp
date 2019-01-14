//
// Created by Jin Zhu on 11/6/18.
//

#include <iostream>
using namespace std;

/*
 * example 0, this is the int case for example 1
 */
auto test0()->int{
    return 100;
}
/*
 * example 1
 */
//template function
template <class T>
//trailing return type
auto test(T value) -> decltype(value) {
    return value;
}
/*
 * example 2: 2 templates
 */

template <class T, class S>
auto test2(T value1, S value2) -> decltype(value1 + value2){
    return value1 + value2;
}
/*
 * example 3
 */
int get(){
    return 999;
}
auto test3() -> decltype(get()){
    return get();
}

int main(){
    auto value = 7;
    auto text = "Hello";
    cout << value <<endl;
    cout << text <<endl;

    cout << test("Hello there") <<endl;
    cout<< test2(4, 5) <<endl;
    cout << test3() <<endl;
    return 0;
}
















