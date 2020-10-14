#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
vector<ll> v(4, 0);
bool func(ll x)
{
    ll p = 0, q = 0;
    for (auto num : v) {
        if (num - x >= 0) {
            p += num - x;
        } else {
            q += num - x;
        }
    }
    return p + 2 * q >= 0;
}

int main()
{
    while(cin >> v[0] >> v[1] >> v[2] >> v[3]){
        ll r = v[0] + v[1] + v[2] + v[3];
        ll l = 0;
        while (l < r) {
            ll m = l + (r - l) / 2;
            if (func(m)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        cout << 4 * (l - 1) << endl;
    }
    return 0;
}