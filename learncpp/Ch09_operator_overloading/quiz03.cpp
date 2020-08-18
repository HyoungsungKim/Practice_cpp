#include <iostream>
#include <cassert>

class IntArray {
private:
    int* m_array{};
    int m_length{};

public:
    IntArray(const int& length): m_length(length) {
        m_array = new int[length];
    }

    // For deep copy
    IntArray(const IntArray& array):m_length{array.m_length} {
        m_array = new int[m_length];

        for (int count{0}; count < array.m_length; ++count) {
            m_array[count] = array.m_array[count];
        }

    }

    ~IntArray() {
        delete[] m_array;
    }

    int& operator[](const int& index);
    friend std::ostream& operator<<(std::ostream& out, IntArray& ar);
    IntArray& operator=(const IntArray& array);
};

int& IntArray::operator[](const int& index) {
    assert(index < m_length && index >= 0);

    return m_array[index];
}

std::ostream& operator<<(std::ostream& out, IntArray& ar) {
    for (int i{0}; i < ar.m_length; ++i) {
        out << ar[i] << ' ';
    }

    return out;
}

IntArray& IntArray::operator=(const IntArray& array) {
    if(this == &array) 
        return *this;

    delete[] m_array;

    m_length = array.m_length;
    m_array = new int[m_length];

    for (int count{0}; count<array.m_length; ++count) {
        m_array[count] = array.m_array[count];
    }

    return *this;
}

IntArray fillArray()
{
	IntArray a(5);
 
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;
 
	return a;
}
 
int main()
{
	IntArray a{ fillArray() };
	std::cout << a << '\n';
 
	auto &ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;
 
	IntArray b(1);
	b = a;
 
	std::cout << b << '\n';
 
	return 0;
}