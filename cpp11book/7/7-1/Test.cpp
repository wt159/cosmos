#include <iostream>
#include <string>

class MyClass {
private:
    int m_min;
    int m_max;
    int m_middle;
    int m_num;

public:
    MyClass() { }
    MyClass(int max)
        : m_num(0) // suc
    {
        m_max = max > 0 ? max : 10;
    }
#if 0
    MyClass(int min, int max) {
        m_max = max > 0 ? max : 10;
        m_min = (min > 0 && min < max) ? min : 1;
    }
    MyClass(int min, int max, int middle) {
        m_max = max > 0 ? max : 10;
        m_min = (min > 0 && min < max) ? min : 1;
        m_middle = (middle < max && middle > min) ? middle : 5;
    }
#else
    MyClass(int min, int max)
        : MyClass(max)
    // , m_num(0) // err, 委托构造函数不能有初始化列表
    {
        m_min = (min > 0 && min < max) ? min : 1;
    }
    MyClass(int min, int max, int middle)
        : MyClass(min, max)
    {
        m_middle = (middle < max && middle > min) ? middle : 5;
    }
#endif
};

struct Base {
    int x;
    double y;
    std::string s;
    Base(int i)
        : x(i)
        , y(0)
    {
    }
    Base(int i, double j)
        : x(i)
        , y(j)
    {
    }
    Base(int i, double j, const std::string& str)
        : x(i)
        , y(j)
        , s(str)
    {
    }
    void func() { std::cout << "Base::func()" << std::endl; }
};
struct Derived : Base {
    using Base::Base;
    using Base::func;
    void func(int a) { std::cout << "Derived::func(int)" << std::endl; }
};

int main(int argc, char const* argv[])
{
    MyClass myClass1 { 1, 3, 2 };
    Derived d1(1);
    Derived d2(1, 2.5);
    Derived d3(1, 2.5, "hello");
    d1.func();
    d2.func(1);
    return 0;
}
