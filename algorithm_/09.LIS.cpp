#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

//使用lower_bound
class Solution {
public:
    /**
     * return the longest increasing subsequence
     * @param arr int整型vector the array
     * @return int整型vector
     */
    vector<int> LIS(vector<int>& arr)
    {
        // write code here
        // 第一步：利用贪心+二分求最长递增子序列长度
        vector<int> res;
        vector<int> maxLen;
        if (arr.size() < 1)
            return res;
        res.push_back(arr[0]); 
        maxLen.push_back(1);
        for (int i = 1; i < (int)arr.size(); ++i) {
            if (res.back() < arr[i]) {
                res.push_back(arr[i]);
                maxLen.push_back(res.size());
            } else {
                // lower_bound(begin, end, val)包含在<algorithm>中
                // 它的作用是返回有序数组begin..end中第一个大于等于val的元素的迭代器
                int pos = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
                res[pos] = arr[i];
                maxLen.push_back(pos + 1);
            }
        }
        /*递减子序列
        for (int i = 1; i < arrLen; ++i) {
            if (seq[seqLen - 1] > arr[i])
                seq[++seqLen - 1] = arr[i];
            else {
                int index = upper_bound(seq, seq + seqLen, arr[i], greater<int>()) - seq;
                seq[index] = arr[i];
            }
        }
        */
        // 第二步：填充最长递增子序列
        for (int i = arr.size() - 1, j = res.size(); j > 0; i--) {
            if (maxLen[i] == j) {
                res[--j] = arr[i];
            }
        }
        return res;
    }
};
//不使用lower_bound
class Solution1 {
public:
    vector<int> LIS(vector<int>& arr)
    {
        // write code here
        // 第一步：利用贪心+二分求最长递增子序列长度
        vector<int> res;
        vector<int> maxLen;
        if (arr.size() < 1)
            return res;
        res.push_back(arr[0]); // 注：emplace_back(val)作用同push_back，效率更高
        maxLen.push_back(1);

        for (int i = 1; i < (int)arr.size(); i++) {
            if (res.back() < arr[i]) {
                res.push_back(arr[i]);
                maxLen.push_back(res.size());
            } else {
                int left = 0, right = res.size();
                while (left <= right) {
                    int mid = (left + right) >> 1;
                    if (res[mid] >= arr[i]) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                res[left] = arr[i];
                maxLen.push_back(left + 1);
            }
        }

        //因为返回的数组要求是字典序，所以从后向前遍历
        for (int i = arr.size() - 1, j = res.size(); j > 0; i--) {
            if (maxLen[i] == j) {
                res[--j] = arr[i];
            }
        }
        return res;
    }
};

int main()
{
    vector<int> arr = { 10, 9, 2, 5, 3, 7, 101, 18 };
    Solution s;
    Solution1 s;
    vector<int> res = s.LIS(arr);
    cout << res.size() << endl;
    for (auto num : res) {
        cout << num << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
