#include "../../../pattern/Singleton.hpp"
#include <iostream>
#include <string>

using namespace std;

struct A {
    A(const string&) { cout << "lvaue" << endl; }
    A(string&& x) { cout << "rvaue" << endl; }
    void Fun() { cout << "test" << endl; }
};
struct B {
    B(const string&) { cout << "lvaue" << endl; }
    B(string&& x) { cout << "rvaue" << endl; }
};
struct C {
    C(int x, double y) { }
    void Fun() { cout << "test" << endl; }
};

int main(int argc, char const* argv[])
{
    string str = "test";
    Singleton<A>::Instance(str);
    Singleton<B>::Instance(std::move(str));
    Singleton<C>::Instance(10, 1.0);

    Singleton<A>::GetInstance()->Fun();

    Singleton<A>::DestroyInstance();
    Singleton<B>::DestroyInstance();
    Singleton<C>::DestroyInstance();
    return 0;
}