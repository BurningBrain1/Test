#include<iostream>
#include<thread>
#include <list>
#include <mutex>
using namespace std;

class A3
{
public:
	std::unique_lock<mutex> rtn_unique_lock()
	{
		std::unique_lock<mutex> tmpguard(my_mutex);
		return tmpguard;//�Ӻ�������һ���ֲ�unique_lock�����ǿ��Ե� �ᵼ��ϵͳ������ʱunique_lock���� ������unique_lock���ƶ����캯��
	}
	//���յ�����Ϣ�뵽���е��߳�
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 100; i++)
		{
			std::unique_lock<mutex> sbguard1(my_mutex);
			//std::unique_lock<mutex> sbguard10(sbguard1);//��������Ȩ ������
			std::unique_lock<mutex>sbguard10(std::move(sbguard1));//�ƶ����� ����my_mutex��sbguard10���԰󶨵�һ����
			//����д��std::unique_lock<mutex> sbguard1=rtn_unique_lock();//Ҳ�ᵼ��unique_lock����Ȩ��ת��
			msgRecvQueue.push_back(i);//����������־����յ������ֱ�ӷŵ���Ϣ������
		}
		return;
	}
	bool outMsgKUKProc(int& commond)
	{
		std::unique_lock<mutex> sbguard(my_mutex);//sbguard�������ı�����
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
};

int main4()
{
    A3 myobja;
    thread myOutnMsgObj(&A3::outMsgRecvQueue, &myobja);//ע������ڶ�����������������
    thread myInMsgObj(&A3::inMsgRecvQueue, &myobja);
    myInMsgObj.join();
    myOutnMsgObj.join();
    return 0;
}