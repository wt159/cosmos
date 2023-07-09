#include "ThreadPool.hpp"
#include <iostream>
#include <string>

void test_pool()
{
    thread_pool pool;
    for (size_t i = 0; i < 10; i++) {
        pool.add_task([] {
            std::this_thread::sleep_for(std::chrono::microseconds(50));
            std::cout << "hello world!" << std::endl;
        });
    }

    std::this_thread::sleep_for(std::chrono::seconds(2));
}

int main()
{
    test_pool();

    return 0;
}
