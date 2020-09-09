#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int len  = s.size();
    
    bool flag = false;
    for(int i = n / 2; i > 1; i--){
        string s1 = s.substr(0,i);
        string s2 = s.substr(i,2*i - i);
        if(s1 == s2){
            cout << n - i + 1;
            flag = true;
            break;
        }
    }
    if(!flag){
        cout << n;
    }

    return 0;
}