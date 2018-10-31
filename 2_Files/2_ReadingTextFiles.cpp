//
// Created by Jin Zhu on 10/20/18.
//
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string inFileName = "test.txt";
    //create an object input file stream
    ifstream inFile;
    inFile.open(inFileName);

    //another way:
    /*
     * fstream inFile;
     * inFile.open(inFileName, ios::in);
     */

    if(inFile.is_open()){
        string line;
        //getline(the stream we what to make from, the string we want to read into)
        //while havent' reached end of file
        //bool operator has been overloaded by inFile.eof()
        //following is equivalent to   while(!inFile.eof())
        while(inFile){
            getline(inFile, line);
            cout << line <<endl;
        }


        inFile.close();
    }else{
        cout<<"Cannot open file"<<inFileName<<endl;
    }



    return 0;
}
