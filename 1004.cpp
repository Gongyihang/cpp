#include <stdio.h>
struct Student {
    char name[11];
    char studentNumber[11];
    int score;
};

int main()
{
    int n;
    scanf("%d", &n);
    struct Student a[n];
    for (int i = 0; i < n; i++) {
        scanf("%s%s%d", a[i].name, a[i].studentNumber, &a[i].score);
    }
    int max = 0;
    int min = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].score > a[max].score)
           {
               max= i;
           }
        if (a[i].score < a[min].score)
           {
                min= i;
           }
    }
    printf("%s %s\n", a[max].name, a[max].studentNumber);
    printf("%s %s\n", a[min].name, a[min].studentNumber);
    return 0;
}
