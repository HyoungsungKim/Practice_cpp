#include <iostream>

int main()
{
    switch(2)
    {
        case 1:
            std::cout << 1 << '\n';
            break;
        case 2:
            std::cout << 2 << '\n';
            break;
        default:
        std::cout << "default case\n";
    }

    return 0;
}