//文件名称：chatRoomTestClient.cpp
//工程名称：简易聊天室客户端
//作    者：六维的尘埃(现在改名为【憧憬少】了)
//最后修改：2019-01-24

// #include "stdafx.h"
#include <WinSock2.h>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;
//===============================全局常量=================
const int BUF_SIZE = 2048;
const int NICKNAME_LEN = 20;
const int COLOR_INFO = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY; //亮黄色
const int COLOR_NORMAL = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN; //白色
const int COLOR_ERROR = FOREGROUND_RED | FOREGROUND_INTENSITY; //亮红色
const int COLOR_SUCCESS = FOREGROUND_GREEN | FOREGROUND_INTENSITY; //亮绿色
const int COLOR_NORMAL_I = COLOR_NORMAL | FOREGROUND_INTENSITY;

//===============================全局变量=================
SOCKET sockSer, sockCli; //服务端和客户端的Socket
SOCKADDR_IN addrSer, addrCli; //服务端、客户端的地址包
int naddr = sizeof(SOCKADDR_IN);

char sendbuf[BUF_SIZE]; //发送缓冲区
char inputbuf[BUF_SIZE]; //输入缓冲区
char recvbuf[BUF_SIZE]; //接受缓冲区
char ServIP[50]; //服务器IP地址
char client_name[NICKNAME_LEN] = "travaler"; //用户名

//===============================函数声明==================
DWORD WINAPI Client_Receive_Thread(LPVOID lp);
void setColor(int color);

void showPromptMessage()
{
    cout << "*************" << endl;
    cout << "chatroom" << endl;
    cout << "*************" << endl;
}

int main()
{
    showPromptMessage();
    /*/test===========
	cout << "请输入服务器IP地址" << endl;
	cin.getline(ServIP,50);
	
	
	cout << "请输入你的昵称：" << endl;
	cin.getline(client_name, NICKNAME_LEN);
	//==============*/
    strcpy(ServIP, "127.0.0.1");

    //载入socket库
    WSADATA WSAData;
    if (WSAStartup(MAKEWORD(2, 2), &WSAData) != 0) {
        setColor(COLOR_ERROR);
        cout << "load socket failed!" << endl;
        system("pause");
        return 0;
    }

    //创建socket
    sockCli = socket(AF_INET, SOCK_STREAM, 0);
    //初始化本地地址
    addrCli.sin_family = AF_INET;
    addrCli.sin_addr.s_addr = inet_addr("127.0.0.1");
    addrCli.sin_port = htons(12248);
    //初始化服务器地址
    addrSer.sin_family = AF_INET;
    addrSer.sin_addr.s_addr = inet_addr(ServIP);
    addrSer.sin_port = htons(12248);

    //连接到服务端
    setColor(COLOR_INFO);
    cout << "loading server,please wait!" << endl;
    setColor(COLOR_NORMAL);
    int nrecv;
    while (1) {
        //将服务器的地址包与本客户端的套接字连接
        if (connect(sockCli, (SOCKADDR*)&addrSer, sizeof(addrCli)) != SOCKET_ERROR) {
            setColor(COLOR_SUCCESS);
            cout << "connect succeed!" << endl;
            setColor(COLOR_NORMAL);
            //先告诉服务端自己的名字
            send(sockCli, client_name, sizeof(client_name), 0);

            break;
        }
    }

    //创建接收数据线程
    LPVOID* lp = (LPVOID*)&sockCli;
    HANDLE hThread = CreateThread(NULL, 0, Client_Receive_Thread, lp, 0, NULL);

    //循环接收输入
    while (1) {
        cin.getline(inputbuf, BUF_SIZE);

        //退出点
        if (strcmp(inputbuf, "exit") == 0)
            break;

        strcpy(sendbuf, "[");
        strcpy(sendbuf, client_name);
        strcpy(sendbuf, "]:>");
        strcpy(sendbuf, inputbuf);
        send(sockCli, sendbuf, BUF_SIZE, 0);
    }

    system("pause");

    return 0;
}
DWORD WINAPI Client_Receive_Thread(LPVOID lp)
{
    SOCKET* s = (SOCKET*)lp;
    int nrecv;
    while (1) {
        nrecv = recv(sockCli, recvbuf, sizeof(recvbuf), 0);
        if (nrecv > 0) //如果接收到数据
        {
            cout << recvbuf << endl;
        }
    }

    return 0;
}
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
