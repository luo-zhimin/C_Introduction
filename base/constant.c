#include <stdio.h>
#include <math.h>
#define PI 3.14;
const double code = 012000;
//定义
#define debug
//取消
#undef debug
//常量
int main(){
    /*
         常量是固定值，在程序执行期间不能改变。这些固定的值，又叫做字面量。
         常量可以是任何的基本数据类型，比如整数常量、浮点常量、字符常量，或字符串字面值，也有枚举常量
         常量的值在定义后不能进行修改

         整数常量可以是十进制、八进制或十六进制的常量。前缀指定基数：0x 或 0X 表示十六进制，0 表示八进制， 不带前缀则默认表示十进制。整数常量也可以带一个后缀，后缀是 U 和 L 的组合，U 表示无符号整数 （unsigned），L 表示长整数（long）。后缀可以是大写，也可以是小写，U 和 L 的顺序任意

         const 和 #define 的区别
             const 定义的常量时，带类型，define 不带类型
             const 是在 编译、运行的时候起作用，而 define 是在编译的预处理阶段起作用
             define 只是简单的替换，没有类型检查。简单的字符串替换会导致边界效应.
             const 常量可以进行调试的，define 是不能进行调试的，主要是预编译阶段就已经替换掉了，调试的时候就没它 了
             const 不能重定义，不可以定义两个一样的，而 define 通过 undef 取消某个符号的定义，再重新定义
             define 可以配合#ifdef、 #ifndef、 #endif 来使用， 可以让代码更加灵活，比如我们可以通过#define 来 启动 或者关闭 调试信息
     */

    int n1 = 0x11;//16进制 ->17
    int n2 = 0123;//8进制 -> 8^2+8^1*2+1 ->

    printf("n1 value[%d] n2 value[%d]\n",n1,n2);

    //definition constant
    //圆计算 面积
    double area;
    double r = 1.2;
    double r2 = pow(r,2);
    area = r2 * PI;
    //area = r2 * code;
    //上面有const 定义了const 不可以在被重新定义
//    code = 010000;
    printf("area %.2f \n",area);
#ifdef debug
    printf("debug");
#endif
#ifndef debug
    printf("no debug");
#endif
    return 0;
}