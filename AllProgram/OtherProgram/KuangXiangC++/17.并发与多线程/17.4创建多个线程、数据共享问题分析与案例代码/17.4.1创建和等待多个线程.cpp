#include<iostream>
#include<vector>
#include<thread>
using namespace std;

void myprint(int inum)
{
	cout << "myprint�߳̿�ʼִ����,�̱߳��=" << inum << endl;
	//do something
	cout << "myprint�߳̽���ִ����,�̱߳��=" << inum << endl;
}

int main1()
{
    vector<thread> mythreads;
    //����5���߳� �߳���ڿ�����ͬһ��
    for (int i=0;i<5;i++)
    {
        mythreads.push_back(thread(myprint,i));//��������ʼִ���߳�
    }
    for (auto iter=mythreads.begin();iter!=mythreads.end();++iter)
    {
        iter->join();  //�ȴ�5���̶߳�����
    }
    cout << "main������ִ�н���" << endl;
    return 0;
}