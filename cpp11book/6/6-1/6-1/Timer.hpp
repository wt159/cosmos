#ifndef _TIMER_HPP_
#define _TIMER_HPP_

#include <chrono>
#include <ctime>
#include <sstream>
#define _USE_TEMPLATE_ 1

static const char* weekdays[]
    = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
class Timer {
public:
    using clock_t = std::chrono::high_resolution_clock;
    using millisecond_t = std::chrono::milliseconds;
    using nanosecond_t = std::chrono::nanoseconds;
    using microsecond_t = std::chrono::microseconds;
    using second_t = std::chrono::seconds;
    using minute_t = std::chrono::minutes;
    using hour_t = std::chrono::hours;
    struct Date {
        int year;
        int month;
        int day;
        int weekday;
        int hour;
        int minute;
        int second;
        int millisecond;

        Date()
            : year(0)
            , month(0)
            , day(0)
            , weekday(0)
            , hour(0)
            , minute(0)
            , second(0)
            , millisecond(0)
        {
        }
        std::string to_str() const
        {
            std::stringstream ss;
            ss << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":"
               << second << "." << millisecond << " " << weekdays[weekday];
            return ss.str();
        }
    };

    Timer()
        : m_begin(clock_t::now())
    {
    }

    void reset() { m_begin = clock_t::now(); }

#ifndef _USE_TEMPLATE_
    // //Ĭ���������
    // int64_t elapsed() const
    // {
    //     return std::chrono::duration_cast<std::chrono::milliseconds>(
    //         clock_t::now() - m_begin)
    //         .count();
    // }

    // //΢��
    // int64_t elapsed_micro() const
    // {
    //     return std::chrono::duration_cast<std::chrono::microseconds>(
    //         clock_t::now() - m_begin)
    //         .count();
    // }

    // //����
    // int64_t elapsed_nano() const
    // {
    //     return std::chrono::duration_cast<std::chrono::nanoseconds>(
    //         clock_t::now() - m_begin)
    //         .count();
    // }

    // //��
    // int64_t elapsed_seconds() const
    // {
    //     return std::chrono::duration_cast<std::chrono::seconds>(
    //         clock_t::now() - m_begin)
    //         .count();
    // }

    // //��
    // int64_t elapsed_minutes() const
    // {
    //     return std::chrono::duration_cast<std::chrono::minutes>(
    //         clock_t::now() - m_begin)
    //         .count();
    // }

    // //ʱ
    // int64_t elapsed_hours() const
    // {
    //     return std::chrono::duration_cast<std::chrono::hours>(
    //         clock_t::now() - m_begin)
    //         .count();
    // }
#else
    template <typename TimeUnit = millisecond_t> int64_t elapsed() const
    {
        return std::chrono::duration_cast<TimeUnit>(clock_t::now() - m_begin).count();
    }
#endif
    std::time_t getStartTimestamp() const { return std::chrono::system_clock::to_time_t(m_begin); }
    std::time_t getCurrentTimestamp() const
    {
        return std::chrono::system_clock::to_time_t(clock_t::now());
    }
    Date getCurrentLocalTime() const
    {
        std::chrono::time_point<clock_t> cur = clock_t::now();
        std::time_t now = std::chrono::system_clock::to_time_t(cur);
        struct tm* localTime = std::localtime(&now);
        Date date;
        date.year = localTime->tm_year + 1900;
        date.month = localTime->tm_mon + 1;
        date.weekday = localTime->tm_wday;
        date.day = localTime->tm_mday;
        date.hour = localTime->tm_hour;
        date.minute = localTime->tm_min;
        date.second = localTime->tm_sec;
        date.millisecond
            = std::chrono::duration_cast<millisecond_t>(cur.time_since_epoch()).count() % 1000;
        return date;
    }

private:
    std::chrono::time_point<clock_t> m_begin;
};

#endif //_TIMER_HPP_