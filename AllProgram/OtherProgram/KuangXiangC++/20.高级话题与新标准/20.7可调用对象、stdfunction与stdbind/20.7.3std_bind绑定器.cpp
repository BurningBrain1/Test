#include<iostream>
#include <functional>
using namespace std;


void myfunc3(int x, int y, int z)
{
    cout << "x=" << x << ",y=" << y << ",z=" << z << endl;
}

void myfunc31(int& x, int& y)
{
    y++;
    x++;
}

class CQ
{
public:
    CQ()
    {
        printf("CQ::CQ()构造函数执行,this=%p\n",this);
    }
	CQ(const CQ&)
	{
		printf("CQ::CQ(const CQ&)拷贝构造函数执行,this=%p\n", this);
	}
	~CQ()
	{
		printf("CQ::~CQ()析构函数执行,this=%p\n", this);
	}
    void myfunpt(int x, int y)
    {
        cout << "x=" << x << ",y=" << y << endl;
        m_a = x;
    }
    int m_a = 0;//成员变量
};
class CT3
{
public:
	CT3()
	{
		cout << "CT3::CT3()执行" << endl;
	}
	CT3(const CT3&)//拷贝构造函数
	{
		cout << "CT3::CT3(const CT3&)执行" << endl;
	}
	~CT3()
	{
		cout << "CT2::~CT2()执行" << endl;
	}
	void operator()(void)
	{
		cout << "CT3::operator()执行" << endl;
	}
};
void myfunc(int i)
{
	cout << "myfunc3()函数执行了." << i << endl;
}
void runfunc3(int x)
{
	cout << x << endl;
}
void mycallback3(int cs, const function<void(int)>& f)
{
	f(cs);
}

int main()
{
    //表示绑定函数myfunc3的三个参数值为10 20 30，返回值anto表示我们不关系它
    //返回的类型，实际它返回的也是一个仿函数类型对象，可以直接调用，也可以
    //赋给std::function
    auto bf1 = std::bind(myfunc3, 10, 20, 30);
    bf1();//执行myfunc3函数 结果x:10 y=20 z=30

    //表示绑定函数myfunc3的第三个参数为30 而myfunc3的第一 第二个参数分别
    //由调用bf2时的第一个 第二个参数指定 _1 _2,...,20这种是标准库里定义的
    //占位符的含义 类似这样的参数有20个 placeholders::_1表示这个位置将在函数调用
    //时被传入的第一个参数所代替
    auto bf2 = std::bind(myfunc3, placeholders::_1, placeholders::_2, 30);
    bf2(5, 15);//实际等于指定myfunc3的第一个和第二个参数 结果x:10 y=20 z=30
    std::bind(myfunc3, placeholders::_1, placeholders::_2, 30)(10, 20);//直接调用

    //myfunc3的第一 第二个参数分别由调用bf3的第二 第一个参数指定
    auto bf3 = std::bind(myfunc3, placeholders::_2, placeholders::_1, 30);
    bf3(5,15);

    int a = 2;
    int b = 3;
    auto bf4 = std::bind(myfunc31,a,placeholders::_1);
    bf4(b);//执行后a=2 b=4 这说明bind对于预先绑定的函数参数是通过值传递的
    //所以这个a实际上是值传递的 bind对于不事先绑定的参数 通过std::placeholders
    //传递的参数是通过引用传递的，所以这个b实际上是引用传递的
    cout << "-------------------------------------------" << endl;
    CQ cq;//一个类对象
    auto bf5 = std::bind(&CQ::myfunpt, cq, placeholders::_1, placeholders::_2);
    //类函数有绝对地址 和对象无关 但要被调用必须有类对象参数
    bf5(10, 20);//对成员函数的调用 结果x=10 y=20
    cout << "-------------------------------------------" << endl;
    //bind和function配合使用（bind返回值直接赋给std::function类型）
    CQ cq1;
    std::function<void(int, int)> bfc6 = std::bind(&CQ::myfunpt, cq1,
                        std::placeholders::_1, std::placeholders::_2);
    bfc6(10, 20);
    cout << "-------------------------------------------" << endl;
    std::function<int& (void)>bf7 = std::bind(&CQ::m_a, &cq);
    bf7() = 60;//执行后cq对象的m_a成员变量值为60了
    cout << "-------------------------------------------" << endl;
    auto rt = std::bind(CT3());
    rt();//调用operator()结果显示CT::operator()执行
    cout << "-------------------------------------------" << endl;
    auto bf = std::bind(runfunc3, placeholders::_1);//第一个参数由调用时
                                                    //的第一个参数指定
    for (int i=0;i<10;i++)
    {
        mycallback3(i, bf);//bf是bind返回的结果 
                           //直接传递给了const std::function<void(int)>&f
    }
    return 0;
}