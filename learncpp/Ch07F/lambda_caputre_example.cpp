#include <iostream>
#include <functional>
 
void invoke(const std::function<void(void)>& fn)
{
    fn();
}
 
int main()
{
    int i{ 0 };
 
    // Increments and prints its local copy of @i.
    auto count{ [&i]() mutable {
      std::cout << ++i << '\n';
    } };
 
    invoke(count);
    invoke(count);
    invoke(count);
    //invoke(std::ref(count));
    //invoke(std::ref(count));
    //invoke(std::ref(count));
    std::cout << i << '\n';
 
    return 0;
}