#include<iostream>
using namespace std;

//1 函数返回类型为void表示函数不返回任何类型 
    //但可以调用一个返回类型为void的函数作为另一个返回void函数的返回值
void funca()
{
    //...
}
void funcb()
{
    return funca();
}

//2 函数返回指针和返回引用的情况
int* myfunc()
{
    int tmpvalue = 9;//要变成全局变量
    return &tmpvalue;//语法上没错 但留下巨大隐患 tmpvalue应该为全局变量
}
int& myfunc2() //返回引用
{
    int tmpvalue = 9;
    cout << &tmpvalue << endl;
    return tmpvalue;//不管怎莫说都是隐患
}

//3 不带形参的函数定义可以写成如下 或者形参列表直接空着更好
int myfunc3(void) { return 1; }

//4 如果一个函数不调用 那么这个函数可以只有声明 没有定义

//5 函数只能定义一次 但可以声明多次

//6 通过引用型形参来进行函数调用参数的传递
struct student3 { int num; };
void fs(student3& stu)
{
    stu.num = 1000;
}

//7 函数重载
//void fs1(const int i){}//错误 const关键字在比较同名函数时会被忽略
//void fs1(int i){}

void fs2(const int i){}//可以 因为形参类型不同
void fs2(float i){}

void fs3(const int i){}//可以 因为形参数量不同
void fs3(const int i,const int j){}

int main3()
{
    //2 函数返回指针和返回引用的情况
    int* p = myfunc();
    *p = 6;//往不属于自己的地址上赋值
    
    int& k = myfunc2();
    //k地址中的内容不属于你 千万不可以读写
    cout << &k << endl;//tmpvalue已经析构 回收了内存

    //正确写法
    int k1 = myfunc2();
    cout << &k1 << endl;//地址不同

    //6 通过引用型形参来进行函数调用参数的传递
    student3 abc;
    abc.num = 100;
    fs(abc);
    cout << abc.num << endl;//1000
    return 0;
}