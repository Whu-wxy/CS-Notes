#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <vector>
#include <condition_variable>
#include <thread>
#include <mutex>
#include <memory>
#include <queue>
#include <atomic>
#include <iostream>
#include <chrono>

using namespace std;

class Task
{
public:
    Task(){}
    ~Task(){}

    virtual void run() = 0;    // The specific work is realized by the developer
};

class MyTask: public Task
{
public:
    MyTask(int num) {number = num; }
    ~MyTask();

    virtual void run(){ cout<<"task output: "<<number<<endl; }

private:
    int number;
};


class threadpool
{
public:
    threadpool(int threadCount=4);
    ~threadpool();

    void    addTask(Task* pTask);

private:
    atomic<bool>    m_bThreadRun;
    condition_variable m_ThreadCondition;
    mutex           m_Mutex;
    queue<Task*>    m_TaskQue;
    vector<thread>  m_ThreadList;

    void    run();
};

#endif // THREADPOOL_H
