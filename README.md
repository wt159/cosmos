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
| [3-9](./cpp11book/3/3-9/3-9/Test.cpp) | dll函数调用 |
| [3-10](./cpp11book/3/3-10/3-10/Test.cpp) | 综合应用：通用dll函数帮助类 |
| [3-12](./cpp11book/3/3-12/3-12/Test.cpp) | 综合应用：lambda链式调用 |
| [3-13](./cpp11book/3/3-13/3-13/Test.cpp) | 综合应用：Any类 |
| [3-15](./cpp11book/3/3-15/3-15/Test.cpp) | 综合应用：Variant类 |
| [3-16](./cpp11book/3/3-16/3-16/Test.cpp) | 综合应用：ScopeGuard类 |
| [3-17~3-21](./cpp11book/3/3-17/3-17/Test.cpp) | std::tuple使用方法 |
| [3-22](./cpp11book/3/3-22/3-22/Test.cpp) | 遍历tuple |
| [3-23](./cpp11book/3/3-23/3-23/Test.cpp) | 反转tuple |
| [3-24](./cpp11book/3/3-24/3-24/Test.cpp) | 函数应用tuple |
| [3-25](./cpp11book/3/3-25/3-25/Test.cpp) | 合并tuple |
| [4-1](./cpp11book/4/4-1/4-1/Test.cpp) | 智能指针`std::shared_ptr`用法 |
| [4-2](./cpp11book/4/4-2/4-2/Test.cpp) | 智能指针`std::unique_ptr`用法 |
| [4-3](./cpp11book/4/4-3/4-3/Test.cpp) | 智能指针`std::weak_ptr`用法 |
| [5-1](./cpp11book/5/5-1/5-1/Test.cpp) | 线程`std::thread`用法 |
| [5-2](./cpp11book/5/5-2/5-2/Test.cpp) | 互斥锁`std::mutex`用法 |
| [5-3](./cpp11book/5/5-3/5-3/Test.cpp) | 互斥锁`std::recursive_mutex`用法 |
| [5-4](./cpp11book/5/5-4/5-4/Test.cpp) | 互斥锁`std::timed_mutex`用法 |
| [5-5](./cpp11book/5/5-5/5-5/Test.cpp) | 条件变量`std::condition_variable_any`用法 |
| [5-6](./cpp11book/5/5-6/5-6/Test.cpp) | 互斥锁/条件变量/通用互斥包装器联合使用|
| [5-7](./cpp11book/5/5-7/5-7/Test.cpp) | 互斥锁和通用互斥包装器实现计时器|
| [5-8](./cpp11book/5/5-8/5-8/Test.cpp) | 原子变量`std::mutex`实现计时器|
| [5-9](./cpp11book/5/5-9/5-9/Test.cpp) | 异步操作`std::future std::package_task`用法 |
| [5-10](./cpp11book/5/5-10/5-10/Test.cpp) | 异步操作`std::future std::async`用法 |
| [5-11](./cpp11book/5/5-11/5-11/Test.cpp) | `std::call_once`用法|
| [6-1](./cpp11book/6/6-1/6-1/Test.cpp) | `chrono`日期和时间用法|
| [6-2](./cpp11book/6/6-2/6-2/Test.cpp) | 数值类型和字符串的相互转换用法|
| [7-1](./cpp11book/7/7-1/Test.cpp) | 委托构造函数和继承构造函数用法|
| [7-2](./cpp11book/7/7-2/Test.cpp) | 原始字面量`R"(xxx)"`用法|
| [7-3](./cpp11book/7/7-3/Test.cpp) | `final override`关键字用法|
| [7-4](./cpp11book/7/7-4/Test.cpp) | 内存对齐相关|
| [8-1](./cpp11book/8/8-1/Test.cpp) | 设计模式：改进单例模式|
| [8-2](./cpp11book/8/8-2/Test.cpp) | 设计模式：改进观察者模式|
| [8-3](./cpp11book/8/8-3/Test.cpp) | 设计模式：改进访问者模式|
| [8-4](./cpp11book/8/8-4/Test.cpp) | 设计模式：改进命令模式|
| [8-5](./cpp11book/8/8-5/Test.cpp) | 设计模式：改进对象池模式|
| [9-1](./worksteal/main.cpp) | 半同步半异步的线程池|

## type_traits和模版等综合应用

### optional

类模板 std::optional 管理一个可选的容纳值，既可以存在也可以不存在的值。

一种常见的 optional 使用情况是一个可能失败的函数的返回值。与其他手段，如 `std::pair<T,bool>` 相比， optional 良好地处理构造开销高昂的对象，并更加可读，因为它显式表达意图。

任何一个 `optional<T>` 的实例在给定时间点要么含值，要么不含值。

若一个 `optional<T>` 含值，则保证值作为 optional 对象所用空间的一部分分配，即不会发生动态内存分配。从而 optional 对象模拟一个对象，而非指针，尽管定义了 operator*() 和 operator->() 运算符。

当一个 `optional<T>` 对象被按语境转换成 bool 时，若对象含值则转换返回 true ，若对象不含值则返回 false 。

optional 对象在下列条件下含值：

* 对象被以 T 类型值或另一含值的 optional 初始化/赋值。

对象在下列条件下不含值：

* 对象被默认初始化。
* 调用了成员函数 reset() 。

### 惰性求值`lazy`

惰性求值一般用于函数式编程，在使用延迟求值时，表达式不在它被绑定到变量之后立即求值，而是在后面某个时候求值。

典型使用场景：当初始化某个对象时，该对象引用了一个大对象，这个对象的创建需要较长的时间，同时也需要在堆上分配较多的空间，这样可能会在初始化时变得很慢，尤其是UI应用时会导致用户体验很差。其实很多时候并不需要马上就获取大数据，只是在需要时获取，这种场景就很适合延迟加载。

