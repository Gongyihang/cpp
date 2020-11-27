#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

struct ball{
    int loc = 0;
    int score = 0;
};

bool cmp(ball a,ball b){
    return a.score > b.score;
}

int main(){
    // int n, d;
    // cin >> n >> d;
    // vector<ball> v(n + 1);
    // for(int i = 1;i <= n;i++){
    //     cin >> v[i].loc;
    // }
    // for(int i = 1;i <= n;i++){
    //     cin >> v[i].score;
    // }

    // // vector<vector<int>> dp(41, vector<int>(n+1,0));
    // // int cur = 0;
    // // for(int i = 1;i <= n;i++){
        
    // // }
    // sort(v.begin(),v.end(),cmp);

    // cout << v[0].score << endl;

    char *m = (char *)malloc(200*sizeof(char));
    cout << sizeof(*m);
    return 0;
}