#include <iostream>
#include <memory>

void testUseAge()
{
    std::shared_ptr<int> sp(new int(10));
    std::weak_ptr<int> wp(sp);
    std::cout << "sp use_count:" << sp.use_count() << std::endl;
    std::cout << "wp use_count:" << wp.use_count() << std::endl;

    if (!wp.expired()/* 判断智能指针内部资源是否被释放 */) { 
        std::shared_ptr<int> sp2 = wp.lock();/* 通过lock获取所监视的shared_ptr */
        std::cout << "sp2 use_count:" << sp2.use_count() << std::endl;
    } else {
        std::cout << "wp is expired" << std::endl;
    }
}

struct A;
struct B;
struct A
{
    std::shared_ptr<B> bptr;
    ~A() { std::cout << "A is deleted" << std::endl; }
};
struct B
{
#if 0
    std::shared_ptr<A> aptr;     // 会造成循环引用
#else
    std::weak_ptr<A> aptr;
#endif
    ~B() { std::cout << "B is deleted" << std::endl; }
};

void testCycle()
{
    std::shared_ptr<A> a(new A());
    std::shared_ptr<B> b(new B());
    a->bptr = b;
    b->aptr = a;
}

int main(int argc, char const *argv[])
{
    testUseAge();
    testCycle();
    return 0;
}
