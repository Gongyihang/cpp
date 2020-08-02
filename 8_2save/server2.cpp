//文件名称：chatRoomTest.cpp
//工程名称：简易聊天室服务端
//作    者：六维的尘埃(现在改名为【憧憬少】了)
//最后修改：2019-01-24

// #include "stdafx.h"
#include <WS2tcpip.h>
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
const int MAX_CLIENT_COUNT = 10;
const int COLOR_INFO = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY; //亮黄色
const int COLOR_NORMAL = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN; //白色
const int COLOR_ERROR = FOREGROUND_RED | FOREGROUND_INTENSITY; //亮红色
const int COLOR_NORMAL_I = COLOR_NORMAL | FOREGROUND_INTENSITY;

//===============================全局变量=================
SOCKET sockSer, sockCli;
SOCKADDR_IN addrCli, addrSer;
int naddr = sizeof(SOCKADDR_IN);
char sendbuf[BUF_SIZE]; //发送缓冲区
char inputbuf[BUF_SIZE]; //输入缓冲区
char recvbuf[BUF_SIZE]; //接受缓冲区
char localIP[50] = "127.0.0.1"; //本地IP地址
int clientCount = 0;

struct Client {
    SOCKET s;
    SOCKADDR_IN sin;
    char name[NICKNAME_LEN];
} Cli[MAX_CLIENT_COUNT];

//===============================函数声明==================
DWORD WINAPI Server_Listen_Thread(LPVOID lp);
DWORD WINAPI Server_Receive_Thread(LPVOID lp);
void getLocalIP(char localIp[], int n);
void setColor(int color);

int main()
{

    //载入socket库
    WSADATA WSAData;
    if (WSAStartup(MAKEWORD(2, 2), &WSAData) != 0) {
        setColor(COLOR_ERROR);
        cout << "load socket failed!" << endl;

        system("pause");
        return 0;
    }

    //getLocalIP(localIP, sizeof(localIP) / sizeof(char));

    setColor(COLOR_INFO);
    cout << "computer:" << localIP << ")as server start!" << endl;
    setColor(COLOR_NORMAL);

    //创建socket
    sockSer = socket(AF_INET, SOCK_STREAM, 0);
    //初始化本地地址
    addrSer.sin_family = AF_INET;

    addrSer.sin_addr.s_addr = inet_addr(localIP);
    addrSer.sin_port = htons(12248);

    //绑定socket和本地地址
    bind(sockSer, (SOCKADDR*)&addrSer, sizeof(SOCKADDR));

    //创建接受连接线程
    LPVOID* lp_link = (LPVOID*)&sockSer;
    HANDLE hT_Accept_Link = CreateThread(NULL, 0, Server_Listen_Thread, lp_link, 0, NULL);

    //创建接收数据线程
    LPVOID* lp_recv = (LPVOID*)&sockCli;
    HANDLE hT_Recv = CreateThread(NULL, 0, Server_Receive_Thread, lp_recv, 0, NULL);

    //循环接收输入
    while (1) {
        cin.getline(inputbuf, BUF_SIZE);

        //退出点
        if (strcmp(inputbuf, "/exit") == 0)
            break;
        //给每个客户端发送留言
        strcpy(sendbuf, "[Server]:>");
        strcat(sendbuf, inputbuf);
        for (int i = 1; i <= clientCount; i++) {
            send(Cli[i].s, sendbuf, BUF_SIZE, 0);
        }

        cout << sendbuf << endl; //在自己这边显示
    }
    closesocket(sockSer); //关闭套接字
    WSACleanup(); //卸载socket库
    return 0;
}
DWORD WINAPI Server_Listen_Thread(LPVOID lp)
{
    SOCKET* s = (SOCKET*)lp;
    while (1) {
        //监听socket
        listen(*s, 5);
        //接受连接
        Cli[clientCount + 1].s = accept(*s, (SOCKADDR*)&Cli[clientCount + 1].sin, &naddr); //从服务器套接口接受连接请求，将接受到的地址保存在缓冲区
        //此时创建了一个新的套接口与客户端的套接口连接，之后的通信都从这个专属套接口执行

        if (Cli[clientCount + 1].s != INVALID_SOCKET) //连接成功
        {
            clientCount++;
            //接收客户端名字
            recv(Cli[clientCount].s, Cli[clientCount].name, BUF_SIZE, 0);

            //欢迎信息
            strcpy(sendbuf, "welcome[");
            strcat(sendbuf, Cli[clientCount].name);
            strcat(sendbuf, "]come in!");
            for (int i = 1; i <= clientCount; i++) {
                send(Cli[i].s, sendbuf, BUF_SIZE, 0);
            }
            setColor(COLOR_INFO);
            cout << "[" << Cli[clientCount].name << "](" << inet_ntoa(Cli[clientCount].sin.sin_addr) << ")connect succeed!current connect number:" << clientCount << endl;
            setColor(COLOR_NORMAL);
        }
    }
}
//接收来自客户端的消息
DWORD WINAPI Server_Receive_Thread(LPVOID lp)
{
    SOCKET* s = (SOCKET*)lp;
    int nrecv[MAX_CLIENT_COUNT] = { 0 };

    while (1) {
        //接收每一个客户端的消息
        for (int k = 1; k <= clientCount; k++) {
            nrecv[k] = recv(Cli[k].s, recvbuf, sizeof(recvbuf), 0);
        }
        //显示有消息的客户端的消息
        for (int i = 1; i <= clientCount; i++) {
            if (nrecv[i] > 0) //如果接收到数据
            {
                strcpy(sendbuf, "[");
                strcat(sendbuf, Cli[i].name);
                strcat(sendbuf, "]:>");
                strcat(sendbuf, recvbuf);
                cout << sendbuf << endl;

                //给每个客户端发送信息
                for (int j = 1; j <= clientCount; j++) {
                    send(Cli[j].s, sendbuf, sizeof(sendbuf), 0);
                }
            }
        }
    }
    return 0;
}

void getLocalIP(char localIp[], int n)
{
    gethostname(localIp, n);
    HOSTENT* host = gethostbyname(localIp);
    //以下未研究
    in_addr PcAddr;
    for (int i = 0;; i++) {
        char* p = host->h_addr_list[i];
        if (NULL == p) {
            break;
        }
        memcpy(&(PcAddr.S_un.S_addr), p, host->h_length);
        strcpy(localIp, inet_ntoa(PcAddr));
    }
}

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}