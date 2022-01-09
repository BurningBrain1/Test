#include <windows.h>
#include <iostream>
#include <list>
#include <mutex>
using namespace std;
#define _WINDOWSLJQ_//�궨��

class A
{
public:
	A()
	{
#ifdef _WINDOWSLJQ_
		//��ʼ���ٽ���
		InitializeCriticalSection(&my_winsec);
#endif
	}
	virtual ~A()
	{
#ifdef _WINDOWSLJQ_
		DeleteCriticalSection(&my_winsec);
#endif
	}
	//���յ�����Ϣ���뵽���е��߳�
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 10000; i++)
		{
			cout << "inMsgRecvQueue()ִ�У�����һ��Ԫ��" << i << endl;

#ifdef _WINDOWSLJQ_
			//�����ٽ���
			EnterCriticalSection(&my_winsec);
			msgRecvQueue.push_back(i);
			//�뿪�ٽ���
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
				cout << "outMsgRecvQueue()ִ���ˣ���������ȡ��һ��Ԫ��" << command << endl;
			}
			else
			{
				cout << "outMsgRecvQueue()ִ���ˣ�����Ϣ�����ǿ�Ԫ��" << i << endl;
			}
		}
		cout << "end" << endl;
	}

private:
	std::list<int>msgRecvQueue;
	std::mutex my_mutex;
#ifdef _WINDOWSLJQ_
	//Windows�½��ٽ���(�����ڻ�����mutex)
	CRITICAL_SECTION my_winsec;
#endif
};