#include<iostream>
#include<vector>
#include<thread>
using namespace std;

vector<int>g_v = { 1,2,3 };

void myprint2(int inum)
{
	cout << "idΪ" << this_thread::get_id() << "���߳� ��ӡg_v��ֵ"
		<< g_v[0] << g_v[1] << g_v[2] << endl;
}

int main2()
{
    vector<thread> mythreads;
    //����5���߳� �߳���ڿ�����ͬһ��
    for (int i = 0; i < 5; i++)
    {
        mythreads.push_back(thread(myprint2, i));//��������ʼִ���߳�
    }
    for (auto iter = mythreads.begin(); iter != mythreads.end(); ++iter)
    {
        iter->join();  //�ȴ�5���̶߳�����
    }
    cout << "main������ִ�н���" << endl;
    return 0;
}