#ifndef SHAREDPTR_H
#define SHAREDPTR_H

#include <iostream>
using namespace std;

template<class T>
class SharedPtr//模拟实现shared_ptr
{
public:
    SharedPtr(T* tmp = nullptr)
        :_ptr(tmp)
    {
        if (_ptr)
        {
            count = 1;
        }
        else
        {
            count = 0;
        }
        cout<<"count: "<<count<<endl;
    }

    SharedPtr(SharedPtr<T>& tmp)  //拷贝构造
    {
        if (this != &tmp)
        {
            _ptr = tmp._ptr;
            count = tmp.count + 1;
        }

        cout<<"count: "<<count<<endl;
    }

    ~SharedPtr()
    {
        if (--count == 0)
        {
            delete _ptr;
        }
    }

    T& operator*()  //返回值的&代表运算符前置
    {
        assert(_ptr == nullptr);
        return *_ptr;
    }

    T* operator->()  //返回值的*代表指针
    {
        assert(_ptr == nullptr);
        return _ptr;
    }

    SharedPtr<T>& operator=(const SharedPtr<T>& tmp)
    {
        if (_ptr != tmp._ptr)//排除自己给自己赋值的可能
        {
            //防止原空间没有释放
            if (--count == 0)
            {
                delete _ptr;
            }
            _ptr = tmp._ptr;
            count = tmp.count + 1;

            cout<<"count: "<<count<<endl;
        }
        return *this;//考虑连等的可能
    }

    size_t use_count()
    {
        return count;
    }

private:
    T* _ptr;
    int count;
};

#endif // SHAREDPTR_H
