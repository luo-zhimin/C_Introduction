#include <stdio.h>

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
        注意：在 c 中，没有字符串类型, 使用字符数组表示字符串
        在不同系统上，部分数据类型字节长度不一样, int 2 或者 4
     */
    int number = 16;
    double score = 90.1;
    char sex = 'a';
    char name [] = {"Java String"};
    printf("number[%d]", number);
    printf("number[%d] score[%f] sex[%c] name[%s]", number,score,sex,name);
}