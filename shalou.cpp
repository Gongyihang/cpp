// #include <iostream>
// using namespace std;
// /*
//     思路：①计算沙漏的行数 ②打印沙漏
// */
// int main()
// {
//     int N;
//     char x;
//     cin >> N >> x;

//     int w = -1, j;
//     int sum = -1;
//     for (int i = 1; sum <= N; i += 2) {
//         w++;
//         j = i - 2;
//         sum += (2 * i);
//     }
//     //for中的sum多执行了一次
//     int res = N - (sum + 2 * (j + 2));
//     int t = 0;
//     //w是上部分的行数，全部打印时须乘以 2 再减 1，j是最大奇数
//     for (int m = 1; m <= w * 2 - 1; m++, j -= 2) {
//         if (j >= 1) {
//             t++;
//         } else {
//             t--;
//             if (j == -1)
//                 j -= 2;
//         }
//         for (int k = 1; k <= t - 1; k++) {
//             cout << ' ';
//         }
//         for (int k = 1; k <= abs(j); k++) {
//             cout << x;
//         }
//         cout << endl;
//     }
//     cout << res;
//     system("pause");
//     return 0;
// }

// #include <algorithm>
// #include <cmath>
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;
// int n;
// int main()
// {
//     cin >> n;
//     for (int i = n; i >= 1; i--) {
//         for (int j = 1; j <= n - i; j++) {
//             cout << " ";
//         }
//         for (int j = i; j >= 1; j--) {
//             cout << "* ";
//         }
//         cout << endl;
//     }
//     for (int i = 2; i <= n; i++) {
//         for (int j = n - i; j >= 1; j--) {
//             cout << " ";
//         }
//         for (int j = 1; j <= i; j++) {
//             cout << "* ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// #include <algorithm>
// #include <iostream>
// #include <cmath>
// #include <string>
// #include <vector>
// using namespace std;
// //http://39.105.108.26/problem.php?cid=1013&pid=1
// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = n; i > 0; i--) {
//         for (int j = 1; j < n - i + 1; j++) {
//             printf(" ");
//         }
//         for (int k = i; k > 0; k--) {
//             printf("* ");
//         }
//         cout << endl;
//     }

//     for (int i = 2; i <= n; i++) {
//         for (int j = n - i; j > 0; j--) {
//             printf(" ");
//         }
//         for (int k = 1; k <= i; k++) {
//             printf("* ");
//         }
//         cout << endl;
//     }
//     return 0;
// }