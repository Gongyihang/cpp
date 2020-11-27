#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

string remove(string s)
{
    string t;
    int i, j;
    t.append(s, 0, 1);
    for (i = 1; i < (int)s.size(); i++) {
        for (j = 0; j < (int)t.size(); j++) {
            if (s[i] == t[j])
                break;
        }
        if (j == (int)t.size())
            t.append(s, i, 1);
    }
    return t;
}

int main()
{
    string s;
    getline(cin, s);
    string res = remove(s);

    cout << res << endl;

    return 0;
}