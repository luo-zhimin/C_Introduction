#include <stdio.h>

/**
 * 类型转化 <br><br>
 * <img src="https://cdn.nlark.com/yuque/0/2022/png/27601787/1666623624782-1011aa9f-e153-47b1-a2fd-aae3cb386b21.png">
 */
void main(){

    /*
        有多种类型的数据混合运算时，系统首先自动将所有数据转换成精度最大的那种数据类型，然后再进行计算(如 int 型和 short 型运算时，先把 short 转成 int 型后再进行运算)
        若两种类型的字节数不同，转换成字节数大的类型，若两种类型的字节数相同，且一种有符号，一种无符号， 则转换成无符号类型
        在赋值运算中，赋值号两边量的数据类型不同时，赋值号右边的类型将转换为左边的类型，如果右边变量的数 据类型长度比左边长时，将丢失一部分数据，这样会降低精度，丢失的部分按四舍五入向前舍入

        强制类型转换
        将精度高的数据类型转换为精度小的数据类型。使用时要加上强制转换符 ( )，但可能造成精度降低或溢出,格 外要注意
        当进行数据的从 精度高——>精度低，就需要使用到强制转换
        强转符号只针对于最近的操作数有效，往往会使用小括号提升优先级
     */
    char c = 'a';
    int num = c;

    float f = 1.1f;
    double d = 1.00111666;//1.00111666 <=> 1.00111663
    f = d;//精读丢失

    printf("num [%d]",num);
    printf("float [%.8f]",f);//1.00111663
}