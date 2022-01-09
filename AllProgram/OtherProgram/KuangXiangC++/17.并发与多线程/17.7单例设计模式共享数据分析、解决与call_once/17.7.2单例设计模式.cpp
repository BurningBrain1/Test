#pragma once
#include<iostream>
#include<thread>
#include <list>
#include <mutex>
using namespace std;

class MyCAS  //������
{
private:
	MyCAS() {}   //���캯����˽�е�
private:
	static MyCAS* m_instance;
public:
	static MyCAS* GetInstance()
	{
		if (m_instance==nullptr)
		{
			m_instance = new MyCAS();
			cout << "CreateInstance()ִ�����" << endl;//������
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

MyCAS* MyCAS::m_instance = nullptr;//�ྲ̬��Ա���岢��ʼ��

int main2()
{

    MyCAS* p_a = MyCAS::GetInstance(); //����������MyCAS��Ķ���
    p_a->Myfunc(); //һ��������� ���ڴ�ӡ���
    return 0;  //����д���Ĳ������Ҳ���Դ�ӡ���
}