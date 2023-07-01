#define _CRT_SECURE_NO_WARNINGS

#include "Timer.hpp"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <thread>

void fun()
{
    std::cout << "hello world" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Test()
{
    std::cout << "\nTest()\n";

    Timer t; //开始计时
    fun();
#ifndef _USE_TEMPLATE_
    // std::cout << t.elapsed_seconds() << std::endl; //打印fun函数耗时多少秒
    // std::cout << t.elapsed_nano() << std::endl; //打印纳秒
    // std::cout << t.elapsed_micro() << std::endl; //打印微秒
    // std::cout << t.elapsed() << std::endl; //打印毫秒
    // std::cout << t.elapsed_seconds() << std::endl; //打印秒
    // std::cout << t.elapsed_minutes() << std::endl; //打印分钟
    // std::cout << t.elapsed_hours() << std::endl; //打印小时
#else
    std::cout << t.elapsed<Timer::nanosecond_t>() << std::endl; //打印纳秒
    std::cout << t.elapsed<Timer::microsecond_t>() << std::endl; //打印微秒
    std::cout << t.elapsed<Timer::millisecond_t>() << std::endl; //打印毫秒
    std::cout << t.elapsed() << std::endl; //打印毫秒
    std::cout << t.elapsed<Timer::second_t>() << std::endl; //打印秒
    std::cout << t.elapsed<Timer::minute_t>() << std::endl; //打印分钟
    std::cout << t.elapsed<Timer::hour_t>() << std::endl; //打印小时
#endif
    std::time_t timestamp = t.getStartTimestamp();
    std::cout << timestamp << std::endl;
    Timer::Date date = t.getCurrentLocalTime();
    std::cout << date.to_str() << std::endl;
}

int main(void)
{
    Test();

    return 0;
}