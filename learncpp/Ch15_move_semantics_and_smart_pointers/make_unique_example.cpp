#include <iostream>
#include <memory>

class Fraction {
private:
    int m_numerator{0};
    int m_denominator{1};

public:
    Fraction(int numerator = 0, int denominator = 1) 
    : m_numerator{numerator}, m_denominator{denominator} {}

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1) {
        out << f1.m_numerator << '/' << f1.m_denominator;

        return out
    }
};

int main() {
    auto f1{std::make_unique<Fraction>(3, 5)};
    std::cout << *f1 << '\n';

    auto f2{std::make_unique<Fraction[]>(4)};
    std::cout << f2[0] << '\n';
}