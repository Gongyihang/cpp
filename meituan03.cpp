#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;



struct thing{
    int y = 0;
    int b = 0;
    int index = 0;
};

bool cmp(thing a,thing b){
    if(a.b == b.b && a.y == b.y) return a.index < b.index;
    else if(a.b == b.b) return a.y > b.y;
    else return a.b > b.b;
}

int main(){
    int n;
    cin >> n;
    vector<thing> v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i].y >> v[i].b;
        v[i].index = i + 1;
    }

    sort(v.begin(),v.end(),cmp);

    for(int i = 0;i < (int)v.size();i++){
        cout << v[i].index << " ";
    }
    return 0;
}