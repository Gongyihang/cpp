#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
//一航代码
class Solution {
public:
    string validIPAddress(string IP)
    {
        string s = IP;
        vector<string> v;
        string t = "";
        int i;
        for (i = 0; i < (int)s.size(); i++) {
            if (s[i] != '.' && s[i] != ':') {
                t += s[i];
            } else if (s[i] == '.' || s[i] == ':') {
                v.push_back(t);
                t = "";
            }
        }
        v.push_back(t);
        if (v.size() == 4) {
            for (string st : v) {
                if (st == "0")
                    continue;
                if ((int)st.size() == 0 || (int)st.size() > 3)
                    return "Neither";
                if (st[0] == '0' && st != "0")
                    return "Neither";
                for (auto c : st)
                    if (isdigit(c))
                        continue;
                    else
                        return "Neither";
                int num = stoi(st);
                if (num < 1 || num > 255)
                    return "Neither";
            }
            return "IPv4";
        } else if (v.size() == 8) {
            for (string st : v) {
                if ((int)st.size() == 0 || (int)st.size() > 4)
                    return "Neither";
                for (auto c : st) {
                    if (!(isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))) {
                        return "Neither";
                    }
                }
            }
            return "IPv6";
        }
        return "Neither";
    }
};

int main()
{
    Solution s;
    cout << s.validIPAddress("172.16.254.1") << endl;
    cout << s.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334") << endl;
    cout << s.validIPAddress("256.256.256.256") << endl;
    cout << s.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334:") << endl;
    cout << s.validIPAddress("1e1.4.5.6") << endl;
    system("pause");
    return 0;
}
