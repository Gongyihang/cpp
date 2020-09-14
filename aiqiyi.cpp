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
    string s;
    cin >> s;
    map<char,int> m;
    for(int i = 0;i < (int)s.size();i++){
        m.insert({s[i],1});
    }
    for(auto c : m){
        if(c.second != 0) cout << c.first;
    }
    system("pause");
    return 0;
}