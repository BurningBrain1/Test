#pragma once
#include<iostream>
#include<thread>
#include <list>
#include <mutex>
#include <future>
using namespace std;


std::atomic<int> g_mycout = 0;//这是一个原子整形类型变量 可以像使用整型变量一样使用
std::atomic<bool> g_ifend = false;//线程退出标记 用原子操作 防止读和写混乱
void mythread4()
{
	for (int i=0;i<1000;i++)
	{
		g_mycout++;//对应的操作就是原子操作 不会被打断
	}
	return;
}

void mythread4_1()
{
	while (g_ifend == false)//不断地读
	{
		//系统没要求线程退出 所以本线程可以干自己想干的事情
		cout << "thread id=" <<std::this_thread::get_id() << "运行中..." << endl;
	}
}

int main()
{
	cout << "" << endl;

	return 0;
}


