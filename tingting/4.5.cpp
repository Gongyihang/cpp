// #include <algorithm>
// #include <iostream>
// #include <math.h>
// #include <string>
// #include <vector>
// using namespace std;

// int main()
// {
//     int i, j;
//     printf("please enter your cost:\n");
//     scanf("%d", &i);
//     if (i < 50) {
//         j = i * 0.9;
//     } else if (i > 100) {
//         j = (i - 100) * 0.8 + 50 * 0.9 + 50;
//     } else {
//         j = 50 * 0.9 + (i - 50);
//     }
//     printf("you cost is: %d", j);
//     system("pause");
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
//     int N;
//     scanf("%d", &N);
//     int sum = 1;
//     int count = 1;
//     int i;
//     for (i = 3; sum <= N; i += 2) {
//         sum += 2 * i;
//         count += 2;
//     }
//     sum -= 2 * (i - 2);
//     count -= 2;
//     printf("%d %d\n", count, sum);
//     system("pause");
//     return 0;
// }
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
//http://39.105.108.26/problem.php?cid=1013&pid=1
int main()
{
    int n;
    cin >> n;
    for (int i = n; i > 0; i--) {
        for (int j = 1; j < n - i + 1; j++) {
            printf(" ");
        }
        for (int k = i; k > 0; k--) {
            printf("* ");
        }
        cout << endl;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = n - i; j > 0; j--) {
            printf(" ");
        }
        for (int k = 1; k <= i; k++) {
            printf("* ");
        }
        cout << endl;
    }
    return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <math.h>
// using namespace std;

// int main()
// {
//     int N;
//     scanf("%d", &N);
//     int sum = 0;
//     int i;
//     for (i = 1; sum <= N; i++) {
//         sum += (i * 2 - 1);
//     }
//     printf("%d %d", i, sum -= (i * 2 - 1));
//     system("pause");
//     return 0;
// }