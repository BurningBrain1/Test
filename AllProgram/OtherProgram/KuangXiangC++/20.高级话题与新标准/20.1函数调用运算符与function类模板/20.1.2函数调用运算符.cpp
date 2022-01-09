#pragma once
#include <iostream>
using namespace std;

class biggerthanzero2
{
public:
    //重载函数调用运算符
    int operator()(int value)const
    {
        if (value < 0)return 0;
        return value;
    }
    biggerthanzero2(int i)
    {
        cout << "biggerthanzero1的构造函数执行了" << endl;
    }
};

void func2(int i)
{
    cout << "这是函数func2()" << i << endl;
    return;
}

int main2()
{
    func2(5);
    int i = 200;
    biggerthanzero2 obj(1);//函数定义并初始化 调用的是构造函数
    int result = obj(i);//等价于obj.operator()(i)
    cout << result << endl;//200
    return 0;
}

