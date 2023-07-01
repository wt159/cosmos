#include <iostream>
#include <memory>
#include <functional>
#include <type_traits>

//支持普通指针
template <class T, class... Args>
inline
    typename std::enable_if<!std::is_array<T>::value, std::unique_ptr<T>>::type
    make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

//支持动态数组
template <class T>
inline
    typename std::enable_if<std::is_array<T>::value && std::extent<T>::value == 0, std::unique_ptr<T>>::type
    make_unique(size_t size)
{
    typedef typename std::remove_extent<T>::type U;
    return std::unique_ptr<T>(new U[size]());
}

//过滤掉定长数组的情况
template <class T, class... Args>
typename std::enable_if<std::extent<T>::value != 0, void>::type
make_unique(Args&&...)
    = delete;

void testInit()
{
    std::cout << "\nunique_ptr init:" << std::endl;
    std::unique_ptr<int> p(new int(10));
    // std::unique_ptr<int> p1 = new int(10);   // error, 不可以直接赋值
    // std::unique_ptr<int> p1 = p;             // error, 不可以复制
    std::unique_ptr<int> p2 = std::move(p);     // ok  转移所有权
    // std::cout << *p << std::endl;            // error, p已经没有指向的对象了
    std::cout << *p2 << std::endl;
    auto unique = make_unique<int>(100);
    std::cout << *unique << std::endl;
}

struct MyDeleter
{
    void operator()(int *p) const
    {
        std::cout << __func__ <<  " : " << *p << std::endl;
        delete p;
    }
};
void MyDeleteFunc(int* p)
{
    std::cout << __func__ <<  " : " << *p << std::endl;
    delete p;
}
void testDelete()
{
    std::cout << "\nunique_ptr delete:" << std::endl;
    std::unique_ptr<int, void(*)(int*)/* 必须指定类型 */> p(new int(10), [](int* p) {
        std::cout << "delete int:" << *p << std::endl;
        delete p;
    });
    // 支持lambda表达式
    std::unique_ptr<int, std::function<void(int*)>> p2(new int(10), [&](int* p) {
        std::cout << "delete int:" << *p << std::endl;
        delete p;
    });
    // 自定义删除器
    std::unique_ptr<int, MyDeleter> p3(new int(11));
    std::unique_ptr<int, void(*)(int*)> p4(new int(12), MyDeleteFunc);
    std::unique_ptr<int, decltype(&MyDeleteFunc)> p5(new int(13), MyDeleteFunc);
    std::unique_ptr<int, std::function<decltype(MyDeleteFunc)>> p6(new int(14), MyDeleteFunc);
}

void testArray()
{
    std::cout << "\nunique_ptr array:" << std::endl;
    auto unique2 = make_unique<int[]>(10);

    for (int i = 0; i < 10; i++) {
        unique2[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        std::cout << unique2[i] << " ";
    }
    std::cout << std::endl;
}

int main(void)
{
    testInit();
    testDelete();
    testArray();
    return 0;
}