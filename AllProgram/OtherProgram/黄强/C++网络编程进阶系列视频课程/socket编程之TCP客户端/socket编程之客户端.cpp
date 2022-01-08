#include<winsock2.h>//winsock的头文件
#include<iostream>
using  namespace  std;

//指定动态库的lib文件
#pragma comment(lib,"ws2_32.lib")


//TCP客户端
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

	//2.链接服务端
	sockaddr_in   addr;//不建议使用sockaddr，建议用sockaddr_in
	addr.sin_port = htons(8000);//网络字节序
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//网络字节序
	addr.sin_family = AF_INET; //地址族
	int len = sizeof(sockaddr_in);

	if (connect(s, (sockaddr*)&addr, len) == SOCKET_ERROR)
	{
		cout << "connect  error:" << WSAGetLastError() << endl;
		return 0;
	}

	//3.接受发送消息
	int  ret = 0;
	do
	{
		//接受客户端的消息
		char buf[64] = { '\0' };
		ret = recv(s, buf, 64, 0);//把flag置0
		cout << "recv" << inet_ntoa(addr.sin_addr) << ":    " << buf << endl;// inet_ntoa转换为IP字符串

		//发送
		ret = send(s, "I am Client!", strlen("I am Client!"), 0);

		Sleep(1000);
	} while (ret != SOCKET_ERROR && ret != 0);


	//4.关闭套接字
	closesocket(s);

	//清理winsock环境
	WSACleanup();


	return   0;
}
