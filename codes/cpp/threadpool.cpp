#include "threadpool.h"

threadpool::threadpool(int threadCount)
{
    m_ThreadList.reserve(threadCount);
    for(int i=0; i<threadCount; i++)
    {
        m_ThreadList.emplace_back(&threadpool::run, this);
//        thread t(&threadpool::run, this);
//        m_ThreadList.push_back(t);         //为什么通过这种方式构造编译报错？
    }
}

threadpool::~threadpool()
{
    m_bThreadRun.store(false);
    m_ThreadCondition.notify_all();

    for(int i=0; i<m_ThreadList.size(); i++)
    {
        m_ThreadList.at(i).join();
    }

    while(!m_TaskQue.empty())
    {
        Task* pTask = m_TaskQue.front();
        m_TaskQue.pop();

        if(pTask)
        {
            delete pTask;
        }
    }
}

void threadpool::addTask(Task* pTask)
{
    if(pTask)
    {
        unique_lock<mutex> lock(m_Mutex);
        m_TaskQue.push(pTask);
    }
    else
        return;
    m_ThreadCondition.notify_one();
}

void threadpool::run()
{
    m_bThreadRun.store(true);
    while(m_bThreadRun.load())
    {
        unique_lock<mutex> lock(m_Mutex);
        //任务队列不为空时直接返回
        m_ThreadCondition.wait(lock, [this]{return !m_TaskQue.empty() || !m_bThreadRun.load(); });

        if(m_TaskQue.empty())
            continue;
        Task* pTask = m_TaskQue.front();
        m_TaskQue.pop();
        lock.unlock(); //不解锁的话，是在task的run结束后才解锁任务队列，实际上只有一个线程在执行任务
        if(pTask)
        {
            pTask->run();
            delete pTask;
            pTask = nullptr;
        }

        this_thread::sleep_for(chrono::milliseconds(2));
    }
}
