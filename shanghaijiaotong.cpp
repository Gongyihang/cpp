#define _CRT_SECURE_NO_WARNINGS
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;
const int INF = INT_MIN;
const int MAXN = 1e6 + 1;
int seq[MAXN];
int mapTable[MAXN];
int minRearElem[MAXN];
int len;
int main()
{
    int n;
    while (scanf("%d", &n) != EOF) {
        memset(mapTable, 0, sizeof(mapTable));
        int x;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            mapTable[x] = i;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            seq[i] = mapTable[x];
        }
        len = 0;
        minRearElem[len] = INF;
        for (int i = 1; i <= n; i++) {
            if (seq[i] >= minRearElem[len]) {
                len++;
                minRearElem[len] = seq[i];
            } else {
                int low = 1, high = len;
                while (low < high) {
                    int mid = (low + high) / 2;
                    if (minRearElem[mid] > seq[i]) {
                        high = mid - 1;
                    } else if (minRearElem[mid] < seq[i]) {
                        low = mid + 1;
                    } else {
                        break;
                    }
                }
                minRearElem[low] = seq[i];
            }
        }
        printf("%d\n", len);
    }
    return 0;
}
