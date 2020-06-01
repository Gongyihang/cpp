// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <cmath>
// using namespace std;

// int main(){
//     float a,b,c = 0;
//     scanf("%f %f",&a,&b);
//     float A = sin(b);
//     c = a * sin(b) * a * cos(b) / 2;
//     printf("%f\n",c);
//     system("pause");
//     return 0;
// }

// #include <algorithm>
// #include <cmath>
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// #define PI 3.14159

// int main()
// {
//     double a, c, b, alpha, e;
//     scanf("%lf %lf %lf", &a, &b, &alpha);
//     e = alpha * PI / 180;
//     c = a * a + b * b - 2 * a * b * cos(e);
//     printf("%lf", sqrt(c));
//     system("pause");
//     return 0;
// }

/*从键盘输入20个数整数，分别用气泡法和选择法对他们进行从小到大进行排队*/
/*选择排序：比如在一个长度为N的无序数组中，在第一趟遍历N个数据，找出其中最小的数值与第一个元素交换，第二趟遍历剩下的N-1个数据，
找出其中最小的数值与第二个元素交换......第N-1趟遍历剩下的2个数据，找出其中最小的数值与第N-1个元素交换，至此选择排序完成。*/

// #include <stdio.h>
// int main()
// {
//     int a[20];
//     int temp = 0;
//     for (int i = 0; i < 20; i++) {
//         scanf("%d", &a[i]);
//     }
//     for (int i = 0; i < 20; i++) {
//         for (int j = i; j < 20; j++) {
//             if (a[j] < a[i]) {
//                 temp = a[j];
//                 a[j] = a[i];
//                 a[i] = temp;
//             }
//         }
//     }
//     int count = 0;
//     for (int i = 0; i < 20; i++) {
//         printf("%3d", a[i]);
//         count++;
//         if (count % 5 == 0) {
//             printf("\n");
//         }
//     }
//     return 0;
// }
/*有一个N个元素的有序数列，输入一个数，把它插入到原有数列中相应位置，使得到的新数列仍保持有序，输出新数列*/
// #include <stdio.h>
// int main()
// {
//     int a[100];
//     // int a[10] = { 1, 2, 4, 5, 6, 7, 8 };
//     int n;
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &a[i]);
//     }
//     int b;
//     scanf("%d", &b);
//     int i = 0;
//     while (a[i] < b)
//         i++;
//     for (int j = n - 1; j >= i; j--) {
//         a[j + 1] = a[j];
//     }
//     a[i] = b;
//     for (int j = 0; j < n + 1; j++) {
//         printf("%d", a[j]);
//     }
//     return 0;
// }

// 1 2 3 4 5
// 6 7 8 9 10
// 11 12 13 14 15
// 16 17 18 19 20
// 21 22 23 24 25


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(){
    int a[100][100];
    int n, m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            scanf("%d",&a[i][j]);
        }
    }

    int averagen[100],averagem[100];
    int sumn = 0, summ = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            sumn += a[i][j];
        }
        averagen[i] = sumn / m;
        sumn = 0;
    }

    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            summ += a[j][i];
        }
        averagem[i] = summ / n;
        summ = 0;
    }

    for(int i = 0;i < n;i++){
        printf("%d ", averagen[i]);
    }
    printf("\n");
    for(int i = 0;i < m;i++){
        printf("%d ", averagem[i]);
    }
    system("pause");
    return 0;
}
// 5 5
// 100 90 80 70 60
// 90 80 70 80 80
// 80 60 70 60 60
// 100 100 100 100 100
// 90 90 80 80 70