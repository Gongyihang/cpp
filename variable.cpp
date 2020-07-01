#include <iostream>

double length = 2.2, width = 3.3, height = 2.1;//全局变量长方体1

int main()
{
    double length = 2, width = 3, height = 4;//局部变量2长方体2
    /*函数声明*/
    void computer(double length, double width, double height);
    void computer1(double length, double width, double height);
    void computer2();

    computer(length, width, height);//首先调用computer函数计算main函数中局部变量2长方体2

    //下面大括号包裹的是一个单独的作用域
    {
        double length = 10, width = 20, height = 30;//局部变量3长方体3

        computer1(length, width, height);//传入局部变量3，计算长方体3
        computer2();                    //没有传入值，默认使用main函数外面的全局变量1长方体1
    }

    //输出顺序：长方体2、长方体3、长方体1
    system("pause");
    return 0;
}

void computer(double length, double width, double height)
{
    printf("rec's length width and height is: %f,%f,%f.\n", length, width, height);
    printf("S:%f.\n", 2 * (length * width) + 2 * (length * height) + 2 * (width * height));
    printf("V:%f.\n", length * width * height);
}

void computer1(double length, double width, double height)
{
    computer(length, width, height);
}

void computer2()
{
    computer(length, width, height);
}