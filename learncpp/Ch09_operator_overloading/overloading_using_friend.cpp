#include <iostream>

class Cents {
private:
    int m_cents{};

public:
    Cents(int cents): m_cents(cents) {}

    // This function is not considered a member of the class, even though the definition is inside the class
    friend Cents operator+(const Cents& c1, const Cents& c2) {
        return Cents(c1.m_cents + c2.m_cents);
    }

    int getCents() const { return m_cents; }
};

int main() {
    Cents cents1{ 6 };
    Cents cents2{ 8 };
    Cents centSum{ cents1 + cents2 };
    std::cout << "I have " << centSum.getCents() << " cents.\n";
}