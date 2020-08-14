#include <iostream>

namespace v1 {
    void doSomething() {
        std::cout << "v1\n";
    }
}

inline namespace v2 {
    void doSomething() {
        std::cout << "v2\n";
    }
}

int main() {
    v1::doSomething();
    v2::doSomething();

    doSomething();  // * It calls inline namespace function

    return 0;
}