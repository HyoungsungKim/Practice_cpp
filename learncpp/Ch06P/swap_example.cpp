#include <iostream>

void my_own_swap(int& a, int& b)
{
    int temp{b};
    b = a;
    a = temp;
}

int main()
{
    int a{1};
    int b{2};
    my_own_swap(a, b);
    std::cout << a << ' ' << b << '\n';
}