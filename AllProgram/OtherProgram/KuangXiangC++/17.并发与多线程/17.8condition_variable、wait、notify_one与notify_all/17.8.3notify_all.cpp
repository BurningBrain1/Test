#pragma once
#include<iostream>
#include<thread>
#include <list>
#include <mutex>
using namespace std;

class A1
{
public:
	//���յ�����Ϣ�뵽���е��߳�
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 100; i++)
		{

			std::unique_lock<mutex> sbguard1(my_mutex);
			msgRecvQueue.push_back(i);//����������־����յ������ֱ�ӷŵ���Ϣ������
			cout << "inMsgRecvQueue()ִ��,����һ��Ԫ��" << i << endl;
			//my_cond.notify_one();//���԰Ѷ�����wait()���̻߳��� ��ֻ���Ѳ���
								 //�������ѻ��������� ����һ���ֳɵ�wait()�Ż������������
			my_cond.notify_all();
			//�������봦��

		}
		return;
	}

	//�����ݴ���Ϣ������ȡ�����߳�
	void outMsgRecvQueue()
	{
		int commond = 0;
		while (true)
		{
			std::unique_lock<mutex> sbguard1(my_mutex);//�ٽ��ȥ
			//wait()���ڵ�һ������
			//���wait()�ڶ���������lambda���ʽ���ص���true wait��ֱ�ӷ���
			//���wait()�ڶ���������lambda���ʽ���ص���false wait()������������������������
			//�µ�����ĳ���̵߳���notify_one()֪ͨΪֹ
			//���wait()���õڶ������� �Ǹ��ڶ�������ΪfalseЧ��һ��
			my_cond.wait(sbguard1, [this] {
				if (!msgRecvQueue.empty())
				{
					return true;
				}
				return false;
				});
			//���ڻ����������ŵ� ������������ζ��msgRecvQueue�������Ȼ������
			commond = msgRecvQueue.front();//���ص�һ��Ԫ�� �������Ԫ���Ƿ����
			msgRecvQueue.pop_front(); //�Ƴ���һ��Ԫ�� ��������
			sbguard1.unlock();//��Ϊunique_lock������� ������ʱunlock���� ������ס̫��ʱ��
			cout << "outMsgRecvQueue()ִ�У�ȡ��һ��Ԫ��" << commond << "thread id="
				<< this_thread::get_id() << endl;
		}//end while
	}
private:
	list<int> msgRecvQueue;//����Ϣ���� ���ڴ�����ҷ��͹���������
	mutex my_mutex; //������
	std::condition_variable my_cond;//����һ����������
};

int main3()
{
    A1 myobja;
    thread myOutMsgObj(&A1::outMsgRecvQueue, &myobja);
    thread myOutMsgObj2(&A1::outMsgRecvQueue, &myobja);
    thread myInMsgObj(&A1::inMsgRecvQueue, &myobja);
    myInMsgObj.join();
    myOutMsgObj2.join();
    myOutMsgObj.join();
    cout << "main������ִ�н���" << endl;
    return 0;
}