#include <algorithm>
#include <array>
#include <iostream>

int main()
{
    std::array arr{13, 90, 99, 5, 40, 80};
    std::cout << "Enter a value to search for and replace with : ";
    int search{};
    int replace{};

    std::cin >> search >> replace;
    auto found{ std::find(arr.begin(), arr.end(), search)};

    if (found != arr.end())
    {
        *found = replace;
    }
    else
    {
        std::cout << "Could not find " << search << '\n';
    }

    for (int i : arr)
    {
        std::cout << i << ' ';
    }
    
    return 0;
}