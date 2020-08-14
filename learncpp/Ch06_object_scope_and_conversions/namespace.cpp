#include <iostream>

int doSomething(int x, int y)
{
    return x * y;
}

namespace foo
{
    int doSomething(int x, int y)
    {
        return x + y;
    }
}

namespace goo
{
    int doSomething(int x, int y)
    {
        return x - y;
    }
}

int main()
{
    std::cout << foo::doSomething(4, 3) << '\n';
    std::cout << goo::doSomething(4, 3) << '\n';
    std::cout << ::doSomething(4, 3) << '\n';
}