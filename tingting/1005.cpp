#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> h(302, 0);

    for (int i = 0; i < n; i++) {
        int t = v[i];
        while (t != 1) {
            if (t % 2 == 0) {
                t /= 2;
                h[t] = 1;
            } else {
                t = (t * 3 + 1) / 2;
                h[t] = 1;
            }
        }
    }

    vector<int> res;

    for (int i = 0; i < n; i++) {
        if (h[v[i]] == 0) {
            res.push_back(v[i]);
        }
    }

    sort(res.begin(),res.end(),cmp);

    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i];
        if (i != (int)res.size() - 1) {
            cout << " ";
        }
    }

    system("pause");
    return 0;
}