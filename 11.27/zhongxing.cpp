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
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i];
    }
    int count = 0;
    for(int i = n - 2;i >= 0 ;i--){
        if(v[i] >= v[i + 1]) continue;
        else{
            v[i] = v[i + 1];
            count++;
        }
    }
    int res = 0;
    for(int i = 0;i < n;i++){
        res += v[i];
    }

    cout << res << " " << count << endl;
    return 0;
}