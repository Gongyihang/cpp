#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    string r;
    cin >> s >> r;
    int res = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == r[i]) {
            res += 20;
        } else {
            if (res != 0)
                res -= 10;
        }
    }
    cout << res;
    return 0;
}