#include<iostream>
#include <functional>
using namespace std;

int main5()
{
	auto aa = []() {};
	auto bb = []() {};
	
	std::function<int(int)>fc1 = [](int tv) {return tv; };
	cout << fc1(15) << endl;//15
	std::function<int(int)>fc2 = std::bind([](int tv){return tv;}, 16);
	                     //bind的第一个参数是函数指针 第二个参数开始是真正的函数参数
	cout << fc2(15) <<endl;//16 因为上面bind绑死了16，所以这里参数不起作用 除非bind中用placeholder::_1

	//捕获列表为空的lambde表达式 可以转换成一个普通的函数指针
	using functype = int(*)(int);//定义一个函数指针类型
	functype fp = [](int tv) {return tv; };
	cout << fp(17) << endl;
	return 0;
}