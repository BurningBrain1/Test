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
	cout << f() << endl;//5 return��x��5������10
    //���ǰ�ֵ������ⲿ���� ��lambda���ʽ��������ʱ��  
	//������Щ�ⲿ����ֵ�ͱ�����һ�ݴ洢��lambda���ʽ������

	//����취
	auto f1 = [&] {  };
	return 0;
}