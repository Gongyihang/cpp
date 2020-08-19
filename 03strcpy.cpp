#include <algorithm>
#include <assert.h>
#include <cmath>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

int main()
{

    system("pause");
    return 0;
}

// char* strcpy(char* dst, const char* src)
// {
//     assert(dst != NULL && src != NULL);
//     char* ret = dst;
//     while ((*dst++ = *src++) != '\0');
//     return ret;
// }

// char* strcpy(char* dst, const char* src)
// {
//     assert(dst != NULL && src != NULL);
//     char* ret = dst;
//     my_memcpy(dst, src, strlen(src) + 1);
// }

// char* my_memcpy(char* dst, const char* src, int cnt)
// {
//     assert(dst != NULL && dst != NULL);
//     char* ret = dst;

//     if (dst > src && dst <= src + cnt - 1) {//高地址到低地址
//         dst = dst + cnt - 1;
//         src = src + cnt - 1;
//         while (cnt--) {
//             *dst-- = *src--;
//         }
//     } else {                    //正常情况，从低地址开始复制
//         while (cnt--) {
//             *dst++ = *src++;
//         }
//     }
//     return ret;
// }

char* strcpy(char* dst, const char* src)
{
    assert(dst != NULL && src != NULL);
    char* ret = dst;
    ret = my_memcpy(dst, src, strlen(src) + 1);
    return ret;
}

char* my_memcpy(char* dst, const char* src, int cnt)
{
    assert(dst != NULL && src != NULL);
    char* ret = dst;
    if (dst > src && dst <= src + cnt - 1) {
        dst = dst + cnt - 1;
        src = src + cnt - 1;
        while (cnt--) {
            *dst-- = *src--;
        }
    } else {
        while (cnt--) {
            *dst++ = *src++;
        }

        return ret;
    }
}