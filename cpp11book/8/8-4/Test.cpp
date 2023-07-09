#include "../../../pattern/Command.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct STA {
    int m_a;
    int operator()() { return m_a; }
    int operator()(int n) { return m_a + n; }
    int triple0() { return m_a * 3; }
    int triple(int a) { return m_a * 3 + a; }
    int triple1() const { return m_a * 3; }
    const int triple2(int a) const { return m_a * 3 + a; }
    void triple3() { cout << "" << endl; }
};
int add_one(int n) { return n + 1; }
void TestWrap()
{
    CommCommand<int> cmd;
    STA sta = { 10 };
    // 接受普通函数
    cmd.Wrap(add_one, 0);
    // 接受lambda表达式
    cmd.Wrap([](int n) { return n + 1; }, 1);
    // 接受函数对象
    cmd.Wrap(sta);
    cmd.Wrap(sta, 4);
    STA t = { 10 };
    int x = 3;
    // 接受成员函数
    cmd.Wrap(&STA::triple0, &t);
    cmd.Wrap(&STA::triple, &t, x);
    cmd.Wrap(&STA::triple, &t, 3);
    cmd.Wrap(&STA::triple2, &t, 3);
    auto r = cmd.Excecute();
    CommCommand<> cmd1;
    cmd1.Wrap(&STA::triple3, &t);
    cmd1.Excecute();
}

int main()
{
    TestWrap();
    return 0;
}