#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

struct child {
    int color = 0;
    int num = 0;
    int index;
};

bool cmp(child a, child b)
{
    return a.num > b.num;
}

bool cmp1(child a,child b){
    return a.index < b.index;
}

int main()
{
    int n;
    cin >> n;
    vector<child> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].num >> v[i].color;
        v[i].index = i;
    }

    vector<child> v1;
    vector<child> v2;


    for (int i = 1; i <= n; i++) {
        if (v[i].color == 1) {
            v1.push_back(v[i]);
        }
        if (v[i].color == 2) {
            v2.push_back(v[i]);
        }
    }

    if (v1.size() < 3 && v2.size() < 3) {
        cout << "null" << endl;
        return 0;
    }
    sort(v1.begin(), v1.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);
    
    sort(v1.begin(), v1.begin()+3, cmp1);
    sort(v2.begin(), v2.begin()+3, cmp1);
    if (v1.size() < 3 && v2.size() >= 3) {
        int sum2 = v2[0].num + v2[1].num + v2[2].num;
        cout << v2[0].index << " "<< v2[1].index << " "<< v2[2].index << endl;
        cout << v2[0].color<<endl;
        cout << sum2 <<endl;
    } else if (v1.size() >= 3 && v2.size() < 3) {
        int sum1 = v1[0].num + v1[1].num + v1[2].num;
        cout << v1[0].index << " "<< v1[1].index << " "<< v1[2].index << endl;
        cout << v1[0].color<<endl;
        cout << sum1 <<endl;
    } else if (v1.size() >= 3 && v2.size() >= 3) {
        int sum1 = v1[0].num + v1[1].num + v1[2].num;
        int sum2 = v2[0].num + v2[1].num + v2[2].num;
        if (sum1 > sum2) {
            cout << v1[0].index << " "<< v1[1].index << " "<< v1[2].index << endl;
            cout << v1[0].color<<endl;
            cout << sum1 <<endl;
        } else {
            cout << v2[0].index << " "<<v2[1].index <<" "<< v2[2].index << endl;
            cout << v2[0].color<<endl;
            cout << sum2 <<endl;
        }
    }
    return 0;
}