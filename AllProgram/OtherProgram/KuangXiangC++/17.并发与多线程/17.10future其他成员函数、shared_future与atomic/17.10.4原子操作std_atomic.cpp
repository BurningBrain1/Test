#pragma once
#include<iostream>
#include<thread>
#include <list>
#include <mutex>
#include <future>
using namespace std;


std::atomic<int> g_mycout = 0;//����һ��ԭ���������ͱ��� ������ʹ�����ͱ���һ��ʹ��
std::atomic<bool> g_ifend = false;//�߳��˳���� ��ԭ�Ӳ��� ��ֹ����д����
void mythread4()
{
	for (int i=0;i<1000;i++)
	{
		g_mycout++;//��Ӧ�Ĳ�������ԭ�Ӳ��� ���ᱻ���
	}
	return;
}

void mythread4_1()
{
	while (g_ifend == false)//���ϵض�
	{
		//ϵͳûҪ���߳��˳� ���Ա��߳̿��Ը��Լ���ɵ�����
		cout << "thread id=" <<std::this_thread::get_id() << "������..." << endl;
	}
}

int main()
{
	cout << "" << endl;

	return 0;
}


