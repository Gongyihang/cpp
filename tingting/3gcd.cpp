#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX(a, b, c) (a > b) ? (a > c ? a : c) : (b > c ? b : c)
#define MIN(a, b, c) (a < b) ? (a < c ? a : c) : (b < c ? b : c)

// 两个数的最大公约数gcd
//辗转相除法 求两个数的最大公约数
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
/*
int gcd(int a,int b){
	int temp;
	while(b > 0){
        temp = a % b;
        a = b;
        b = temp;
   }
	return a;
}
//辗转相减法
int measure(int a,int b)
{		
	while(a != b)
	{
		if(a>b)
		{
			a = a - b;
		}
		else 
		{
			b = b - a;
		}
	}
	return a;
}*/

int gcd(int a, int b, int c)
{
    int min_three = MIN(a, b, c);
    for (int i = min_three; i >= 1; i--) {
        if (a % i == 0 && b % i == 0 && c % i == 0) {
            return i;
        }
    }
    return 1;
}

int lcm(int a, int b, int c)
{
    int max_three = MAX(a, b, c);
    for (int i = max_three; i < a * b * c; i++) {
        if (i % a == 0 && i % b == 0 && i % c == 0) {
            return i;
        }
    }
    return -1;
}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int t = gcd(a, b);
    int g1 = gcd(t, c);
    printf("gcd1 = %d\n", g1);
    printf("lcm1 = %d\n", a * b * c * g1 / gcd(a, b) / gcd(a, c) / gcd(b, c));

    int g2 = gcd(a, b, c);
    int l2 = lcm(a, b, c);

    printf("gcd2 = %d\n", g2);
    printf("lcm2 = %d\n", l2);

    system("pause");
    return 0;
}