#include <stdio.h>

//金字塔
void pyramid(int level) {
    for (int i = 1; i <= level; ++i) {

        for (int k = 0; k < level - i; ++k) {
            //控制空格
            printf("\t");
        }

        for (int j = 1; j <= 2 * i - 1; ++j) {
            if (j == 1 || i == level || j == 2 * i - 1) {
                printf("*\t");
            } else {
                printf("\t");
            }
        }
        printf("\n");
    }
}

//乘法表
void table(int number) {
    for (int i = 1; i <= number; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf(" %d * %d = %d\t", i, j, (i * j));
        }
        printf("\n");
    }
}

//实现求两个 double 数字的最大值
double maxDoubleValue(double a, double b) {
    return a > b ? a : b;
}

//求出三个 int 类型数的和
int sum(int a, int b, int c) {
    return a + b + c;
}

void main() {
    //1.函数可以没有返回值案例，编写一个函数,从终端输入一个整数打印出对应的金子塔
    int totalLevel = 0;
    printf("请输入要获取的金字塔的层数: ");
    scanf("%d", &totalLevel);
    pyramid(totalLevel);

    //2.编写一个函数,从终端输入一个整数(1—9),打印出对应的乘法表
    int number = 0;
    printf("请输入要打印出对应的乘法表个数(1—9): ");
    scanf("%d", &number);
    table(number);

    //3.定义函数，实现求两个 double 数字的最大值，并返回
    double max = maxDoubleValue(1.0, 2.0);
    printf("maxDouble=%.2f\n", max);
    //4.定义函数，求出三个 int 类型数的和，并返回
    int sumValue = sum(1, 2, 3);
    printf("sum=%d\n", sumValue);

    //数组时候完成
    //5.编写函数,对给定的一个二维数组(3×3)转置
    //6.定义函数，求出一个 int 类型数组中的最大值的索引
    //7.定义函数，可以接受一个 double 类型数组，使用冒泡法对其排序
}
