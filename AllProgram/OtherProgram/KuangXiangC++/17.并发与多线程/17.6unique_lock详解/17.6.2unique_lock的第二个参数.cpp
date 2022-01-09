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
			{
				my_mutex.lock();
				std::unique_lock<std::mutex> sbguard1(my_mutex, std::adopt_lock);
				//std::unique_lock<mutex> sbguard1(my_mutex);//这里也卡了10s 因为拿不到锁
				
				msgRecvQueue.push_back(i);//假设这个数字就是收到的命令，直接放到消息队列里
				cout << "inMsgRecvQueue()执行,插入一个元素" << i << endl;
				
			}   //执行到这里sbguard的析构函数就会调用mutex的unlock函数
		}
	}
	bool outMsgKUKProc(int& commond)
	{
		std::unique_lock<mutex> sbguard1(my_mutex);//sbguard是随便起的变量名
		std::chrono::milliseconds dura(10000);//定义一个时间相关对象 单位毫秒 卡在这里10s
		std::this_thread::sleep_for(dura);// 卡在这里10s
		
		if (!msgRecvQueue.empty())
		{
			commond = msgRecvQueue.front();
			msgRecvQueue.pop_front();
			
			return true;
		}
		
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

class A1 //std::try_to_lock
{
public:
	//把收到的消息入到队列的线程
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 100; i++)
		{

			std::unique_lock<mutex> sbguard1(my_mutex, std::try_to_lock);
			//my_mutex.lock();//要操作共享数据 所以先加锁    
			if (sbguard1.owns_lock())  //条件成立表示拿到了锁头
			{
				//拿到了锁头，离开作用域会自动释放
				msgRecvQueue.push_back(i);//假设这个数字就是收到的命令，直接放到消息队列里
				cout << "inMsgRecvQueue()执行,插入一个元素" << i << endl;
				//其他代码处理
			}
			else
			{
				//没拿到锁头 
				cout << "inMsgRecvQueue()执行，但没拿到锁头，只能干点别的事情" << i << endl;
			}
			//执行到这里sbguard的构造函数就会调用mutex的unlock函数
		}
		return;
	}
	bool outMsgKUKProc(int& commond)
	{
		std::unique_lock<mutex> sbguard1(my_mutex);//sbguard是随便起的变量名
		std::chrono::milliseconds dura(200);//定义一个时间相关对象 单位毫秒 卡在这里2s
		std::this_thread::sleep_for(dura);// 卡在这里2s
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
{   //1 睡眠状态 卡死等待演示 一个函数拿到锁后睡眠20秒 那么另一个函数也这样
    A myobja;
    thread myOutnMsgObj(&A::outMsgRecvQueue, &myobja);//注意这里第二个参数必须是引用
    thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
    myInMsgObj.join();
    myOutnMsgObj.join();

	//2 std::try to lock
	A1 myobja1;
	thread myOutnMsgObj1(&A1::outMsgRecvQueue, &myobja1);//注意这里第二个参数必须是引用
	thread myInMsgObj1(&A1::inMsgRecvQueue, &myobja1);
	myInMsgObj1.join();
	myOutnMsgObj1.join();

	//3 std::defer_lock


    return 0;
}
