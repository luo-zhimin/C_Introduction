#include <stdio.h>
#include <math.h>
//进制转化
void main(){

    /*
         1) 二进制：0,1 ，满 2 进 1，C 语言中没有二进制常数的表示方法。
         2) 十进制：0-9 ，满 10 进 1。
         3) 八进制：0-7 ，满 8 进 1. 以数字 0 开头表示。
         4) 十六进制：0-9 及 A-F，满 16 进 1. 以 0x 或 0X 开头表示
     */

    //first group 其他进制 转化10进制
    //从左到右依次 减少
    int binary = 1011;
    int eight = 0123;
    int sixteen = 0x34a;
    //binary transform to ten
    int ten = 1* pow(2,0)+1* pow(2,1)+0* pow(2,2)+1* pow(2,3);
    printf("binary transform to ten %d\n",ten);
    //eight transform to ten
    ten = 3* pow(8,0)+2* pow(8,1)+1* pow(8,2)+0* pow(8,3);
    printf("eight transform to ten %d\n",ten);
    //sixteen
    ten = 10* pow(16,0)+4* pow(16,1)+3* pow(16,2);//10+64+256*3
    printf("sixteen transform to ten %d", ten);

    //十进制 转化其他进制 除以对应的进制 取余数倒过来

    //二进制 转化 其他进制
    //二进制转化八进制 低位开始 3个一组
    //二进制转化十六进制 低位开始 4个一组

    //其他进制转化二进制
    //八进制 将每一位转化成一个3位的二进制
    //十六进制 将每一位转化成一个4位的二进制

    int a = 0123;//8进制
    int a1 = 001010011;

    int b = 0x23b;
    int b1 = 001000111011;

    //位运算

    /*
        原码、反码、补码
        1) 二进制的最高位是符号位: 0 表示正数,1 表示负数
        2) 正数的原码，反码，补码都一样 (三码合一)
        3) 负数的反码=它的原码符号位不变，其它位取反(0->1,1->0)
        4) 负数的补码=它的反码+1
        5) 0 的反码，补码都是 0
        6) 在计算机运算的时候，都是以补码的方式来运算的

        1) 按位与& ： 两位全为１，结果为 1，否则为 0
        2) 按位或| : 两位有一个为 1，结果为 1，否则为 0
        3) 按位异或 ^ : 两位一个为 0,一个为 1，结果为 1，否则为 0
        4) 按位取反 ~ : 0->1 ,1->0
     */

    int c = 1<<2;//4 0000 0001 ==> 0000 0100
    //源码 1000 0000 0000 0000 0000 0000 0000 0001
    //反码 1111 1111 1111 1111 1111 1111 1111 1110
    //补码 1111 1111 1111 1111 1111 1111 1111 1111

    // << 2
    //源码 1000 0000 0000 0000 0000 0000 0000 0100
    int d = -1<<2;

    int f = -1>>2;
    printf("\nc=%d d=%d",c,d);

    //todo need exercise
}