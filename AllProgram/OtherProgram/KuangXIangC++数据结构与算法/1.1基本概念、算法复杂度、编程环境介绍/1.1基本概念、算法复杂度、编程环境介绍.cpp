﻿// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成 ，内含一辈子都让你感激自己的优质视频教程，欢迎关注

#include <iostream>


#ifdef _DEBUG   //只在Debug（调试）模式下
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //重新定义new运算符
#define new DEBUG_NEW
#endif
#endif

//#include <boost/type_index.hpp>
using namespace std;
#pragma warning(disable : 4996) 


//----------------------------
namespace _nmsp1
{
	//1+1001+1000+1 = 2003  =    2n+3次
	void calc(int n) //n=1000 问题规模
	{
		int sum = 0;    //执行1次；
		for (int i = 1; i <= n; ++i)  //执行1001次
		{
			sum = sum + i;    //执行1000次
		}
		cout << sum << endl; //执行1次
	}

	//1+1001+1000  + 1001 + 1001000 + 1000000 + 1 = 2004004   = 2n^2 + 4n + 4次
	void calc2(int n)
	{
		int sum = 0;    //执行1次；
		for (int i = 1; i <= n; ++i)  //执行1001次
		{
			sum = sum + i;    //执行1000次
		}

		for (int j = 1; j <= n; ++j)//执行1001次
		{
			for (int k = 1; k <= n; ++k) //1001 * 1000 = 1001000次
			{
				sum = sum + k;  //1000 * 1000次 = 1000000次
			}
		} //end for j

		cout << sum << endl; //执行1次
	}

	int testfunc(int n) //O(n)
	{
		int sum = 0;
		for (int i = 1; i <= n; ++i)
		{
			sum = sum + i;
		}
		return sum;
	}
	void cacl3(int n)  //O(n * n) = O(n^2)
	{
		int sum = 0;
		for (int i = 1; i <= n; ++i)
		{
			sum = sum + testfunc(i);
		}
	}

}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口

	//C语言：指针
	//C++：类模板
	//不需要C++11
	//课程特色：简单好理解，细致，全面。

	//第1章 基本概念、算法复杂度、编程环境介绍
	//大O表示算法时间复杂度和算法空间复杂度。
	//第一节 数据结构与算法概述
	//a)数据结构：是研究数据之间组织结构的一门学科。
	  //数据结构可以理解为一组数据在计算机中的存储结构或者理解为相互之间存在一种或者多种特定关系的数据集合。
	//b)算法：是操作数据解决特定问题的求解步骤和方法。 一个问题可以有多种算法。
	//c)数据结构和算法的关系：数据结构服务于算法，算法也要作用于特定的数据结构之上，两者相辅相成，不能孤立。
	//d)算法五个特性：输入；输出；有穷性；确定性；可行性；
	//e)一个好的算法通常有四个设计要求：正确性；可读性；健壮性；高时间效率和低存储量需求；

	//第二节 算法的效率度量
	//算法度量：事后统计方法；事前分析估算方法；
	 //事前分析估算方法：算法的时间复杂度分析   与  空间复杂度分析
	//1.2.1 算法的时间复杂度分析
	//1.2.1.1  大O时间复杂度表示法
	   //有公式T(n) = O(f(n))，其中：
		//a)n：表示问题规模的大小
		//b)T(n)：表示算法的执行时间（T指的Time），也就是算法的时间复杂度。
		//c)f(n)：表示代码的执行次数总和。
		//d)O：表示代码的执行时间T(n)与F(n)的函数关系（正比关系）；
		//所以：calc函数中T(n) = O(2n+3)   = O(n)。
		//      calc2函数中T(n) = O( 2n^2 + 4n + 4) = O(n^2)。
	//1.2.1.2 算法时间复杂度计算规则
		//a)只关注循环中的代码段。
		//b)加法规则：  若有T1(n) = O(f(n)),  T2(n) = O(g(n))，则
		   //则T(n) = T1(n) + T2(n) = O(max(f(n),g(n)))。
		   //说明，加法规则的算法时间复杂度取决于阶数最高的代码段的复杂度。所以calc2时间复杂度 O(n^2)。
		//c)乘法规则： 若有T1(n) = O(f(n)),  T2(n) = O(g(n))，则
		   //则T(n) = T1(n) * T2(n) = O(f(n)) * O(g(n)) = O(f(n) * g(n))。
		   //说明，乘法规则的算法时间复杂度取决于内外循环（将对testfunc函数的调用看成是内循环）代码段时间复杂度的乘积。








	_nmsp1::calc(1000);
	_nmsp1::calc2(1000);





	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件


