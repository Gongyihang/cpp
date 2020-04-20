#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <math.h>
#include <queue>
#include <stack>
#include <string>
using namespace std;

const int maxn = 110;
#define INF 0x3f3f3f
int n, m, mod = 100000;
int map[maxn][maxn];
int vis[maxn];
int dis[maxn];

int Pow(long a, long b)
{
    long ret = 1;
    while (b > 0) {
        if (b & 1)
            ret = (ret * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ret;
}

void dij(int x)
{
    for (int i = 0; i < n; i++) {
        dis[i] = INF;
        vis[i] = 0;
    }
    dis[x] = 0;
    for (int i = 0; i < n; i++) {
        int minn = INF, k = -1;
        for (int j = 0; j < n; j++) {
            if (vis[j] == 0 && dis[j] < minn) {
                minn = dis[j];
                k = j;
            }
        }
        if (k == -1) {
            return;
        }
        vis[k] = 1;
        for (int j = 0; j < n; j++) {
            if (vis[j] == 0 && dis[k] + map[k][j] < dis[j]) {
                dis[j] = dis[k] + map[k][j];
            }
        }
    }
}
int main()
{
    while (cin >> n >> m) {
        fill(map[0], map[0] + maxn * maxn, INF);
        int a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            int c = Pow(2, i);
            if (c < map[a][b]) {
                map[a][b] = map[b][a] = c;
            }
        }
        dij(0);
        for (int i = 1; i < n; i++) {
            if (dis[i] != INF) {
                cout << dis[i] << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    system("pause");
    return 0;
}