### 链式调用

链式调用是一种编程风格，通过将多个函数调用连接在一起，使得代码更加简洁和易读。在链式调用中，每个函数调用都会返回一个对象或者引用，使得可以直接在其上继续调用其他函数。这样的调用方式可以形成一个函数调用链，将多个操作按照顺序串联起来。

链式调用的主要优点是可以减少临时变量的使用，避免中间结果的存储和传递。通过将多个操作连接在一起，可以直接在上一个操作的输出上进行下一个操作，避免了中间结果的临时存储和传递，使得代码更加简洁和高效。

### Any类

Any类是一种通用的类型安全容器，它可以存储和操作任意类型的值。Any类通过使用模板和类型擦除等技术来实现，可以在运行时动态确定存储的值的类型，并提供类型转换和值访问的功能。

### Variant类

类模板 std::variant 表示一个类型安全的联合体（以下称“变化体”）。std::variant 的一个实例在任意时刻要么保有它的一个可选类型之一的值，要么在错误情况下无值（此状态难以达成，见 valueless_by_exception）。

与联合体的行为一致，如果变化体保有某个对象类型 T 的值，那么 T 的对象表示会在变化体自身的对象表示中直接分配。不允许变化体分配额外的（动态）内存。

变化体不能保有引用、数组，或类型 void。空变化体也非良构。

变化体可以保有同一类型多于一次，而且可保有同一类型的不同 cv 限定版本。

与联合体在聚合初始化中的行为一致，默认构造的变化体保有它的首个选项的值，除非该选项不可默认构造（此时该变化体也不可默认构造）。

### ScopeGuard类

ScopeGuard 类是一种用于资源管理和异常处理的设计模式，在 C++ 中可以通过 RAII（资源获取即初始化）技术来实现。它的主要目的是确保在离开当前作用域时，能够正确释放已经获取的资源。

ScopeGuard 类通常被设计为一个模板类，模板参数可以是资源的类型。通过在对象的构造函数中获取资源，在析构函数中释放资源，ScopeGuard 类能够确保资源的正确管理。

## 智能指针

### std::shared_ptr

智能指针虽然能自动管理堆内存，但它还是有不少陷阱，在使用时要注意。

1. 不要用一个原始指针初始化多个shared_ptr

2. 不要在函数实参中创建shared_ptr

3. 通过shared_from_this（）返回this指针

4. 要避免循环引用

### std::unique_ptr

关于shared_ptr和unique_ptr的使用场景要根据实际应用需求来选择，如果希望只有一个智能指针管理资源或者管理数组就用unique_ptr，如果希望多个智能指针管理同一个资源就用shared_ptr.

### std::weak_ptr

弱引用指针weak_ptr是用来监视shared_ptr的，不会使引用计数加1，它不管理shared_ptr内部的指针，主要是为了监视shared_ptr的生命周期，更像是shared_ptr的一个助手。weak_ptr没有重载操作符*和->，因为它不共享指针，不能操作资源，主要是为了通过shared_ptr获得资源的监测权，它的构造不会增加引用计数，它的析构也不会减少引用计数，纯粹只是作为一个旁观者来监视shared_ptr中管理的资源是否存在。weak_ptr还可以用来返回this指针和解决循环引用的问题。

## 多线程开发

### 线程

`std::thread`是`C++11`标准库中提供的多线程支持的类。它允许开发人员创建和管理线程，以实现并发执行的程序。

### 互斥锁

互斥量是一种同步原语，是一种线程同步的手段，用来保护多线程同时访
问的共享数据。
C++11中提供了如下4种语义的互斥量（mutex）：

* std：：mutex：独占的互斥量，不能递归使用。
* std：：timed_mutex：带超时的独占互斥量，不能递归使用。
* std：：recursive_mutex：递归互斥量，不带超时功能。
* std：：recursive_timed_mutex：带超时的递归互斥量。

### 条件变量

条件变量是C++11提供的另外一种用于等待的同步机制，它能阻塞一个或多个线程，直到收到另外一个线程发出的通知或者超时，才会唤醒当前阻塞的线程。条件变量需要和互斥量配合起来用。C++11提供了两种条件变量：

* condition_variable，配合std：：unique_lock进行wait操作。
* condition_variable_any，和任意带有lock、unlock语义的mutex搭配使用，比较灵活，但效率比condition_variable差一些。
可以看到condition_variable_any比condition_variable更灵活，因为它更通用，对所有的锁都适用，而condition_variable性能更好。我们应该根据具体应用场景来选择条件变量。
条件变量的使用过程如下：

1. 拥有条件变量的线程获取互斥量。
2. 循环检查某个条件，如果条件不满足，则阻塞直到条件满足；如果条件满足，则向下执行。
3. 某个线程满足条件执行完之后调用notify_one或notify_all唤醒一个或者所有的等待线程。

### 通用互斥锁包装器

#### std::lock_guard

类`lock_guard`是互斥体包装器，为在作用域块期间占有互斥提供便利`RAII`风格机制。

创建`lock_guard`对象时，它试图接收给定互斥的所有权。控制离开创建`lock_guard`对象的作用域时，销毁`lock_guard`并释放互斥。

`lock_guard`类不可复制。

#### std::unique_lock

类`unique_lock`是通用互斥包装器，允许延迟锁定、锁定的有时限尝试、递归锁定、所有权转移和与条件变量一同使用。
类`unique_lock`可移动，但不可复制

### 原子变量

`C++11`提供了一个原子类型`std：：atomic<T>`，可以使用任意类型作为模板参数，C++11内置了整型的原子变量，可以更方便地使用原子变量，使用原子变量就不需要使用互斥量来保护该变量了，用起来更简洁。
