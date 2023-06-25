#include "MyDLL.h"

#include <iostream>
#include <windows.h>

void TestDll()
{
    typedef int (*pMax)(int a, int b);
    typedef int (*pGet)(int a);

    HINSTANCE hDLL = LoadLibrary("libMyDLL.dll");
    if (hDLL == nullptr) {
        std::cout << "LoadLibrary failed\n";
        return;
    }

    pMax Max = (pMax)GetProcAddress(hDLL, "Max");
    if (Max == nullptr) {
        std::cout << "GetProcAddress Max failed\n";
        return;
    }

    int a = 5, b = 8;
    int ret = Max(a, b);
    std::cout << "Max = " << ret << "\n";

    pGet Get = (pGet)GetProcAddress(hDLL, "Get");
    if (Get == nullptr) {
        std::cout << "GetProcAddress Get failed\n";
        return;
    }

    int ret2 = Get(a);
    std::cout << "Get = " << ret2 << "\n";

    FreeLibrary(hDLL);
}

int main(void)
{
    TestDll();
    return 0;
}