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
int n, m;
int map[maxn][maxn];
int vis[maxn];
int dis[maxn];
void dij(int x)
{
    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
        vis[i] = 0;
    }
    dis[x] = 0;
    for (int i = 1; i <= n; i++) {
        int minn = INF, k = -1;
        for (int j = 1; j <= n; j++) {
            if (vis[j] == 0 && dis[j] < minn) {
                minn = dis[j];
                k = j;
            }
        }
        if (k == -1) {
            return;
        }
        vis[k] = 1;
        for (int j = 1; j <= n; j++) {
            if (vis[j] == 0 && dis[k] + map[k][j] < dis[j]) {
                dis[j] = dis[k] + map[k][j];
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    fill(map[0], map[0] + maxn * maxn, INF);
    int a, b, c;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        if (c < map[a][b]) {
            map[a][b] = map[b][a] = c;
        }
    }
    dij(1);
    if (dis[n] != INF) {
        cout << dis[n] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}