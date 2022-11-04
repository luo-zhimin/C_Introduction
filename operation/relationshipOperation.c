#include <stdio.h>

//关系运算符号 && 赋值运算符
/**
 * <img src="https://cdn.nlark.com/yuque/0/2022/png/27601787/1666883926709-8626f248-1045-4699-998c-1a001715daa8.png">
 */
void main() {
    //关系运算符的结果要么是真(非 0 表示, 默认使用 1)，要么是 假(0 表示)
    // 关系运算符组成的表达式，我们称为关系表达式。 a > b
    // 比较运算符 "=="(关系运算符) 不能误写成 "=" (赋值)

    int a = 8;
    int b = 7;
    int c = 9;
    printf("\na>b=%d", a > b); // 1
    printf("\na>=b=%d", a >= b); // 1
    printf("\na<b=%d", a < b); //0
    printf("\na<=b=%d", a <= b);//0
    printf("\na==b=%d", a == b);//0
    printf("\na!=b=%d", a != b);//1

    //赋值运算符
    //+=、-=、*= 、/=、%= <<=、>>=、&=、^=  todo 位运算 二进制 之后 做
//    int sub = a -= b;
//    int div = a /= b;
    printf("\n+= %d -= %d、*= %d、/= %d、取膜= %d", a += b, a -= b, a *= b, a /= b, a %= b);

    //三元运算符号
    //：实现两个数的最大值 (a , b ) ：实现三个数的最大值
    int num1 = 10;
    int num2 = 11;
    int num3 = 13;
    int maxTwoValue = num1 > num2 ? num1 : num2;
    printf("\nmaxTwoValue [%d]", maxTwoValue);

    //最简单的
//    int maxThreeValue = maxTwoValue > num3 ? maxTwoValue : num3;
    int maxThreeValue = (num1 > num2 ? num1 : num2) ? (num1 > num3 ? num1 : num3) : (num2 > num3 ? num2 : num3);
    printf("\nmaxThreeValue [%d]", maxThreeValue);
}