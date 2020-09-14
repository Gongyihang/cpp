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
    int n,m;
    cin >> n >> m;

    

    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i = 0;i < n;i++){
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}