#pragma once
#include<iostream>
#include<thread>
#include <list>
#include <mutex>
using namespace std;

std::mutex resource_mutex;
std::once_flag g_flag;//这是一个系统定义的标记

class MyCAS  //单例类
{
private:
	MyCAS() {}   //构造函数是私有的
private:
	static MyCAS* m_instance;

	static void CreateInstance()
	{
		//如下两行是测试代码
		std::chrono::milliseconds dura(20000);
		std::this_thread::sleep_for(dura);
		m_instance = new MyCAS();
		cout << "CreateInstance()执行完毕" << endl;
		static CGarhuishou cl;
	}
public:
	static MyCAS* GetInstance1()
	{
		if (m_instance == nullptr)
		{
			std::call_once(g_flag, CreateInstance);//两个线程同时执行到这里时 
											  //其中一个线程卡在这里等另一个线程的该行执行完毕
											  //g_flag可以看成一把锁
		}
		return m_instance;
	}

	static MyCAS* GetInstance2()
	{
		if (m_instance == nullptr)//在主线程中其他子线程创建之前创建单例类对象 不需要考虑多线程互斥问题
		{
			m_instance = new MyCAS();
			static CGarhuishou cl;
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

void mythread1()
{
	cout << "我的线程开始执行了" << endl;
	MyCAS* p_a = MyCAS::GetInstance1();//这里调用的是GetInstance1
	cout << "我的线程执行完毕了" << endl;
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