#include <stdio.h>
#include <winsock.h>

#define SERVER_ADDRESS "127.0.0.1" //服务器端IP地址
#define PORT 5150 //服务器端的端口号
#define MSGSIZE 1024 //收发缓冲区的大小

#pragma comment(lib, "ws2_32.lib")
int main()
{
    //1.初始化
    //该结构体包含系统所支持的winsock版本信息
    WSADATA wsaData;
    //初始化Winsock2.2
    if (WSAStartup(0x0202, &wsaData) != 0) //WSAStartup(MAKWWORD(2,2),&wsaData)使用Socket的程序在使用Socket之前必须调用WSAStartup函数。
    //以后应用程序就可以调用所请求的Socket库中的其它Socket函数了。
    {
        printf("unable to initialized!");
        return 0;
    }
    //2.socket套接字
    //定义客户端连接所用的套接字
    SOCKET sClient;
    //参数1：TCP/IP协议族，参数2：TCP协议，UDP使用SOCK_DGRAM
    sClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //AF_INET就是IPV4通信AF_INET6是IPV6通信
        //SOCK_STREAM是有保障的(即能保证数据正确传送到对方)面向连接的SOCKET，即TCP链接
        //sock_dgram 是无保障的面向消息的socket ， 主要用于在网络上发广播信息。

    if (sClient == INVALID_SOCKET) {
        printf("socket failed");
        return 0;
    }
    //3.远端服务器
    //保存远端服务器地址
    SOCKADDR_IN server;
    //置0操作
    memset(&server, 0, sizeof(SOCKADDR_IN));
    //指定远端服务器的3个参数
    server.sin_family = AF_INET; //指定地址家族
    server.sin_port = htons(PORT); //指定端口号
    server.sin_addr.s_addr = inet_addr(SERVER_ADDRESS); //server.sin_addr.s_addr=htonl(SERVER_ADDRESS)
        //sin_addr字段用于保存IP地址，sin_addr字段也是一个结构体，sin_addr.s_addr用于保存最终的IP地址
        //inet_addr()函数用于将形如"127.0.0.1"字符串转换为IP地址格式
        //4.连接到服务器
    connect(sClient, (struct sockaddr*)&server, sizeof(SOCKADDR_IN));

    //5.建立连接后传输数据
    char szMessage[MSGSIZE]; //收发缓冲区
    int ret; //成功接收到的字节数
    while (TRUE) {
        printf("Send:");
        //从键盘输入
        fgets(szMessage,MSGSIZE,stdin);
        //发送数据
        //指明发送数据的套接字，待发送数据的保存地址，指明数据长度
        send(sClient, szMessage, strlen(szMessage), 0);

        //接收数据
        ret = recv(sClient, szMessage, MSGSIZE, 0);
        szMessage[ret] = '\0'; //添加这个截断字符

        printf("Received [%d bytes ]: '%s'\n", ret, szMessage);
    }
    //6.释放资源和结束工作
    closesocket(sClient);
    WSACleanup();
    return 0;
}
