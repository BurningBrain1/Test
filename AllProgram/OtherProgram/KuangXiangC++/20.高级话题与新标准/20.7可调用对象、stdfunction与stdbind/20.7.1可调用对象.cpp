#include<iostream>
using namespace std;

class TC1
{
public:
    TC1()
    {
        m_a = 1;
    }
    void operator()(int tv)
    {
        cout << "TC1::operator()执行了，tv=" << tv << endl;
    }
    void ptfunc(int tv)
    {
        cout << "TC1::ptfunc()执行了,tv=" << tv << endl;
    }
    static int stcfunc(int tv)
    {
        cout << "TC1::stcfunc()静态函数执行了，tv=" << tv << endl;
        return tv;
    }
    int m_a;
};

class TC11
{
public:
    using tfpoint = void(*)(int);
    static void myfunc(int tv)
    {
        cout << "TC11::myfunc()静态成员函数执行了，tv=" << tv << endl;
    }
    operator tfpoint() { return myfunc; }//类型转换运算符/类型转换函数
};

void myfunc1(int i)
{
    cout << "myfunc1()函数执行了." << i << endl;
}

int main1()
{
    //1函数指针
    void(*pmf)(int) = myfunc1;//定义函数指针并给初值，myfunc与&myfunc一个效果
    pmf(15);//一个可调用对象

    //2具有函数调用操作符的类对象
    TC1 tc;
    tc(20);//等价于tc.operator()(20)

   //3可转换为函数指针的类对象
    TC11 tc2;
    tc2(50);//先调用tfpoint，再调用myfunc 这是个可调用对象
            //等价于tc2.operator TC11::tfpoint()(50)

    //4类成员函数指针
    TC1 tc3;
    //类成员函数指针变量myfpointpt定义并被给初值
    void(TC1:: * myfpointpt)(int) = &TC1::ptfunc;
    //要调用成员函数 就必须用到对象tc3
    (tc3.*myfpointpt)(68);
    return 0;
}