
#include <iostream>
#include <ctime>
#include <vector>
#include <functional>
using namespace std;

std::vector<std::function<bool(int)>>gv;//全局量 每个元素都是一个function
								//每个function给进去一个int 返回一个bool

void myfunc1()
{
	//要包含<ctime>头
	srand((unsigned)time(NULL));//根据当前时间设置一个随机数种子 方便后面用rand
								//产生随机数 否则每次程序运行随机数都一样
	int tmpvalue = rand() % 6;//0-5之间随机值
	gv.push_back(//塞一个可调用对象(lambda表达式)到gv容器中
		[&](int tv) {
			//这个lambda的生存依赖于tmpvalue的生命期 这是很麻烦的事
			if (tv % tmpvalue == 0)//如果tv是tmpvalue的倍数
			{
				return true;
			}
			return false;
		});
}

int main()
{
	myfunc1();
	cout << gv[0](10) << endl;//跟踪调试 这个调用导致问题 因为此时lambda里tmpvalue
							  //已被销毁 所以会产生未定义行为



	return 0;
}
