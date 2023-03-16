#include <stdio.h>

const int MAX = 3;//常量

/**
 * 指针入门<br>
 * <img src="https://cdn.nlark.com/yuque/0/2023/png/27601787/1678898607104-c725d41f-15ae-4efb-8874-84be97956706.png">
 */
void main() {

    /*
        指针是 C 语言的精华，也是 C 语言的难点
        指针，也就是内存的地址；所谓指针变量，也就是保存了内存地址的变量。关于指针的基本使用，变量的时候做了入门级的介绍
        获取变量的地址，用&，比如： int num = 10, 获取 num 的地址：&num
        指针类型，指针变量存的是一个地址，这个地址指向的空间存的才是值
            比如：int *ptr = &num; ptr 就是指向 int 类型的指针变量, 即 ptr 是 int * 类型。
        获取指针类型所指向的值，使用：*(取值符号)，比如：int * ptr , 使用*ptr 获取 ptr 指向的值
     */

    //指针是一个变量，其值为另一个变量的地址(前示意图已经说明)，即内存位置的直接地址。就像其他变量或常量一样，在使用指针存储其他变量地址之前，对其进行声明。指针变量声明的一般形式为
    int *ip;  /* 一个整型的指针 */
    double *dp;   /* 一个 double 型的指针 */
    float *fp;   /* 一个浮点型的指针 */
    char *ch;   /* 一个字符型的指针 */

    //指针是一个用数值表示的地址。可以对指针执行算术运算。可以对指针进行四种算术运算：++、--、+、-

    /**
     * <img src="https://cdn.nlark.com/yuque/0/2023/png/27601787/1678897247814-a2a1df1f-6da3-49a1-9749-03bfac023ede.png">
     */
    //++
    int var[] = {10, 100, 200}; // int 数组
    int i, *ptr; // ptr 是一个 int* 指针
    //default
    ptr = var; // ptr 指向了 var 数组的首地址
    for (i = 0; i < MAX; i++) {
        printf("var[%d] 地址= %p \n", i, ptr);
        printf("存储值：var[%d] = %d\n", i, *ptr);
        //todo !!! ++ 字节数 数组中地址连续分布！ 16进制 满16->1
        ptr++;// ptr = ptr + 1(1 个 int 字节数); ptr 存放值+4 字节(int)
    }

    printf("-----------\n");
    //--
    int *second;
    second = &var[MAX - 1]; // &var[2]
    for (i = MAX; i > 0; i--) {// 反向遍历
        printf("second 存放的地址=%p\n", second);
        printf("存储值：var[%d] = %d\n", i - 1, *second);
        second--; // ptr = ptr - 1(1 个 int 的字节数 [4 个字节])
    }

    //+=
    int *third;
    third=var;
    third+=2;//=>ptr 的存储的地址 + 2 个 int 的字节 (8 个字节)
    printf("var[2]=%d var[2]的地址=%p ptr 存储的地址=%p ptr 指向的值=%d\n", var[2], &var[2], third, *third);

    //查看字节数 byte
    printf("long=%lu\n",sizeof (long ));
    printf("long double=%lu\n",sizeof (long double));
    printf("char*=%lu\n",sizeof (char* ));
    printf("short=%lu\n",sizeof (short ));

    //exercise
    //-
    int a[]= {1,2,3,4,44,66,0};
    int *fourth;
    fourth=&a[3];
    fourth-=1;//后移动一个字节(int)
    printf("ptr 指向的值=%d\n", *fourth);
}