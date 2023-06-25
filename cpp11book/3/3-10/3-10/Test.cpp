#include "DllParser.hpp"

#include <iostream>

void TestDllParser()
{
    DllParser dllParser;
    std::string str("libMyDLL.dll");

    dllParser.Load(str);

    int a = 5;
    int b = 8;

    auto max = dllParser.ExcecuteFunc<int(const int, const int)>("Max", a, b);
    std::cout << "max = " << max << std::endl;
    auto add = dllParser.ExcecuteFunc<int(int, int)>("Add", a, b);
    std::cout << "add = " << add << std::endl;
    auto get = dllParser.ExcecuteFunc<int(int)>("Get", a);
    std::cout << "get = " << get << std::endl;
}

int main(void)
{
    TestDllParser();
    return 0;
}