
//项目：网络编程|聊天室|服务端

// #include "pch.h" //预编译头
#include <WinSock2.h> //socket头文件
#include <cstring>
#include <iostream>

using namespace std;

#pragma comment(lib, "ws2_32.lib") //socket库

//=====================全局变量区=============================

const int port = 12345;
const int WAIT_TIME = 10; //每个客户端等待事件的时间，毫秒
const int MAX_LINK_NUM = 10; //服务端最大连接数
const int BUFFER_SIZE = 1024; //缓冲区大小
int RECV_TIMEOUT = 10; //接收消息超时，毫秒
int SEND_TIMEOUT = 10; //发送消息超时，毫秒

//应该不能弄全局的缓冲区，因为线程之间可能会同时使用它

SOCKET cliSock[MAX_LINK_NUM]; //客户端套接字,0为服务端，下同
WSAEVENT cliEvent[MAX_LINK_NUM]; //客户端事件
SOCKADDR_IN cliAddr[MAX_LINK_NUM]; //客户端地址
int total = 0; //当前已连接的客户端数目

//=====================函数声明区=============================
DWORD WINAPI servEventThread(LPVOID lpParameter); //服务端事件处理线程

int main()
{
    //1.初始化socket库
    WSADATA wsaData; //获取版本信息
    WSAStartup(MAKEWORD(2, 2), &wsaData); //MAKEWORD(主版本号，副版本号)

    //2.创建socket
    SOCKET servSock = socket(AF_INET, SOCK_STREAM, 0); //流式套接字SOCK_STREAM

    //3.将服务端地址打包在一个结构体里面
    SOCKADDR_IN servAddr = { 0 };
    servAddr.sin_family = AF_INET; //和服务端socket的一样
    servAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); //服务端地址设置为回传地址
    servAddr.sin_port = htons(port); //host to net short,设置端口号

    //4.绑定服务端的socket和打包好的地址
    bind(servSock, (SOCKADDR*)&servAddr, sizeof(servAddr));

    //4.5 给服务端socket绑定一个事件对象，来接收客户端连接的事件
    WSAEVENT servEvent = WSACreateEvent(); //创建一个人工重设的未传信事件对象
    WSAEventSelect(servSock, servEvent, FD_ALL_EVENTS); //绑定事件对象并监听所有事件

    cliSock[0] = servSock;
    cliEvent[0] = servEvent;

    //5.开启监听
    listen(servSock, 10); //监听队列长度为10

    //6.创建接受连接的线程

    //不需要句柄标识所以直接关闭
    CloseHandle(CreateThread(NULL, 0, servEventThread, (LPVOID)&servSock, 0, 0));

    //显示服务器开启信息

    cout << "server start" << endl;
    cout << "max connect number:" << MAX_LINK_NUM << endl;

    /*/connect test
	int addrLen = sizeof(SOCKADDR);//用于接收客户端的地址包结构体长度
	SOCKET cliSock = accept(servSock, (SOCKADDR*)&servAddr, &addrLen);
	if (cliSock != INVALID_SOCKET)
	{
		cout << "连接成功！" << endl;
	}
	while (1)
	{
		char buf[100] = { 0 };//测试用缓冲区
		int nrecv = recv(cliSock, buf, sizeof(buf), 0);
		if (nrecv > 0)//如果接收到客户端的信息就输出到屏幕
		{
			cout << buf << endl;
		}
		
	}
	//=============/*/

    //发送消息给全部客户端
    while (1) {
        char contentBuf[BUFFER_SIZE] = { 0 };
        char sendBuf[BUFFER_SIZE] = { 0 };

        cin.getline(contentBuf, sizeof(contentBuf));
        sprintf(sendBuf, "[server]%s", contentBuf);
        for (int j = 1; j <= total; j++) {
            send(cliSock[j], sendBuf, sizeof(sendBuf), 0);
        }
    }

    //-1.关闭socket库的收尾工作
    WSACleanup();
    return 0;
}

