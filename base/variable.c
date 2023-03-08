#include <stdio.h>
#include <stdbool.h>

//变量
/**
 * <img src="https://cdn.nlark.com/yuque/0/2022/png/27601787/1666617530298-e1d6bffc-27cf-4806-9b6f-c2c381b86e03.png">
 */
void main() {
    /*
        1) 变量表示内存中的一个存储区域（不同的数据类型，占用的空间大小不一样）
        2) 该区域有自己的名称 和类型
        3) 变量必须先声明，后使用
        4) 该区域的数据可以在同一类型范围内不断变化
        5) 变量在同一个作用域内不能重名
        6) 变量三要素 (变量名+值+数据类型)

        每一种数据都定义了明确的数据类型，在内存中分配了不同大小的内存空间(使用字节多少表示)
        注意：在 c 中，没有字符串类型, 使用字符数组表示字符串
        在不同系统上，部分数据类型字节长度不一样, int 2 或者 4

        整型的使用细节
        各种类型的存储大小与操作系统、系统位数和编译器有关 ，目前通用的以 64 位系统为主
        在实际工作中，c 程序通常运行在 linux/unix 操作系统下.二级考试，使用 windows
        C 语言的整型类型，分为有符号 signed 和无符号 unsigned 两种，默认是 signed
        C 程序中整型常声明为 int 型，除非不足以表示大数，才使用 long long
        bit(位): 计算机中的最小存储单位。byte(字节):计算机中基本存储单元

        浮点型使用细节
        关于浮点数在机器中存放形式的简单说明,浮点数=符号位+指数位+尾数位 , 浮点数是近视值
        尾数部分可能丢失，造成精度损失
        浮点型常量默认为 double 型 ，声明 float 型常量时，须后加‘f’或‘F’
        通常情况下，应该使用 double 型，因为它比 float 型更精确
     */
    int number = 16;
    double score = 90.1;
    char sex = 'a';
    char name [] = {"Java String"};
    //重新赋值 默认是带符号的
    number = 32;
    long l = 999999999999999999;//9999999999999999999 越界

    double salary = 1000.57;
    double num = 1.43;
    double sum = salary + num;
    bool flag = 1;
    //long 输出 %ld (long long) %lld
    printf("number[%d]", number);
    printf("number[%d] score[%f] sex[%c] name[%s]\n", number,score,sex,name);
    //sizeof(int) int 占多个字节
    printf("int size[%lu] long size[%lu] long[%ld]\n",sizeof(int), sizeof(long),l);//4 byte
    //double .2f 保留2位 float 6 位 double 15位 %f 默认是输出 6位 小数点后6位
    printf("double [%.2f]\n",sum);
    if(flag){
        printf("flag true");
    }
}