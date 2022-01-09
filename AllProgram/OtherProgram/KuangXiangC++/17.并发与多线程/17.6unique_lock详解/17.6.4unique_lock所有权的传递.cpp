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
		return tmpguard;//从函数返回一个局部unique_lock对象是可以的 会导致系统生成临时unique_lock对象 并调用unique_lock的移动构造函数
	}
	//把收到的消息入到队列的线程
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 100; i++)
		{
			std::unique_lock<mutex> sbguard1(my_mutex);
			//std::unique_lock<mutex> sbguard10(sbguard1);//复制所有权 不可以
			std::unique_lock<mutex>sbguard10(std::move(sbguard1));//移动语义 现在my_mutex和sbguard10可以绑定到一起了
			//或者写成std::unique_lock<mutex> sbguard1=rtn_unique_lock();//也会导致unique_lock所有权的转移
			msgRecvQueue.push_back(i);//假设这个数字就是收到的命令，直接放到消息队列里
		}
		return;
	}
	bool outMsgKUKProc(int& commond)
	{
		std::unique_lock<mutex> sbguard(my_mutex);//sbguard是随便起的变量名
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

int main4()
{
    A3 myobja;
    thread myOutnMsgObj(&A3::outMsgRecvQueue, &myobja);//注意这里第二个参数必须是引用
    thread myInMsgObj(&A3::inMsgRecvQueue, &myobja);
    myInMsgObj.join();
    myOutnMsgObj.join();
    return 0;
}