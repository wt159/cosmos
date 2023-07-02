#include <iostream>
#include <string>
#include <assert.h>
#include <type_traits>
#include <cstddef>
using namespace std;

inline void* aligned_malloc(size_t size, size_t alignment)
{
    // 检查alignment是否为2的幂
    assert((alignment & (alignment - 1)) == 0);
    // 计算出一个最大的offset, sizeof(void*)是为了存储offset
    size_t offset = alignment - 1 + sizeof(void*);
    // 分配内存
    void *p1 = malloc(size + offset);
    if(!p1) return nullptr;
    // 计算对齐后的内存地址
    void *p2 = (void*)(((size_t)p1 + offset) & ~(alignment - 1));
    // 将offset存储在对齐后的内存地址的前sizeof(void*)个字节
    ((void**)p2)[-1] = p1;
    return p2;
}
inline void aligned_free(void *p)
{
    // 读取offset
    void *p1 = ((void**)p)[-1];
    free(p1);
}

struct MyStruct {
    char a;         // 1 byte
    int b;          // 4 bytes
    short c;        // 2 bytes
    long long d;    // 8 bytes
    char e;         // 1 byte
};

struct A {
    int avg;
    A(int a, int b) : avg((a + b) / 2) {}
};
typedef std::aligned_storage<sizeof(A), alignof(A)>::type Aligned_A;

int main(int argc, char const* argv[])
{
    cout << "sizeof(char) = " << sizeof(char) << endl;
    cout << "sizeof(short) = " << sizeof(short) << endl;
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(long long) = " << sizeof(long long) << endl;
    cout << "sizeof(MyStruct) = " << sizeof(MyStruct) << endl;
    
    MyStruct myStruct;
    char *p1 = &(myStruct.a);
    int *p = &(myStruct.b);
    short *p2 = &(myStruct.c);
    long long *p3 = &(myStruct.d);
    char *p4 = &(myStruct.e);
    cout << (int*)p1 << endl;
    cout << p << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cout << (int*)p4 << endl;
    int num = (size_t)(int*)p4 - (size_t)(int*)p1;
    cout << num << endl;
    cout << "alignof(myStruct) = " << alignof(myStruct) << endl;
    cout << "alignof(MyStruct) = " << alignof(MyStruct) << endl;
    cout << "alignment_of<MyStruct>::value = " << alignment_of<MyStruct>::value << endl;
    cout << "alignof(std::max_align_t) = " << alignof(std::max_align_t) << endl;
    cout << "alignment_of<std::max_align_t>::value = " << alignment_of<std::max_align_t>::value << endl;

    Aligned_A a,b;
    new (&a) A(1, 2);
    b = a;
    cout << "reinterpret_cast<A&>(b).avg:" << reinterpret_cast<A&>(b).avg << endl;
    return 0;
}
