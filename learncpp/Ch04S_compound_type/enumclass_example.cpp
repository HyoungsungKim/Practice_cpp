#include <iostream>

int main() 
{
    enum class Color
    {
        red,
        blue
    };

    enum class Fruit
    {
        banana,
        blue
    };

    Color color{ Color::red };
    Fruit fruit{ Fruit::banana };

    // * Compiler error!
    // * enum class make variable type safe
    if (color == fruit)
    {
        std::cout << "Color and fruit are equal\n";
    }
    else
    {
        std::cout << "color and fruit are not equal\n";
    }
    
    return 0;
}