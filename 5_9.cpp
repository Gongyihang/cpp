#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int ex1(int);
    int p, m, n;
    scanf("%d %d", &m, &n);
    int a = ex1(m);
    int b = ex1(n);
    int c = ex1(m - n);
    p = a / (b * c);
    printf("%d\n", p);
    system("pause");
    return 0;
}

int ex1(int a)
{
    static int b = a;
    static int s = 1;
    if (b == 1) {
        return s;
    } else {
        s *= b;
        b--;
        return ex1(b);
    }
    
    
}