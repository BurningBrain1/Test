#include<winsock2.h>//winsock的头文件
#include<iostream>
using  namespace  std;

//指定动态库的lib文件
#pragma comment(lib,"ws2_32.lib")

//TCP服务端
int main()
{

	//初始化winsock2.2相关的动态库
	WSADATA  wd;//获取socket相关信息
	if (WSAStartup(MAKEWORD(2, 2), &wd) != 0)//0表示成功
	{
		cout << "WSAStartup  error:" << WSAGetLastError() << endl;
		return 0;
	}

	//1.创建TCP   socket , 流式套接字
	SOCKET   s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET)
	{
		cout << "socket  error:" << WSAGetLastError() << endl;
		return 0;
	}

	//2.绑定socket到一个IP地址和端口
	sockaddr_in   addr;//不建议使用sockaddr，建议用sockaddr_in
	addr.sin_port = htons(8000);//网络字节序
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//网络字节序
	addr.sin_family = AF_INET; //地址族
	int len = sizeof(sockaddr_in);
	if (bind(s, (sockaddr*)&addr, len) == SOCKET_ERROR)
	{
		cout << "bind  error:" << WSAGetLastError() << endl;
		return 0;
	}

	//3.监听, 5代表正在等待完成相应的TCP三路握手过程的队列长度
	if (listen(s, 5) == SOCKET_ERROR)
	{
		cout << "listen  error:" << WSAGetLastError() << endl;
		return 0;
	}


	//4.接受客户端请求，并且返回和客户端通讯的套接字
	sockaddr_in   addrClient;// 保存客户端IP地址端口 
	memset(&addrClient, 0, sizeof(sockaddr_in));
	len = sizeof(sockaddr_in);
	SOCKET c = accept(s, (sockaddr*)&addrClient, &len);//成功返回套接字
	if (c == INVALID_SOCKET)
	{
		cout << "accept  error:" << WSAGetLastError() << endl;
		return 0;
	}


	//5.发送，接受消息
	int  ret = 0;
	do
	{
		//向客户端发送数据,不能用监听套接字s，而应该用accept返回的套接字c
		ret = send(c, "I am  Server!", strlen("I am  Server!"), 0);//把flag置0

		//接受客户端的消息
		char buf[64] = { '\0' };
		ret = recv(c, buf, 64, 0);//把flag置0
		cout << "recv" << inet_ntoa(addrClient.sin_addr) << ":    " << buf << endl;// inet_ntoa转换为IP字符串
	} while (ret != SOCKET_ERROR && ret != 0);//对方关闭，返回0 ，错误返回SOCKET_ERROR


	//6.关闭套接字
	closesocket(s);


	//清理winsock环境
	WSACleanup();


	return   0;
}

