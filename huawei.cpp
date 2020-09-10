#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;


int main(){
    // int n;
    vector<int> v = {10,9,2,5,3,7,101,18};
    int n = v.size();
    // for(int i = 0; i < (int)v.size();i++){
    //     cin >> v[i];
    // }
    //dp[i][j] 表示从i到j的最长上升子序列
    vector<vector<int>> dp(n,vector<int>(n));

    dp[0][0] = 1;
    for(int i = 1; i < n; i++){
        for(int j = i; j < n; j++){
            //如果v[j] > v[i] 更新dp
            if(v[j] >= v[i]){
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
            }else{
                continue;
            }
        }
    }
    cout << dp[0][n-1] << endl;
    system("pause");
    return 0;
}