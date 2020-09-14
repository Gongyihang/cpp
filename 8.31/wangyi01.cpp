#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<string>> v(n);
    string s;
    char ch;
    for (int k = 0; k < n; k++) {
        while (cin >> s) {
            v[k].push_back(s);
            if(ch = getchar() == '\n') break;
        }
    }
    vector<string> res;
    int max_len = 0;
    for(int i = 1; i < n; i++){
        max_len = max(v[i-1].size(),v[i].size());
    }

    vector<int> index(n, 0);
    int k = 0;
    int i = 0, j = 0;
    while (k < max_len) {
        while (index[k] < (int)v[index[k]].size()) {
            i = 0;
            string t = "";
            while (i < n) {
                if (i == 0)
                    t += v[i][index[k]];
                else
                    t = t + "-" + v[i][index[k]];
                i++;
            }
            res.push_back(t);
            index[k]++;
            for (int x = 0; x < n; x++) {
                if (x == k) {
                    continue;
                } else {
                    index[x] = 0;
                }
            }
        }
    }

    for(auto r: res) cout << r << endl;
    system("pause");
    return 0;
}


/*
1.答：大端模式是指，数据的高字节保存在内存的低地址中，而数据的低字节保存在内存的高地址中。
小端模式则相反，数据的高字节保存在内存的高地址中，而数据的低字节保存在内存的低地址中。
2.答：利用强制类型转换即可。
譬如定义一个指针，指向int类型的低位地址。
int i = 0x1234;
char *p;
p = (char *)&i;
if(*p == 0x34){
    cout << "小端模式";
}else{
    cout << "大端模式";​
}

3.答：
例如：
父类A::virtual void show();
子类B::virtual void show();
B e;
A *p = &e;
p->show();
当执行p->show();时，首先查看父类A中的show()，发现它是虚函数，然后访问p指向的对象e，在对象中得到B类的虚函数表，在A类声明中找到show()声明的位序0，访问B类的虚函数表位置0，得到show的函数地址。
调用p->show();执行的步骤：
①判断A类中的show是否为虚函数
②若不是虚函数则找到p所指向的对象的所属的父类A，执行A::show()。若是虚函数，则执行步骤③
③访问p所指对象的虚函数表指针得到p所指向对象所在类的虚函数表
④查找A中show()在声明时的位序为x，到步骤③中得到的虚函数表中找到位序x，从而得到要执行的show的函数地址
⑤根据函数地址和A中声明的show函数类型访问地址所指向的函数​​
*/