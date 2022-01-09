#include<iostream>
#include<thread>
#include <list>
#include <mutex>
using namespace std;

class A
{
public:
	//把收到的消息入到队列的线程
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 100; i++)
		{
			my_mutex.lock();//要操作共享数据 所以先加锁    
			msgRecvQueue.push_back(i);//假设这个数字就是收到的命令，直接放到消息队列里
			cout << "inMsgRecvQueue()执行,插入一个元素" << i << endl;
			my_mutex.unlock();//共享数据操作完毕 解锁
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
	//把数据从消息队列中取出的线程
	void outMsgRecvQueue()
	{
		int commond = 0;
		for (int i = 0; i < 100; i++)
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
};

class A1
{
public:
	//把收到的消息入到队列的线程
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 100; i++)
		{
			{
				std::lock_guard<mutex> sbguard(my_mutex);
				//my_mutex.lock();//要操作共享数据 所以先加锁    
				msgRecvQueue.push_back(i);//假设这个数字就是收到的命令，直接放到消息队列里
				cout << "inMsgRecvQueue()执行,插入一个元素" << i << endl;
				//my_mutex.unlock();//共享数据操作完毕 解锁
			}//执行到这里sbguard的析构函数就会调用mutex的unlock函数
		}
	}
	bool outMsgKUKProc(int& commond)
	{
		std::lock_guard<mutex> sbguard(my_mutex);//sbguard是随便起的变量名
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
	//把数据从消息队列中取出的线程
	void outMsgRecvQueue()
	{
		int commond = 0;
		for (int i = 0; i < 100; i++)
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
};


int main2()
{
    //1 使用原始lock与unlock的方式
    A myobja;
    thread myOutnMsgObj(&A::outMsgRecvQueue, &myobja);//注意这里第二个参数必须是引用
    thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
    myInMsgObj.join();
    myOutnMsgObj.join();

	//2 使用std::lock_guard类模板
	//工作原理:在lock_guard类模板的构造函数里，调用了mutex的lock成员函数
	//而在析构函数里，调用了mutex的unlock成员函数

	//注意:虽然使用起来很方便，但不如单独使用mutex灵活，单独使用mutex，可以随时通过
	//mutex的unlock成员函数来解锁互斥量 而sbguard无法做到这点，只有当sbguard超出
	//作用域或者所在函数返回的时候才会因为std::lock_guard<std::mutex>析构函数的执行
	//而去调用mutex的unlock成员函数

	A1 myobja;
	thread myOutnMsgObj(&A1::outMsgRecvQueue, &myobja);//注意这里第二个参数必须是引用
	thread myInMsgObj(&A1::inMsgRecvQueue, &myobja);
	myInMsgObj.join();
	myOutnMsgObj.join();
    return 0;
}



