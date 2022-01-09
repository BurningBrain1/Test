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
{   //std::thread()如果系统资源紧张 那麽可能创建线程就会失败 执行std::thread()程序会崩溃
    //std::async()我们一般不叫创建线程(解释async能够创建线程),一般叫它创建一个异步任务
    cout << "main start" << " thread id=" << std::this_thread::get_id() << endl;
    std::future<int>result = std::async(mythread2);
    cout << result.get() << endl;
    return 0;
}