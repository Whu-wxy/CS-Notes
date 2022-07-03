#ifndef THREADTEST_H
#define THREADTEST_H

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class Test
{
public:
    Test(int id, int number)
        :mId(id), mNumber(number)
    {

    }

    void func(string arg)
    {
        locker.lock();
        cout<<arg<<endl;
        for(int j=0; j<3; j++)
        {
            cout<<"j======"<<j<<endl;

            for(int i=0;i<mNumber;++i)
            {
                cout<<mId<<":"<<i<<endl;
            }
            this_thread::sleep_for(chrono::milliseconds(10));
        }
        locker.unlock();
    }
private:
    int mId;
    int mNumber;
    mutex locker;
};

#endif // THREADTEST_H