DWORD WINAPI servEventThread(LPVOID lpParameter) //服务端事件处理线程
{
    //这个线程中处理服务端和各个客户端发生的事件
    //没学过线程的朋友可以理解为这里是新的main函数，现在同时有两个main函数在执行
    //CreateThread(NULL, 0, servEventThread, (LPVOID)&servSock, 0, 0)
    //上面这个语句调用了servEventThread函数作为新的main函数，我是这样理解的

    //首先需要将传入的参数还原

    SOCKET servSock = *(SOCKET*)lpParameter;
    //lpParameter是LPVOID类型，可以用f12看到它就是void*类型
    //因此转换为SOCKET*类型后再解引用即可取得传入的socket

    while (1) //不停执行
    {

        for (int i = 0; i < total + 1; i++) //i代表现在正在监听事件的终端
        {
            //若有一个客户端连接，total==1，循环2次，包含服务端和客户端

            //对每一个终端（服务端和客户端），查看是否发生事件，等待WAIT_TIME毫秒
            int index = WSAWaitForMultipleEvents(1, &cliEvent[i], false, WAIT_TIME, 0);
            index -= WSA_WAIT_EVENT_0; //此时index为发生事件的终端下标
            if (index == WSA_WAIT_TIMEOUT || index == WSA_WAIT_FAILED) {
                continue; //如果超时或者出错则跳过此终端
            } else if (index == 0) //若此终端发生事件
            {
                WSANETWORKEVENTS networkEvent; //获取返回的结构体
                WSAEnumNetworkEvents(cliSock[i], cliEvent[i], &networkEvent); //查看是什么事件

                //事件选择================================================
                if (networkEvent.lNetworkEvents & FD_ACCEPT) //若产生accept事件（此处和位掩码相与）
                {
                    if (networkEvent.iErrorCode[FD_ACCEPT_BIT] != 0) {
                        cout << "error:" << networkEvent.iErrorCode[FD_ACCEPT_BIT] << endl;
                        continue;
                    }
                    //接受连接
                    if (total + 1 < MAX_LINK_NUM) //若增加一个客户端仍然小于最大连接数则接收连接
                    {
                        //total为已连接客户端数量
                        int newIndex = total + 1; //分配给新客户端的下标
                        int addrLen = sizeof(SOCKADDR);
                        SOCKET newSock = accept(servSock, (SOCKADDR*)&cliAddr[newIndex], &addrLen);
                        if (newSock != INVALID_SOCKET) {
                            //设置发送和接收时限
                            //setsockopt(newSock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&SEND_TIMEOUT, sizeof(SEND_TIMEOUT));
                            //setsockopt(newSock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&RECV_TIMEOUT, sizeof(RECV_TIMEOUT));

                            //给新客户端分配socket
                            cliSock[newIndex] = newSock;
                            //新客户端的地址已经存在cliAddr[nextIndex]中了
                            //为新客户端创建并绑定事件对象,同时设置监听close,read,write事件
                            WSAEVENT newEvent = WSACreateEvent();
                            WSAEventSelect(cliSock[newIndex], newEvent, FD_CLOSE | FD_READ | FD_WRITE);

                            //忘记把newEvent放进去了
                            cliEvent[newIndex] = newEvent;

                            total++; //客户端连接数增加
                            cout << "#" << newIndex << "(IP:"<< inet_ntoa(cliAddr[newIndex].sin_addr) << ")came into the chatroom:" << total << endl;

                            //给所有客户端发送欢迎消息
                            char buf[BUFFER_SIZE] = { 0 };
                            sprintf(buf, "[server]welcome(IP:%s)", inet_ntoa(cliAddr[newIndex].sin_addr));
                            for (int j = 1; j <= total; j++) {
                                send(cliSock[j], buf, sizeof(buf), 0);
                            }
                        }
                    }

                } else if (networkEvent.lNetworkEvents & FD_CLOSE) //客户端被关闭，即断开连接
                {
                    //i表示已关闭的客户端下标
                    total--;

                    cout << "#" << i << "(IP:" << inet_ntoa(cliAddr[i].sin_addr) << ")exit,current connect number:" << total << endl;
                    //释放这个客户端的资源
                    closesocket(cliSock[i]);
                    WSACloseEvent(cliEvent[i]);

                    //数组调整,用的是顺序表删除元素的方法
                    for (int j = i; j < total; j++) {
                        cliSock[j] = cliSock[j + 1];
                        cliEvent[j] = cliEvent[j + 1];
                        cliAddr[j] = cliAddr[j + 1];
                    }

                    //给所有客户端发送退出聊天室的消息

                    char buf[BUFFER_SIZE] = { 0 };
                    sprintf(buf, "[server]client(IP:%s)exit", inet_ntoa(cliAddr[i].sin_addr));
                    for (int j = 1; j <= total; j++) {
                        send(cliSock[j], buf, sizeof(buf), 0);
                    }
                } else if (networkEvent.lNetworkEvents & FD_READ) //接收到消息
                {
                    char buf[BUFFER_SIZE] = { 0 };
                    char buf2[BUFFER_SIZE] = { 0 };

                    for (int j = 1; j <= total; j++) {
                        int nrecv = recv(cliSock[j], buf, sizeof(buf), 0); //nrecv是接收到的数据字节数
                        if (nrecv > 0) //若接收到数据
                        {
                            sprintf(buf2, "[#%d]%s", j, buf);
                            //在服务端显示
                            cout << buf2 << endl;
                            //在其他客户端显示（广播给其他客户端）
                            for (int k = 1; k <= total; k++) {
                                send(cliSock[k], buf2, sizeof(buf), 0);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}