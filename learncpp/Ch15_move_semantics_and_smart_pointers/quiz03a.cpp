#include <iostream>
#include <memory>

class Resource {
public:
    int m_id{};
    Resource() {std::cout << "Resource acquired\n";}
    ~Resource() {std::cout << "Resource destroyed\n";}
};


int main() {
    // When ptr1 is deallocated, ptr2 has nothing to deallocate.
    /*
    Resource* res = new Resource;
    std::shared_ptr<Resource> ptr1(res);
    std::shared_ptr<Resource> ptr2(res);
    */
    //std::shared_ptr<Resource> ptr1(res);
    //std::shared_ptr<Resource> ptr2(ptr1);    

    auto ptr1{std::make_shared<Resource>()};
    ptr1->m_id = 1;
    std::cout << "Copy\n";
    auto ptr2(ptr1);
    std::cout << ptr1->m_id << " " << ptr2->m_id << '\n';
    ptr2->m_id = 2;
    std::cout << ptr1->m_id << " " << ptr2->m_id << '\n';
    // Copy of shared_ptr is shallow copy
    std::cout << &(*ptr1) << " " << &(*ptr2) << '\n';
}
