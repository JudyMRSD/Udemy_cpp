//
// Created by Jin Zhu on 10/20/18.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string filename = "stats.txt";
    ifstream input;

    input.open(filename);
    if(!input.is_open()){
        return 1;
    }
    while(input){
        string line;
        //read up to the delimiter ':'
        getline(input, line, ':');
        //get the number after :
        int population;

        input >> population;

        //get the newline character
        input.get();

        cout << "'"<<line <<"'"<< " --' "<< population<<"'"<<endl;
    }
}