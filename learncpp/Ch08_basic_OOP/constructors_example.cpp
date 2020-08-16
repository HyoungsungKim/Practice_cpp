#include <iostream>

class Fraction {
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction() {
        m_numerator = 0;
        m_denominator = 1;
    }

    int getNumberator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};

int main() {
    Fraction frac;
    std::cout << frac.getNumberator() << '/' << frac.getDenominator() << '\n';
    
    return 0;
}