//https://www.geeksforgeeks.org/functors-in-cpp/

/*
 * Functors are objects that can be treated as though they are a function or function pointer.
 * Example: Below program uses transform() in STL to add 1 to all elements of arr[].
 *
*/




// A C++ program uses transform() in STL to add
// 1 to all elements of arr[]
#include <iostream>     // std::cout
#include <algorithm>    // std::transform
#include <vector>       // std::vector
using namespace std;



/* //1. use function pointer
int increment(int x) {  return (x+1); }



class increment
{
private:
    int num;
public:
    increment(int n) : num(n) {  }

    // This operator overloading enables calling
    // operator function () on objects of increment
    int operator () (int arr_num) const {
        return num + arr_num;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Apply increment to all elements of
    // arr[] and store the modified elements
    // back in arr[]
    // Problem: As transform requires a unary function(a function taking only one argument) for an array, we cannot pass a number to increment().
    transform(arr, arr+n, arr, increment);

    for (int i=0; i<n; i++)
        cout << arr[i] << endl;

    return 0;
}


 */


//2. use functor
// C++ program to demonstrate working of
// functors.


// A Functor
// A Functor
//To create a functor, we create a object that overloads the operator().
//The line,
//MyFunctor(10);
//
//Is same as
//MyFunctor.operator()(10);
// C++ program to demonstrate working of
// functors.
using namespace std;

// A Functor
class increment
{
private:
    int num;
public:
    increment(int n) : num(n) {  }

    // This operator overloading enables calling
    // operator function () on objects of increment
    int operator () (int arr_num) const {
        return num + arr_num;
    }
};
/*
 * As transform requires a unary function(a function taking only one argument) for an array, we cannot pass a number to increment().
 * And this would, in effect,
 * make us write several different functions to add each number. What a mess. This is where functors come into use.

 * A functor (or function object) is a C++ class that acts like a function.
 * Functors are called using the same old function call syntax.
 * To create a functor, we create a object that overloads the operator().
 */
// Driver code
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int to_add = 5;

    transform(arr, arr+n, arr, increment(to_add));

    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
}