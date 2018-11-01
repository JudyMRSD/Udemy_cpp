# Vectors

###### Vectors and Memory
A vector manages an array internally.

Add more elements to the vector than it's capacity will create
a new array whose capacity doubles every time.

```
Capacity: 20
Capacity : 40
Capacity : 80
Capacity : 160
...
```

vector **size**:
actual elements added to the vector, change using **resize()**

vector **capacity**:
internal array capacity, change using **reserve()**

Insertion time: constant amortized time

###### Vector vs List

in vector, restricted to insert items at the end.
vector elements are stored next to each other.

in list, contains doubly linked nodes that points to previous
and next elements.

**Usage**:

To loop through list, cannot use `index`, need to use `iterator`

Iterator for vector can use `it+=2`,
but iterator for list can only `it++`, `it--`

###### Custom object as map values
shallow vs deep copy

##### Custom objects as map keys
operator overloading, need to define custom definition for "<" sign
for the key objects (elements in map are ordered)



##### Multimap
Rather than each key being unique, the key value and mapped value pair has to be unique in this case.
Multimap allows you to store entries with duplicate keys.

##### Set
set::Begin    returns an iterator to the first element in the container.
If the set object is const-qualified, the function returns a const_iterator. Otherwise, it returns an iterator.

operator== is not used by std::set. Elements a and b are considered equal iff !(a < b) && !(b < a)
Need to overload < operator