#pragma once
#include<iostream>
#include<thread>
#include <list>
#include <mutex>
#include <future>
using namespace std;

class A1
{
public:
    int mythread(int mypar)
    {
        cout << mypar << endl;
        cout << "mythread()start" << "thread id=" << std::this_thread::get_id() << endl;
        std::chrono::milliseconds dura(2000);
        std::this_thread::sleep_for(dura);
        cout << "mythread()end" << "thread id=" << std::this_thread::get_id() << endl;
        return 5;
    }
};

int mythread()
{
    cout << "mythread()start" << "thread id="<< this_thread::get_id() << endl;
    std::chrono::milliseconds dura(2000);//1s=1000s
    std::this_thread::sleep_for(dura);//休息一定的时常
    cout << "mythread()end" << "thread id=" << std::this_thread::get_id() << endl;
    return 5;
}

int mythread1()
{
    return 1;
}

int main()
{
    //1 std::async和std::future
    cout << "main " << "thread id=" << std::this_thread::get_id() << endl;
    std::future<int>result = std::async(mythread);//流程并不会卡在这里
                                                  //如果线程入口函数需要参数
                                                  //把参数放在async第二个参数的位置
    cout << "continue" << endl;
    cout << result.get()<< endl;//卡在这里等待线程执行完 
                                //但这种get因为一些内部特殊操作 只能get一次 否则异常
    cout << "main主函数执行结束" << endl;
    //结果:
    //main threadid=15064
    //continue..!
    //mythread() start threadid=6896
    //mythread() end threadid=6896
    //5
    //main主函数执行结束

    result.wait();//流程卡在这里等待线程返回 但本身不返回结果
    
    A1 a;
    int tmppar = 12;
    std::future<int> result1 = std::async(&A1::mythread, &a, tmppar);
                                    //这里第二个参数是对象地址，才能保证线程里面用的是
                                    //同一个对象 第三个参数是线程入口函数的参数 
    cout << "continue" << endl;
    cout << result1.get() << endl;
    cout << "main主函数执行结束" << endl;
    //结果:
    //main threadid=11552
    //continue..!
    //12
    //mythread() start threadid=13868
    //mythread() end threadid=13868
    //5
    //main主函数执行结束

    //2 std::async额外参数详解
    // 
    //(1)std::launch::deferred
    //该参数表示线程入口函数的执行被延迟到std::future的wait或者get函数调用时，如果wait
    //或者get没有被调用 那么线程就干脆不执行了
    //注意 这种写法根本没创建新线程 而是在主线程中调用的入口函数 
    auto result2 = std::async(std::launch::deferred, &A1::mythread, &a, tmppar);//这里注意偷懒写法auto
    //结果:
    //main threadid=15072
    //continue..!
    //12
    //mythread() start threadid=15072
    //mythread() end threadid=15072
    //5
    //main主函数执行结束

    //(2)std::launch::async 系统必须要创建出新线程来执行
    auto result3 = std::async(std::launch::async, &A1::mythread, &a, tmppar);
    //结果:
    //main threadid=9892
    //continue..!
    //12
    //mythread() start threadid=7916
    //mythread() end threadid=7916
    //5
    //main主函数执行结束

    //(3)std::launch::deferred和std::launch::async同时使用
    auto result4 = std::async(launch::async | launch::deferred, &A1::mythread, &a, tmppar);
    //|表示两个枚举值一起用

    //(4)不用任何额外的参数  
    //async()函数 默认用的就是std::launch::async标记
    std::future<int>result5 = std::async(&A1::mythread, &a, tmppar);

    //3 std::async和std::thread的区别
    //意味着可能是创建新线程并立即开始执行线程
    cout << "main主函数执行结束" << endl;
    return 0;
}