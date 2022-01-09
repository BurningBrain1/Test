#include<iostream>
#include<vector>
#include<thread>
#include <list>
using namespace std;
class A
{
public:
    //把收到的消息入到队列的线程
    void inMsgRecvQueue()
    {
        for (int i=0;i<100000;i++)
        {
            cout << "inMsgRecvQueue()执行,插入一个元素" << i << endl;
            msgRecvQueue.push_back(i);//假设这个数字就是收到的命令，直接放到消息队列里
        }
    }

    //把数据从消息队列中取出的线程
    void outMsgRecvQueue()
    {
        for (int i=0;i<100000;i++)
        {
            if (!msgRecvQueue.empty())
            {
                int commond = msgRecvQueue.front();//返回第一个元素但不检查有效性
                msgRecvQueue.pop_front(); //移除第一个元素但不返回
                //这里可以考虑处理数据
                //。。。。
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
};

int main()
{
    A myobja;
    thread myOutnMsgObj(&A::outMsgRecvQueue,&myobja);//注意这里第二个参数必须是引用
    //用std::ref也可以 才能保证线程里用的是同一个对象
    thread myInMsgObj(&A::inMsgRecvQueue,&myobja);
    myInMsgObj.join();
    myOutnMsgObj.join();
    return 0;
}