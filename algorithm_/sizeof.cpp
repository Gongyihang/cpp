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
struct A {
};
struct B {
    char ch;
    int i;
};

struct C {
    char ch1 = '1';
    char ch2 = '2';
    char ch3 = '3';
};

struct D {
    char ch1;
    B b;
    char ch2;
};

//虚函数的sizeof不在乎自己的虚函数有多少个，而在乎在继承的时候，有多少个虚函数指针

int main()
{
    int a;
    int arr[] = { 1, 2, 3 };
    int arr_[10];
    int* arrnew = new int[3] { 1, 2, 3 };
    char b;
    char str[] = "hello";
    long c;
    long long d;
    double e;
    float f;
    int* g;
    char* h;
    long* i;
    long long* j;
    double* k;
    float* l;
    int m[10];
    char n[10];
    char* o = (char*)malloc(sizeof(char*) * 10);

    cout << " 1. sizeof(a) = "
         << sizeof(a) << "          int a;" << endl
         << " 2. sizeof(arr) = "
         << sizeof(arr) << "        arr[] = {1, 2, 3};" << endl
         << " 3. sizeof(arr_) = "
         << sizeof(arr_) << "       arr_[10];" << endl
         << " 4. sizeof(arrnew) = "
         << sizeof(arrnew) << "     int *arrnew = new int[3] = {1, 2, 3};" << endl
         << " 5. sizeof(*arrnew) = "
         << sizeof(*arrnew) << "    int *arrnew = new int[3] = {1, 2, 3};" << endl //指向的是int数组的第一个元素，类型是int，所以输出为4
         << " 6. sizeof(b) = "
         << sizeof(b) << "          char b" << endl
         << " 7. sizeof(str) = "
         << sizeof(str) << "        char str[] = \"hello\"" << endl
         << " 8. sizeof(c) = "
         << sizeof(c) << "          long c" << endl
         << " 9. sizeof(d) = "
         << sizeof(d) << "          long long d" << endl
         << "10. sizeof(e) = "
         << sizeof(e) << "          double e" << endl
         << "11. sizeof(f) = "
         << sizeof(f) << "          float f" << endl
         << "12. sizeof(g) = "
         << sizeof(g) << "          int* g" << endl
         << "13. sizeof(h) = "
         << sizeof(h) << "          char* h" << endl
         << "14. sizeof(i) = "
         << sizeof(i) << "          long* i" << endl
         << "15. sizeof(j) = "
         << sizeof(j) << "          long long* j" << endl
         << "16. sizeof(k) = "
         << sizeof(k) << "          double* k" << endl
         << "17. sizeof(l) = "
         << sizeof(l) << "          float* l" << endl
         << "18. sizeof(m) = "
         << sizeof(m) << "          int m[10]" << endl
         << "19. sizeof(n) = "
         << sizeof(n) << "          char n[10]" << endl
         << "20. sizeof(o) = "
         << sizeof(o) << "          char *o = (char*)malloc(sizeof(char*) * 10)" << endl
         << "21. sizeof(A) = "
         << sizeof(A) << "          empty" << endl
         << "22. sizeof(B) = "
         << sizeof(B) << "          one char and one int" << endl
         << "23. sizeof(C) = "
         << sizeof(C) << "          three char" << endl
         << "24. sizeof(D) = "
         << sizeof(D) << "          two char and one struct" << endl;
    system("pause");
    return 0;
}