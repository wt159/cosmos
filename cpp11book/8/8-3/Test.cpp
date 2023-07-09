#include "../../../pattern/Visitor.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct stA;
struct stB;
struct Base {
    // 定义通用的访问者类型，它可以访问stA和 stB
    typedef Visitor<stA, stB> MytVisitor;
    virtual void Accept(MytVisitor&) = 0;
};
struct stA : Base {
    double val;
    void Accept(Base::MytVisitor& v) { v.Visit(*this); }
};
struct stB : Base {
    int val;
    void Accept(Base::MytVisitor& v) { v.Visit(*this); }
};
struct PrintVisitor : Base::MytVisitor {
    void Visit(const stA& a) { std::cout << "from stA: " << a.val << std::endl; }
    void Visit(const stB& b) { std::cout << "from stB: " << b.val << std::endl; }
};

void TestVisitor()
{
    PrintVisitor vis;
    stA a;
    a.val = 8.97;
    stB b;
    b.val = 8;
    Base* base = &a;
    base->Accept(vis);
    base = &b;
    base->Accept(vis);
}

int main()
{
    TestVisitor();
    return 0;
}