#include<winsock2.h>
#include<iostream>
using namespace  std;

//添加动态库的lib
#pragma comment(lib, "ws2_32.lib")

//UDP服务端
int  main()
{

	//初始化winsock2环境
	WSADATA  wd;
	if (WSAStartup(MAKEWORD(2, 2), &wd) != 0)
	{
		cout << "WSAStartup error:" << GetLastError() << endl;
		return 0;
	}

	//1.创建UDP数据报套接字
	SOCKET  s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (s == INVALID_SOCKET)
	{
		cout << "socket  error:" << GetLastError() << endl;
		return 0;
	}


	//2.绑定到Ip地址和端口
	sockaddr_in  addr;
	addr.sin_port = htons(8000);//网络字节序
	//addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");//s_addr是个宏
	addr.sin_family = AF_INET;

	int len = sizeof(SOCKADDR);
	if (bind(s, (SOCKADDR*)&addr, len) == SOCKET_ERROR)
	{
		cout << "bind error:" << GetLastError() << endl;
		return 0;
	}

	int nNetTimeout = 5000; //5秒
	//接收时限
	if (setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char*)&nNetTimeout, sizeof(int)) == SOCKET_ERROR)
	{
		cout << "setsockopt error:" << GetLastError() << endl;
		return 0;
	}



	//3.接受或者发送数据recvfrom, sendto ,不同于TCP的 recv与 send
	int   ret = 0;
	do
	{
		//接受客户端的地址
		sockaddr_in  addrClient;
		memset(&addrClient, 0, sizeof(addrClient));
		int len = sizeof(SOCKADDR);//要赋值结构体的长度

		char buf[100] = { 0 };
		//默认是阻塞的，也就是说，如果没有数据过来，会一直等待
		ret = recvfrom(s, buf, 100, 0, (SOCKADDR*)&addrClient, &len);
		cout << "recvfrom " << ret << ":    " << buf << endl;


		//字节使用上面的客户端地址
		ret = sendto(s, "I am Server!", strlen("I am Server!"), 0, (SOCKADDR*)&addrClient, len);

	} while (ret != SOCKET_ERROR && ret != 0);

	//4.关闭套接字
	closesocket(s);


	//清理winsock2环境
	WSACleanup();


	return 0;
}