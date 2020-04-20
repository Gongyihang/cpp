#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <cstdlib>
#include <cstring>
#include<set>
#include<map>
using namespace std;
#define INF 0x3f3f3f
int g[110][110];
bool vis[1010];//标记数组
int dis[1010];//距离数组
int m,n;
int mod=100000;
int Pow(long a, long b)
{
    long ret = 1;
    while (b > 0)
    {
        if (b & 1)
            ret = (ret * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ret;
}

void dfs(){
	for(int i=0;i<n;i++){
		dis[i]=g[0][i];
		vis[i]=false;
	}
	vis[0]=true;
	int p=0;
	for(int i=0;i<n;i++){
		int minn=INF;
		//选取最短的边
		for(int j=0;j<n;j++){
			if(vis[j]==0&&dis[j]<minn){
				minn=dis[j];
				p=j;
			}
		}
		vis[p]=true;
		//以p为中间点更新顶点0到其他顶点的最短距离
		for(int j=0;j<n;j++){
			if(vis[j]==0&&(dis[p]+g[p][j]<dis[j])){
				dis[j]=dis[p]+g[p][j];
			}
		
		}
	}
	for(int i=1;i<n;i++){
		if(dis[i]==INF){
			cout<<-1<<endl;
		}else{
			cout<<dis[i]%100000<<endl;
		}
	}
}
int main(){
	//int n,m;
	
	while(cin>>n>>m){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				g[i][j]=INF;
			}
			g[i][i]=0;
		}	
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			g[a][b]=Pow(2,i);
		}
		dfs();
	}
	
	return 0;
}