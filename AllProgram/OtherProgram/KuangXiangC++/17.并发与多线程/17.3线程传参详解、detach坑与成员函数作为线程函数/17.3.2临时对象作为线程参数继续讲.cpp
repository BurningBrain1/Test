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

//这里一定要写成引用 否则多在子线程中调用一次拷贝构造函数
void myprint4(const A& pmybuf)
{
	cout << "子线程myprint2的参数pmybuf的地址是:" << &pmybuf
		<< ",thread id=" << this_thread::get_id() << endl;
}

int main2()
{
    //1 临时对象构造时机抓捕
    cout << "主线程id=" << this_thread::get_id() << endl;
    int mvar = 1;
	//detach有问题的写法 这个临时对象是在子线程中构造的
    thread mytobj(myprint4,mvar);
    mytobj.join();//用join()方便观察
    cout << "*********************************" << endl;
    thread mytobj1(myprint4,A(mvar));
    mytobj1.join();
    cout << "main主函数执行结束" << endl;
    return 0;
}