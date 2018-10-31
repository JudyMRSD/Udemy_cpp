//
// Created by Jin Zhu on 10/21/18.
//
#include <iostream>
#include <map>
using namespace std;


int main(){
    map<string, int> ages;
    /*
     * insert
     */
    ages["Mike"] = 40;
    ages["Vicky"] = 30;
    ages.insert(pair<string, int>("Raj", 20));
    ages.insert(make_pair("Peter", 100));

    cout<<ages["Raj"]<<endl;


    /*
     * Check if value is stored in a map
     */
    //wrong way
    cout<<ages["Sue"]<<endl;//Sue : 0 is added to map
    //correct way
    if(ages.find("Vicky")!= ages.end()){
        cout<<"Found  Vicky"<<endl;
    }
    else{
        cout<<"Key not found"<<endl;
    }
    /*
     * iterate as pair
     */
    for(map<string, int>::iterator it = ages.begin(); it!=ages.end();it++){
        pair<string, int> age = *it;
        cout<<age.first<<": "<<age.second<<endl;
    }
    /*
     * iterate through map
     */
    for(map<string, int>::iterator it = ages.begin(); it!=ages.end(); it++){
        cout<<it->first<<":" <<it->second<<endl;
    }
    return 0;
}