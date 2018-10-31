//
// Created by Jin Zhu on 10/31/18.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    map<string, vector<int>> scores;

    scores["Mike"].push_back(10);//key: "Mike"    value: vector
    scores["Mike"].push_back(20);//key: "Mike"    value: vector
    scores["Vicky"].push_back(15);//key: "Vicky"    value: vector

    for(map<string, vector<int>::iterator it=scores.begin(); it!=scores.end(); it++){
        string name = it->first;
        vector<int> scoreList = it->second;
        cout<<name<<": "<<flush;
        for(int i = 0; i<scoreLiest.size(); i++){
            cout<<scoreList[i]<<" "<<flush;
        }
    }

    return 0;
}