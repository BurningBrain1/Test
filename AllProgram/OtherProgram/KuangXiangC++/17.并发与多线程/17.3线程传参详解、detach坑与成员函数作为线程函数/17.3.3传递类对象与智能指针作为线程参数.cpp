#include<iostream>
#include<thread>
using namespace std;

class A
{
public:
	A(int a) :m_i(a) {
		cout << "A::A(int a)构造函数执行,this=" << this
			<< ",thread id=" << this_thread::get_id() << endl;
	}
	A(const A& a) {
		cout << "A::A(const A)拷贝构造函数执行,this=" << this
			<< ",thread id=" << this_thread::get_id() << endl;
	}
	~A() {
		cout << "~A::A()析构函数执行,this=" << this
			<< ",thread id=" << this_thread::get_id() << endl;
	}
	mutable int m_i;
};

void myprint5(const A& pmybuf)
{
    pmybuf.m_i = 199;//修改该值不会影响到main主函数中实参的成员变量
    cout << "子线程myprint2的参数pmybuf的地址是:" << &pmybuf
        << ",thread id=" << this_thread::get_id() << endl;
}

void myprint6(unique_ptr<int> pzn)
{
    return;
}

int main3()
{
    A myobj(10);//生成一个类对象
    thread mytobj(myprint5,myobj); //修改myprint5形参不会影响到main主函数中实参的成员变量
    mytobj.join();
	cout << "----------------------------------------------------" << endl;

	A myobj1(10);
	thread mytobj1(myprint5, ref(myobj1));//传递真引用 形参const mutable可去掉
	mytobj1.join();
	cout << "----------------------------------------------------" << endl;

	unique_ptr<int> myp(new int(100));
	thread mytobj2(myprint6, std::move(myp));
	mytobj2.join();
    cout << "main主函数执行结束" << endl;
    return 0;
}

