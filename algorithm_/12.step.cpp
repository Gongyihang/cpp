// #include <algorithm>
// #include <cmath>
// #include <iostream>
// #include <map>
// #include <queue>
// #include <stack>
// #include <string>
// #include <vector>
// using namespace std;
// //一航代码
// typedef long long ll;
// int main()
// {
//     ll n, m;
//     cin >> n >> m;
//     vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(m + 1, vector<ll>(m + 1)));
//     for (int i = 0; i <= min(n, m); ++i) {
//         dp[i][i][0] = 1;
//     }
//     for (int hig = 0; hig <= n; ++hig) {                
//         int count = 0;
//         for (int nxt = 0; nxt <= m; ++nxt) {            
//             for (int cur = 0; cur <= m; ++cur) {        
//                 if (cur != nxt) {
//                     for (int pre = 0; pre <= m; ++pre) {                
//                         if (pre != nxt && pre != cur && hig >= nxt + cur
//                             && hig - nxt >= cur + pre && dp[hig - nxt][cur][pre] != 0) {
//                             dp[hig][nxt][cur] = (dp[hig][nxt][cur] + dp[hig - nxt][cur][pre]) % 1000000007;
//                             count = (count + dp[hig - nxt][cur][pre]) % 1000000007;
//                         }
//                     }
//                 }
//             }
//         }
//         if (hig == n) { 
//             if (n <= m) {
//                 count++;
//             }
//             cout << count;
//         }
//     }
//     return 0;
// }

// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <map>
// #include <stack>
// #include <queue>
// #include <cmath>
// using namespace std;
// //一航代码
// typedef long long ll;
// ll steps[100001][8][8] = {0};
// const ll mod = 1e9+7;

// ll backtracking(int n,int m,int pre1, int pre2);

// int main(){
//     int n, m;
//     cin >> n >> m;
//     cout << backtracking(n, m, 0, 0);
//     system("pause");
//     return 0;
// }

// static ll backtracking(int n, int m,int pre1, int pre2){
//     if(n <= 0){
//         return n == 0 ? 1 : 0;
//     }
//     if(steps[n][pre1][pre2] != 0){
//         return steps[n][pre1][pre2];
//     }
//     ll cnt = 0;
//     for(int i = 1; i <= m; i++){
//         if(i != pre1 && i != pre2){
//             cnt += backtracking(n - i, m, i, pre1);
//         }
//     }
//     steps[n][pre1][pre2] = cnt % mod;
//     return steps[n][pre1][pre2];
// }

// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <map>
// #include <stack>
// #include <queue>
// #include <cmath>
// using namespace std;
// //一航代码
// //跳台阶,1,2
// int fib_cur(int n){
//     if(n == 1) return 1;
//     else if(n == 2) return 2;
//     else return fib_cur(n - 1) + fib_cur(n - 2);
// }
// //跳台阶备忘录
// int helper(vector<int>& memo, int n);
// int fib_memo(int N) {
//     if (N < 1) return 0;
//     // 备忘录全初始化为 0
//     vector<int> memo(N + 1, 0);
//     // 初始化最简情况
//     return helper(memo, N);
// }
 
// int helper(vector<int>& memo, int n) {
//     // base case 
//     if(n == 1) return 1;
//     else if(n == 2) return 2;
//     // 已经计算过
//     if (memo[n] != 0) return memo[n];
//     memo[n] = helper(memo, n - 1) + 
//                 helper(memo, n - 2);
//     return memo[n];
// }

// //dp数组迭代法
// int fib_ite(int N) {
//     vector<int> dp(N + 1, 0);
//     // base case
//     dp[1] = 1;
//     dp[2] = 2;
//     for (int i = 3; i <= N; i++)
//         dp[i] = dp[i - 1] + dp[i - 2];
//     return dp[N];
// }
// //迭代空间复杂度O(1)
// int fib_ite_space(int n) {
//     // base case 
//     if(n == 1) return 1;
//     else if(n == 2) return 2;
//     int prev = 1, curr = 2;
//     for (int i = 3; i <= n; i++) {
//         int sum = prev + curr;
//         prev = curr;
//         curr = sum;
//     }
//     return curr;
// }

// int main(){
//     int n = 20;
//     cout << fib_cur(n) << endl;         //递归
//     cout << fib_memo(n) << endl;        //备忘录递归
//     cout << fib_ite(n) << endl;         //dp数组迭代
//     cout << fib_ite_space(n) << endl;   //迭代优化
//     system("pause");
//     return 0;
// }

// #include <algorithm>
// #include <cmath>
// #include <iostream>
// #include <map>
// #include <queue>
// #include <stack>
// #include <string>
// #include <vector>
// using namespace std;

// typedef long long ll;
// const int mod = 1e9 + 7;
// int f[8][8][100005];
// int main()
// {
//     int m, n;
//     cin >> n >> m;
//     f[0][0][0] = 1;
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m && j <= i; j++) {//下一步
//             for (int k = 1; k <= m; k++) {      //上一步
//                 for (int t = 1; t <= m; t++) {  //上上一步
//                     if (k != j && t != j) {
//                         f[t][j][i] += f[k][t][i - j];
//                         f[t][j][i] %= mod;
//                     }
//                 }
//             }
//         }
//     }
//     ll ans = 0;
//     for (int i = 1; i <= m; i++) {
//         for (int j = 1; j <= m; j++) {
//             ans += f[i][j][n];
//             ans %= mod;
//         }
//     }
//     cout << ans << endl;
// }

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
//一航代码
int fib(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    int f = 1;
    for (int i = 2; i <= n; i++) {
        f = 2 * f;
    }
    return f;
}

int main(){
    int n = 10;
    cout << fib(n) << endl;
    cout << pow(2, n - 1) << endl;//简便运算
    system("pause");
    return 0;
}