#include <stdio.h>
int main()
{
    int i, n, a[1001], A1, A2, A3, count;
    scanf("%d", &n);
    A1 = A2 = A3 = count = 0;
    int t = 0;
    double A4 = 0;
    int flag = 1, A5 = 0;
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] % 5 == 0 && a[i] % 2 == 0)
            A1 += a[i];

        if (a[i] % 5 == 1) {
            A2 += a[i] * flag;
            flag = flag * -1;
            t++;
        }

        if (a[i] % 5 == 2)
            A3++;

        if (a[i] % 5 == 3) {
            A4 += a[i]; //后面要除以个数count
            count++;
        }

        if (a[i] % 5 == 4) {
            if (a[i] > A5)
                A5 = a[i];
        }
    }

    if (A1 == 0)
        printf("N ");
    else
        printf("%d ", A1);
    if (t == 0)
        printf("N ");
    else
        printf("%d ", A2);
    if (A3 == 0)
        printf("N ");
    else
        printf("%d ", A3);
    if (A4 == 0)
        printf("N ");
    else
        printf("%.1lf ", A4 / (count * 1.0));
    if (A5 == 0)
        printf("N");
    else
        printf("%d", A5);

    return 0;
}