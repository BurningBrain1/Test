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
		for (int i = 0; i < 100; i++)
		{

			//1 lock函数和try_lock函数
			std::unique_lock<mutex> sbguard1(my_mutex, std::defer_lock);
			//sbguard1.lock();//反正unique_lock能自动解锁 不用自己解 所以这里只管加锁
			if (sbguard1.try_lock() == true)//返回true表示拿到了锁 自己不用管unlock问题
			{
				msgRecvQueue.push_back(i);//假设这个数字就是收到的命令，直接放到消息队列里
				cout << "inMsgRecvQueue()执行,插入一个元素" << i << endl;
				//其他代码处理
			}
			else
			{
				cout << "抱歉没拿到锁头 做点别的事情吧" << endl;
			}
			//2 unlock函数
			if (0)
			{
				//3 release 函数
				std::unique_lock<mutex> sbguard2(my_mutex);
				std::mutex* p_mtx = sbguard2.release();
				//现在关联关系解除 程序员有责任自己解锁了 其实这个就是my_mutex
				//现在sbguard1已经不和my_mytex关联了

				p_mtx->unlock();//因为前面已经加锁 所以这里要自己解锁
			}
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
	mutex my_mutex1; //互斥量
};

int main3()
{
    A2 myobja;
    thread myOutnMsgObj(&A2::outMsgRecvQueue, &myobja);//注意这里第二个参数必须是引用
    thread myInMsgObj(&A2::inMsgRecvQueue, &myobja);
    myInMsgObj.join();
    myOutnMsgObj.join();
    return 0;
}