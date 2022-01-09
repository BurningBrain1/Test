#include<iostream>
#include<thread>
using namespace std;

class TA2
{
public:
    void operator()()
    {
        cout << "TA2::operator()开始执行了" << endl;
        cout << "TA2::operator()执行结束了" << endl;
    }
};

class TA21
{
public:
    TA21(int i) :m_i(i)
    {
        printf("TA21()构造函数执行，m_i=%d,this=%p\n", m_i, this);
    }
    ~TA21()
    {
        printf("TA21()析构函数执行，m_i=%d,this=%p\n", m_i, this);
    }
    TA21(const TA21& ta) :m_i(ta.m_i)
    {
        printf("TA21()拷贝构造函数执行，m_i=%d,this=%p\n", m_i, this);
    }
    void operator()()
    {
        cout << "mi1的值为" << m_i << endl;
        cout << "mi2的值为" << m_i << endl;
        cout << "mi3的值为" << m_i << endl;
        cout << "mi4的值为" << m_i << endl;
        cout << "mi5的值为" << m_i << endl;
        cout << "mi6的值为" << m_i << endl;
    }

    int m_i;  //这里不能用指针或引用 
};

int main2()
{
    //1 用类创建线程
    TA2 ta;
    thread mytobj3(ta);//ta是类可调用对象，不能写thread mytobj3(TA()) 否则编译不过
    mytobj3.join();//确保等待线程执行结束 这里用join
    cout << "**************************************" << endl;

    int myi = 6;
    TA21 ta1(myi);//构造函数执行
    thread mytobj4(ta1);//拷贝构造函数执行
    //mytobj4.detach();
    mytobj4.join();//用join()会输出完整结果      
    cout << "main主函数执行结束" << endl;

	//2 用lambda表达式来创建线程
	auto mylamthread = []
	{
		cout << "我的线程开始执行了" << endl;
		cout << "我的线程执行了完毕了" << endl;
	};

	thread mytobj4(mylamthread);
	mytobj4.join();
	cout << "main主函数执行结束" << endl;
    //结果:
   //我的线程开始执行了
   //我的线程执行了完毕了
   //main主函数执行结束
    return 0;
}
