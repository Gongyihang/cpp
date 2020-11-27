#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
//小米
using namespace std;
bool ispair(char a, char b)
{
    if (a == '(' && b == ')')
        return true;
    if (a == '{' && b == '}')
        return true;
    if (a == '[' && b == ']')
        return true;
    return false;
}

int main()
{
    string s = "";
    while (getline(cin,s)) {
        if (s.empty()) {
            cout << "true" << endl;
            continue;
        } else {
            stack<int> st;
            st.push(s[0]);
            for (int i = 1; i < (int)s.size(); i++) {
                if (!st.empty() && ispair(st.top(), s[i]))
                    st.pop();
                else
                    st.push(s[i]);
            }
            if (st.empty())
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
    }
    return 0;
}