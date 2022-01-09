#pragma once

#include <map>
#include <string>
#include <iostream>
using namespace std;

int echovalue3(int value)
{
    cout << value << endl;
    return value;
}
class biggerthanzero3
{
public:
    //重载函数调用运算符
    int operator()(int value)const
    {
        if (value < 0)return 0;
        return value;
    }
};
int main3()
{
    map<string, int(*)(int)> myoper;//键是字符串 值是函数指针
    myoper.insert({"ev",echovalue3});//用insert函数往容器中增加键值对
    
    biggerthanzero3 obj;
    //myoper.insert({"bt",biggerthanzero});//报错 不允许使用类型名
    //myoper.insert({"bt",obj1});//报错 对象obj没有被系统看成函数指针

    return 0;
}



