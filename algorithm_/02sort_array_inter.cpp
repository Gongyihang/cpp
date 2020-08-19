#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

/*
int main(){
    vector<int> nums1 = {1, 3, 4, 6, 8, 9};
    vector<int> nums2 = {0, 2 ,3, 6, 9};
    vector<int> res;
    for(int i = 0, j = 0;i < (int)nums1.size() && j < (int)nums2.size();){
        if(nums1[i] == nums2[j]){
            res.push_back(nums1[i]);
            i++;j++;
        }else if(nums1[i] > nums2[j]){
            j++;
        }else if(nums1[i] < nums2[j])
        {
            i++;
        }
    }
    for(int i = 0;i < (int)res.size();i++){
        cout << res[i] << endl;
    }
    system("pause");
    return 0;
}
*/

int main()
{
    vector<int> nums1 = { 1, 3, 4, 6, 8, 9 };
    vector<int> nums2 = { 0, 2, 3, 6, 9 };
    vector<int> nums3 = { 1, 2, 5, 6, 9, 10, 11 };
    vector<int> res;

    map<int, int> m;
    for (int t : nums1) {
        m[t]++;
    }

    for (int t : nums2) {
        m[t]++;
    }
    /*
    for (int t : nums3) {
        m[t]++;
    }
    
    for(auto t : m){
        if(t.second == 3){
            res.push_back(t.first);
        }
    }
    for(auto t : res){
        cout << t << endl;
    }
    */
    for(auto t : nums3){
        if(m[t] == 2){
            res.push_back(t);
        }
    }


    for(auto t : res){
        cout << t << endl;
    }

    system("pause");
    return 0;
}