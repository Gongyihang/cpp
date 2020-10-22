#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param pcStr string字符串 
     * @return string字符串
     */
    string MyCompress(string s) {
        // write code here
        string cs = "";
        int k = 1;
        for(int i = 0; i < (int)s.size();i++){
            if(s[i] == s[i + 1]) k++;
            else {
                cs += s[i];
                if( k > 1) cs += to_string(k);
                k = 1;
            }
        }
        return cs;
    }
};
int main(){
    Solution s;
    string res = s.MyCompress("aAAAAAAAAAAAA");
    cout << res <<endl;
    
    system("pause");
    return 0;
}





// class Solution {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      * 
//      * @param llVal long长整型 
//      * @return long长整型
//      */
//     long long MidFactor(long long num) {
//         // write code here
//         long long res;
//         vector<long long> v;
//         for(long long i = 1; i * i <= num; i++){
//             if(num % i == 0){
//                 v.push_back(i);
//                 if(i != num / i) v.push_back(num / i);
//             }
//         }
//         sort(v.begin(),v.end());
//         return v[(long long)(v.size()) / 2];
//     }
// };
