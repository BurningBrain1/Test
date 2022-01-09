#include<iostream>
#include <functional>
using namespace std;

int main4()
{
	int x = 5;
	auto f = [=]()mutable
	{
		x = 6;     //没有mutable 这个x是不允许修改的
		return x;
	};
	//有mutable关键字的话  ()不可以省略
}