# Ch07F Functions

## 7.1 Function parameters and arguments

### Parameters vs Arguments

A function parameters us a variable declared in the function declaration

```c++
void foo(int x); // deflaration -> x is parameter
void foo(int x)  // definition -> x is parameter
{
    
}
```

An argument is the value that is passed to the function by the caller

```c++
foo(6);		// 6 is the argument passed to parameter x
foo(y+1);	// the value y + 1 is the argument passed to parameter x
```

## 7.4a Returning values by value, reference, and address

### Mixing return references and values

```c++
int returnByValue()
{
    return 5;
}
 
int& returnByReference()
{
     static int x{ 5 }; // static ensures x isn't destroyed when the function ends
     return x;
}
 
int main()
{
    int giana{ returnByReference() }; // case A -- ok, treated as return by value
    int& ref{ returnByValue() }; // case B -- compile error since the value is an r-value, and an r-value can't bind to a non-const reference
    const int& cref{ returnByValue() }; // case C -- ok, the lifetime of the return value is extended to the lifetime of cref
 
    return 0;
}
```

- In case A, we’re assigning a reference return value to a  non-reference variable. Because giana isn’t a reference, the return value is copied into giana, as if returnByReference() had returned by value.
- In case B, we’re trying to initialize reference ref with the copy of  the return value returned by returnByValue().  However, because the  value being returned doesn’t have an address (it’s an r-value), this  will cause a compile error.
- In case C, we’re trying to initialize const reference cref with the  copy of the return value returned by returnByValue().  Because const  references can bind to r-values, there’s no problem here. Normally,  r-values expire at the end of the expression in which they are created  -- however, when bound to a const reference, the lifetime of the r-value (in this case, the return value of the function) is extended to match  the lifetime of the reference (in this case, cref)

***Warning***

```c++
const int& returnByReference()
{
     return 5;
}
 
int main()
{
    const int &ref { returnByReference() }; // runtime error
}
```

- **Lifetime extension doesn’t save dangling references**
- Assign reference to reference is runtime error
- It return original 5 and 5 is deleted because of out of scope

```c++
const int returnByValue()
{
     return 5;
}
 
int main()
{
    const int &ref { returnByValue() }; // ok, we're extending the lifetime of the copy passed back to main
}
```

- It works because returnByValue() function return copy of 5 and it is not related to scope of function.

When we use return by reference?

```c++
const std::string& getElement(const std::vector<std::string>& array, const int index);
```

- It return specific location of vector.
- Also, we can use it when we don't want to use copy to save memory.

## 7.6 Function overloading

**Function overloading** is a feature of C++ that allows us to create multiple functions with the same name, so long as they have different parameters.

```c++
int add(int x, int y);
int add(int x, int y, int z);
double add(double x, double y);
```

- **Function return types are not considered for uniqueness**

```c++
int getRandomValue();
double getRandomValue(); // Compile error
void getRandomValue(int& num);
void getRandomValue(double& num); \\ Works
```

- It uses same parameter(None)

## 7.9 Function pointers

```c++
int (*funcptr)();
int (*const funcptr)();
```

Example 1)

```c++
int foo()
{
    return 5;
}

int goo()
{
    return 6;
}

int main()
{
    int (*fcnPtr)(){ & foo };
    fcnPtr = &goo;
    
    return 0;
}
```

Example 2) explicit version

```c++
int foo(int x)
{
    return x;
}
 
int main()
{
    int (*fcnPtr)(int){ &foo }; // Initialize fcnPtr with function foo
    (*fcnPtr)(5); // call function foo(5) through fcnPtr.
 
    return 0;
}
```

Example 3) Implicit version

```c++
int foo(int x)
{
    return x;
}
 
int main()
{
    int (*fcnPtr)(int){ &foo }; // Initialize fcnPtr with function foo
    fcnPtr(5); // call function foo(5) through fcnPtr.
 
    return 0;
}
```

### Passing functions as arguments to other functions

One of the most useful things to do with function pointers is pass a  function as an argument to another function.  Functions used as  arguments to another function are sometimes called **callback functions**.

## 7.12a assert and static_assert

```c++
assert(a > 5); // Runtime check
static_assert(a > 5); // Compile time check
```

## 7.13 Command line arguments

### Using command line arguments

```c++
int main(int argc, char* argv[])
```

- **argc** is an integer parameter containing a count of the number of arguments passed to the program (think: argc = **arg**ument **c**ount).
  - argc will always be at least 1, because the first argument is always the name of the program itself.  Each command line argument the user provides will cause argc to increase by 1.

- **argv** is where the actual argument values are stored (think: argv = **arg**ument **v**alues, though the proper name is “argument vectors”).
  - Although the declaration of argv looks intimidating, argv is really just an array of  C-style strings.  The length of this array is argc.

## 7.15 Introduction to lambdas

A lambda expression (also called a lambda or closure) allows us to define an anonymous function inside another function. The nesting is important, as it allows us both to avoid namespace naming pollution, and to define the function as close to where it is used as  possible (providing additional context).

