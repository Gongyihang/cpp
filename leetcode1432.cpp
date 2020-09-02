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
        if(num >= 0 && num <= 9) return 8;
        //找第一个不为9的数字，将其替换为9
        string s = to_string(num);
        string sm = s;
        int i = 0;
        while(s[i] == '9') i++;
        if(s[i] != '9' && i < (int)sm.size()){
            char ch = s[i];
            s[i++] = '9';
            for(int k = i;k < (int)s.size(); k++) s[k] = s[k] == ch ? '9' : s[k];
        } 
        //首位如果不为1，则将其换成1
        i = 0;
        if(sm[0] != '1'){ 
            char ch = sm[0];
            sm[0] = '1';
            for(int k = 1;k < (int)sm.size(); k++) sm[k] = sm[k] == ch ? '1' : sm[k];
        }
        //首位如果为1，则将后面不为0且不为1(很重要)的数字换成0
        else{
            i++;
            while(sm[i] == '0' || sm[i] == '1') i++;
            if(i < (int)sm.size()){
            char ch = sm[i];
            sm[i] = '0';
            for(int k = i;k < (int)sm.size(); k++) sm[k] = sm[k] == ch ? '0' : sm[k];
            }
        }

        return stoi(s) - stoi(sm);
    }
};

int main(){
    Solution s;
    int res = s.maxDiff(111);
    cout << res << endl;
    system("pause");
    return 0;
}