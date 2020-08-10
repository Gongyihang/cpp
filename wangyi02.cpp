#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <string.h>
using namespace std;

/*
1
5
30 60 5 15 30

20
*/

int a[20];
int suffixSum[20];
int n;
int minLoss;
void dfs(int first, int second, int cost, int index)
{
    if (index >= n)
    {
        if (first == second)
            minLoss = min(minLoss, cost);
        return;
    }
    if (first == second)
        minLoss = min(minLoss, suffixSum[index] + cost);
    if (abs(first - second) > suffixSum[index])
        return;
    // 给first，给second，扔掉
    dfs(first + a[index], second, cost, index + 1);
    dfs(first, second + a[index], cost, index + 1);
    dfs(first, second, cost + a[index], index + 1);
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        memset(suffixSum, 0, sizeof(suffixSum));
        for (int i = n - 1; i >= 0; --i)
            suffixSum[i] = suffixSum[i + 1] + a[i];
        minLoss = INT32_MAX;
        dfs(0, 0, 0, 0);
        cout << minLoss << endl;
    }
    return 0;
}