#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int t;
    vector<int> v;
    while (cin >> t) {
        v.push_back(t);
        if (char ch = getchar() == '\n') {
            break;
        }
        
    }

    for(int i = 0; i < (int)v.size();i++){
        cout << v[i] << endl;
    }
    system("pause");
    return 0;
}
 