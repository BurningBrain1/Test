#pragma once
#include <iostream>
#include <functional>
#include <map>
using namespace std;

int echovalue4(int value)
{
    cout << value << endl;
    return value;
}
class biggerthanzero4
{
public:
    //重载函数调用运算符
    int operator()(int value)const
    {
        if (value < 0)return 0;
        return value;
    }
};
int main4()
{
    biggerthanzero4 obj;   //含有函数调用运算符的对象
    function<int(int)> f1 = echovalue4;//函数指针
    function<int(int)> f2 = obj;//类对象中重载函数调用运算符
    function<int(int)> f3 = biggerthanzero4();//用类名生成了临时对象

    f1(5);//5
    cout << f2(3) << endl;//3
    cout << f3(-5) << endl;//0

    map<string, function<int(int)>> myoper;

    biggerthanzero4 obj1;
    map<string, function<int(int)>> myoper1 =
    {
        {"ev",echovalue4},
        {"bt",obj1},
        {"bt2",biggerthanzero4()}
    };

    myoper1["ev"](12);//"ev"是键,那么myoper["ev"]代表值 12
    cout << myoper1["bt"](3) <<endl;//3
    cout << myoper1["bt2"](-5) << endl;//0

    //如果存在echovalue的函数重载 做法如下
    int(*fp)(int) = echovalue4;//定义一个函数指针 不会产生二义性 因为函数指针里有对应的参数类型和返回类型
    function<int(int)>f4 = fp;//直接塞进去函数指针而不是函数名


    return 0;
}
