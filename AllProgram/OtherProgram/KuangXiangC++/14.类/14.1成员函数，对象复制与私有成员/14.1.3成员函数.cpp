#include <iostream>
using namespace std;

//C����д��
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

//C++д��
class Time
{
public:
    int Hour;
    int Minute;
    int Second;
    void initTime(int tmphour, int tmpmin, int tmpsec);//��Ա����
};

//����ð�Ž������������ ��Ϊ���������Ҳ��ͬ���ĺ���
//��Time::�������ú�������Time��
void Time::initTime(int tmphour, int tmpmin, int tmpsec)
{
    Hour = tmphour;//��Ա�����п���ֱ��ʹ�ñ�����
                   //���Ա����֪���Ǹ�������õĳ�Ա��������
    Minute = tmpmin;
    Second = tmpsec;
}
#endif // !_MYTIME_

int main3()
{
    //C����д��
    TimeC myTime;
    initTime(myTime, 11, 14, 5);
    cout << myTime.Hour <<endl;//11
    cout << myTime.Minute << endl;//14
    cout << myTime.Second << endl;//5

    //C++д��
    Time myTime1;
    myTime1.initTime(11,14,5);
    cout << myTime1.Hour << endl;//11
    cout << myTime1.Minute << endl;//14
    cout << myTime1.Second << endl;//5
    return 0;
}