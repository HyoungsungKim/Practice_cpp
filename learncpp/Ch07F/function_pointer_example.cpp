#include <iostream>
#include <functional>

int add(const int& x, const int& y)
{
    return x + y;
}

int substract(const int& x, const int& y)
{
    return x - y;
}

int multiply(const int& x, const int& y)
{
    return x * y;
}

int divide(const int& x, const int& y)
{
    return x / y;
}

int getArithmeticFunction(int x, int y, std::function<int(int, int)> arithmetic)
{
    return arithmetic(x, y);
}

int main()
{
    int x{};
    int y{};
    int result{};
    char operation{};

    std::function<int(int, int)> arithmeticFcn;
    std::cin >> x >> operation >> y;

    switch(operation)
    {
        case '+':
        {
            arithmeticFcn = &add;
            break;
        }
        case '-':
        {
            arithmeticFcn = &substract;
            break;
        }
        case '*':
        {
            arithmeticFcn = &multiply;
            break;
        }
        case '/':
        {
            arithmeticFcn = &divide;
            break;
        }
    }

    std::cout << getArithmeticFunction(x, y, arithmeticFcn) << '\n';
}