# A Tour of C++

## 2.4 Unions

I union is a struct in which all members are allocated at the same address so that the ***union occupies only as much space as its largest member***.

## 3.3 Modules(C++20)

The  use  of `#includes` is a very  old,  error-prone, and rather expensive way of composing programs out of parts.  

-  If you `#include` header.h in 101 translation units, the text of header.h will be processed by the compiler 101 times.

Example of module

```c++
// file Vector.cpp
module;

exoport module Vector;
export class Vector {
public:
	Vector(int s);
    double& operator[](int i);
    int size();
private:
    double* elem;
    int sz;
};
```

```c++
//file user.cpp
import Vector
#include <cmath>
double sqrt_sum(Vector& v) {
    ...
}
```

- Can use `module` with `import`

The differences between headers and modules are not just syntactic.

- A module is compiled once only (rather than in each translation unit in which it is used).
- Two modules can be imported in either order without changing their meaning.
- If you import something into a module, users of your module do not implicitly gain access to (and are not bothered by) what you imported: import is not transitive.

The effects on maintainability and compile-time performance can be spectacular.

### 3.5.2 Invariants

Statement of what is ***assumed to be true for a class is called a `class invariant`, or simply an `invariant`***. It is the job of a constructor to establish the invariant for its class (so that the member functions can rely on it) and for the member functions to make sure that the invariant holds when they exit.

- It will be mentioned again in 4.2.2 and 13.2

### 3.5.3 Error-Handling Alternatives

Error handling is a major issue in all real-world software, so naturally there are a variety of approaches. If an error is detected and it cannot be handled locally in a function, the function must somehow communicate the problem to some caller. Throwing an exception is C++’s most general mechanism for that.

- Compilers are optimized to make returning a value much cheaper than throwing the same value as an exception.

A function can indicate that it cannot perform its allotted task by:

1. throwing an exception
2. somehow return a value indicating failure
3. terminating the program (by invoking a function like terminate(), exit(), or abort()). 

We return an error indicator (an ‘‘error code’’) when:(에러를 예상 할 수 있을 때)

- A failure is normal and expected. For example, it is quite normal for a request to open a file to fail (maybe there is no file of that name or maybe the file cannot be opened with the per-missions requested).
- An immediate caller can reasonably be expected to handle the failure.

We throw an exception when:(예상치 못한 에러지만 복구 가능 할 때)

- An error is so rare that a programmer is likely to forget to check for it. For example, when did you last check the return value of printf()?
- An error cannot be handled by an immediate caller. Instead, the error has to percolate(여과하다) back to an ultimate  caller. For example, it is infeasible to have every function in an application reliably handle every allocation failure or network outage.
- New kinds of errors can be added in lower-modules of an application so that ***higher-level modules are not written to  cope with such errors***. For example, when a previously single-threaded application is modified to use multiple threads or resources are placed remotely to be accessed over a network.
- ***No suitable return path for errors codes are available***. For example, a constructor does not have a return value for a  ‘‘caller’’ to check. In particular, constructors may be invoked for several local variables or in a partially constructed complex object so that clean-up based on error codes would be quite complicated.
- The return path of a function is made more complicated or expensive by a need to pass both a value and an error indicator back (e.g., a pair; §13.4.3 ), possibly leading to the use of out-parameters, non-local error-status indicators, or other workarounds.
- The error has to be transmitted up a call chain to an ‘‘ultimate caller.’’ Repeatedly checking an error-code would be tedious, expensive, and error-prone.
- The recovery from errors depends on the results of several function calls, leading to the need to maintain local state between calls and complicated control structures.
- The function that found the error was a callback (a function argument), so the immediate caller may not even know what function was called.
- ***An error implies that some ‘‘undo action’’ is needed***.

We terminate when(정말 답이 없을 때)

- An error is of a kind from which we cannot recover. For example, for many – but not all –systems there is no reasonable way to recover from memory exhaustion.
- The system is one where error-handling is based on restarting a thread, process, or computer whenever a non-trivial error is detected.

### 3.5.5 Static Assertions

Exceptions report errors found at run time. If an error can be found at compile time, it is usually preferable to do so. 

```c++
static_assert(4<=sizeof(int), "integers are too small");
```

- Print error message when condition is not true.
- The most important uses of `static_assert` come when we make assertions about types used as parameters in generic programming.

## 4.2 Concrete Types

The basic idea of concrete classes is that they behave ‘‘just like built-in types.’’ For example, a complex number type and an infinite-precision integer are much like built-in `int`, except of course that they have their own semantics and sets of operations. Similarly, a `vector` and a `string` are much like built-in arrays, except that they are better behaved.

### 4.2.2 A Container

A container is an object holding a collection of elements.

The constructor allocates the elements and initializes the Vector members appropriately. The destructor deallocates the  elements. This handle-to-data model is very commonly used to manage data that can vary in size during the lifetime of an object.

