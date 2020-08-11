#include <iostream>

int readNumber()
{
    int number{};
    std::cout << "read : ";
    std::cin >>number;
    return number;
}


void writeAnswer(int number)
{
    std::cout << number << '\n';
}