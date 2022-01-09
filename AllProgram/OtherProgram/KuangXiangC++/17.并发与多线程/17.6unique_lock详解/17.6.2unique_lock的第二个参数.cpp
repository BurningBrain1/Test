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
			{
				my_mutex.lock();
				std::unique_lock<std::mutex> sbguard1(my_mutex, std::adopt_lock);
				//std::unique_lock<mutex> sbguard1(my_mutex);//����Ҳ����10s ��Ϊ�ò�����
				
				msgRecvQueue.push_back(i);//����������־����յ������ֱ�ӷŵ���Ϣ������
				cout << "inMsgRecvQueue()ִ��,����һ��Ԫ��" << i << endl;
				
			}   //ִ�е�����sbguard�����������ͻ����mutex��unlock����
		}
	}
	bool outMsgKUKProc(int& commond)
	{
		std::unique_lock<mutex> sbguard1(my_mutex);//sbguard�������ı�����
		std::chrono::milliseconds dura(10000);//����һ��ʱ����ض��� ��λ���� ��������10s
		std::this_thread::sleep_for(dura);// ��������10s
		
		if (!msgRecvQueue.empty())
		{
			commond = msgRecvQueue.front();
			msgRecvQueue.pop_front();
			
			return true;
		}
		
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

class A1 //std::try_to_lock
{
public:
	//���յ�����Ϣ�뵽���е��߳�
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 100; i++)
		{

			std::unique_lock<mutex> sbguard1(my_mutex, std::try_to_lock);
			//my_mutex.lock();//Ҫ������������ �����ȼ���    
			if (sbguard1.owns_lock())  //����������ʾ�õ�����ͷ
			{
				//�õ�����ͷ���뿪��������Զ��ͷ�
				msgRecvQueue.push_back(i);//����������־����յ������ֱ�ӷŵ���Ϣ������
				cout << "inMsgRecvQueue()ִ��,����һ��Ԫ��" << i << endl;
				//�������봦��
			}
			else
			{
				//û�õ���ͷ 
				cout << "inMsgRecvQueue()ִ�У���û�õ���ͷ��ֻ�ܸɵ�������" << i << endl;
			}
			//ִ�е�����sbguard�Ĺ��캯���ͻ����mutex��unlock����
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
};

int main2()
{   //1 ˯��״̬ �����ȴ���ʾ һ�������õ�����˯��20�� ��ô��һ������Ҳ����
    A myobja;
    thread myOutnMsgObj(&A::outMsgRecvQueue, &myobja);//ע������ڶ�����������������
    thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
    myInMsgObj.join();
    myOutnMsgObj.join();

	//2 std::try to lock
	A1 myobja1;
	thread myOutnMsgObj1(&A1::outMsgRecvQueue, &myobja1);//ע������ڶ�����������������
	thread myInMsgObj1(&A1::inMsgRecvQueue, &myobja1);
	myInMsgObj1.join();
	myOutnMsgObj1.join();

	//3 std::defer_lock


    return 0;
}
