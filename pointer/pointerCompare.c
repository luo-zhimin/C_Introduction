#include <stdio.h>

const int Max = 3;

void main() {

    /*
        指针可以用关系运算符进行比较，如 ==、< <= 和 > >=
     */

    //如果 p1 和 p2 指向两个变量，比如同一个数组中 的不同元素，则可对 p1 和 p2 进行大小比较
    int var[] = {10, 100, 200};
    int *ptr;
    ptr = var;

    printf("引用=%p,本身=%p，ptr=%d，var[0]=%p,var[0]=%d", ptr, &ptr, *ptr, &var[0], var[0]);
    //!!!比较的是地址 par是int* var[0]==》*par
    //if(ptr == var[0]) {//错误,类型不一样 (int *) 和 (int )
    // printf("ok1");
    // }

    if (ptr == &var[0]) { // 可以
        printf("\nok2"); //输出
    }

    if (ptr == var) { //可以
        printf("\nok3"); //输出
    }

    if (ptr >= &var[1]) { //可以比较,但是返回 false
        printf("\nok4");//不会输出
    }

    int i = 0;
    while (ptr <= &var[Max - 1]) {
        //%x表示以十六进制数形式输出整数
        printf("\nAddress of var[%d] = %x", i, ptr);
        printf("\nValue of var[%d] = %d", i, *ptr);
        ptr++;
        i++;
    }
}