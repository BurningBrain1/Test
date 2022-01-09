#include<iostream>
#include<thread>
#include <list>
#include <mutex>
using namespace std;

class A2
{
public:
	//把收到的消息入到队列的线程
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 10000; i++)
		{
			// std::lock_guard<mutex> sbguard(my_mutex);
			//std::lock_guard<mutex> sbguard(my_mutex2);
			my_mutex.lock();//要操作共享数据 所以先加锁  
			my_mutex2.lock();
			msgRecvQueue.push_back(i);//假设这个数字就是收到的命令，直接放到消息队列里
			cout << "inMsgRecvQueue()执行,插入一个元素" << i << endl;
			my_mutex2.unlock();
			my_mutex.unlock();//共享数据操作完毕 解锁
		}
	}
	bool outMsgKUKProc(int& commond)
	{
		//std::lock_guard<mutex> sbguard(my_mutex);
		//std::lock_guard<mutex> sbguard(my_mutex2);
		my_mutex.lock();//my_mutex与my.mutex2位置调换会导致死锁问题
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
	//把数据从消息队列中取出的线程
	void outMsgRecvQueue()
	{
		int commond = 0;
		for (int i = 0; i < 10000; i++)
		{
			bool result = outMsgKUKProc(commond);
			if (result == true)
			{
				cout << "outMsgRecvQueue()执行了,从容器中取出一个元素" << commond << endl;
				//这里可以考虑处理数据
				//。。。。。。。
			}
			else
			{
				cout << "outMsgRecvQueue()执行,但目前收消息队列中是空元素" << i << endl;
			}
		}
		cout << "end" << endl;
	}
private:
	list<int> msgRecvQueue;//收消息队列 用于代表玩家发送过来的命令
	mutex my_mutex; //互斥量
	mutex my_mutex2; //为演示死锁创建的互斥量
};

class A3
{
public:
	//把收到的消息入到队列的线程
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 10000; i++)
		{
			std::lock(my_mutex, my_mutex2);//相当于每个互斥量都调用了lock
			std::lock_guard<mutex>sbguard1(my_mutex, std::adopt_lock);//可以不用unlock 自动
			std::lock_guard<mutex>sbguard2(my_mutex2, std::adopt_lock);//可以不用unlock 自动
			msgRecvQueue.push_back(i);//假设这个数字就是收到的命令，直接放到消息队列里
			cout << "inMsgRecvQueue()执行,插入一个元素" << i << endl;
		}
	}
	bool outMsgKUKProc(int& commond)
	{
		std::lock(my_mutex, my_mutex2);//顺序不重要
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
	//把数据从消息队列中取出的线程
	void outMsgRecvQueue()
	{
		int commond = 0;
		for (int i = 0; i < 10000; i++)
		{
			bool result = outMsgKUKProc(commond);
			if (result == true)
			{
				cout << "outMsgRecvQueue()执行了,从容器中取出一个元素" << commond << endl;
				//这里可以考虑处理数据
				//。。。。。。。
			}
			else
			{
				cout << "outMsgRecvQueue()执行,但目前收消息队列中是空元素" << i << endl;
			}
		}
		cout << "end" << endl;
	}
private:
	list<int> msgRecvQueue;//收消息队列 用于代表玩家发送过来的命令
	mutex my_mutex; //互斥量
	mutex my_mutex2; //为演示死锁创建的互斥量
};

int main3_1()
{
    //2.死锁解开方式
    A2 myobja;
    thread myOutnMsgObj(&A2::outMsgRecvQueue, &myobja);//注意这里第二个参数必须是引用
    thread myInMsgObj(&A2::inMsgRecvQueue, &myobja);
    myInMsgObj.join();
    myOutnMsgObj.join();

	//3 std::lock函数模板 同时可以锁两个互斥量
	//4 std::lock_guard的std::adopt_lock参数  标记互斥量已上锁  只需要解锁
	A3 myobja;
	thread myOutnMsgObj(&A3::outMsgRecvQueue, &myobja);//注意这里第二个参数必须是引用
	thread myInMsgObj(&A3::inMsgRecvQueue, &myobja);
	myInMsgObj.join();
	myOutnMsgObj.join();
    return 0;
}

