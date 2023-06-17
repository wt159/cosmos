# 《深入应用C++11 代码优化与工程级应用》

**祁宇**大佬的著作。原书仓库[qicosmos](https://github.com/qicosmos/cosmos)

## 学习笔记

| 章节 | 描述 |
| --- | --- |
| [1-1](./cpp11book/1/1-1/1-1/Test.cpp) | auto关键字的用法 |
| [1-2](./cpp11book/1/1-2/1-2/Test2.cpp) | 模版的用法 |
| [1-3](./cpp11book/1/1-3/1-3/Test.cpp) | decltype关键字用法：编译时推导出表达式的类型|
| [1-4~1-5](./cpp11book/1/1-4/1-4/Test.cpp) | decltype进阶用法 |
| [1-7~1-10](./cpp11book/1/1-7/1-7/Test.cpp) | 列表初始化的用法 |
| [1-14~1-15](./cpp11book/1/1-11~1-15/1-11~1-15/Test.cpp) | for循环的新用法 |
| [1-16](./cpp11book/1/1-16/1-16/Test.cpp) | 可调用对象 |
| [1-17~1-19](./cpp11book/1/1-17/1-17/Test.cpp) | std:function |
| [1-20~1-22](./cpp11book/1/1-20/1-20/Test.cpp) | bind |
| [1-23](./cpp11book/1/1-23/1-23/Test.cpp) | lambda |
| [1-24](./cpp11book/1/1-24/1-24/Test.cpp) | std::for_each用法 |
| [2-1](./cpp11book/2/2-1/2-1/Test.cpp) | &&的特性 |
| [2-2~2-3](./cpp11book/2/2-2/2-2/Test.cpp) | 右值引用优化性能，避免深拷贝 |
| [2-4](./cpp11book/2/2-4/2-4/Test.cpp) | move语义 forward和完美转发 |
| [2-5](./cpp11book/2/2-5/2-5/Test.cpp) | emplace_back减少内存拷贝和移动 |
| [2-6](./cpp11book/2/2-6/2-6/Test.cpp) | unordered_map无序容器 |
| [3-1](./cpp11book/3/3-1/3-1/Test.cpp) | type_traits类型转换 |
| [3-2](./cpp11book/3/3-2/3-2/Test.cpp) | type_traits类型获取:获取可调用对象的返回类型 |
| [3-3](./cpp11book/3/3-3/3-3/Test.cpp) | 可变参数模版消除重复代码：泛型打印函数 |
| [3-4](./cpp11book/3/3-4/3-4/Test.cpp) | 可变参数模版消除重复代码：创建对象工厂函数 |
| [3-5](./cpp11book/3/3-5/3-5/optional.hpp) | 可变参数模版和type_traits综合应用：optional |
| [3-7](./cpp11book/3/3-7~3-8/3-7~3-8/Test.cpp) | 可变参数模版和type_traits综合应用：lazy |

## optional

类模板 std::optional 管理一个可选的容纳值，既可以存在也可以不存在的值。

一种常见的 optional 使用情况是一个可能失败的函数的返回值。与其他手段，如 std::pair\<T,bool> 相比， optional 良好地处理构造开销高昂的对象，并更加可读，因为它显式表达意图。

任何一个 optional\<T> 的实例在给定时间点要么含值，要么不含值。

若一个 optional\<T> 含值，则保证值作为 optional 对象所用空间的一部分分配，即不会发生动态内存分配。从而 optional 对象模拟一个对象，而非指针，尽管定义了 operator*() 和 operator->() 运算符。

当一个 optional\<T> 对象被按语境转换成 bool 时，若对象含值则转换返回 true ，若对象不含值则返回 false 。

optional 对象在下列条件下含值：

* 对象被以 T 类型值或另一含值的 optional 初始化/赋值。

对象在下列条件下不含值：

* 对象被默认初始化。
* 调用了成员函数 reset() 。

## 惰性求值`lazy`

惰性求值一般用于函数式编程，在使用延迟求值时，表达式不在它被绑定到变量之后立即求值，而是在后面某个时候求值。

典型使用场景：当初始化某个对象时，该对象引用了一个大对象，这个对象的创建需要较长的时间，同时也需要在堆上分配较多的空间，这样可能会在初始化时变得很慢，尤其是UI应用时会导致用户体验很差。其实很多时候并不需要马上就获取大数据，只是在需要时获取，这种场景就很适合延迟加载。
