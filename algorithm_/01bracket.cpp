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
                if (c == '(' || c == '{' || c == '[')       // 判断每一个输入的字符是否为左括号，如果是就压栈
                    st.push(c);
                else {
                    if (!st.empty() && ispair(st.top(), c)) //注意ispair顺序
                        st.pop();                           // 如果栈不空，且栈顶元素与当前字符匹配则括号匹配成功，出栈
                    else
                        break;                              // 否则，结束，此时栈中不空，后序判断栈非空输出false即可
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