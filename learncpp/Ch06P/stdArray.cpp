#include <iostream>
#include <array>

int main()
{
    std::array<int, 5> myArray {7, 3, 1, 9, 5};

    // ! Warning: Comparing signed and unsigned type
    for (int i{0}; i < myArray.size(); ++i)
    {
        std::cout << myArray[i] << ' ';
    }

    std::cout << '\n';
    return 0;
}