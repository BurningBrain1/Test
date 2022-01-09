#include<iostream>
#include <functional>
using namespace std;

class TC2
{
public:
    TC2()
    {
        m_a = 1;
    }
    void operator()(int tv)
    {
        cout << "TC2::operator()执行了，tv=" << tv << endl;
    }
    void ptfunc(int tv)
    {
        cout << "TC2::ptfunc()执行了,tv=" << tv << endl;
    }
    static int stcfunc(int tv)
    {
        cout << "TC2::stcfunc()静态函数执行了，tv=" << tv << endl;
        return tv;
    }
    int m_a;
};
class TC21
{
public:
    using tfpoint = void(*)(int);
    static void myfunc(int tv)
    {
        cout << "TC21::myfunc()静态成员函数执行了，tv=" << tv << endl;
    }
    operator tfpoint() { return myfunc; }//类型转换运算符/类型转换函数
};
class CB2
{
    function<void()> fcallback;
public:
    CB2(const function<void()> f) :fcallback(f)
    {
        
        cout << "执行CB2构造函数"<<endl;
        //function<void()> fcallback = f;
        int i;  
        i = 1;
    }
    void runcallback(void)
    {
        fcallback();
    }
};

class CT2
{
public:
    CT2()
    {
        cout << "CT2::CT2()执行" << endl;
    }
    CT2(const CT2&)//拷贝构造函数
    {
        cout << "CT2::CT2(const CT&)执行" << endl;
    }
    ~CT2()
    {
        cout<<"CT2::~CT2()执行" << endl;
    }
    void operator()(void)
    {
        cout << "CT2::operator()执行" << endl;
    }
};
void myfunc2(int i)
{
    cout << "myfunc2()函数执行了." << i << endl;
}
void runfunc2(int x)
{
    cout << x << endl;
}
void mycallback2(int cs, const function<void(int)>& f)
{
    f(cs);
}

int main2()
{
    //1.绑定普通函数
    function<void(int)> f1 = myfunc2;
    f1(100);
    cout << "-----------------------------------------" << endl;
    //2.绑定类的静态成员函数
    function<int(int)>fs2 = TC2::stcfunc;//绑定一个类的静态成员函数
    fs2(110);//调用静态成员函数
    cout << "-----------------------------------------" << endl;
    //3.绑定仿函数
    TC2 tc3;
    function<void(int)>f3 = tc3;//使用了未初始化的局部变量“tc3”
    //因为类TC中有成员变量没被初始化，需要增加一个构造函数来初始化成员变量
    f3(120);//TC2::operator执行了，tv=120

    TC21 tc4;  //注意这是TC21类
    function<void(int)>f4 = tc4;
    f4(150);//TC21::myfunc()静态成员函数执行了 tv=150
    cout << "-----------------------------------------" << endl;
    //4范例演示1
    CT2 ct;  
    //(function<void()>)(ct);
    CB2 cb(ct);//CB2需要可调用对象作为参数来构造
    //因为有operator()所以ct可以转为function<void(void)>&对象，
    //这行导致CT2拷贝构造函数执行多次

    //cb.runcallback();//CT2::operator()执行
    cout << "-----------------------------------------" << endl;
    //5范例演示2
    for (int i = 0; i < 10; i++)
    {
        mycallback2(i, runfunc2);//0-9
    }
    return 0;
}

