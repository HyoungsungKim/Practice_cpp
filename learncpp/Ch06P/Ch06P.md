# Ch06P Pointers and references

## Reference

```c++
int a{1}
int& b{a}
```

- 깊은 복사(주소까지 다 복사 함)
- 따라서 b 수정하면 a도 변함

### l-values and r-values

In C++, variables are a type of l-value (pronounced ell-value).

- An **l-value** is a value that has an address (in memory).
  - ***l-value란 메모리에 address가 있는 value***
- Since all variables have addresses, all variables are l-values.
- The name l-value came about because l-values are the only values that can be on the left side of an assignment statement.
  - When we do an assignment, the left hand side of the assignment operator must be an l-value.
-  Consequently, a statement  like `5 = 6;` will cause a compile error, because 5 is not an l-value. The value of 5 has no memory, and thus nothing can be assigned to it. 5 means 5, and its value can not be reassigned. When an l-value has a value assigned to it, the current value at that memory address is overwritten.
- An **r-value** is an expression that is not an l-value. Examples of r-values are literals (such as 5, which evaluates to 5) and non-l-value expressions (such as 2 + x).

### References to r-values extend the lifetime of the referenced value

```c++
int value{5}
const int& ref{value} 	// It is poissible! different with pointer
const int& ref2{5}		// Possible -> reference r-value
```

## Member selection with pointers and references

```c++
struct Person
{
    int age{};
    double weight{};
};

Person person{};
Person* ptr{&person};
person& ref{person};
ref.age = 5
```

There are 2 ways to select member using pointer

```c++
ptr->age = 5; // Preffered way!
(*ptr).age = 5;
```

## For-each

```c++
std::string array[]{ "peter", "likes", "frozen", "yogurt" };
for (auto element : array) // element will be a copy of the current array element
{
    std::cout << element << ' ';
}
```

- ***This means each array element iterated over will be copied into variable element***. Copying array elements can be expensive, and most of the time we really just want to refer to the original element.

```c++
std::string array[]{ "peter", "likes", "frozen", "yogurt" };
for (auto& element : array) // element will be a copy of the current array element
{
    std::cout << element << ' ';
}
```

- It avoids copying

```c++
std::string array[]{ "peter", "likes", "frozen", "yogurt" };
for (const auto& element : array) // element will be a copy of the current array element
{
    std::cout << element << ' ';
}
```

- Read only and avoid copy

