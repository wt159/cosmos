#include <iostream>
#include <mutex>
#include <thread>

std::mutex g_lock;
void func()
{
    g_lock.lock();
    std::cout << "entered thread " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "leaving thread " << std::this_thread::get_id() << std::endl;
    g_lock.unlock();
}
void testBase()
{
    std::thread t1(func);
    std::thread t2(func);
    std::thread t3(func);
    t1.join();
    t2.join();
    t3.join();
}
struct Complex {
    std::mutex mutex;
    int i;

    Complex()
        : i(0)
    {
    }

    void mul(int x)
    {
        std::lock_guard<std::mutex> lock(mutex);
        i *= x;
    }

    void div(int x)
    {
        std::lock_guard<std::mutex> lock(mutex);
        i /= x;
    }

    void both(int x, int y)
    {
        std::lock_guard<std::mutex> lock(mutex);
        mul(x);
        div(y);
    }
};

void testLockGuard()
{
    Complex complex;

    complex.mul(32);
    std::cout << "complex.i = " << complex.i << std::endl;

    // complex.both(32, 23);   // 会死锁
    // std::cout << "complex.i = " << complex.i << std::endl;
}

int main(void)
{
    testBase();
    testLockGuard();
    return 0;
}