//
// Created by Jin Zhu on 10/28/18.
//
# include <iostream>
# include <map>
using namespace std;

int main(){
    multimap<int, string> lookup;
    //multimap does not have the overloaded array operator [], has to use insert
    //make_pair(key, value)
    lookup.insert(make_pair(30, "Vicky"));
    lookup.insert(make_pair(10, "Mike"));
    lookup.insert(make_pair(30, "Raj"));
    lookup.insert(make_pair(20, "Bob"));

    //iterate through multimap is the same as iterate through a regular map
    for(multimap<int, string>::iterator it = lookup.begin(); it!=lookup.end(); it++){
        cout<< it->first << " : "<<it->second <<endl;

    }
    cout<<endl;

    //there are two values with this key 30
    pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(30);
    //Returns a range containing all elements equivalent to value in the range [first, last).


    //pair::first is the lower bound of the range (the same as lower_bound), and pair::second is the upper bound
    //iterate through range of keys in multimap
    //its.first   start of the range
    for(multimap<int, string>::iterator it = its.first; it!=its.second; it++){
        cout<< it->first <<" : "<<it->second <<endl;
    }
    //same, rewritten in C++ 11 : use auto to automatically get the type for you
    //pair<iterator,iterator>             equal_range (const key_type& k);
    cout<<endl;
    auto its2 = lookup.equal_range(30);

    for(multimap<int, string>::iterator it = its.first; it!=its.second; it++){
        cout<< it->first <<" : "<<it->second <<endl;
    }

}

