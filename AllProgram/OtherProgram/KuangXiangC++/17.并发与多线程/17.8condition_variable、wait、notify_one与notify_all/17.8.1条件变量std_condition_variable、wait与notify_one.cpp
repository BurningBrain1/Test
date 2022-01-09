#pragma once
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
		for (int i = 0; i < 1000; i++)
		{
			std::unique_lock<mutex> sbguard1(my_mutex);
			msgRecvQueue.push_back(i);//假设这个数字就是收到的命令，直接放到消息队列里
			cout << "inMsgRecvQueue()执行,插入一个元素" << i << endl;
			my_cond.notify_one();//尝试把堵塞在wait()的线程唤醒 但只唤醒不够
								 //这里必须把互斥量解锁 另外一个线程的wait()才会继续正常工作
			//其他代码处理
		}
		return;
	}


	//把数据从消息队列中取出的线程
	void outMsgRecvQueue()
	{
		int commond = 0;
		while (true)
		{
			std::unique_lock<mutex> sbguard1(my_mutex);//临界进去
			//wait()用于等一个东西
			//如果wait()第二个参数的lambda表达式返回的是true wait就直接返回 此时持续锁住互斥量
			//如果wait()第二个参数的lambda表达式返回的是false wait()将解锁互斥量并堵塞到这行
			//堵到其他某个线程调用notify_one()通知为止
			//如果wait()不用第二个参数 那跟第二个参数为false效果一样 但尽量不要无参用
			my_cond.wait(sbguard1, [this] {
				if (!msgRecvQueue.empty())
				{
					return true;
				}
				return false;
				});
			

			//现在互斥量是锁着的 流程走下来意味着msgRecvQueue队列里必然有数据
			commond = msgRecvQueue.front();//返回第一个元素 但不检查元素是否存在
			msgRecvQueue.pop_front(); //移除第一个元素 但不返回
			cout << "outMsgRecvQueue()执行，取出一个元素" << commond << endl;
			sbguard1.unlock();//因为unique_lock的灵活性 可以随时unlock解锁 以免锁住太长时间
			
		}//end while
	}
private:
	list<int> msgRecvQueue;//收消息队列 用于代表玩家发送过来的命令
	mutex my_mutex; //互斥量
	std::condition_variable my_cond;//生成一个条件对象
};

int main()
{
	A myobja;
	thread myOutMsgObj(&A::outMsgRecvQueue, &myobja);
	thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
	myInMsgObj.join();
	myOutMsgObj.join();
	cout << "main主函数执行结束" << endl;
	return 0;
}
