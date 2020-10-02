#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
//一航代码
char* myitoa(int num)
{
    char* res = (char*)malloc(sizeof(char*) * 12); //在堆上分配内存解决函数运行完之后局部变量释放问题
    // static char* res[12]; //定义成静态变量，但是不能解决多次调用，会改变上一次变量的值的问题
    if (num == 0) {
        res[0] = '0';
        res[1] = '\0';
        return res;
    }
    int flag = 0;
    if (num < 0) {
        flag = 1;
        num = -num;
    }
    char tem[12];
    int t = num, i = 0;
    while (t > 0) {
        tem[i++] = t % 10 + '0';
        t /= 10;
    }
    if (flag) {
        tem[i++] = '-';
    }
    int j, k;
    for (j = 0, k = i - 1; j <= i - 1; j++, k--) {
        res[j] = tem[k];
    }
    res[j] = '\0';
    return res;
}

//字符串转数字，考虑正负及int溢出
//https://leetcode-cn.com/problems/string-to-integer-atoi/
int strToInt(char* str)
{
    int res = 0, flag = 1, i = 0;
    while (str[i] == ' ')
        i++;
    if (str[i] == '-')
        flag = -1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    for (; str[i] != '\0' && isdigit(str[i]); i++) { //看图理解
        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' > 7)) //若当前数字大于214748364 || 当前数字等于214748364，判断最后一位是否大于7，根据flag返回最大值/最小值。
            return flag == 1 ? INT_MAX : INT_MIN;
        res = res * 10 + (str[i] - '0');
    }
    return flag * res;
}

int main()
{
    char* p = myitoa(0);
    char* q = myitoa(-1); //如果在myitoa中将声明为static，则二次调用myitoa将改变char *p的值（会改变之前调用myitoa return的值）
    cout << p << endl;
    cout << q << endl;
    char* s = (char*)"100"; //如果定义成非const会警告ISO C++ forbids converting a string constant to 'char*，此处注意const char * 、char const *、 char * const 三者的区别
        //不使用const,使用强制类型转换。等号右边是一个不变常量，在c++中叫string literal，type是const char* 而p是一个char*指针
    int num = strToInt(s); //强制转换的结果就是我们在将右边的常量强制类型转换成一个指针，结果就是我们在修改一个const常量。
    cout << num << endl; //编译运行的结果会因编译器和操作系统共同决定，有的编译器会通过，有的会抛异常，就算过了也可能因为操作系统的敏感性而被杀掉。
    system("pause");
    return 0;
}

// #include <stdio.h>
// //反转字符串
// char *reverse(char *s)
// {
// 	char temp;
// 	char *p = s;	//p指向s的头部
// 	char *q = s;	//q指向s的尾部
// 	while(*q)
// 		++q;
// 	q--;

// 	//交换移动指针，直到p和q交叉
// 	while(q > p)
// 	{
// 		temp = *p;
// 		*p++ = *q;
// 		*q-- = temp;
// 	}
// 	return s;
// }

// /*
//  * 功能：整数转换为字符串
//  * char s[] 的作用是存储整数的每一位
//  */
// char *my_itoa(int n)
// {
// 	int i = 0,isNegative = 0;
// 	static char s[100];		 //必须为static变量，或者是全局变量
// 	if((isNegative = n) < 0) //如果是负数，先转为正数
// 	{
// 		n = -n;
// 	}
// 	do		//从各位开始变为字符，直到最高位，最后应该反转
// 	{
// 		s[i++] = n%10 + '0';
// 		n = n/10;
// 	}while(n > 0);

// 	if(isNegative < 0)	//如果是负数，补上负号
// 	{
// 		s[i++] = '-';
// 	}
// 	s[i] = '\0';	//最后加上字符串结束符
// 	return reverse(s);
// }

// int main(void)
// {
// 	int m;
// 	printf("请输入int型整数m：");
// 	scanf("%d",&m);
// 	printf("整数=%d,字符串=%s\n",m,my_itoa(m));
// 	return 0;
// }
