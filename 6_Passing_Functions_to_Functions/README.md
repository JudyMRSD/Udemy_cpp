## Function Pointers
Declare a pointer to a function (instead of a pointer to a variable)
Virtual table is a table of function pointers

Unlike normal pointers, a function pointer points to code, not data.
Typically a function pointer stores the start of executable code.
```
pTest = &test; //get address of function
(*pTest)();//dereference the function
```
Unlike normal pointers, we do not allocate de-allocate memory using function pointers

A function’s name can also be used to get functions’ address. For example,
in the below program, we have removed address operator ‘&’ in assignment.
We have also changed function call by removing *,
the program still works.
```
pTest = test;//the name of a function is a pointer to that function
pTest();//do not need to dereference, since if you are calling a function, it's not ambiguous that it needs to be dereferenced
```

Example:
```
#include <iostream>

double add(double left, double right) {
    return left + right;
}

double multiply(double left, double right) {
    return left * right;
}

double binary_op(double left, double right, double (*f)(double, double)) {
    return (*f)(left, right);
}

int main( ) {
    double a = 5.0;
    double b = 10.0;

    std::cout << "Add: " << binary_op(a, b, add) << std::endl;
    std::cout << "Multiply: " << binary_op(a, b, multiply) << std::endl;

    return 0;
}
```


In order for a function to receive a function pointer as a parameter
it is necessary to specify its return type (in this case `double`),
the parameter name of the function (in this case `f`) and
the types of all parameters necessary for the function pointer
(in this case two `double` values).

We are then able to pass the function pointers into the `binary_op` function.
`binary_op` then dereferences the function pointer in order to
execute the correct function - `add` or `multiply`.

Drawbacks:

1. Efficiency - Function pointers are inefficient when compared with functors (discussed below). The compiler will often pass them as raw pointers
and as such the compiler will struggle to inline the code.

2. State - Function pointers by themselves are not particularly flexible at storing state.
Although it is possible, by using a local static variable within the function,
there is only ever one global state for the function itself
and as such this static variable must be shared.

Furthermore this static variable will not be thread-safe,
unless the appropriate thread synchronisation code is added.
Thus it can lead to bottlenecks or even race conditions in multithreaded programs.

These problems can be solved by using functors.


## Functors: function objects
A function object allows an instance object of a class to be called
or invoked as if it were an ordinary function.

In C++ this is carried out by overloading operator().
The main benefit of using function objects is that they are objects
and hence can contain state, either statically across all instances
of the function objects or individually on a particular instance.

Here is a C++ example of a function object (in fact a function object hierarchy),
which replaces the function pointer syntax from the version above, with functors:

```
#include <iostream>

// Abstract base class
class BinaryFunction {
public:
  BinaryFunction() {};
  virtual double operator() (double left, double right) = 0;
};

// Add two doubles
class Add : public BinaryFunction {
public:
  Add() {};
  virtual double operator() (double left, double right) { return left+right; }
};

// Multiply two doubles
class Multiply : public BinaryFunction {
public:
  Multiply() {};
  virtual double operator() (double left, double right) { return left*right; }
};

double binary_op(double left, double right, BinaryFunction* bin_func) {
  return (*bin_func)(left, right);
}

int main( ) {
  double a = 5.0;
  double b = 10.0;

  BinaryFunction* pAdd = new Add();
  BinaryFunction* pMultiply = new Multiply();

  std::cout << "Add: " << binary_op(a, b, pAdd) << std::endl;
  std::cout << "Multiply: " << binary_op(a, b, pMultiply) << std::endl;

  delete pAdd;
  delete pMultiply;

  return 0;
}

```

We have created an abstract base class, called `BinaryFunction`
and then inherited `Add` and `Multiply` classes.
Since `BinaryFunction` is abstract, it cannot be instantiated.
Hence we need to make use of pointers to pass in `pAdd` and `pMultiply`
to the new `binary_op` function.


The main benefit is that we are now able to add state to the function objects.


## Object Slicing and Polymorphism

"Slicing" is where you assign an object of a derived class to an instance of a base class,
thereby losing part of the information - some of it is "sliced" away.

For example,
```
class A {
   int foo;
};

class B : public A {
   int bar;
};

```
So an object of type B has two data members, foo and bar.

Then if you were to write this:
```
B b;

A a = b;
```
Then the information in b about member bar is lost in a.
Upcasting is converting a derived-class reference or pointer to a base-class.
In other words, upcasting allows us to treat a derived type as though it were its base type.


## Pure virtual function
Pure virtual function must be declared ending with "= 0" and it can only be declared in abstract class.
Implementation must be provided in class(es) that derived from that abstract class

You cannot instantiate an abstract class.

When an array of object is created, run constructor for objects.
Thus, cannot create array of objects for abstract class.

Can create an array of pointers to objects for an abstract class.
