#include<iostream>
#include<vector>
#include<thread>
#include <list>
using namespace std;
class A
{
public:
    //���յ�����Ϣ�뵽���е��߳�
    void inMsgRecvQueue()
    {
        for (int i=0;i<100000;i++)
        {
            cout << "inMsgRecvQueue()ִ��,����һ��Ԫ��" << i << endl;
            msgRecvQueue.push_back(i);//����������־����յ������ֱ�ӷŵ���Ϣ������
        }
    }

    //�����ݴ���Ϣ������ȡ�����߳�
    void outMsgRecvQueue()
    {
        for (int i=0;i<100000;i++)
        {
            if (!msgRecvQueue.empty())
            {
                int commond = msgRecvQueue.front();//���ص�һ��Ԫ�ص��������Ч��
                msgRecvQueue.pop_front(); //�Ƴ���һ��Ԫ�ص�������
                //������Կ��Ǵ�������
                //��������
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
};

int main()
{
    A myobja;
    thread myOutnMsgObj(&A::outMsgRecvQueue,&myobja);//ע������ڶ�����������������
    //��std::refҲ���� ���ܱ�֤�߳����õ���ͬһ������
    thread myInMsgObj(&A::inMsgRecvQueue,&myobja);
    myInMsgObj.join();
    myOutnMsgObj.join();
    return 0;
}