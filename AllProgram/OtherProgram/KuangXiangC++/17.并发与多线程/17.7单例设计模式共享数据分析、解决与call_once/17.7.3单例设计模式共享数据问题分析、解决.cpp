#pragma once
#include<iostream>
#include<thread>
#include <list>
#include <mutex>
using namespace std;

std::mutex resource_mutex;

class MyCAS  //单例类
{
private:
	MyCAS() {}   //构造函数是私有的
private:
	static MyCAS* m_instance;
public:
	static MyCAS* GetInstance()
	{
		if (m_instance == nullptr)
		{
			std::unique_lock<mutex>mymutex(resource_mutex);//自动加锁
			if (m_instance == nullptr)
			{			
				m_instance = new MyCAS();
				static CGarhuishou cl; //生命周期一直到退出
			}
		}
		return m_instance;
	}

	class CGarhuishou  //类中套类 用于释放对象
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
		cout << "测试" << endl;
	}
};
void mythread()
{
	cout << "我的线程开始执行了" << endl;
	MyCAS* p_a = MyCAS::GetInstance();//在这里初始化很可能出现问题
	cout << "我的线程执行完毕了" << endl;
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