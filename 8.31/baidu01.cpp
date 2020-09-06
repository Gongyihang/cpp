#include <bits/stdc++.h>
using namespace std;

int helper(int n, int m, int t, vector<int>& v){
    int sum = 0;
    if(n == 0) return 1;
    v.push_back(t);
    if( n >= m){
        for(int i = 1; i <= m; i++){
            if(i == v[v.size()-1] || i == v[v.size()-2]) continue;
            sum += helper(n - i, m, i, v);
        }
    }else{
        sum = helper(n, n, 0, v);
    }
    return sum % 1000000007;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v;
    int res = helper(n, m, 0, v);
    /*
    int res = 0;
    if(n < 0) return -1;
    if(n <= 2) return n;
    int t1 = 1;
    int t2 = 2;
    for(int i = 3;)
    */
    cout << res << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;
    while(k--){
        int L,n;
        cin >> L >> n;
        vector<int> v(L);
        while(n--){
            int l, r;
            cin >> l >> r;
            for(int i = l; i <= r; ++i){
                v[i - 1]++;
            }
        }
        for(auto e : v) cout << e << " ";
        cout << endl;
    }
    return 0;
}