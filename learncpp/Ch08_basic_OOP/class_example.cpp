#include <iostream>

class IntPair
{
public:
    int p1{};
    int p2{};

    void set(const int& a, const int& b) {
        p1 = a;
        p2 = b;
    }

    void print() {
        std::cout << "Pair(" << p1 << ", " << p2 << ")" << '\n';
    }
};

int main() {
    IntPair p1;
    p1.set(1,1);

    IntPair p2{2, 2};
    p1.print();
    p2.print();

    return 0;
}
