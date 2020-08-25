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

