#include<iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	//1 for_each中的lambda表达式
	vector<int> myvector = {10,20,30,40,50};
	int isum = 0;
	for_each(myvector.begin(), myvector.end(), [&isum](int val) {
		isum += val;
		cout << val << endl;
		});
	cout << "sum=" << isum << endl;//sum=150

	//2 find_if中的lambda表达式
	vector<int>myvector1 = { 10,20,30,40,50 };
	auto result = find_if(myvector1.begin(), myvector1.end(), [](int val) {
		cout << val << endl;
		if (val>15)
		{
			return true;//返回true就停止遍历
		}
		return false;//只要返回false,find_if就不停的遍历myvector 一直到返回true停止
		});

		if (result==myvector1.end())
		{
			cout << "没找到" << endl;
		} 
		else
		{
			cout << *result << endl;//找到了 结果为20
		}
}