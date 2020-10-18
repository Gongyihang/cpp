#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

struct point{
    int x;
    int y;
};

int main(){
    vector<vector<int>> m(10,vector<int>(10,0));
    point p;
    cin >> p.x >> p.y;
    int count = 0;
    for(int i = 0;i < 10;i++){
        string s;
        cin >> s;
        for(int j = 0;j < 10;j++){
            m[i][j] = s[j] - '0';
            if(m[i][j] != 0) count++;
        }
    }

    if(count == 0)
    cout << 1 << endl;
    else cout << 2 << endl;
    return 0;
}

