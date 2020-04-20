
//项目：网络编程|聊天室|客户端


// #include "pch.h"//预编译头
#include <iostream>
#include <WinSock2.h>//socket头文件
#include <cstring>

using namespace std;

#pragma comment(lib,"ws2_32.lib")//socket库

const int port = 12345;//端口号
const int BUFFER_SIZE = 1024;//缓冲区大小

char servIP[] = "127.0.0.1";
DWORD WINAPI recvMsgThread(LPVOID lpParameter);

int main()
{

	//1.初始化socket库
	WSADATA wsaData;//获取版本信息
	WSAStartup(MAKEWORD(2, 2), &wsaData);//MAKEWORD(主版本号，副版本号)

	//2.创建socket
	SOCKET cliSock = socket(AF_INET, SOCK_STREAM, 0);//第三个参数为0代表自动选择协议

	//3.打包地址
	//服务端
	SOCKADDR_IN servAddr = { 0 };
	servAddr.sin_family = AF_INET;//和服务端socket的一样
	servAddr.sin_addr.S_un.S_addr = inet_addr(servIP);//服务端地址设置为回传地址
	servAddr.sin_port = htons(port);//host to net short,设置端口号

	//客户端不用绑定
	if (connect(cliSock, (SOCKADDR*)&servAddr, sizeof(SOCKADDR)) == SOCKET_ERROR)
	{
		cout << "error:" << WSAGetLastError() << endl;
		
	}

	//创建接收消息线程
	CloseHandle(CreateThread(NULL, 0, recvMsgThread, (LPVOID)&cliSock, 0, 0));


	//主线程用于输入要说的消息
	while (1)
	{
		char buf[BUFFER_SIZE] = { 0 };
		cin.getline(buf, sizeof(buf));
		if (strcmp(buf, "quit") == 0)//若输入“quit”则退出聊天室
		{
			break;
		}
		send(cliSock, buf, sizeof(buf), 0);
	}

	closesocket(cliSock);

	WSACleanup();
	return 0;
}
DWORD WINAPI recvMsgThread(LPVOID lpParameter)//接收消息的线程
{
	SOCKET cliSock = *(SOCKET*)lpParameter;//获取参数：客户端socket

	while (1)
	{
		char buffer[BUFFER_SIZE] = { 0 };
		int nrecv = recv(cliSock, buffer, sizeof(buffer), 0);//nrecv是接收到的数据字节数
		if (nrecv > 0)//若接收到数据
		{
			cout << buffer << endl;

		}
		else if (nrecv < 0)//若小于0则说明断开连接
		{
			cout << "lost connect!" << endl;
			break;
		}
	}

	return 0;
}