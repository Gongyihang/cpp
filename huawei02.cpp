#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

int fib(int N) {
    if (N == 1) return 1;
    else if(N == 2) return 2;
    else return fib(N - 1) + fib(N - 2);
}

int main(){
    int n;
    cin >> n;
    int res = fib(n);
    cout << res;
    system("pause");
    return 0;
}