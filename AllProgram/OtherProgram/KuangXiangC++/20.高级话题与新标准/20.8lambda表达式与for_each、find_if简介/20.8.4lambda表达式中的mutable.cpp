#include<iostream>
#include <functional>
using namespace std;

int main4()
{
	int x = 5;
	auto f = [=]()mutable
	{
		x = 6;     //û��mutable ���x�ǲ������޸ĵ�
		return x;
	};
	//��mutable�ؼ��ֵĻ�  ()������ʡ��
}