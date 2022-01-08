#include<winsock2.h>
#include<iostream>
using namespace  std;

//添加动态库的lib
#pragma comment(lib, "ws2_32.lib")

//UDP客户端
int  main()
{

	//初始化winsock2环境
	WSADATA  wd;
	if (WSAStartup(MAKEWORD(2, 2), &wd) != 0)
	{
		cout << "WSAStartup error:" << GetLastError() << endl;
		return 0;
	}


	//1.依然是创建数据报socket 
	SOCKET  s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (s == INVALID_SOCKET)
	{
		cout << "socket error:" << GetLastError() << endl;
		return 0;
	}

	//服务器端的地址
	sockaddr_in  addr;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(8000);//网络字节序
	addr.sin_family = AF_INET;
	int len = sizeof(sockaddr_in);

	int  ret = 0;
	do
	{
		//2.可以sendto发送和 recvfrom接收 
		ret = sendto(s, "I am Client!", strlen("I am Client!"), 0, (SOCKADDR*)&addr, len);

		char buf[100] = { 0 };
		ret = recvfrom(s, buf, 100, 0, NULL, NULL);//不需要服务端地址
		cout << "recvfrom  " << ret << "  :" << buf << endl;

		Sleep(1000);

	} while (ret != SOCKET_ERROR && ret != 0);


	//3.关闭套接字
	closesocket(s);


	//清理winsock2环境
	WSACleanup();


	return 0;
}