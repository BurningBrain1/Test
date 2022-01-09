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
    std::this_thread::sleep_for(dura);//休息一定的时常
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
        cout << "线程被延迟执行" << endl;
        cout << result.get() << endl;//可以使用get(),wait()来调用mythread2(同步调用)
                                     //在这里等待完成
    } 
    else
    {
        //任务未被推迟 已经开始运行 但是否运行结束 取决于任务执行时间
        if (status==std::future_status::ready)
        {
            //线程运行完毕 可以获取结果
            cout << result.get() << endl;
        } 
        else if(status==std::future_status::timeout)
        {
            //线程还没运行完毕
            //....
        }
    }
    cout << "main主函数执行结束" << endl;
    return 0;
}