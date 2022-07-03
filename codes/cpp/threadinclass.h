#ifndef THREADINCLASS_H
#define THREADINCLASS_H

#include <thread>
#include <atomic>
#include <condition_variable>
#include <chrono>
#include <mutex>
#include <queue>
#include <iostream>
#include <memory>

class threadInClass
{
public:
    threadInClass();
    ~threadInClass();

    void    addData(int data);
    void    process();


private:
    std::atomic<bool>   m_thread_running;
    std::mutex          m_data_mutex;
    std::queue<int>     m_data_queue;
    std::condition_variable m_data_cond_var;
    std::unique_ptr<std::thread>    m_pThread;

};

#endif // THREADINCLASS_H
