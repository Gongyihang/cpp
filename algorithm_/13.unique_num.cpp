#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
//一航代码
int main(){
    vector<int> arr = {1,1,2,3,3,4,4,5,5};
    map<int,int> m;
    for(int n : arr){
        m[n]++;
    }
    for(auto it = m.begin(); it != m.end(); it++){
        if(it->second == 1) cout << it->first << endl;
    }

    //用异或
    int res = 0;
    for(int i = 0; i < (int)arr.size(); i++){
        res ^= arr[i];
    }
    cout << res << endl;
    system("pause");
    return 0;
}