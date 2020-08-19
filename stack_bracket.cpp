#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>

using namespace std;
class Solution {
public:
    bool isValid (string const& s) {
        // 定义左右两边的括号序列
        string left = "([{";
        string right = ")]}";
        stack<char> stk;
        for (auto c : s) {
            // 判断每一个输入的字符是否为左括号，如果是就压栈
            if (left.find(c) != string::npos) {
                stk.push (c);
            } else {
                // 如果不是左括号，且如果发现栈为空，或者栈顶元素不是匹配的左括号的话，就返回 false
                if (stk.empty () || stk.top () != left[right.find (c)])
                    return false;
                // 如果匹配的话，就把栈顶出栈
                else
                    stk.pop ();
            }
        }
        return stk.empty();
    }
};

int main(){
    Solution s;
    string judge_s = "{]";
    if(s.isValid(judge_s)){
        cout << true << endl;
    }else
    {
        cout << false << endl; 
    }
    
    system("pause");
    return 0;
}