#include <iostream>
#include <vector>
using namespace std;

int main(){
    //use {} to initialize values
    int values[] = {1,2,3};
    cout<<values[0]<<endl;

    //1.initialize public member
    class C{
    public:
        string text;
        int id;
    };

    C c1 = {"Hello", 7};
    cout<<c1.text<<endl;


    //2.structs default public
    struct S{
        string text;
        int id;
    };

    S s1 = {"Hello", 7};
    cout << c1.text << endl;



    //3. intialize right after the struct
    struct R{
        string text;
        int id;
    }r1 = {"Hello", 7}, r2 = {"Hi", 8};

    cout<< r1.text<<endl;
    cout<< r2.text<<endl;

    //4. need push back
    vector<string> strings;
    strings.push_back("one");

    return 0;
}