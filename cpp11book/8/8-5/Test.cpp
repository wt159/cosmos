#include "../../../object_pool/ObjectPool.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
using namespace std;

#include <iostream>
struct BigObject {
    BigObject() { }
    BigObject(int a) { }
    BigObject(const int a, const int b) { }
    void Print(const string& str) { cout << str << endl; }
};
void Print(shared_ptr<BigObject> p, const string& str)
{
    if (p != nullptr) {
        p->Print(str);
    }
}
void TestObjPool()
{
    ObjectPool<BigObject> pool;
    pool.init(2); // 初始化对象池，初始创建两个对象
    {
        auto p = pool.get();
        Print(p, "p");
        auto p2 = pool.get();
        Print(p2, "p2");
    } // 出了作用域之后，对象池返回出来的对象又会自动回收
    auto p = pool.get();
    auto p2 = pool.get();
    Print(p, "p");
    Print(p2, "p2");
    // 对象池支持重载构造函数
    pool.init(2, 1);
    auto p4 = pool.get<int>();
    Print(p4, "p4");

    pool.init(2, 1, 2);
    auto p5 = pool.get<int, int>();
    Print(p5, "p5");
}
int main()
{
    TestObjPool();
    return 0;
}