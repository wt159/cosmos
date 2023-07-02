#include <iostream>
#include <string>

// final specifier
struct A {
    // A::foo is final，限定该虚函数不能被重写
    virtual void foo() final;
    // Error: non-virtual function cannot be final，只能修饰虚函数
    void bar() final;
};
struct B final : A // struct B is final
{
    // Error: foo cannot be overridden as it's final in A
    void foo();
};
struct C : B // Error: B is final
{ };

// override specifier
struct Base {
    virtual void func(void) { }
};
struct Derived : Base {
    virtual void func(void) override { }
    // Error: 'void Derived::func(void)' marked 'override', but does not override
    // void func(int) override { }
};

int main(int argc, char const* argv[])
{
    B b;
    Derived d;
    return 0;
}
