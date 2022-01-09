#pragma once
#include<iostream>
#include<thread>
#include <list>
#include <mutex>
#include <future>
using namespace std;

int mythread2()
{
    cout << "mythread2()start" << " thread id=" << std::this_thread::get_id() << endl;
    std::chrono::milliseconds dura(5000); //5s
    std::this_thread::sleep_for(dura);//��Ϣһ����ʱ��
    cout << "mythread2()end" << " thread id=" << std::this_thread::get_id() << endl;
    return 5;
}
int main()
{
    cout << "main start" << " thread id=" << std::this_thread::get_id() << endl;
    std::future<int>result = std::async(mythread2);
    std::future_status status = result.wait_for(std::chrono::seconds(0));//0s
    if (status==std::future_status::deferred)
    {
        cout << "�̱߳��ӳ�ִ��" << endl;
        cout << result.get() << endl;//����ʹ��get(),wait()������mythread2(ͬ������)
                                     //������ȴ����
    } 
    else
    {
        //����δ���Ƴ� �Ѿ���ʼ���� ���Ƿ����н��� ȡ��������ִ��ʱ��
        if (status==std::future_status::ready)
        {
            //�߳�������� ���Ի�ȡ���
            cout << result.get() << endl;
        } 
        else if(status==std::future_status::timeout)
        {
            //�̻߳�û�������
            //....
        }
    }
    cout << "main������ִ�н���" << endl;
    return 0;
}