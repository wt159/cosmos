#include <functional>
#include <iostream>


class A {
public:
    int i_ = 0;

    void output(int x, int y)
    {
        std::cout << x << " " << y << std::endl;
    }
};

int main(void)
{
    A a;
    std::function<void(int, int)> fr = std::bind(&A::output, &a, std::placeholders::_1, std::placeholders::_2);
    fr(1, 2); //Êä³ö 1 2

    std::function<int&(void)> fr_i = std::bind(&A::i_, &a); 
    fr_i() = 123;

    std::cout << a.i_ << std::endl; //Êä³ö 123

    return 0;
}