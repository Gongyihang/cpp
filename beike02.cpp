#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;


int main(){
    int T;
    cin >> T;
    while(T--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> yl(m + 1,vector<int>(k + 1,0));
        //dp[i][j]数组表示第i块木板为j种颜料时有多少种配色
        vector<vector<int>> dp(n + 1,vector<int>(m + 1,0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= k; j++){
                cin >> yl[i][k];
            }
        }
        
        for(int j = 1; j <= m; j++){
            dp[1][j] = 1;
        }
        
        for(int i = 1; i < n; i++){//木板
            for(int j = 1; j <= m; j++){//颜料
                for(int x = 1; x <= k; x++){//如果当前木板i+1涂j颜料,考虑前一块木板涂的什么颜色
                    if(j != yl[j - 1][x]){      //j颜料不在限制里
                        dp[i+1][j] = dp[i][j] + 1;
                    }else{
                        continue;
                    }
                }
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}