// #include <algorithm>
// #include <cmath>
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// int main()
// {
//     int ex4(char*);
//     int i = 0;
//     char* p;
//     char a[6];
//     p = &a[0];

//     do {
//         scanf("%c", &a[i]);
//         i++;
//     } while (a[i] != '\n');

//     ex4(p);
//     system("pause");
//     return 0;
// }

// int ex4(char* q)
// {
//     int count = 4;
//     if (*q == '\n') {
//         return 0;
//     } else {
//         printf("%c", *(q + (count -= 1)));
//         return ex4(q);
//     }
// }

#include<stdio.h>
#include<stdlib.h>

void reverse(int n)
{
	char next;
	if (n <= 1)
	{
		next = getchar();
		printf("\n");
		putchar(next);
	}
	else
	{
		next = getchar();
		reverse(n - 1);
		putchar(next);
	}
}

int main()
{
	reverse(5);
	system("pause");
	return 0;
}
