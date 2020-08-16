#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            v.push_back(i * j);
        }
    }
    sort(v.begin(), v.end());
    cout << v[k-1] << endl;
}