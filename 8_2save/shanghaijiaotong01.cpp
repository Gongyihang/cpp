#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//公众号：一航代码
//LCS最长公共子序列
//递归-暴力解法
int find(string str1, string str2, int i, int j)
{
    //空串
    if (i == -1 || j == -1) {
        return 0;
    }
    //找到一个LCS元素，继续往前找
    if (str1[i] == str2[j]) {
        return find(str1, str2, i - 1, j - 1) + 1;
    } else {
        //哪一个串能让LCS更长就更新谁
        return max(find(str1, str2, i - 1, j), find(str1, str2, i, j - 1));
    }
    return find(str1, str2, i - 1, j - 1);
}
//使用dp Table优化
//参考：https://github.com/labuladong/fucking-algorithm/blob/master/动态规划系列/最长公共子序列.md
int longest_common_subsequence(string str1, string str2)
{
    int len1 = str1.size();
    int len2 = str2.size();

    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    for (int i = 1; i < len1 + 1; i++) {
        for (int j = 1; j < len2 + 1; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[len1][len2];
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    // cout << find(str1, str2, str1.size() - 1, str2.size() - 1) << endl;
    cout << longest_common_subsequence(str1, str2) << endl;
    system("pause");
    return 0;
}