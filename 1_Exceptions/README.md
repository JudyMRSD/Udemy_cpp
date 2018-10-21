# Exceptions
Use for things that your program cannot recover from.

##### custom exception inherit stl exception class:
override what() method


```
class exception {
public:
  exception () noexcept;
  exception (const exception&) noexcept;
  exception& operator= (const exception&) noexcept;
  virtual ~exception();
  virtual const char* what() const noexcept;
}

```
##### catch subclass exception
Need to catch child class before parent class because of polymorphism.

If both base and derived classes are caught as exceptions
then catch block of derived class must appear before the base class.

If we put base class first then the derived class catch block will never be reached.
because of polymorphism, the base class bad_alloc IS of class exception, catch(exception &e)
will be executed if the code is before catch(bad_alloc &e)

```
    try{
        goesWrong();
    }
    //need to catch subclass before catch parent class
    catch(bad_alloc &e){
        cout<<"Catching bad alloc"<<e.what()<<endl;
    }
    //parent class excepetion
    catch(exception &e){
        cout<<"Catching exception: "<<e.what()<<endl;
    }

```

