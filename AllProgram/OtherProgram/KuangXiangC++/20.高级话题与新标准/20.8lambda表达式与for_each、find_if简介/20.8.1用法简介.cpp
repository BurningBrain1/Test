#include<iostream>
#include <functional>
using namespace std;



int main1()
{
    //(1) 返回类型后置的这种语法 lambda表达式的返回类型必须后置
    auto e = [](int a)->int
    {
        return a + 1;
    };
    cout << e(1) << endl;
    //也可以写成auto f=[](int a){...}因为编译器可以根据return推断类型
    //也可以auto f=[](int a=8)->int{...}参数可以有默认值
    
    //(2)没有参数的时候 参数列表可以省略 （）也可以省略
    auto f1 = []() {return 1; };
    auto f2 = [] {return 2; };
    cout << f1() << endl;//1
    cout << f2() << endl;//2

    //(3)捕获列表[]和函数体不能省略 必须时刻包含
    //(4)lambda表达式的调用方法和普通函数相同 都是用()这种函数调用运算符
    //(5)lambda表达式可以不返回任何类型 不返回任何类型就是返回void
    //(6)函数体末尾的分号不能省略

    return 0;
}