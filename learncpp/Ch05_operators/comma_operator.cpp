#include <iostream>

int main() 
{
    int x{1};
    int y{2};

    // * It prints 3
    std::cout << (++x, ++y) << '\n';

    return 0;
}