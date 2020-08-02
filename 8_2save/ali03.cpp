#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

struct emp {
    int a = 0;
    int b = 0;
};

int main()
{
    int n;
    while (scanf("%d", &n) != EOF) {
        vector<emp> v(n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d",&v[i].a,&v[i].b);
        }
        double mx = 0;
        for (int i = 0; i <= n-1; i++) {
            for (int j = i+1; j < n; j++) {
                double x = (v[i].a + v[j].a) / 2.0;
                double y = (v[i].b + v[j].b) / 2.0;
                double mn = min(x, y);
                if (mn >= mx) {
                    mx = mn;
                }
            }
        }
        printf("%.1lf\n", mx);
    }
    system("pause");
    return 0;
}