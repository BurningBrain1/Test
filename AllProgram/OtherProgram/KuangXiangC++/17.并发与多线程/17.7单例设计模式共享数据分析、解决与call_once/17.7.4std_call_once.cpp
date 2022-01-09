#pragma once
#include<iostream>
#include<thread>
#include <list>
#include <mutex>
using namespace std;

std::mutex resource_mutex;
std::once_flag g_flag;//����һ��ϵͳ����ı��

class MyCAS  //������
{
private:
	MyCAS() {}   //���캯����˽�е�
private:
	static MyCAS* m_instance;

	static void CreateInstance()
	{
		//���������ǲ��Դ���
		std::chrono::milliseconds dura(20000);
		std::this_thread::sleep_for(dura);
		m_instance = new MyCAS();
		cout << "CreateInstance()ִ�����" << endl;
		static CGarhuishou cl;
	}
public:
	static MyCAS* GetInstance1()
	{
		if (m_instance == nullptr)
		{
			std::call_once(g_flag, CreateInstance);//�����߳�ͬʱִ�е�����ʱ 
											  //����һ���߳̿����������һ���̵߳ĸ���ִ�����
											  //g_flag���Կ���һ����
		}
		return m_instance;
	}

	static MyCAS* GetInstance2()
	{
		if (m_instance == nullptr)//�����߳����������̴߳���֮ǰ������������� ����Ҫ���Ƕ��̻߳�������
		{
			m_instance = new MyCAS();
			static CGarhuishou cl;
		}
		return m_instance;
	}

	class CGarhuishou  //�������� �����ͷŶ���
	{
	public:
		~CGarhuishou()
		{
			if (MyCAS::m_instance)
			{
				delete MyCAS::m_instance;
				MyCAS::m_instance = nullptr;
			}
		}
	};

	void Myfunc()
	{
		cout << "����" << endl;
	}
};

void mythread1()
{
	cout << "�ҵ��߳̿�ʼִ����" << endl;
	MyCAS* p_a = MyCAS::GetInstance1();//������õ���GetInstance1
	cout << "�ҵ��߳�ִ�������" << endl;
	return;
}

int main()
{
    
    thread mytobj1(mythread1);
    thread mytobj2(mythread1);
    mytobj1.join();
    mytobj2.join();
    return 0;
}