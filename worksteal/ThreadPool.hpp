#include "worker.hpp"

class thread_pool {
public:
    thread_pool(size_t thread_num = std::thread::hardware_concurrency())
    {
        m_workers = std::make_shared<std::vector<std::shared_ptr<worker_t>>>();
        for (size_t i = 0; i < thread_num; i++) {
            auto worker = std::make_shared<worker_t>(m_workers, thread_num);
            m_workers->push_back(worker);
        }
    }

    ~thread_pool()
    {
        for (auto worker : *m_workers) {
            worker->join();
        }

        m_workers->clear();
    }

    void add_task(const task_t& task)
    {
        auto worker = get_rand_worker();
        worker->assign(task);
    }

private:
    std::shared_ptr<worker_t> get_rand_worker()
    {
        int i = rand() % m_workers->size();
        return m_workers->at(i);
    }

    workers_ptr m_workers;
};
