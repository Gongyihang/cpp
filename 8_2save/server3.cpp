#include <iostream>
#include <winsock.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;
void initialization();
int main()
{
    //定义长度变量
    int send_len = 0;
    int recv_len = 0;
    int len = 0;
    //定义发送缓冲区和接受缓冲区
    char send_buf[100];
    char recv_buf[100];
    //定义服务端套接字，接受请求套接字
    SOCKET s_server;
    SOCKET s_accept;
    //服务端地址客户端地址
    SOCKADDR_IN server_addr;
    SOCKADDR_IN accept_addr;
    initialization();
    //填充服务端信息
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);
    //创建套接字
    s_server = socket(AF_INET, SOCK_STREAM, 0);
    if (bind(s_server, (SOCKADDR*)&server_addr, sizeof(SOCKADDR)) == SOCKET_ERROR) {
        cout << "socket bind failed!" << endl;
        WSACleanup();
    } else {
        cout << "socket bind succeed!" << endl;
    }
    //设置套接字为监听状态
    if (listen(s_server, SOMAXCONN) < 0) {
        cout << "socket listen failed!" << endl;
        WSACleanup();
    } else {
        cout << "socket listen succeed!" << endl;
    }
    cout << "server listening......" << endl;
    //接受连接请求
    len = sizeof(SOCKADDR);
    s_accept = accept(s_server, (SOCKADDR*)&accept_addr, &len);
    if (s_accept == SOCKET_ERROR) {
        cout << "connect failed!" << endl;
        WSACleanup();
        return 0;
    }
    cout << "connected and prepered to recv data!" << endl;
    //接收数据
    while (1) {
        recv_len = recv(s_accept, recv_buf, 100, 0);
        if (recv_len < 0) {
            cout << "recv failed!" << endl;
            break;
        } else {
            cout << "client info:" << recv_buf << endl;
        }
        cout << "please enter reply info:" << endl;
        cin >> send_buf;
        send_len = send(s_accept, send_buf, 100, 0);
        if (send_len < 0) {
            cout << "send failed" << endl;
            break;
        }
    }
    //关闭套接字
    closesocket(s_server);
    closesocket(s_accept);
    //释放DLL资源
    WSACleanup();
    return 0;
}
void initialization()
{
    //初始化套接字库
    WORD w_req = MAKEWORD(2, 2); //版本号
    WSADATA wsadata;
    int err;
    err = WSAStartup(w_req, &wsadata);
    if (err != 0) {
        cout << "init socket failed!" << endl;
    } else {
        cout << "init socket succeed!" << endl;
    }
    //检测版本号
    if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wHighVersion) != 2) {
        cout << "socket no not correct!" << endl;
        WSACleanup();
    } else {
        cout << "socket no correct!" << endl;
    }
    //填充服务端地址信息
}