#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    int d;
    cin >> s >> d;
    string res;
    int qu, re = 0; //qu为商、re为余数
    bool flag = false; //商是否出现非0位，是为true,商一直为0，则一直为false，一直continue
    for (int i = 0; i < (int)s.size(); i++) {
        re = re * 10 + s[i] - '0'; //核心
        qu = re / d;
        re = re % d;
        if ((qu == 0) && !flag) {
            continue;
        }
        res += to_string(qu);
        flag = true;
    }
    if (!flag) { //商为0的情况
        cout << "0 " << re;
    } else {
        cout << res << " " << re << endl;
    }
    system("pause");
    return 0;
}

// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     string A;
//     int B, Q[1000], R, i = 0, j = 0;
//     cin >> A >> B;
//     for (int k = 0; k < A.length(); k++)
//         if (A[k] - '0' != 0) //找到不为前导0的数字的位置
//         {
//             i = k;
//             break;
//         }
//     R = A[i] - '0';
//     if (R < B && i == A.length() - 1) //如果该数字小于除数且A表示一位数
//     {
//         cout << "0 " << R;
//         return 0;
//     }
//     while (R < B)
//         R = R * 10 + (A[++i] - '0'); //余数不断增加末位直到不小于除数
//     Q[j++] = R / B;                  //存商
//     R %= B;                          //存余
//     while (++i < A.length())         //如果没到串末尾
//     {
//         R = R * 10 + (A[i] - '0'); //余数不断增加末位
//         Q[j++] = R / B;
//         R %= B;
//     }
//     for (i = 0; i < j; i++)
//         cout << Q[i];
//     cout << ' ' << R;
//     system("pause");
//     return 0;
// }

// #include <algorithm>
// #include <iostream>
// #include <math.h>
// #include <string>
// #include <vector>
// using namespace std;

// int main()
// {
//     string s;
//     int d, div, mod;
//     cin >> s >> d;
//     div = (s[0] - '0') / d;
//     mod = (s[0] - '0') % d;
//     if (div != 0 || (int)s.size() == 1) {
//         cout << div;
//     }
//     for (int i = 1; i < (int)s.size(); i++) {
//         div = (mod * 10 + (s[i] - '0')) / d;
//         cout << div;
//         mod = (mod * 10 + (s[i] - '0')) % d;
//     }
//     cout << ' ' << mod << endl;
//     system("pause");
//     return 0;
// }

// #include <iostream>
// #include <string>

// using namespace std;

// int main()
// {
//     string a;
//     int b;
//     cin >> a >> b;
//     int temp = 0;
//     bool flag = false; //是否输出过非零位
//     for (int i = 0; i < a.length(); i++) {
//         temp = temp * 10 + a[i] - '0';
//         int x = temp / b;
//         temp %= b;
//         //如果首位为0就跳过（防止出现前导零）
//         if (!flag && x == 0)
//             continue;
//         cout << x; //输出商的这一位
//         flag = true; //已经输出过非零位了，置为true，以后出现0就可以输出了
//     }
//     if (!flag)
//         cout << "0"; //商为0的情况
//     cout << " " << temp << endl; //输出余数
//     return 0;
// }
