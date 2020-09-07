#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

vector<int> soul(vector<int> &v1, vector<int> &v2, int n, int m){
    vector<int> res;
    int i = 1, j = 1;
    while(i <= n && j <= m){
        if(v1[i] > v2[j]) i++;
        else if(v1[i] < v2[j]) j++;
        else if(v1[i] == v2[j]){
            res.push_back(v1[i]);
            i++;
            j++;
        }
    }
    
    return res;
}

int main(){
    int n, m;
    cin >> n;
    vector<int> v1(n + 1);
    vector<int> v2(m + 1);
    for(int i = 1; i <= n; i++) cin >> v1[i];
    cin >> m;
    for(int i = 1; i <= m; i++) cin >> v2[i];
    
    vector<int> res = soul(v1, v2, n, m);
    
    for(int i = 0; i < res.size(); i++){
        cout << res[i]<< " ";
    }
    system("pause");
    return 0;
}