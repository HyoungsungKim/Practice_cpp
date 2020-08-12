#include <iostream>

/*
 * constexpr ensures that a constant must be a compile-time constant
*/
int main() 
{
    constexpr double gravity{9.8};
    constexpr int sum{4 + 5};

    std::cout << "Enter your age : ";
    int age;
    std::cin >> age;
    constexpr int myAge{age}; // * Wrong

    return 0;
}