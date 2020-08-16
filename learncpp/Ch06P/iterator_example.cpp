#include <array>
#include <iostream>

int main()
{
    std::array<int, 3> array{1,2,3};

    auto begin{array.begin()};
    auto end{array.end()};

    // * Work identically with for-each
    for (auto p{begin}; p != end; ++p)
    {
        std::cout << *p << ' ';
    }
    std::cout << '\n';

    return 0;
}
