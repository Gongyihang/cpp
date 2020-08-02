/*有一个N个元素的有序数列，输入一个数，把它插入到原有数列中相应位置，使得到的新数列仍保持有序，输出新数列*/
#include <stdio.h>
int main()
{
    int a[8] = { 1, 2, 4, 5, 6, 7, 8 };
    int b;
    scanf("%d", &b);
    int i = 0;
    while (a[i] < b)
        i++;
    for (int j = 7; j >= i; j--) {
        a[j + 1] = a[j];
    }
    a[i] = b;
    for (int j = 0; j < 8; j++) {
        printf("%d", a[j]);
    }
    return 0;
}
//我这个代码有问题：如果加得是最后一个就没办法了