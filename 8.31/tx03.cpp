#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <map>
using namespace std;

bool cmp(string a, string b){
    int i,j;
    for(i = 0, j = 0; i < a.size(), j < b.size();){
        if(a[i] != b[j]){
            return a[i] < b[j];
        }else{
            i++;
            j++;
        }
    }
    if(i != a.size() - 1 || j != b.size() - 1) return a.size() < b.size();
}

int main(){
    int n,k;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    sort(v.begin(),v.end(),cmp);
    
    
    return 0;
}