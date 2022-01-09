#include<iostream>
#include<vector>
#include<thread>
using namespace std;

void myprint(int inum)
{
	cout << "myprint线程开始执行了,线程编号=" << inum << endl;
	//do something
	cout << "myprint线程结束执行了,线程编号=" << inum << endl;
}

int main1()
{
    vector<thread> mythreads;
    //创建5个线程 线程入口可以用同一个
    for (int i=0;i<5;i++)
    {
        mythreads.push_back(thread(myprint,i));//创建并开始执行线程
    }
    for (auto iter=mythreads.begin();iter!=mythreads.end();++iter)
    {
        iter->join();  //等待5个线程都返回
    }
    cout << "main主函数执行结束" << endl;
    return 0;
}