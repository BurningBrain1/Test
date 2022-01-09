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
		for (int i = 0; i < 100; i++)
		{

			//1 lock������try_lock����
			std::unique_lock<mutex> sbguard1(my_mutex, std::defer_lock);
			//sbguard1.lock();//����unique_lock���Զ����� �����Լ��� ��������ֻ�ܼ���
			if (sbguard1.try_lock() == true)//����true��ʾ�õ����� �Լ����ù�unlock����
			{
				msgRecvQueue.push_back(i);//����������־����յ������ֱ�ӷŵ���Ϣ������
				cout << "inMsgRecvQueue()ִ��,����һ��Ԫ��" << i << endl;
				//�������봦��
			}
			else
			{
				cout << "��Ǹû�õ���ͷ �����������" << endl;
			}
			//2 unlock����
			if (0)
			{
				//3 release ����
				std::unique_lock<mutex> sbguard2(my_mutex);
				std::mutex* p_mtx = sbguard2.release();
				//���ڹ�����ϵ��� ����Ա�������Լ������� ��ʵ�������my_mutex
				//����sbguard1�Ѿ�����my_mytex������

				p_mtx->unlock();//��Ϊǰ���Ѿ����� ��������Ҫ�Լ�����
			}
		}
		return;
	}
	bool outMsgKUKProc(int& commond)
	{
		std::unique_lock<mutex> sbguard1(my_mutex);//sbguard�������ı�����
		std::chrono::milliseconds dura(200);//����һ��ʱ����ض��� ��λ���� ��������2s
		std::this_thread::sleep_for(dura);// ��������2s
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
	mutex my_mutex1; //������
};

int main3()
{
    A2 myobja;
    thread myOutnMsgObj(&A2::outMsgRecvQueue, &myobja);//ע������ڶ�����������������
    thread myInMsgObj(&A2::inMsgRecvQueue, &myobja);
    myInMsgObj.join();
    myOutnMsgObj.join();
    return 0;
}