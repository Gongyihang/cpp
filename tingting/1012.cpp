/*给定一系列正整数，请按要求对数字进行分类，并输出以下 5 个数字：*/

#include <stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
    int a[1001];
    int b[4] = { 0, 0, 0, 0 };
    int j = 0;
    int sum = 0;
    int t = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < N; i++) {
        if (a[i] % 5 == 0) {
            if (a[i] % 2 == 0) {
                sum += a[i];
            }
        }
    }
    b[j++] = sum;
    sum = 0;
    for (int i = 0, m = 0; i < N; i++) {
        if (a[i] % 5 == 1) {
            t++;
            if (m % 2 == 0) {
                sum += a[i];
            } else {
                sum -= a[i];
            }
            m++;
        }
    }
    b[j++] = sum;
    sum = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] % 5 == 2) {
            sum++;
        }
    }
    b[j++] = sum;
    sum = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] % 5 == 4) {
            if (a[i] > sum) {
                sum = a[i];
            }
        }
    }
    b[j] = sum;
    sum = 0;
    double m = 0;
    bool flag = true;
    for (int i = 0; i < N; i++) {
        if (a[i] % 5 == 3) {
            m += a[i];
            sum++;
            flag = false;
        }
    }
    for (int i = 0; i < j; i++) {
        if (i != 1 && b[i] == 0)
            printf("N ");
        else if (i == 1 && !t)
            printf("N ");
        else
            printf("%d ", b[i]);
    }
    if (flag && m == 0)
        printf("N ");
    else
        printf("%0.1f ", m / sum);

    if (b[j] == 0)
        printf("N");
    else
        printf("%d", b[j]);
    return 0;
}

