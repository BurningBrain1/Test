#include <windows.h>
#include <iostream>
#include <list>
#include <mutex>
using namespace std;
#define _WINDOWSLJQ_//宏定义

class A
{
public:
	A()
	{
#ifdef _WINDOWSLJQ_
		//初始化临界区
		InitializeCriticalSection(&my_winsec);
#endif
	}
	virtual ~A()
	{
#ifdef _WINDOWSLJQ_
		DeleteCriticalSection(&my_winsec);
#endif
	}
	//把收到的消息放入到队列的线程
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 10000; i++)
		{
			cout << "inMsgRecvQueue()执行，插入一个元素" << i << endl;

#ifdef _WINDOWSLJQ_
			//进入临界区
			EnterCriticalSection(&my_winsec);
			msgRecvQueue.push_back(i);
			//离开临界区
			LeaveCriticalSection(&my_winsec);
#else
			my_mutex.lock();
			msgRecvQueue.push_back(i);
			my_mutex.unlock();
#endif
		}
	}
	bool outMsgLULProc(int& command)
	{
#ifdef _WINDOWSLJQ_
		EnterCriticalSection(&my_winsec);
		if (!msgRecvQueue.empty())
		{
			int command = msgRecvQueue.front();
			msgRecvQueue.pop_front();
			LeaveCriticalSection(&my_winsec);
			return true;
		}
		LeaveCriticalSection(&my_winsec);
#else
		my_mutex.lock();
		if (!msgRecvQueue.empty())
		{
			command = msgRecvQueue.front();
			msgRecvQueue.pop_front();
			my_mutex.unlock();
			return true;
		}
		my_mutex.unlock();
#endif
		return false;
	}

	void outMsgRecvQueue()
	{
		int command = 0;
		for (int i=0;i<10000;i++)
		{
			bool result = outMsgLULProc(command);
			if (result=true)
			{
				cout << "outMsgRecvQueue()执行了，从容器中取出一个元素" << command << endl;
			}
			else
			{
				cout << "outMsgRecvQueue()执行了，但消息队列是空元素" << i << endl;
			}
		}
		cout << "end" << endl;
	}

private:
	std::list<int>msgRecvQueue;
	std::mutex my_mutex;
#ifdef _WINDOWSLJQ_
	//Windows下叫临界区(类似于互斥量mutex)
	CRITICAL_SECTION my_winsec;
#endif
};