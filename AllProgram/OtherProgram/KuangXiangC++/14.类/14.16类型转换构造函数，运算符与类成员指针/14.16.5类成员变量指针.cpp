#include<iostream>
using namespace std;

class CT5
{
public:
	void ptfunc(int tmpvalue)
	{
		cout << "ptfunc��ͨ��Ա����������,value=" << tmpvalue << endl;
	}
	virtual void virtualfunc(int tmpvalue)
	{
		cout << "virtualfunc���Ա����������,value=" << tmpvalue << endl;
	}
	static void staticfunc(int tmpvalue)
	{
		cout << "staticfunc��̬��Ա����������,value=" << tmpvalue << endl;
	}

public:
	int m_a;
	static int m_stca;//������̬��Ա����
};

int CT5::m_stca = 1;//������CT5�ľ�̬��Ա����

int main()
{
	//1.������ͨ��Ա����
	int CT5::* mp = &CT5::m_a;//����һ�����Ա����ָ��
	CT5 ct;
	ct.*mp = 189;//ͨ�����Ա����ָ�����޸ĳ�Ա����ֵ �ȼ�ct.m_a=189
	cout << ct.*mp << endl;//189
	cout << ct.m_a << endl;//189

	//2.���ھ�̬��Ա����
	int* stcp = &CT5::m_stca;//����һ����̬��Ա����ָ��
	*stcp = 796;//�ȼ���CT5::m_stca=796
	cout << *stcp << endl;//796
	return 0;
}