#pragma once
#include<iostream>
#include<thread>
#include <list>
#include <mutex>
#include <future>
#include <vector>
using namespace std;

vector<std::packaged_task<int(int)>>mytasks;

int mythread2(int mypar)
{
	cout << mypar << endl;
	cout << "mythread2()start" << " thread id=" << std::this_thread::get_id() << endl;
	std::chrono::milliseconds dura(5000); //5s
	std::this_thread::sleep_for(dura);//休息一定的时常
	cout << "mythread()end" << " thread id=" << std::this_thread::get_id() << endl;
	return 5;
}

int main()
{
	cout << "main" << " thread id=" << std::this_thread::get_id() <<endl;
	std::packaged_task<int(int)>mypt(mythread2);//把函数(函数换成lambda也可以)mythread通过package_task包装起来
	std::thread t1(std::ref(mypt),1);//线程直接开始执行 第二个参数作为线程入口函数的参数
	t1.join();//可以调用这个等待线程执行完毕 不调用这个不行 程序会崩溃
	std::future<int>result = mypt.get_future();//std::future对象里含有线程入口函数的返回结果
											   //这里用result保存mythread返回的结果
	cout << result.get() << endl;
	cout << "main主函数执行结束" << endl;
	//结果:
	//main thread id=3040
	//1
	//mythread2()start thread id=11308
	//mythread2()end thread id=11308
	//5
	//main主函数执行结束

	//包装lambda写法
	cout << "main" << " thread id=" << std::this_thread::get_id() << endl;
	std::packaged_task<int(int)>mypt([](int mypar)
		{
			cout << mypar << endl;
			cout << "lambda mythread2()start" << " thread id=" << std::this_thread::get_id() << endl;
			std::chrono::milliseconds dura(5000);
			std::this_thread::sleep_for(dura);
			cout << "lambda mythread2()end" << " thread id=" << std::this_thread::get_id() << endl;
			return 15;
		});
	std::thread t1(std::ref(mypt),1);
	t1.join();
	std::future<int>result1 = mypt.get_future();
	cout << result1.get() << endl;
	cout << "main主函数执行结束" << endl;
	//结果:
	//main thread id = 10332;
	//1
	//lambda my mythread2()start thread id=1380
	//lambda my mythread2()end thread id=1380
	//15
	//main主函数执行结束

	//package_task包装起来的对象也可以直接调用  也是一个可调用对象
	cout << "main" << " thread id=" << std::this_thread::get_id() << endl;
	std::packaged_task<int(int)>mypt1([](int mypar)
		{
			//同上
		});
	mypt1(105);//可调用对象 相当于直接进行函数调用 不涉及创建线程
	std::future<int>result = mypt1.get_future();
	cout << result.get() << endl;
	cout << "main主函数执行结束" << endl;
	//结果:
	//main thread id = 3356;
	//105
	//lambda my mythread2()start thread id=3356
	//lambda my mythread2()end thread id=3356
	//15
	//main主函数执行结束

    cout << "main" << " thread id=" << std::this_thread::get_id() << endl;
    std::packaged_task<int(int)>mypt2([](int mypar)
        {
            //同上
        });
	//vector<std::packaged_task<int(int)>>mytasks; 全局变量
	//入容器
	mytasks.push_back(std::move(mypt2));//移动语义 入进去后mypt就empty了
	//出容器
	std::packaged_task<int(int)>mypt3;
	auto iter = mytasks.begin();
	mypt3 = std::move(*iter);//用移动语义
	mytasks.erase(iter);//删除第一个元素 迭代器已经失效不能再用
	mypt3(123);//直接调用
	//要取得结果 还是要借助这个future
	std::future<int>result = mypt3.get_future();
	cout << result.get() << endl;
	cout << "main主函数执行结束" << endl;
    //结果:
    //main thread id = 11712;
    //123
    //lambda my mythread2()start thread id=11712
    //lambda my mythread2()end thread id=11712
    //15
    //main主函数执行结束
	return 0;
}