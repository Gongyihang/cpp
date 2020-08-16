#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

/*
342323
第一层：
s[i] = 3 s[j] = 3
break;
*/

inline bool check(string &s, int start, int end)
{
    int i = start, j = end;
    while (i < j && s[i] == s[j])
    {
        ++i, --j;
    }
    return i >= j;
}
int main()
{
    string s;
    cin >> s;
    int length = s.size();
    int i;
    for (i = 0; i < length; ++i)
    {
        if (check(s, i, length - 1))
        {
            break;
        }
    }
    string prefix = s.substr(0, i);
    reverse(prefix.begin(), prefix.end());
    cout << s + prefix << endl;
    return 0;
}
