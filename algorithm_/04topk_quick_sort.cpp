#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
//small K
class small_k {
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
class large_k {
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

class quicksort{
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
    int k = 4;
    vector<int> arr1 = {40, 8, 7, 20, 5, 6, 7, 8, 9, 1};
    vector<int> arr2 = {40, 8, 7, 20, 5, 6, 7, 8, 9, 1};
    vector<int> arr3 = {40, 8, 7, 20, 5, 6, 7, 8, 9, 1};
    quicksort s1;
    small_k s2;
    large_k s3;
    s1.quick_sort(arr1, 0, arr1.size() - 1);
    s2.quick_sort(arr2, 0, arr2.size() - 1, k);
    s3.quick_sort(arr3, 0, arr3.size() - 1, k);

    for(int i = 0;i < (int)arr1.size();i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    for(int i = 0;i < k;i++){
        cout << arr2[i] << " ";
    }
    cout << endl;
    for(int i = 0;i < k;i++){
        cout << arr3[i] << " ";
    }
    system("pause");
    return 0;
}

