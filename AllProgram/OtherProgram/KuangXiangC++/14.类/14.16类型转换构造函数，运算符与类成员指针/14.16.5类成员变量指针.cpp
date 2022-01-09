#include<iostream>
using namespace std;

class CT5
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

public:
	int m_a;
	static int m_stca;//声明静态成员变量
};

int CT5::m_stca = 1;//定义类CT5的静态成员变量

int main()
{
	//1.对于普通成员变量
	int CT5::* mp = &CT5::m_a;//定义一个类成员变量指针
	CT5 ct;
	ct.*mp = 189;//通过类成员变量指针来修改成员变量值 等价ct.m_a=189
	cout << ct.*mp << endl;//189
	cout << ct.m_a << endl;//189

	//2.对于静态成员变量
	int* stcp = &CT5::m_stca;//定义一个静态成员变量指针
	*stcp = 796;//等价于CT5::m_stca=796
	cout << *stcp << endl;//796
	return 0;
}