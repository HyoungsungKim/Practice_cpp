#include <iostream>

int main()
{
    int value{5};
    int* ptr{&value};

    std::cout << &value << '\n';
    std::cout << ptr << '\n';
    std::cout << *ptr << '\n';

    return 0;
}