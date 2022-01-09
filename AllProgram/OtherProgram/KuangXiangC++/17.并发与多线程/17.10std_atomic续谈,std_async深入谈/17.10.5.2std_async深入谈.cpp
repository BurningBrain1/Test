#pragma once
#include<iostream>
#include<thread>
#include <list>
#include <mutex>
#include <future>
using namespace std;

int mythread2()
{
    cout << "mythread2 start" << " thread id=" << std::this_thread::get_id() << endl;
    return 1;
}

int main()
{   //std::thread()���ϵͳ��Դ���� ������ܴ����߳̾ͻ�ʧ�� ִ��std::thread()��������
    //std::async()����һ�㲻�д����߳�(����async�ܹ������߳�),һ���������һ���첽����
    cout << "main start" << " thread id=" << std::this_thread::get_id() << endl;
    std::future<int>result = std::async(mythread2);
    cout << result.get() << endl;
    return 0;
}