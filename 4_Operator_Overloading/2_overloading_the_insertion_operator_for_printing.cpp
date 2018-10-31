#include <iostream>
using namespace std;


class Test{
private:
    int id;
    string name;
public:
    Test(): id(0), name(""){

    }

    Test(int id, string name): id(id), name(name){

    }

    /*
     * overload << operator
     */
    friend ostream &operator<<(ostream &out, const Test &test){
        out << test.id << ": "<<test.name;
        return out;
    }
};


int main() {
    Test test1(10, "Mike");

    cout << test1 <<endl; // << left right associativity   (cout << test1) <<endl;

    int value = 1+2+5;//+ right left associativity         1+(2+5)

    return 0;
}