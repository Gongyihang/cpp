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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i];
    }
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = i; j < n && j < i + m; j++)
        {
            if(v[i] >= k && v[j] >= k) flag++; 
        }
        if(flag == m) dp[i]++;
    }
    int res = 0;
    for(int i = 0;i < n;i++){
        res += dp[i];
    }
    cout << res << endl;

    system("pause");
    return 0;
}