#include <iostream>
#include <fstream> //file stream,  stream are objects

using namespace std;

int main() {
    string outputFileName = "test.txt";
    //Method 1: decleare an output file stream (ofstream) object
    /*
    ofstream outFile;
    outFile.open(outputFileName);
     */
    //Method 2: use file stream and specify ios::out
    fstream outFile;
    outFile.open(outputFileName, ios::out);
    if(outFile.is_open()){
        outFile<<"Hello World"<<endl;
        outFile<<123<<endl;
        outFile.close();
    }
    else{
        cout<<"Could not create file: "<< outputFileName<< endl;
    }
    return 0;
}