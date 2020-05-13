#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(){
    float a,b,c = 0;
    scanf("%f %f",&a,&b);
    float A = sin(b);
    c = a * sin(b) * a * cos(b) / 2;
    printf("%f\n",c);
    system("pause");
    return 0;
}