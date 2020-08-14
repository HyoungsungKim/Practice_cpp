#include <iostream>

extern int g_x;
extern const int g_y;
// const int g_z; compile error!
// const global vairable is not initialized automatically

int main()
{
    std::cout << g_x << '\n';
    // std::cout << g_z << '\n';
    return 0;
}