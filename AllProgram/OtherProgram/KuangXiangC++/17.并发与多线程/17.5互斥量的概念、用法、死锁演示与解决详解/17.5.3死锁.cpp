#include<iostream>
#include<thread>
#include <list>
#include <mutex>
using namespace std;

class A2
{
public:
	//���յ�����Ϣ�뵽���е��߳�
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 10000; i++)
		{
			// std::lock_guard<mutex> sbguard(my_mutex);
			//std::lock_guard<mutex> sbguard(my_mutex2);
			my_mutex.lock();//Ҫ������������ �����ȼ���  
			my_mutex2.lock();
			msgRecvQueue.push_back(i);//����������־����յ������ֱ�ӷŵ���Ϣ������
			cout << "inMsgRecvQueue()ִ��,����һ��Ԫ��" << i << endl;
			my_mutex2.unlock();
			my_mutex.unlock();//�������ݲ������ ����
		}
	}
	bool outMsgKUKProc(int& commond)
	{
		//std::lock_guard<mutex> sbguard(my_mutex);
		//std::lock_guard<mutex> sbguard(my_mutex2);
		my_mutex.lock();//my_mutex��my.mutex2λ�õ����ᵼ����������
		my_mutex2.lock();
		if (!msgRecvQueue.empty())
		{
			commond = msgRecvQueue.front();
			msgRecvQueue.pop_front();
			my_mutex.unlock();
			my_mutex2.unlock();
			return true;
		}
		my_mutex.unlock();
		my_mutex2.unlock();
		return false;
	}
	//�����ݴ���Ϣ������ȡ�����߳�
	void outMsgRecvQueue()
	{
		int commond = 0;
		for (int i = 0; i < 10000; i++)
		{
			bool result = outMsgKUKProc(commond);
			if (result == true)
			{
				cout << "outMsgRecvQueue()ִ����,��������ȡ��һ��Ԫ��" << commond << endl;
				//������Կ��Ǵ�������
				//��������������
			}
			else
			{
				cout << "outMsgRecvQueue()ִ��,��Ŀǰ����Ϣ�������ǿ�Ԫ��" << i << endl;
			}
		}
		cout << "end" << endl;
	}
private:
	list<int> msgRecvQueue;//����Ϣ���� ���ڴ�����ҷ��͹���������
	mutex my_mutex; //������
	mutex my_mutex2; //Ϊ��ʾ���������Ļ�����
};

class A3
{
public:
	//���յ�����Ϣ�뵽���е��߳�
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 10000; i++)
		{
			std::lock(my_mutex, my_mutex2);//�൱��ÿ����������������lock
			std::lock_guard<mutex>sbguard1(my_mutex, std::adopt_lock);//���Բ���unlock �Զ�
			std::lock_guard<mutex>sbguard2(my_mutex2, std::adopt_lock);//���Բ���unlock �Զ�
			msgRecvQueue.push_back(i);//����������־����յ������ֱ�ӷŵ���Ϣ������
			cout << "inMsgRecvQueue()ִ��,����һ��Ԫ��" << i << endl;
		}
	}
	bool outMsgKUKProc(int& commond)
	{
		std::lock(my_mutex, my_mutex2);//˳����Ҫ
		if (!msgRecvQueue.empty())
		{
			commond = msgRecvQueue.front();
			msgRecvQueue.pop_front();
			my_mutex.unlock();
			my_mutex2.unlock();
			return true;
		}
		my_mutex.unlock();
		my_mutex2.unlock();
		return false;
	}
	//�����ݴ���Ϣ������ȡ�����߳�
	void outMsgRecvQueue()
	{
		int commond = 0;
		for (int i = 0; i < 10000; i++)
		{
			bool result = outMsgKUKProc(commond);
			if (result == true)
			{
				cout << "outMsgRecvQueue()ִ����,��������ȡ��һ��Ԫ��" << commond << endl;
				//������Կ��Ǵ�������
				//��������������
			}
			else
			{
				cout << "outMsgRecvQueue()ִ��,��Ŀǰ����Ϣ�������ǿ�Ԫ��" << i << endl;
			}
		}
		cout << "end" << endl;
	}
private:
	list<int> msgRecvQueue;//����Ϣ���� ���ڴ�����ҷ��͹���������
	mutex my_mutex; //������
	mutex my_mutex2; //Ϊ��ʾ���������Ļ�����
};

int main3_1()
{
    //2.�����⿪��ʽ
    A2 myobja;
    thread myOutnMsgObj(&A2::outMsgRecvQueue, &myobja);//ע������ڶ�����������������
    thread myInMsgObj(&A2::inMsgRecvQueue, &myobja);
    myInMsgObj.join();
    myOutnMsgObj.join();

	//3 std::lock����ģ�� ͬʱ����������������
	//4 std::lock_guard��std::adopt_lock����  ��ǻ�����������  ֻ��Ҫ����
	A3 myobja;
	thread myOutnMsgObj(&A3::outMsgRecvQueue, &myobja);//ע������ڶ�����������������
	thread myInMsgObj(&A3::inMsgRecvQueue, &myobja);
	myInMsgObj.join();
	myOutnMsgObj.join();
    return 0;
}

