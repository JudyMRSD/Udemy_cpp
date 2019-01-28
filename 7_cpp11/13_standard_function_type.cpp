//
// Created by Jin Zhu on 1/27/19.
//
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;
//2.pass in function pointer to count_if
bool check(string &test){
    return test.size()==3;
}
//3. pass in a functor
class Check{
public:
    bool operator()(string &test) {
        return test.size() == 5;
    }
} check1; //define an object right after

//count_if accepts lambda expression, function or functor
//define run() that can also do this
//run can accppt anything that is callable, accept a string, return a bool
//function<return type (input type)> name
void run(function<bool(string&)> check){
    string test = "stars";
    cout<<check(test)<<endl;
}


int main(){
    int size = 3;
    vector<string> vec{"one", "two", "three"};
    //1.pass in lambda expression to count_if
    auto lambda = [size](string test){return test.size()==size;};
    int count = count_if(vec.begin(), vec.end(), lambda);
    cout <<count<<endl;
    //2.pass in function pointer to count_if
    count = count_if(vec.begin(), vec.end(), check);
    cout<<check<<endl;
    //3. pass in a functor
    count = count_if(vec.begin(), vec.end(), check1);
    cout<< count << endl;
    //----------------------
    //1.pass in lambda expression to run
    run(lambda);//check if the size equals to 3
    //2.pass in function pointer
    run(check1);//check if the size equals to 5
    //3. pass in a functor
    run(check);//check if the size equals to 3

    cout<<"-----------------"<<endl;
    //define local variables add, set to something callable
    function<int(int, int)> add = [](int one, int two){
        return one + two;
    };
    //call add
    cout << add(7, 3) <<endl;


    return 0;
}

