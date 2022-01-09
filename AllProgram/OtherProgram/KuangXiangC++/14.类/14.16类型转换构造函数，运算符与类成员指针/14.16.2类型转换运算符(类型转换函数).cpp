#include <iostream>
using namespace std;

//类型转换构造函数特点：只有一个形参 形参不是本类的const引用
class TestInt2 //一个类 里面保存0-100之间的数字
{
public:
    //如果不希望发生隐式转换 前面可加explicit
    TestInt2(int x = 0) :m_i(x)//类型转换构造函数 
                           //本构造函数可以将数字转换成类类型对象
    {
        if (m_i < 0) m_i = 0;//限制一下范围
        if (m_i > 100) m_i = 100;//限制一下范围
        cout << "调用了类型转换构造函数"<<endl;
    }
    TestInt2& operator=(const TestInt2& test)
    {
        cout << "调用了赋值运算符" << endl;
        m_i = test.m_i;
        return *this;
    }
    //类型转换运算符 可以从本类类型转换成其他类型 必须无形参
    operator int() const
    {
        cout << "调用了类型转换运算符" << endl;
        return m_i;//返回int类型 可以把类对象转成int对象
    }
public:
    typedef void(*tfpoint)(int);//函数指针类型定义 
    using tfpoint = void(*)(int);//函数指针类型定义 这个using后的tfpoint是类型名
                                 //*后不能有tfpoint 本行等价于上面typedef行
                                 //以后会讲using格式 这里只需要记住是类型定义
    //一个静态成员函数
    static void mysfunc(int v1)   //静态成员函数
    {
        int test;
        test = 1;
    }
    //类型转换运算符 能把本类类型对象转换成一个函数指针类型
    operator tfpoint()//const不是必须加的
    {
        //那就必须要返回一个函数指针
        cout << "调用了函数指针类型转换" << endl;
        return mysfunc;//函数地址作为函数指针类型返回了
    }
public:
    int m_i;
};

    int main2()
    {
        TestInt2 ti = 12;//隐式类型转换 将数字转换成TestInt1对象 调用了类型转换构造函数
        TestInt2 ti2(22);//调用类型转换构造函数 但这个不是隐式类型转换
        cout << "---------------------------------------------------" << endl;
        ti2 = 6;//隐式转换把6转成一个临时的TestInt2对象 然后调用赋值运算符把临时对象给ti2
        //int k = ti2 + 5;//k=11 这里调用operator int()将ti2转成int 结果为6
                          //注意如果有多个类型转换运算符 隐式转换会报错 因为不知道选用哪个类型转换运算符
        int k2 = ti2.operator int() + 5;//也可以显式调用
        cout << k2 << endl;
        cout << "---------------------------------------------------" << endl;
        //1 显式的类型转换运算符 
        int k3 = static_cast<int>(ti2) + 5;//11 调用operator int()将ti2转成int
        cout << "---------------------------------------------------" << endl;
        //2 有趣范例 类对象转换为函数指针
        TestInt2 myi(12);
        myi(123);//执行operator tfpoint() 然后会执行mysfunc成员函数
        myi.operator TestInt2::tfpoint()(123);//tfpoint是TestInt2中定义的类型
                                              //所以前面要增加TestInt2::进行限定
        return 0;
    }

