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
    int x,y;
    vector<vector<int>> p;
    while (scanf("%d,%d,",&x,&y)!= EOF)
    {
        p.push_back({x,y});
    }

    int x0 = p[0][0], x1 = p[0][1];
    int res = 0;
    for(int i = 0;i < (int)p.size();i++){
        int y0 = p[i][0], y1 = p[i][1];
        res += max(abs(x0 - y0), abs(x1 - y1));
        x0 = y0;
        x1 = y1;
    }
    cout << res;
    return 0;
}