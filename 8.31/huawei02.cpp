#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int k, n;
    cin >> k >> n;
    vector<int> w(n + 1);
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    //dp[i][j]表示把第i个物品装入，背包的容量是j的时候的最大价值

    for (int i = 1; i <= n+1; i++) {
        for (int j = 1; j <= k+1; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i-1] && dp[i][j] < dp[i - 1][j - w[i-1]] + v[i-1]) {
                dp[i][j] = dp[i - 1][j - w[i-1]] + v[i-1];
            }
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}