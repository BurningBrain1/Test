#include <iostream>
using namespace std;

class Time4
{
public:
    int Hour;
    int Minute;
    int Second;
};


int main()
{
    Time4 myTime;
    Time4 myTime2 = myTime;
    Time4 myTime3(myTime);
    Time4 myTime4{myTime};
    Time4 myTime5 = {myTime};
    myTime5.Hour = 8;

    Time4 myTime6;
    myTime6 = myTime5;//通过赋值操作来复制对象
    return 0;
}