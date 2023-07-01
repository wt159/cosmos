#include <iostream>
#include <memory>

void testInit()
{
    // init
    std::cout << "\nshared_ptr init:" << std::endl;
    std::shared_ptr<int> p(new int(10));
    std::cout << *p << std::endl;
    std::shared_ptr<int> p2 = p;
    std::cout << *p2 << std::endl;
    std::cout << "p use_count:" << p.use_count() << std::endl;
    std::shared_ptr<int> p3;
    p3.reset(new int(20));
    if (p3) {
        std::cout << "p3 is not null:" << *p3 << std::endl;
    }
    // std::shared_ptr<int> p4 = new int(1); // error, 不可以直接赋值
    std::shared_ptr<int> p5 = std::make_shared<int>(10);
}

void testRawPointer()
{
    std::cout << "\nshared_ptr raw pointer:" << std::endl;
    std::shared_ptr<int> ptr(new int(10));
    std::cout << *ptr << std::endl;
    int* p = ptr.get();
    std::cout << *p << std::endl;
}

void DeleteInt(int* p)
{
    std::cout << "delete int:" << *p << std::endl;
    delete p;
}
void testDelete()
{
    std::cout << "\nshared_ptr delete:" << std::endl;
    std::shared_ptr<int> p(new int(10), DeleteInt);
    std::cout << *p << std::endl;
}

template <typename T>
std::shared_ptr<T> make_shared_array(size_t size)
{
    return std::shared_ptr<T>(new T[size], std::default_delete<int[]>());
}

void testArray()
{
    std::cout << "\nshared_ptr array:" << std::endl;
    // 自定义删除器
    std::shared_ptr<int> p(new int[10], [](int* p) {
        std::cout << "delete array" << std::endl;
        delete[] p;
    });
    for (int i = 0; i < 10; i++) {
        p.get()[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        std::cout << p.get()[i] << " ";
    }
    std::cout << std::endl;

    // 使用std::default_delete作为删除器
    std::shared_ptr<int> p2(new int[10], std::default_delete<int[]>());
    // 使用make_shared_array
    std::shared_ptr<int> p3 = make_shared_array<int>(10);
}

void testNotice()
{
    std::cout << "\nshared_ptr notice:" << std::endl;
    // 1. 不要用一个原始指针初始化多个shared_ptr
    // 2. 不要在函数实参中创建shared_ptr
    // 3. 通过shared_from_this（）返回this指针
    // 4. 要避免循环引用
}

int main(int argc, char const* argv[])
{
    testInit();
    testRawPointer();
    testDelete();
    testArray();
    return 0;
}