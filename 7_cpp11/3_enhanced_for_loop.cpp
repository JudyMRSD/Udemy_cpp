#include <iostream>
#include <vector>
using namespace std;

int main(){
    auto texts = {"one", "two", "three"}; //char texts[] = {"one", "two", "three"}
    for(auto text: texts){
        cout<< text <<endl;
    }


    vector<int> numbers{1,2,3};

    for (auto num : numbers){
        cout << num <<endl;
    }

    string hello = "Hello";
    for(auto c : hello){
        cout << c <<endl;
    }


};
