#include <iostream>
#include <random>
#include <ctime>

int main()
{
    std::mt19937 mersenn{static_cast<std::mt19937::result_type>(std::time(nullptr))};
    // ! Since c++17, std::uniform_int_distribution die{1,6}; is possible
    std::uniform_int_distribution<> die{1,6};

    for (int count{1}; count <= 48; ++count)
    {
        std::cout << die(mersenn) << '\t';

        if (count % 6 == 0)
            std::cout << '\n';
    }

    return 0;
}