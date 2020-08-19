#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
//small K
class Solution1 {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        quick_sort(arr,0,arr.size()-1,k);
        return vector<int>(arr.begin(),arr.begin()+k);
    }
    void quick_sort(vector<int>& arr, int l,int h, int k){
        if(l >= h) return ;
        int i = l - 1, j = h + 1, x = arr[(l + h) >> 1];
        while(i < j){
            do i++;while(arr[i] < x);
            do j--;while(arr[j] > x);
            if(i < j) swap(arr[i], arr[j]);
        }
        if(j - l + 1 >= k)
            quick_sort(arr, l, j, k);
        else
            quick_sort(arr, j + 1, h, k - (j - l + 1));
    }
};
//large K
class Solution2 {
public:
    vector<int> largestestK(vector<int>& arr, int k) {
        quick_sort(arr,0,arr.size()-1,k);
        return vector<int>(arr.begin(),arr.begin() + k);
    }
    void quick_sort(vector<int>& arr, int l,int h, int k){
        if(l >= h) return ;
        int i = l - 1, j = h + 1, x = arr[(l + h) >> 1];
        while(i < j){
            do i++;while(arr[i] > x);
            do j--;while(arr[j] < x);
            if(i < j) swap(arr[i], arr[j]);
        }
        if(j - l + 1 >= k)
            quick_sort(arr, l, j, k);
        else
            quick_sort(arr, j + 1, h, k - (j - l + 1));
    }
};

class Solution{
    public:
        vector<int> smallK(vector<int>& arr, int k){
            quick_sort(arr, 0, arr.size() - 1, k);
            return vector<int>(arr.begin(),arr.begin() + k);
        }

        void quick_sort(vector<int>& arr, int l, int h, int k){
            if( l >= h) return ;
            int i = l - 1, j = h + 1, x = arr[(l + h) >> 1];
            while(i < j){
                do i++; while(arr[i] < x);
                do j--; while(arr[j] > x);
                if(i < j){
                    swap(arr[i], arr[j]);
                }
            }
            if(j - l + 1 <= k){
                quick_sort(arr, l, j, k);
            }else
            {
                quick_sort(arr, j + 1, h, k - (j - l + 1));
            }
            
        }
};


class Solution3{
    public:
    void quick_sort(vector<int>& arr, int l, int h){
        if(l >= h) return ;
        int i = l - 1, j = h + 1, x = arr[(l + h) >> 1];
        while(i < j){
            do i++; while(arr[i] < x);
            do j--; while(arr[j] > x);
            if(i < j){
                swap(arr[i], arr[j]);
            }
        }
        quick_sort(arr, l, j);
        quick_sort(arr, j + 1, h);
    }
};


int main(){
    vector<int> arr = {40, 8, 7, 20, 5, 6, 7, 8, 9, 1};
    vector<int> res;
    Solution3 s2;
    s2.quick_sort(arr, 0, arr.size() - 1);
    for(int i = 0;i < (int)arr.size();i++){
        cout << arr[i] << endl;
    }
    system("pause");
    return 0;
}

