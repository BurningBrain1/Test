#pragma once
#include<iostream>
#include<thread>
#include <list>
#include <mutex>
using namespace std;

std::mutex resource_mutex;

class MyCAS  //������
{
private:
	MyCAS() {}   //���캯����˽�е�
private:
	static MyCAS* m_instance;
public:
	static MyCAS* GetInstance()
	{
		if (m_instance == nullptr)
		{
			std::unique_lock<mutex>mymutex(resource_mutex);//�Զ�����
			if (m_instance == nullptr)
			{			
				m_instance = new MyCAS();
				static CGarhuishou cl; //��������һֱ���˳�
			}
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
void mythread()
{
	cout << "�ҵ��߳̿�ʼִ����" << endl;
	MyCAS* p_a = MyCAS::GetInstance();//�������ʼ���ܿ��ܳ�������
	cout << "�ҵ��߳�ִ�������" << endl;
	return;
}

int main3()
{

    thread mytobj1(mythread);
    thread mytobj2(mythread);
    mytobj1.join();
    mytobj2.join();
    return 0;
}