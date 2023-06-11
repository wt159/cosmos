#include "optional.hpp"
#include <iostream>
#include <map>
#include <string>

struct MyStruct {
    MyStruct() { }
    MyStruct(int a, int b)
        : m_a(a)
        , m_b(b)
    {
    }
    int m_a;
    int m_b;
};

void TestOptional()
{
    optional<std::string> a("ok");
    optional<std::string> b("ok");
    optional<std::string> c("aa");

    c = a;

    optional<MyStruct> op;
    op.emplace(1, 2);
    MyStruct t;

    if (op) //判断op是否被初始化
    {
        t = *op;
    }

    op.emplace(3, 4);
    t = *op;
}

int main(void)
{
    TestOptional();

    return 0;
}