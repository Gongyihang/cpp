#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

void quick_sort(vector<int> &arr, int left, int right)
{
    if (left >= right || left < 0 || right > arr.size() - 1)
        return;
    int index = arr[left];                          //每次都以区间内的第一个数为标准，找到它在整个数组中的正确位置
    while (left < right) {
        while (left < right && index <= arr[right]) //从右到左
            right--;
        if (left == right)
            break;
        arr[left] = arr[right];
        while (left < right && index >= arr[left]) //从左到右
            left++;
        if (left == right)
            break;
        arr[right] = arr[left];
    }
    arr[left] = index;
    quick_sort(arr, left, left - 1);
    quick_sort(arr, left + 1, right);
}
vector<int> getLeastNumbers(vector<int>& arr, int k)
{
    if (arr.size() == 0)
        return arr;
    vector<int> res;
    if (k == 0)
        return res;
    quick_sort(arr, 0, arr.size() - 1);
    res.assign(arr.begin(), arr.begin() + k);
    return res;
}

int main()
{
    vector<int> v(20, 0);
    for (int i = 0; i < (int)v.size(); i++) {
        v[i] = i;
    }
    // quick_sort(v,0,(int)v.size());
    vector<int> res;
    res = getLeastNumbers(v,10);
    for(int i = 0;i < (int)res.size();i++){
        cout << res[i] << endl;
    }

    system("pause");
    return 0;
}