#include<iostream>
using namespace std;

class CT4
{
public:
	void ptfunc(int tmpvalue)
	{
		cout << "ptfunc普通成员函数被调用,value=" << tmpvalue << endl;
	}
	virtual void virtualfunc(int tmpvalue)
	{
		cout << "virtualfunc虚成员函数被调用,value=" << tmpvalue << endl;
	}
	static void staticfunc(int tmpvalue)
	{
		cout << "staticfunc静态成员函数被调用,value=" << tmpvalue << endl;
	}
};

int main4()
{
	//1.对于普通成员函数
	void (CT4:: * myfpointpt)(int);//一个类成员函数指针变量的定义 变量名字为myfpointpt
	myfpointpt = &CT4::ptfunc;//类成员函数指针变量myfpointpt被赋值
	CT4 ct, * pct;
	pct = &ct;
	(ct.*myfpointpt)(100);//对象ct 调用成员函数指针变量myfpointpt所指向的成员函数
	(pct->*myfpointpt)(200);//对pct所指的对象 调用成员函数指针变量myfpointpt所指向的成员函数
	cout << "---------------------------------------------------" << endl;
	//2.对于虚成员函数
	void (CT4:: * myfpointvirtual)(int) = &CT4::virtualfunc;
	(ct.*myfpointvirtual)(100);//对象ct 调用指针变量myfpointvirtual所指向的虚成员函数
	(pct->*myfpointvirtual)(200);//对pct所指向的对象 
								 //调用指针变量myfpointvirtual所指向的虚成员函数
	cout << "---------------------------------------------------" << endl;
	//3.对于静态成员函数
	void (*myfpointstatic)(int) = &CT4::staticfunc;//定义一个静态的类成员函数指针并给初值
	myfpointstatic(100);//直接使用静态成员函数指针名即可调用静态成员函数
	cout << "---------------------------------------------------" << endl;
	return 0;
}