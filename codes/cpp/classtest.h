#ifndef CLASSTEST_H
#define CLASSTEST_H

#include <iostream>

using namespace std;

class Class_Test{
public:
    Class_Test(){}
    Class_Test (int x){ int_x = x; }
    void show(){cout<< int_x << endl;}
private:
    int int_x;
};

class Mytest: public Class_Test{
public:
    Mytest() : Class_Test(110)
    {
//        int_x = 0;
//      Class_Test(110);            //  构造函数只能在初始化列表中被显示调用，不能在构造函数内部被显示调用
    }
};




//typedef void(*FUN)();//重定义一个函数指针类型

//父类
struct Base
{
    //FUN _f;
    void (*_f)();
};

//子类
struct Derived
{
    Base _b;//在子类中定义一个基类的对象即可实现对父类的继承
};


void FunB()
{
    printf("%s\n", "Base::fun()");
}
void FunD()
{
    printf("%s\n", "Derived::fun()");
}

void Test2()
{
    Base b;//父类对象
    Derived d;//子类对象

    b._f = FunB;//父类对象调用父类同名函数
    d._b._f = FunD;//子类调用子类的同名函数

    Base *pb = &b;//父类指针指向父类对象
    pb->_f();

    pb = (Base *)&d;//让父类指针指向子类的对象,由于类型不匹配所以要进行强转
    pb->_f();

}

#endif // CLASSTEST_H
