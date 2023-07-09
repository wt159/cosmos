#pragma once
#include "SyncDeque.hpp"
#include <algorithm>
#include <functional>
#include <memory>
#include <thread>
#include <vector>

class worker_t;
using workers_ptr = std::shared_ptr<std::vector<std::shared_ptr<worker_t>>>;
using task_t = std::function<void()>;

class worker_t final {
public:
    worker_t(workers_ptr workers, int work_num)
        : m_workers(workers)
        , m_workNum(work_num)
        , m_enable(true)
    {
        m_thread = std::thread(&worker_t::execute, this);
    }

    ~worker_t()
    {
    }

    void assign(const task_t& task)
    {
        m_queue.push_front(task);
    }

    task_t steal()
    {
        return m_queue.pop_back();
    }

    bool empty()
    {
        return m_queue.empty();
    }

    void join()
    {
        m_enable = false;
        m_thread.join();
    }

private:
    void execute()
    {
        m_threadID = std::this_thread::get_id();
        while (m_enable) {
            // not ready
            if (m_workNum != m_workers->size()) {
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                continue;
            }

            // do work
            task_t t = m_queue.pop_front();
            while (t != nullptr) {
                t();
                t = m_queue.pop_front();
            }

            // check if has task
            bool no_task = std::all_of(m_workers->begin(), m_workers->end(), [](std::shared_ptr<worker_t> worker) { return worker->empty(); });
            if (no_task) {
                // std::cout<<"all tasks have been finished!"<<std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
                continue;
            }

            // steal
            int rand_select = rand() % m_workers->size();
            if (m_workers->at(rand_select) == nullptr)
                continue;

            t = m_workers->at(rand_select)->steal();

            if (t != nullptr) {
                t();
            }
        }
    }

    std::thread m_thread;
    std::shared_ptr<std::vector<std::shared_ptr<worker_t>>> m_workers;
    std::thread::id m_threadID;
    sync_deque<task_t> m_queue;

    int m_workNum;
    bool m_enable;
};
