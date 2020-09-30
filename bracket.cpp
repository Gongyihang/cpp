#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
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
    while (getline(cin, s)) { //此处使用cin无法捕获空字符而判断有效输出true，须使用getline
        if (s.empty()) {
            cout << "true" << endl;
            continue;
        } else {
            stack<char> st;
            for (char c : s) {
                if (c == '(' || c == '{' || c == '[')
                    st.push(c);
                else {
                    if (!st.empty() && ispair(st.top(), c))//
                        st.pop();
                    else
                        break;
                }
            }
            if (st.empty())
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
    }
    system("pause");
    return 0;
}