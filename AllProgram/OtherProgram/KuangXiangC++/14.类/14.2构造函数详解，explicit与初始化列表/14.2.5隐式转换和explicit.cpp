#include <iostream>
using namespace std;

class Time5
{
public:
    int Hour;
    int Minute;
    int Second;
public:
    Time5(int tmphour)
    {
        Hour = tmphour;
        Minute = 59;
        Second = 59;
    }
    Time5(){}
};

void func5(Time5 myt)
{
    return;
}
int main()
{
    func5(16);//这里依旧调用了Time类的单参数的构造函数
    Time5 myTime23;
    myTime23 = 16;//这句也调用了Time类的单参数构造函数，生成一个临时对象
                  //然后把这个临时对象的值复制到了myTime23的成员变量中去了
    Time5 myTime100 = { 16 };//这种写法正常 带一个参数16 
                             //可以让系统明确调用带一个参数的构造函数
    Time5 myTime101 = 16;//含糊不清的代码 存在临时对象或者隐式转换问题
    func5(16);//含糊不清的代码 存在临时对象或者隐式转换问题
    return 0;
}