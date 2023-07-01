#include "SyncQueue.hpp"

#include <iostream>
#include <mutex>
#include <thread>

SyncQueue<int> syncQueue(5);

void PutDatas()
{
    for (int i = 0; i < 20; ++i) {
        syncQueue.Put(i+1);
    }
}

void TakeDatas()
{
    int x = 0;

    for (int i = 0; i < 20; ++i) {
        syncQueue.Take(x);
        std::cout << x << std::endl;
    }
}

int main(void)
{
    std::thread t1(PutDatas);
    std::thread t2(TakeDatas);

    t1.join();
    t2.join();

    return 0;
}