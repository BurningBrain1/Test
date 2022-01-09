#include<iostream>
#include <functional>
using namespace std;

int main3()
{
	int x = 5;
	auto f = [=]
	{
		return x;
	};
	x = 10;
	cout << f() << endl;//5 return的x是5而不是10
    //凡是按值捕获的外部变量 在lambda表达式定义的这个时刻  
	//所有这些外部变量值就被复制一份存储在lambda表达式变量中

	//解决办法
	auto f1 = [&] {  };
	return 0;
}