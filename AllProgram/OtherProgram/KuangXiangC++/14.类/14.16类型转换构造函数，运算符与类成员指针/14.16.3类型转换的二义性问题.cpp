#include <iostream>
using namespace std;

//类型转换构造函数特点：只有一个形参 形参不是本类的const引用
class TestInt3 //一个类 里面保存0-100之间的数字
{
public:
    //如果不希望发生隐式转换 前面可加explicit
    TestInt3(int x = 0) :m_i(x)//类型转换构造函数 
                           //本构造函数可以将数字转换成类类型对象
    {
        if (m_i < 0) m_i = 0;//限制一下范围
        if (m_i > 100) m_i = 100;//限制一下范围
        cout << "调用了类型转换构造函数" << endl;
    }
    TestInt3& operator=(const TestInt3& test)
    {
        cout << "调用了赋值运算符" << endl;
        m_i = test.m_i;
        return *this;
    }
    
    operator int() //定义一个转换成整型数字的类型转换运算符
    {
        return 6;
    }
    //operator double() { return 10.6; };//又定义一个转换成实型数字的类型转换运算符
public:
    int m_i;
};

class CT1
{
public:
    CT1(int ct) {};//类型转换构造函数
};
class CT2
{
public:
    CT2(int ct){}//类型转换构造函数
};

void testfunc(const CT1& C){};
void testfunc(const CT2& C){};
int main3()
{
    TestInt3 aa;
    int abc = aa + 12;//会报二义性错误

    //testfunc(101);//会报二义性 int可转换成CT1对象 也可以转换成CT2对象
    testfunc(CT1(101));//能明确调用void testfunc(const CT1 &C){}
                       //但这种手段表明代码设计的不好
	return 0;
}