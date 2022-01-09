#include<iostream>
#include <functional>
using namespace std;

class CT
{
public:
	int m_i = 5;
	void myfuncpt(int x, int y)
	{
		auto mylambda1 = [this]   //无论用this还是= &都可以读取成员变量值
		{
			return m_i;//有this 这个访问才合法 有& =也可以
		};
		cout << mylambda1() << endl;
	}
};


int main2()
{
	//1 []:不捕获任何变量
	int i = 9;
	auto f1 = []
	{
		//return i;//报错(无法捕获外部变量) 不认识i在哪里定义 看来lambda表达式
										//毕竟是一个匿名函数 按常规理解方式不行
	};
	//不包括静态局部变量 lambda可以直接使用全局静态变量

	//2 [&]:捕获外部作用域中的所有变量 并作为引用在函数体内使用
	int i = 9;
	auto f2 = [&]
	{
		i = 5;
		return i;//因为&的存在 允许给i赋值 从而也就改变了i的值
	};
	cout << f2() << endl;
	cout << i <<endl;

	//(3)[=]:捕获外部作用域中所有的变量 并作为副本按值在函数中使用 可以用它的值 但不能给它赋值
	int i = 9;
	auto f3 = [=]
	{
		//i=5;//这就非法了 不可以给它赋值 因为是以值方式捕获
		return i;//5 i值发生改变 现在i=5
	};
	cout << f3() << endl;//9

	//(4)[this]:一般用于类中 捕获当前类中this指针 让lambda表达式拥有和当前类成员函数相同的
	//访问权限 捕获this的目的是在lambda表达式中使用当前类的成员函数和成员变量
	//注意：：：针对成员变量 [this]或者[=]可以读取 但不能修改 想修改用[&]
	CT ct;
	ct.myfuncpt(3, 4);//5

	//(5)按值捕获和按引用捕获
	//[变量名]:按值捕获(不能修改)变量名所代表的变量 同时不捕获其他变量
	//[&变量名]:按引用捕获(可以修改)变量名代表的变量 同时不捕获其他变量
	//auto mylambda1=[this,x,y](...)  //不能在lambda表达式中修改x y值
	//auto mylambda1=[=](...)         //不能在lambda表达式中修改x y值
	//auto mylambda1=[&](...)         //可以在lambda表达式中修改x y值
	//auto mylambda1=[&x](...)        //只可以使用和修改x值
	//auto mylambda1=[&x,&y](...)     //可以使用和修改x和y值

	//(6)[=,&变量名]:按值捕获所有外部变量 但按引用捕获&中所指的变量
	//auto mylambda1 = [this, &x, y]  //写成auto mylambda1=[=,&x]也可以
	//{
	//	x = 8;   //可以修改了
	//	return m_i;
	//};

	//(7)[&,变量名]:按引用捕获所有的外部变量 但按值捕获变量名所代表的变量
	//auto f4 = [&, x](...);
	return 0;
}

