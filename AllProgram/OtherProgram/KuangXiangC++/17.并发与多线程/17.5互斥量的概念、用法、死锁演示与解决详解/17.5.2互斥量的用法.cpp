#include<iostream>
#include<thread>
#include <list>
#include <mutex>
using namespace std;

class A
{
public:
	//���յ�����Ϣ�뵽���е��߳�
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 100; i++)
		{
			my_mutex.lock();//Ҫ������������ �����ȼ���    
			msgRecvQueue.push_back(i);//����������־����յ������ֱ�ӷŵ���Ϣ������
			cout << "inMsgRecvQueue()ִ��,����һ��Ԫ��" << i << endl;
			my_mutex.unlock();//�������ݲ������ ����
		}
	}
	bool outMsgKUKProc(int& commond)
	{
		my_mutex.lock();
		if (!msgRecvQueue.empty())
		{
			commond = msgRecvQueue.front();
			msgRecvQueue.pop_front();
			my_mutex.unlock();
			return true;
		}
		my_mutex.unlock();
		return false;
	}
	//�����ݴ���Ϣ������ȡ�����߳�
	void outMsgRecvQueue()
	{
		int commond = 0;
		for (int i = 0; i < 100; i++)
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
};

class A1
{
public:
	//���յ�����Ϣ�뵽���е��߳�
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 100; i++)
		{
			{
				std::lock_guard<mutex> sbguard(my_mutex);
				//my_mutex.lock();//Ҫ������������ �����ȼ���    
				msgRecvQueue.push_back(i);//����������־����յ������ֱ�ӷŵ���Ϣ������
				cout << "inMsgRecvQueue()ִ��,����һ��Ԫ��" << i << endl;
				//my_mutex.unlock();//�������ݲ������ ����
			}//ִ�е�����sbguard�����������ͻ����mutex��unlock����
		}
	}
	bool outMsgKUKProc(int& commond)
	{
		std::lock_guard<mutex> sbguard(my_mutex);//sbguard�������ı�����
		//my_mutex.lock();
		if (!msgRecvQueue.empty())
		{
			commond = msgRecvQueue.front();
			msgRecvQueue.pop_front();
			//my_mutex.unlock();
			return true;
		}
		//my_mutex.unlock();
		return false;
	}
	//�����ݴ���Ϣ������ȡ�����߳�
	void outMsgRecvQueue()
	{
		int commond = 0;
		for (int i = 0; i < 100; i++)
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
};


int main2()
{
    //1 ʹ��ԭʼlock��unlock�ķ�ʽ
    A myobja;
    thread myOutnMsgObj(&A::outMsgRecvQueue, &myobja);//ע������ڶ�����������������
    thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
    myInMsgObj.join();
    myOutnMsgObj.join();

	//2 ʹ��std::lock_guard��ģ��
	//����ԭ��:��lock_guard��ģ��Ĺ��캯���������mutex��lock��Ա����
	//�������������������mutex��unlock��Ա����

	//ע��:��Ȼʹ�������ܷ��㣬�����絥��ʹ��mutex������ʹ��mutex��������ʱͨ��
	//mutex��unlock��Ա���������������� ��sbguard�޷�������㣬ֻ�е�sbguard����
	//������������ں������ص�ʱ��Ż���Ϊstd::lock_guard<std::mutex>����������ִ��
	//��ȥ����mutex��unlock��Ա����

	A1 myobja;
	thread myOutnMsgObj(&A1::outMsgRecvQueue, &myobja);//ע������ڶ�����������������
	thread myInMsgObj(&A1::inMsgRecvQueue, &myobja);
	myInMsgObj.join();
	myOutnMsgObj.join();
    return 0;
}



