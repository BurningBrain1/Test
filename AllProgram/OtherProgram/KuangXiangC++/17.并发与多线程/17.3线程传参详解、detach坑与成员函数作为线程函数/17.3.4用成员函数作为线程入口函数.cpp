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

public:
	void thread_work(int num)  //带一个参数
	{
		cout << "子线程thread_work执行,this=" << this << ",thread id=" << this_thread::get_id() << endl;
	}
	void operator()(int num)
	{
		cout << "子线程()执行,this=" << this << ",thread id=" << this_thread::get_id() << endl;
	}
};

int main4()
{
	//1 普通类成员函数
    A myobj(10);
    thread mytobj(&A::thread_work,myobj,15);//类A的拷贝构造函数是在主线程中执行的 析构函数在子线程中执行
    mytobj.join();
    cout << "*****************************************" << endl;
    A myobj1(10);
    thread mytobj1(&A::thread_work,&myobj1,16);//传 真引用写法1
    mytobj1.join();
    cout << "*****************************************" << endl;
    A myobj2(10);
    thread mytobj2(&A::thread_work, ref(myobj2), 16);//传 真引用写法2
    mytobj2.join();
    cout << "main主函数执行结束" << endl;

	//2 可调用对象
	A myobj1(10);
	//thread mytobj(myobj,15);拷贝构造复制带参可调用对象写法
	thread mytobj1(ref(myobj1), 17);//第二个参数不能修改为&myobj 编译会报错
	mytobj1.join();
	cout << "main主函数执行结束" << endl;
    return 0;
}