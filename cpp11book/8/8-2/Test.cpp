#include "../../../pattern/Observer.hpp"
#include <iostream>
#include <string>
using namespace std;

struct stA {
    int a, b;
    void print(int a, int b) { cout << a << ", " << b << endl; }
};

void print(int a, int b) { cout << a << ", " << b << endl; }

int main()
{
    Events<std::function<void(int, int)>> myevent;
    auto key = myevent.Connect(print); // 以函数方式注册观察者
    stA t;
    auto lambdakey = myevent.Connect([&t](int a, int b) {
        t.a = a;
        t.b = b;
    }); // lamda注册
    // std::function注册
    std::function<void(int, int)> f
        = std::bind(&stA::print, &t, std::placeholders::_1, std::placeholders::_2);
    myevent.Connect(f);
    int a = 1, b = 2;
    myevent.Notify(a, b); // 广播所有观察者
    myevent.Disconnect(key); // 移除观察者
    return 0;
}