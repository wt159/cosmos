#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <cstring>

void f1(int n)
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "正在执行线程1\n";
        ++n;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
 
void f2(int& n)
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "正在执行线程2\n";
        ++n;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
 
class foo
{
public:
    void bar()
    {
        for (int i = 0; i < 5; ++i)
        {
            std::cout << "正在执行线程3\n";
            ++n;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
    int n = 0;
};
 
class baz
{
public:
    void operator()()
    {
        for (int i = 0; i < 5; ++i)
        {
            std::cout << "正在执行线程4\n";
            ++n;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
    int n = 0;
};
 
int testCreate()
{
    int n = 0;
    foo f;
    baz b;
    std::thread t1; // t1 不是线程
    std::thread t2(f1, n + 1); // 按值传递
    std::thread t3(f2, std::ref(n)); // 按引用传递
    std::thread t4(std::move(t3)); // t4 现在运行 f2()。t3 不再是线程
    std::thread t5(&foo::bar, &f); // t5 在对象 f 上运行 foo::bar()
    std::thread t6(b); // t6 在对象 b 的副本上运行 baz::operator()
    t2.join();
    t4.join();
    t5.join();
    t6.join();
    std::cout << "n 的最终值是 " << n << '\n';
    std::cout << "f.n (foo::n) 的最终值是 " << f.n << '\n';
    std::cout << "b.n (baz::n) 的最终值是 " << b.n << '\n';
}

void testJoin()
{
    std::thread t;
    std::cout << "before starting, joinable: " << std::boolalpha << t.joinable()
              << '\n';
 
    t = std::thread(f1, 10);
    std::cout << "after starting, joinable: " << t.joinable() 
              << '\n';
 
    t.join();
    std::cout << "after joining, joinable: " << t.joinable() 
              << '\n';
}

void testOther()
{
    std::thread t1([]() {
        // 休眠5秒
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cout << "t1\n";
    });
    std::cout << "t1 id: " << t1.get_id() << '\n'; // 输出线程t1的id
    t1.detach();    // 线程t1和主线程分离，主线程不再等待t1执行完毕
    std::thread::id id = std::this_thread::get_id();
    std::cout << "id: " << id << '\n';
    // hardware_concurrency()返回CPU核心数,不是百分百准确
    auto thread_num = std::thread::hardware_concurrency();
    std::cout << "thread_num: " << thread_num << '\n';
}

// 在 POSIX 系统上用 native_handle 启用 C++ 线程的实时调度
void testNativeHandle()
{
    std::thread t([]() {
        std::cout << "t\n";
    });
    // 获取线程的原生句柄
    auto handle = t.native_handle();
    // 设置线程的调度策略为实时调度策略
    sched_param sch;
    sch.sched_priority = 1;
    if (pthread_setschedparam(handle, SCHED_FIFO, &sch)) {
        std::cout << "Failed to setschedparam: " << std::strerror(errno) << '\n';
    }
    t.join();
}

int main(void)
{
    testCreate();
    testJoin();
    testOther();
    testNativeHandle();
    return 0;
}