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
    vector<string> data;
    string temp;
    while (getline(cin,temp,','))
    {
        data.push_back(temp);
    }
    vector<int> v(data.size(),0);
    for(int i = 0;i < (int)data.size();i++){
        v[i] = stoi(data[i]);
    }

    int x = v[0];
    int y = v[1];
    int n = v[2];
    if(n == 0) return 0;

    int m = 999999999;
    int index = 0;
    for(int i = 3, j = 4 ;i < (int)v.size(), j < (int)v.size();i++, j++){
        int t = (v[i] - x)*(v[i] - x) + (v[j] - y)*(v[j] - y);
        if(t < m){
            m = t;
            index = i;
        }
    }
    if(index != 0) cout << v[index] << "," << v[index+1]<<endl;
    return 0;
}