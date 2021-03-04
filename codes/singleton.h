#ifndef SINGLETON_H
#define SINGLETON_H

#include <mutex>


class singleton
{
public:
    static singleton*  getInstance();

private:
    singleton() {}
    static singleton* m_instance;
    static std::mutex mutex; //getInstance中会报undefined
};


#endif // SINGLETON_H
