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

    Timer t; //��ʼ��ʱ
    fun();
#ifndef _USE_TEMPLATE_
    // std::cout << t.elapsed_seconds() << std::endl; //��ӡfun������ʱ������
    // std::cout << t.elapsed_nano() << std::endl; //��ӡ����
    // std::cout << t.elapsed_micro() << std::endl; //��ӡ΢��
    // std::cout << t.elapsed() << std::endl; //��ӡ����
    // std::cout << t.elapsed_seconds() << std::endl; //��ӡ��
    // std::cout << t.elapsed_minutes() << std::endl; //��ӡ����
    // std::cout << t.elapsed_hours() << std::endl; //��ӡСʱ
#else
    std::cout << t.elapsed<Timer::nanosecond_t>() << std::endl; //��ӡ����
    std::cout << t.elapsed<Timer::microsecond_t>() << std::endl; //��ӡ΢��
    std::cout << t.elapsed<Timer::millisecond_t>() << std::endl; //��ӡ����
    std::cout << t.elapsed() << std::endl; //��ӡ����
    std::cout << t.elapsed<Timer::second_t>() << std::endl; //��ӡ��
    std::cout << t.elapsed<Timer::minute_t>() << std::endl; //��ӡ����
    std::cout << t.elapsed<Timer::hour_t>() << std::endl; //��ӡСʱ
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