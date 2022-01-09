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
	                     //bind�ĵ�һ�������Ǻ���ָ�� �ڶ���������ʼ�������ĺ�������
	cout << fc2(15) <<endl;//16 ��Ϊ����bind������16��������������������� ����bind����placeholder::_1

	//�����б�Ϊ�յ�lambde���ʽ ����ת����һ����ͨ�ĺ���ָ��
	using functype = int(*)(int);//����һ������ָ������
	functype fp = [](int tv) {return tv; };
	cout << fp(17) << endl;
	return 0;
}