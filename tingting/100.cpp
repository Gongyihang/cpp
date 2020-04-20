#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

// bool isPrime(int num){
//     for(int i = 2;i < num;i++){
//         if(num % i == 0){
//             return false;
//         }
//     }
//     return true;
// }

// int main(){
//     int count = 1;
//     for(int i = 2;i < 100;i++){
//         if (i % 2 == 0)
//         {
//             for(int j = 2;j < i;j++){
//                 int k = i - j;
//                 if(isPrime(k) && isPrime(j)){
//                     printf("%d = %d + %d   ",i,j,k);
//                     count++;
//                     if(count % 5 == 0){
//                         printf("\n");
//                     }
//                     break;
//                 }
//             }
//         }
//     }
//     system("pause");
//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main(){
    int n = 10;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n-i;j++){
            printf(" ");
        }
        for(int k = 1;k <= 2 * i - 1; k++){
            printf("*");
        }
        printf("\n");
    }
    system("pause");
    return 0;
}


// #include <stdio.h>

// int main()
// {
//     int k;
//     int i, j;
//     for (i = 6; i <= 100; i++) {
//         int count = 0; //为了5个一行
//         int flag = 0; //判断可以输出
//         if (i % 2 == 0) {
//             for (j = 2; j < i; j++) {
//                 // m = i j;
//                 k = i - j;
//                 for (int w = 2; w < j; w++) {
//                     if (j % w == 0) { //他不是素数
//                         flag = 0;
//                         break;

//                     } else {

//                         for (int s = 2; s < k; s++) {
//                             if ((k % s) == 0) {  
//                                 flag = 0;
//                                 break;
//                             }
//                              else {
//                                  if (k != 1) {
//                                     flag = 1;
//                                 }
//                                 else
//                                 {
//                                     flag =0;
//                                 }
                                
//                              }
//                         }
//                     }
//                 }
//             }

//             if (flag == 1) {

//                 count++;
//                 printf("%d=%d+%d   ", i, j, i - j);
//                 if (count == 5) {
//                     printf("\n");
//                 }
//             }
//         }

//     }
//     return 0;
// }


// #include <algorithm>
// #include <iostream>
// #include <math.h>
// #include <string>
// #include <vector>
// using namespace std;

// int main()
// {
//     int n = 0;
//     scanf("%d", &n);
//     for (int i = 1; i <= n; i++) {
//         for (int j = n - i; j >= 0; j--) {
//             printf(" ");
//         }
//         for (int k = 1; k <= i; k++) {
//             printf("*");
//         }
//         for (int k = 1; k < i; k++) {
//             printf("*");
//         }
//         printf("\n");
//     }
//     system("pause");
//     return 0;
// }

// /*一个球从100米高度自由落下，每次落地后反跳回高度的一半；再落下，...。求它在第10次落地时，共经过多少米？第10次反弹多高？*/
// #include <stdio.h>
// int main()
// {
//     int a = 100;
//     int count = 1;
//     double sum = a, i = a;
//     double h = 0;
//     while (i) {
//         i = i / 2.0;
//         sum += i * 2.0;
//         count++;
//         if (count == 10) {
//             h = i / 2;
//             break;
//         }
//     }
//     printf("在第十次落地时，它经历%f米，反弹%f米", sum, h);
//     return 0;
// }
// #include<stdio.h>
// #define H 100
// int main()
// {
// 	int i, n;
// 	float s, h;
// 	s = H;		//记录经过距离.
// 	h = H / 2;	//记录第一次反弹的高度
// 	scanf("%d", &n);
// 	for(i=1;i < n;i++){//从第二次落地开始循环
// 		s += 2*h;
// 		h /= 2;
// 	}
// 	printf("第%d次落地时共经过%f米\n，第%d次反弹高度为：h=%f米\n",n, s, n, h);
// }
