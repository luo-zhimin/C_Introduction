#include <stdio.h>

//关系运算符号
void main(){
    //关系运算符的结果要么是真(非 0 表示, 默认使用 1)，要么是 假(0 表示)
    // 关系运算符组成的表达式，我们称为关系表达式。 a > b
    // 比较运算符 "=="(关系运算符) 不能误写成 "=" (赋值)

    int a = 8; int b = 7;
    printf("\na>b=%d", a > b); // 1
    printf("\na>=b=%d", a >= b); // 1
    printf("\na<b=%d", a < b); //0
    printf("\na<=b=%d", a <= b);//0
    printf("\na==b=%d", a == b);//0
    printf("\na!=b=%d", a != b);//1
}