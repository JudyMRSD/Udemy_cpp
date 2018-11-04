//
// Created by Jin Zhu on 11/1/18.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool match(string test){
    return test.size() == 3;
}

//define my own version of count_if from stl
//pass in a pointer to a function that performs the check of string length

//a variable called match is a function pointer that points to a function , the function it points
//to returns bool, takes one string parameter test

int countStrings(vector<string> &texts, bool (*match)(string test)){
    int count = 0;
    for(int i=0; i<texts.size(); i++){
        if(match(texts[i])){
            count++;
        }
    }
    return count;
}

int main(){
    vector<string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");

    //pass iterator to the start and end of the range you want to check
    //an pass a pointer to a function

    //count number of strings with 3 characters in it
    cout<< count_if(texts.begin(), texts.end(), match)<< endl;
    cout<< countStrings(texts, match)<<endl;
}