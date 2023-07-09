#pragma once
#include <deque>
#include <mutex>

template <class T>
class sync_deque final {
public:
    sync_deque() = default;
    ~sync_deque() = default;

    // LIFO
    void push_front(const T& val)
    {
        std::unique_lock<std::mutex> l(m_mtx);
        m_deque.push_front(val);
    }

    T pop_front()
    {
        m_mtx.lock();

        if (m_deque.empty()) {
            m_mtx.unlock();
            return nullptr;
        }

        T val = m_deque.front();
        m_deque.pop_front();

        m_mtx.unlock();

        return val;
    }

    // for steal FIFO
    T pop_back()
    {
        if (!m_mtx.try_lock())
            return nullptr;

        if (m_deque.empty()) {
            m_mtx.unlock();
            return nullptr;
        }

        T val = m_deque.back();
        m_deque.pop_back();

        m_mtx.unlock();

        return val;
    }

    bool empty()
    {
        // std::unique_lock<std::mutex> l(mtx_);
        return m_deque.empty();
    }

private:
    std::deque<T> m_deque;
    std::mutex m_mtx;
};
