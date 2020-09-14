#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

bool dfs(vector<vector<int>>& v2, vector<int>& flags, int i)
{
    if (flags[i] == 1)
        return false;
    if (flags[i] == -1)
        return true;
    flags[i] = 1;
    for (int course : v2[i]) {
        if (!dfs(v2, flags, course))
            return false;
    }
    flags[i] = -1;
    return true;
}

int main()
{
    int n;
    scanf("%d,", &n);
    vector<vector<int>> prere;
    int a, b;
    while (scanf("%d,%d,", &a, &b) != EOF) {
        prere.push_back({ a, b });
    }

    vector<int> flags(n, 0);
    vector<vector<int>> v2(n);
    for (vector<int> pre : prere) {
        v2[pre[0]].push_back(pre[1]);
    }

    for (int i = 0; i < n; i++) {
        if (!dfs(v2, flags, i)) {
            printf("0\n");
            return 0;
        }
    }
    printf("1\n");
    return 0;

    system("pause");
    return 0;
}