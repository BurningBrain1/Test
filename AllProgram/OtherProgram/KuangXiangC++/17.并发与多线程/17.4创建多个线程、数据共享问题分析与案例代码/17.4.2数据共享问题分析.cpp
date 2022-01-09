#include<iostream>
#include<vector>
#include<thread>
using namespace std;

vector<int>g_v = { 1,2,3 };

void myprint2(int inum)
{
	cout << "id为" << this_thread::get_id() << "的线程 打印g_v的值"
		<< g_v[0] << g_v[1] << g_v[2] << endl;
}

int main2()
{
    vector<thread> mythreads;
    //创建5个线程 线程入口可以用同一个
    for (int i = 0; i < 5; i++)
    {
        mythreads.push_back(thread(myprint2, i));//创建并开始执行线程
    }
    for (auto iter = mythreads.begin(); iter != mythreads.end(); ++iter)
    {
        iter->join();  //等待5个线程都返回
    }
    cout << "main主函数执行结束" << endl;
    return 0;
}