#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
struct c{
    int sp;
    int mp;
};

void dfs(int k, int hp, vector<bool> &vs,int n,vector<c> &v, int &ans){
    if( k  >= 11) return ;

    if(hp <= 0){
        if(ans > k){
            ans = k;
        }
        return ;
    }
    

    for(int i = 1;i <= n ;i++){
        if(vs[i] == false){
            vs[i] == true;
            if(hp <= v[i].mp){
                dfs(k+1,hp-v[i].sp*2,vs,n,v,ans);
            }else{
                dfs(k+1,hp-v[i].sp,vs,n,v,ans);
            }
            vs[i] = false;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int ans = 11;
        vector<c> v(n + 1);
        vector<bool> vs(n + 1, false);
        for(int i = 1;i <= n;i++){
            cin >> v[i].sp >> v[i].mp;
        }

        dfs(0,m,vs,n,v,ans);

        if(ans == 11) cout << -1 << endl;
        else cout << ans << endl;       
    }

    return 0;
}