#pragma once
#include<iostream>
#include<thread>
#include <list>
#include <mutex>
#include <future>
using namespace std;

int mythread1()
{
	cout << "mythread1()start" << " thread id=" << std::this_thread::get_id() << endl;
	std::chrono::milliseconds dura(5000); //5s
	std::this_thread::sleep_for(dura);//休息一定的时常
	cout << "mythread1()end" << " thread id=" << std::this_thread::get_id() << endl;
	return 5;
}

int main()
{
	cout << "main thread id =" << std::this_thread::get_id() <<endl;
	std::future<int>result = std::async(mythread1);//流程并不会卡在这
	cout << "continue!" << endl;
	cout << result.get() << endl;//卡在这里等待线程执行完 但是这种get因为一些内部特殊操作
								 //不能get多次 只能get一次
	cout << "main主函数执行结束" <<endl;
	//结果:
	//main thread id=12024
	//continue
    //mythread()start threadid=3916
	//mythread()end threadid=3916
	//5
	//main主函数执行结束

	//future_status
	std::future_status status = result.wait_for(std::chrono::seconds(1));//等待一秒 注意写法
									//但如果async的第一个参数用了std::launch::deferred
									//则这里是不会做任何等待的 因为线程根本没启动(延迟)
	if (status==std::future_status::timeout)
	{
		//超时：表示线程还没执行完
		cout << "超时线程没执行完" << endl;
		cout << result.get() << endl;
	}
	else if (status == std::future_status::ready)
	{
		//线程成功返回
		cout << "线程成功执行完毕并返回" << endl;
		cout << result.get() << endl;
	}
	else if (status==std::future_status::deferred)
	{
		//如果async的第一个参数被设置为std::launch::deferred 则本条件成立
		cout << "线程被延迟执行" << endl;
		cout << "result.get()" << endl;//这会导致在主线程中执行了线程入口函数
	}
	cout << "main主函数执行结束" << endl;
	return 0;
}