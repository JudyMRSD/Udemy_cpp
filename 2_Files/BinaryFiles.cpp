//
// Created by Jin Zhu on 10/21/18.
//

//
// Created by Jin Zhu on 10/20/18.
//
#include <iostream>
#include <fstream>
using namespace std;





//need to turn off the padding if we want to write to a file
#pragma pack(push, 1)//align the data in 1 bite
struct Person{
    //Pointers hold memory addresses.
    //string name;//a pointer to the string object is stored in stack, new operator allocates memory on heap
    char name[50];//char array of 50 characters maximum
    int age;//4 bites
    double height;//8 bites
};
#pragma pack(pop) // turn off pack




int main(){
    //create an instance of the struct
    Person someone = {"Frodo", 220, 0.8};

    string fileName = "test.bin";
    /*
     * Write binary file
     */
    ofstream outputFile;
    //binary file does not have new line characters after each line
    outputFile.open(fileName, ios::binary);
    if(outputFile.is_open()){
        //Person pointer, &someone, address of the struct type variable
        //cast to char pointer to use with write
        //following two ways both works
        //outputFile.write((char *)&someone, sizeof(Person));
        outputFile.write(reinterpret_cast<char*>(&someone), sizeof(Person));
        outputFile.close();
    }
    else{
        cout<< "Could not create file " + fileName;
    }
    /*
     * Read binary file
     */
    ifstream inputFile;
    Person someoneElse = {};//a struct with nothing in it
    //binary file does not have new line characters after each line
    inputFile.open(fileName, ios::binary);
    if(inputFile.is_open()){
        //read into the struct
        inputFile.read(reinterpret_cast<char*>(&someoneElse), sizeof(Person));
        inputFile.close();
    }
    else{
        cout<< "Could not read file " + fileName;
    }

    cout<<someoneElse.name<<", "<<someoneElse.age<<", "<<someoneElse.height<<endl;
    return 0;
}