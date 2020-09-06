#include <bits/stdc++.h>
using namespace std;

struct huowu {
    stack<int> s;
    int value;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<huowu> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].value;
    }
    stack<int> sl;
    stack<int> sr;
    vector<int> res(m, 0);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            string shou, move;
            int num;
            cin >> shou >> move;
            //被这个keep的输入害惨了啊！！！结束了才想起来这里要判断一下，num不能上面的cin后面。
            if (move != "keep") {
                cin >> num;
            }
            if (shou == "left" && move == "take") {
                if (v[num].s.empty()) {
                    sl.push(v[num].value);
                } else {
                    sl.push(v[num].s.top());
                    v[num].s.pop();
                }
            }
            if (shou == "left" && move == "keep") {
                res[i] += sl.top();
                sl.pop();
            }
            if (shou == "left" && move == "return") {
                int re = sl.top();
                sl.pop();
                v[num].s.push(re);
            }
            if (shou == "right" && move == "take") {
                if (v[num].s.empty()) {
                    sr.push(v[num].value);
                } else {
                    sr.push(v[num].s.top());
                    v[num].s.pop();
                }
            }
            if (shou == "right" && move == "keep") {
                res[i] += sr.top();
                sr.pop();
            }
            if (shou == "right" && move == "return") {
                int re = sr.top();
                sr.pop();
                v[num].s.push(re);
            }
        }
        while (!sl.empty()) {
            res[i] += sl.top();
            sl.pop();
        }
        while (!sr.empty()) {
            res[i] += sr.top();
            sr.pop();
        }
    }
    for (int i = 0; i < m; i++) {
        cout << res[i] << endl;
    }
    return 0;
}

/*
5 3
1 2 3 4 5
5
left take 1
right take 2
left return 3
right keep
right take 4
6
left take 5
right take 1
left return 2
right return 3
left take 5
left return 4
10
left take 1
left keep
left take 2
left keep
left take 3
left keep
left take 4
left keep
left take 5
left keep
*/