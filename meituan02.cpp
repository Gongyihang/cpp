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
    int n, k, d;
    cin >> n >> k >> d;
    int len = n - d + 1;
    int res = 0;
    // for(int i = d;i <= k;i++){
    //     res = res + n - i + 1;
    // }

    
    // int num = n;
    for (int i = 2; i < len; i++) {
        vector<int> eq;
        int flag = 0;
        for (int j = i; j >= 0; j--) {
            int x = 1;
            while(x <= k){
                if (x >= d && !flag)
                    flag = 1;
                eq.push_back(x);
            }
        }
        int sum = 0;
        for (int y = 0; y < len; y++) {
            sum += eq[y];
        }
        if (sum == n && flag)
            res++;
    }

    cout << res << endl;

    return 0;
}




