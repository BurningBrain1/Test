#include<iostream>
using namespace std;

class CT4
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
};

int main4()
{
	//1.������ͨ��Ա����
	void (CT4:: * myfpointpt)(int);//һ�����Ա����ָ������Ķ��� ��������Ϊmyfpointpt
	myfpointpt = &CT4::ptfunc;//���Ա����ָ�����myfpointpt����ֵ
	CT4 ct, * pct;
	pct = &ct;
	(ct.*myfpointpt)(100);//����ct ���ó�Ա����ָ�����myfpointpt��ָ��ĳ�Ա����
	(pct->*myfpointpt)(200);//��pct��ָ�Ķ��� ���ó�Ա����ָ�����myfpointpt��ָ��ĳ�Ա����
	cout << "---------------------------------------------------" << endl;
	//2.�������Ա����
	void (CT4:: * myfpointvirtual)(int) = &CT4::virtualfunc;
	(ct.*myfpointvirtual)(100);//����ct ����ָ�����myfpointvirtual��ָ������Ա����
	(pct->*myfpointvirtual)(200);//��pct��ָ��Ķ��� 
								 //����ָ�����myfpointvirtual��ָ������Ա����
	cout << "---------------------------------------------------" << endl;
	//3.���ھ�̬��Ա����
	void (*myfpointstatic)(int) = &CT4::staticfunc;//����һ����̬�����Ա����ָ�벢����ֵ
	myfpointstatic(100);//ֱ��ʹ�þ�̬��Ա����ָ�������ɵ��þ�̬��Ա����
	cout << "---------------------------------------------------" << endl;
	return 0;
}