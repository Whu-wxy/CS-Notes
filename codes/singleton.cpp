#include "singleton.h"

//懒汉模式
// 1.先为nullptr，在getInstance里new出来
singleton* singleton::m_instance = nullptr;
std::mutex singleton::mutex;


//饿汉模式
// 2.直接new出来，getInstance直接返回指针,是以空间换时间
//singleton* singleton::m_instance = new singleton();



//懒汉模式
singleton* singleton::getInstance()
{
    if(m_instance == nullptr)  //不加这个的话，在实例创建后，锁的代价过高，
        //因为多个线程只用读这个实例，实际上不需要加锁，在高并发的情况下，一个线程读这个实例时，
        //其他线程都要等待，此时锁对效率影响大
    {
        mutex.lock();
        if(m_instance == nullptr) //第二次判断必须有，防止被new多次
        {
            m_instance = new singleton();
        }
        mutex.unlock();
    }
    return m_instance;
}

//饿汉模式
//singleton* singleton::getInstance()
//{
//    return m_instance;
//}
