#include<algorithm>
#include <iostream>
#include <vector>
using namespace std;

void myfunc(int i)
{
	cout << i << endl;
}

//for_each工作原理
template<class InputIterator,class Function>
Function for_each(InputIterator first, InputIterator last, Function f)
{
	for (;first!=last;++first)
		f(*first);//所有可调用对象 只要这样写代码 就可以被调用 非常统一
	return f;
}

int main()
{
	//1 for_each算法
	vector<int> myvector = {10,20,30,40,50};
	for_each (myvector.begin(),myvector.end(),myfunc);//输出：10 20 30 40 50
	

	return 0;
}