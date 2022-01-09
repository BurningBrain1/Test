#include <iostream>
using namespace std;

//C语言写法
class TimeC
{
public:
    int Hour;
    int Minute;
    int Second;
};

void initTime(TimeC& stmptime,int tmphour,int tmpmin,int tmpsec)
{
    stmptime.Hour = tmphour;
    stmptime.Minute = tmpmin;
    stmptime.Second = tmpsec;
}

#ifndef _MYTIME_
#define _MYTIME_

//C++写法
class Time
{
public:
    int Hour;
    int Minute;
    int Second;
    void initTime(int tmphour, int tmpmin, int tmpsec);//成员函数
};

//两个冒号叫作用域运算符 因为其他类可能也有同名的函数
//用Time::来表明该函数属于Time类
void Time::initTime(int tmphour, int tmpmin, int tmpsec)
{
    Hour = tmphour;//成员函数中可以直接使用变量名
                   //类成员函数知道那个对象调用的成员函数自身
    Minute = tmpmin;
    Second = tmpsec;
}
#endif // !_MYTIME_

int main3()
{
    //C语言写法
    TimeC myTime;
    initTime(myTime, 11, 14, 5);
    cout << myTime.Hour <<endl;//11
    cout << myTime.Minute << endl;//14
    cout << myTime.Second << endl;//5

    //C++写法
    Time myTime1;
    myTime1.initTime(11,14,5);
    cout << myTime1.Hour << endl;//11
    cout << myTime1.Minute << endl;//14
    cout << myTime1.Second << endl;//5
    return 0;
}