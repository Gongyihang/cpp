#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <stdio.h>

#define PORT 5150
#define MSGSIZE 1024

#pragma comment(lib, "ws2_32.lib")

int main()
{
    //1.初始化
    WSADATA wsaData;
    WSAStartup(0x0202, &wsaData);

    //2.创建服务端+客户端套接字  地址
    SOCKET sListen;
    sListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //返回值是成功为0，失败为-1
    SOCKET sClient; //无需初始化

    //3. 服务端自身地址的设置
    SOCKADDR_IN local;
    SOCKADDR_IN client; //客户端的地址 此处无需处理
    local.sin_family = AF_INET;
    local.sin_port = htons(PORT);
    local.sin_addr.s_addr = htonl(INADDR_ANY);

    //4.定义一个客户端地址+绑定操作

    bind(sListen, (struct sockaddr*)&local, sizeof(SOCKADDR_IN));

    //5.将socket设置为监听模式
    listen(sListen, 1); //参数2表示可以监听的个数

    //6.接收客户端发送的连接请求
    int iaddrSize = sizeof(SOCKADDR_IN);
    sClient = accept(sListen, (struct sockaddr*)&client, &iaddrSize); //注意此处最后一个参数是地址，而不是长度和bind函数不同

    //打印客户端的部分信息
    printf("Accepted client:%s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

    //7.传输数据
    char szMessage[MSGSIZE]; //收发缓冲区
    int ret; //收到的个数
    while (TRUE) {
        ret = recv(sClient, szMessage, MSGSIZE, 0);
        szMessage[ret] = '\0';
        printf("Received [%d bytes]: '%s'\n", ret, szMessage);
        printf("Send:");
        //从键盘输入
        fgets(szMessage, MSGSIZE,stdin);
        send(sClient, szMessage, strlen(szMessage), 0);
    }

    system("pause");
    return 0;
}