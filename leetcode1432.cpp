#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        if(num >= 0 && num <= 9)  return 9;
        string init = to_string(num);
        string nmin = init;
        string nmax = init;
        int length = init.size();
        char t = init[0];
        for(int i = 0; i < length;i++){
            if(init[i] != '9') {
                t = init[i];
            }
            if(i < length - 1 && nmax[i + 1] == t){
                nmax[i + 1] = '9';
            }
            if(nmin[i] == init[0]){
                nmin[i] = '1';
            }
        }
        stringstream ss1,ss2;
        int resmax,resmin;
        ss1 << nmax;
        ss1 >> resmax;
        ss2 << nmin;
        ss2 >> resmin;
        return resmax - resmin;
    }
};

int main(){
    Solution s;
    int res = s.maxDiff(9288);
    cout << res << endl;
    system("pause");
    return 0;
}