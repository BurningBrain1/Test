#include<iostream>
using namespace std;

int main3()
{
    int a = 1;
    int& b{ a };//b绑到a 当然可以
    //int& c;//不可以 引用必须要初始化(绑定一个对象) 
    //int& c = 1;//不可以 c要绑在左值上 不能绑定到右值1上
    const int& c = 1;//可以 const引用可以绑定到右值上 所以const引用比较特殊

    int tempvalue = 1; //可以把tempvalue看成一个临时变量
    const int& d = tempvalue;
    cout << d << endl;//1
    tempvalue = 10;
    cout << d << endl;//10
    //d = 20; 错误 不能赋值
    return 0;
}