The syntax for lambdas is one of the weirder things in C++, and takes a bit of getting used to. Lambdas take the form:

```
[ captureClause ] ( parameters ) -> returnType
{
    statements;
}
```

- ***The `return type` is optional, and if omitted, `auto` will be assumed (thus using type inference used to determine the return type)***.

Example: no captures, no parameters, and no return type

```c++
int main()
{
    []() {}; // Lambdas expression
}
```

When we don't know return type of lambdas, use std::function

```c++
#include <functional>
#include <iostream>
 
// We don't know what fn will be. std::function works with regular functions and lambdas.
void repeat(int repetitions, const std::function<void(int)>& fn)
{
  for (int i{ 0 }; i < repetitions; ++i)
  {
    fn(i);
  }
}
 
int main()
{
  repeat(3, [](int i) {
    std::cout << i << '\n';
  });
 
  return 0;
}
```

### Generic lambdas and static variables

```c++
#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
 
int main()
{
  // Print a value and count how many times @print has been called.
  auto print{
    [](auto value) {
      static int callCount{ 0 };
      std::cout << callCount++ << ": " << value << '\n';
    }
  };
 
  print("hello"); // 0: hello
  print("world"); // 1: world
 
  print(1); // 0: 1
  print(2); // 1: 2
 
  print("ding dong"); // 2: ding dong
 
  return 0;
}
/*
Output

0: hello
1: world
0: 1
1: 2
2: ding dong

*/
```

In the above example, we define a lambda and then call it with two  different parameters (a string literal parameter, and an integer  parameter).  ***This generates two different versions of the lambda (one  with a string literal parameter, and one with an integer parameter)***.

- auto 쓰면 변수 타입에 따라서 다른 람다 함수 사용 함.

## 7.16 Lambda caputres

### Captures default to const value

***By default, variables are captured by `const value`***.  This  means when the lambda is created, the lambda captures a constant copy of the outer scope variable, which means that the lambda is not allowed to modify them. In the following example, we capture the variable `ammo` and try to decrement it.

```c++
#include <iostream>
 
int main()
{
  int ammo{ 10 };
 
  // Define a lambda and store it in a variable called "shoot".
  auto shoot{
    [ammo]() {
      // Illegal, ammo was captured as a const copy.
      --ammo;
 
      std::cout << "Pew! " << ammo << " shot(s) left.\n";
    }
  };
 
  // Call the lambda
  shoot();
 
  std::cout << ammo << " shot(s) left\n";
 
  return 0;
}
```

- It is illegal to change captures in lambdas

### Mutable capture by value

```c++
#include <iostream>

int main()
{
    int ammo{ 10 };
    
    auto shoot{
        [ammo]() mutable {
            --ammo;
            std::cout << "Pew! " << ammo << " shot(s) left.\n"
        }
    };
    
    shoot();
    shoot();
    
    std::cout << ammo << " shot(s) left\n";
    
    return 0;
}
// Output
/*
Pew! 9 shot(s) left.
Pew! 8 shot(s) left.
10 shot(s) left
*/
```

### Capture by reference

```c++
#include <iostream>
 
int main()
{
  int ammo{ 10 };
 
  auto shoot{
    // We don't need mutable anymore
    [&ammo]() { // &ammo means ammo is captured by reference
      // Changes to ammo will affect main's ammo
      --ammo;
 
      std::cout << "Pew! " << ammo << " shot(s) left.\n";
    }
  };
 
  shoot();
 
  std::cout << ammo << " shot(s) left\n";
 
  return 0;
}

// Output
/*
Pew! 9 shot(s) left.
9 shot(s) left
*/
```

### Default captures

A default capture (also called a capture-default) captures all variables that are mentioned in the lambda. Variables not mentioned in the lambda are not captured if a default capture is used.

- To capture all used variables by value, use a capture value of `=`.
- To capture all used variables by reference, use a capture value of `&`.

### Defining new variables in the lambda-capture

Sometimes we want to capture a variable with a slight modification or  declare a new variable that is only visible in the scope of the lambda.  ***We can do so by defining a variable in the lambda-capture without  specifying its type***.

```c++
#include <array>
#include <iostream>

int main()
{
    std::array areas{100, 25, 121, 40, 56};
    
    int width{};
    int height{};
    
    std::cout << "Enter width and height : ";
    std::cin >> width >> height;
    
    auto found{ std::find_if(areas.begin(), areas.end(),
                             [userArea{width * height}](int knownArea) {
                                 return (userArea == knownArea);
                             })};
}
```

- `userArea` will only be calculated once when the lambda is defined.

***캡쳐는 호출 될때가 아니라 정의 될 때 함!!***

```c++
#include <iostream>
#include <string>
 
int main()
{
  std::string favoriteFruit{ "grapes" };
 
  auto printFavoriteFruit{
    [=]() {
      std::cout << "I like " << favoriteFruit << '\n';
    }
  };
 
  favoriteFruit = "bananas with chocolate";
 
  printFavoriteFruit();
 
  return 0;
}
// Output : I like grapes
```

- capture에 &쓰면 favoriteFruit 바뀔때 같이 바뀜