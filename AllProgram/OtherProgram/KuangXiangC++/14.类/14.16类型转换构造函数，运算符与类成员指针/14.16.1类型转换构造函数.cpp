#include <iostream>
using namespace std;

//类型转换构造函数特点：只有一个形参 形参不是本类的const引用
class TestInt1 //一个类 里面保存0-100之间的数字
{
public:
    //如果不希望发生隐式转换 前面可加explicit
    TestInt1(int x = 0) :m_i(x)//类型转换构造函数 
                           //本构造函数可以将数字转换成类类型对象
    {
        if (m_i < 0) m_i = 0;//限制一下范围
        if (m_i > 100) m_i = 100;//限制一下范围      
    }
public:
    int m_i;
};

int main1()
{
    
    TestInt1 ti = 12;//隐式类型转换 将数字转换成TestInt1对象 调用了类型转换构造函数
    TestInt1 ti2(22);//调用类型转换构造函数 但这个不是隐式类型转换
    return 0;
}