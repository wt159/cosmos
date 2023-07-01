#include <iostream>
#include <mutex>
#include <thread>

struct Complex {
    std::recursive_mutex mutex;
    int i;

    Complex()
        : i(10)
    {
    }

    void mul(int x)
    {
        std::lock_guard<std::recursive_mutex> lock(mutex);
        i *= x;
    }

    void div(int x)
    {
        std::lock_guard<std::recursive_mutex> lock(mutex);
        i /= x;
    }

    void both(int x, int y)
    {
        std::lock_guard<std::recursive_mutex> lock(mutex);
        mul(x);
        div(y);
    }
};

int main(void)
{
    Complex complex;

    complex.mul(32);
    std::cout << "complex.i = " << complex.i << std::endl;

    complex.both(32, 23);   // ������������
    std::cout << "complex.i = " << complex.i << std::endl;
    return 0;
}