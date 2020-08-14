#include <cstdlib>
#include <iostream>

void cleanup()
{

}

int main()
{
    std::cout << 1 << '\n';
    cleanup();

    std::exit(0);

    std::cout << 2 << '\n';
    return 0;
}