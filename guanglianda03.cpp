#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int v[100001];
stack<int> s;

int main()
{
    int n;
    while (cin >> n) {
        int minn = 0;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            if (!s.empty() && s.top() > v[i]) {
                minn = max(minn, v[i]);
            } else {
                s.push(v[i]);
            }
        }
        if (minn == 0) {
            cout << 0 << endl;
            continue;
        }
        int res = 1;
        for (int i = 1; i <= n; i++) {
            if (v[i] < minn) {
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}