- The technique of acquiring resources in a constructor and releasing them in a destructor, known as ***Resource Acquisition Is Initialization or RAII***, allows us to eliminate ‘‘naked new operations,’’ that is, to ***avoid allocations in general code and keep them buried inside the implementation of well-behaved abstractions***.
- Similarly, ‘‘naked delete operations’’ should be avoided. Avoiding naked new and naked delete makes code far less error-prone and far easier to keep free of resource leaks

## 4.3 Abstract Types

An abstract type is a type that completely insulates a user from implementation details. ***To do that, we decouple the interface from the representation and give up genuine local variables***. Since we don’t know anything about the representation of an abstract type (not even its size), we must allocate objects on the free store(§4.2.2) and access them through references or pointer.

```c++
class Container {
public:
    virtual double& operator[](int) = 0; // = 0 means it is pure virtual function.
    virtual int size() const = 0;
    virtual ~Container(){}
};
```

This class is a pure interface to specific containers defined later. The word virtual means ‘‘may be redefined later in a class derived from this one.’’ Unsurprisingly, a function declared `virtual` is called a `virtual function`. A class derived from Container provides an implementation for the Container interface. ***The curious=0 syntax says the function is pure virtual***; that is, some class derived from Container must define the function. Thus, it is not possible to define an object that is just a Container. 

- `pure virtual` : 반드시 재정의 해야함. 사용하지 않아도 정의 되어야 함.(재정의가 가능한 함수 의미)
- `virtual` : 사용하려면 재정의 해야함. 하지만 사용 안할려면 재정의 안해도 됨.(재정의 해야만 하는 함수 의미)

```c++
Container c;						// Error: There can be no objects of an abstract class
Container* p = new Vector_container(10);	// Ok: Container is an interface
```

A Container can only serve as the interface to a class that implements its `operator[]()` and `size()` functions. ***A class with a pure virtual function is called an abstract class***.

The Container can be used liker this:

```c++
void use(Container& c) {
    const int sz = c.size();
    for(int i = 0; i != sz; ++i) {
        cout <<c[i] << '\n';
    }
}
```

> ***Rule: Whenever you are dealing with inheritance, you should make any explicit destructors virtual.***

## 4.5 Class Hierarchies

### 4.5.1 Benefits from Hierarchies

A class hierarchy offers two kinds of benefits:

- ***Interface inheritance***: An object of a derived class can be used wherever an object of a base class is required.  ***That is, the base class acts as an interface for the derived class***.
- ***Implementation inheritance***: A base class provides functions or data that simplifies the implementation of derived classes. Smiley’s uses of Circle’s constructor and of Circle::draw() are examples. Such base classes often have data members and constructors

### 4.5.2 Hierarchy Navigation

The `read_shape()` function returns `Shape∗` so that we can treat all `Shapes` alike.  However,  what  can we do if we want to use a member function that is only provided by a particular derived class, such as `Smiley`’s `wink()`?  We can ask ‘‘is this `Shape` a kind of `Smiley`?’’ using the `dynamic_cast` operator:

```c++
Shape* ps{read_shape(cin)};
if (Smiley* p = dynamic_cast<Smiley*>(ps)) {
    
}
else {
    
}
```

- Code is cleaner when `dynamic_cast` is used with restraint. If we can avoid using type information, we can write simpler and more efficient code, but occasionally type information is lost and must be recovered.
- Operations similar to dynamic_cast are known as ‘‘is kind of’’ and ‘‘is instance of’’ operations.

## Ch 5 Essential Operations

### 5.1 Introduction

#### 5.1.1 Essential Operations

```c++
class X {
public:
    X(Sometype);	// "Ordinary constructor" : create an object
    X();			// default constructor
    X(const X& x);	// copy constructor(X is a type)
    X(X&& x);		// move constructor
    X& operator=(const X& x); // copy assignment: clean up target and copy
    X& operator=(X&& x);      // move assignment: clean up target and move
    ~X();			// destructor
};
```

### 5.2 Copy and Move

When we design a class, we must always consider if and how an object might be copied. For simple concrete types, memberwise copy is often exactly the right semantics for copy. For some sophisticated concrete types, such as Vector, memberwise copy is not the right semantics for copy; for abstract types it almost never is.

#### 5.2.1 Copying Containers

- Default copy : Shallow copy

Deep copy example

1. Copy constructor

```c++
Vector::Vector(const Vector& a) :elem{new double[a.sz]}, sz{a.sz} {
    // Copy constructor
    for(int i{0}; i != sz; ++i) {
        elem[i] = a.elem[i];
}
```

2. Copy assignment

```c++
Vector& Vector::operator=(const Vector& a) {
    double* p = new double[a.sz];
    for(int i{0}; i != a.sz; ++i) {
        p[i] = a.elem[i];
    }
    // delete old elements
    delete[] elem;
    elem = p;
    sz = a.sz;
    return *this;
}
```

- ***Do not forget to delete old elements***

