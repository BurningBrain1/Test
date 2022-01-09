#pragma once
#include<iostream>
#include<thread>
#include <list>
#include <mutex>
using namespace std;

class MyCAS  //单例类
{
private:
	MyCAS() {}   //构造函数是私有的
private:
	static MyCAS* m_instance;
public:
	static MyCAS* GetInstance()
	{
		if (m_instance==nullptr)
		{
			m_instance = new MyCAS();
			cout << "CreateInstance()执行完毕" << endl;//测试用
			static CGarhuishou cl;
		}	
		return m_instance;
	}

	class CGarhuishou  //类中套类 用于释放对象
	{
	public:
		~CGarhuishou()
		{
			if (MyCAS::m_instance)
			{
				delete MyCAS::m_instance;
				MyCAS::m_instance = nullptr;
			}
		}
	};

	void Myfunc()
	{
		cout << "测试" << endl;
	}
};

MyCAS* MyCAS::m_instance = nullptr;//类静态成员定义并初始化

int main2()
{

    MyCAS* p_a = MyCAS::GetInstance(); //创建单例类MyCAS类的对象
    p_a->Myfunc(); //一条测试语句 用于打印结果
    return 0;  //这种写法的测试语句也可以打印结果
}