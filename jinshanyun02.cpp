#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

void f(vector<int> a,int i){
    for(int j = 1;j <= i;j++){
        cout << a[j] << ' ';
    }
    for(int j = i - 1;j >= 1 ;j--){
        cout << a[j] << ' ';
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a;
    a.push_back(0);
    a.push_back(1);
    int pre1 = 0, pre2 = 1, output = 0;
    for(int i = 2;i <= n;i++){
        output = pre1 + pre2;
        pre1 = pre2;
        pre2 = output;
        a.push_back(output);
    }
    for(int i = 1;i <= n;i++){
        f(a,i);
        cout << endl;
    }
    return 0;
}