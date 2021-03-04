#include "threadinclass.h"

threadInClass::threadInClass()
{
    //m_pThread = std::make_unique<std::thread>(&threadInClass::process, this); //make_unique在C++14加入

    m_pThread.reset(new std::thread(&threadInClass::process, this)); //启动线程

}

threadInClass::~threadInClass()
{
    m_thread_running.store(false);
    m_pThread->join();
}

void threadInClass::addData(int data)
{
    {
        std::lock_guard<std::mutex> lock(m_data_mutex);
        m_data_queue.push(data);
    }
    m_data_cond_var.notify_one();  //通知线程中的m_data_cond_var
}

void threadInClass::process()
{
    m_thread_running.store(true);

    while(m_thread_running.load())  // 可以不用原子变量
    {
        int data;
        {
            std::unique_lock<std::mutex> lock(m_data_mutex);

            // m_data_queue为空时阻塞
            // 收到数据时通知线程进行处理
            m_data_cond_var.wait(lock, [this]{return !m_data_queue.empty(); } );

           // std::cout<<"m_data_queue.size: "<<m_data_queue.size()<<std::endl;
            data = m_data_queue.front();
            m_data_queue.pop();
        }

        // Process data.
        std::cout << "[threadInClass]: Recive data: " << data << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
