#include <stdio.h>
#include <stdlib.h>

void check(const double *score);

/**
 * 动态分配<br>
 * <img src="https://cdn.nlark.com/yuque/0/2023/png/27601787/1679128287130-7e53af68-56eb-4d75-aaff-7004460d42ee.png"><br>
 * <img src="https://cdn.nlark.com/yuque/0/2023/png/27601787/1679128840802-0e186a37-8d63-4100-b48f-ceae7163ebd6.png"><br>
 * <img src="https://cdn.nlark.com/yuque/0/2023/png/27601787/1679130733927-1d4f4694-a819-41bb-857d-8acdce24e89d.png"><br>
 * <img src="https://cdn.nlark.com/yuque/0/2023/png/27601787/1679136476194-15b784af-4053-4687-b918-15572c33ac21.png">
 */
void main(){

    //dynamic allocation

    /*
        不同数据在内存中分配说明
            全局变量——内存中的静态存储区
            非静态的局部变量——内存中的动态存储区——stack 栈
            临时使用的数据---建立动态内存分配区域，需要时随时开辟，不需要时及时释放——heap 堆
            根据需要向系统申请所需大小的空间，由于未在声明部分定义其为变量或者数组，不能通过变量名或者数组名 来引用这些数据，只能通过指针来引用

         动态分配的相关函数
            头文件 #include <stdlib.h> 声明了四个关于内存动态分配的函数
            函数原型 void * malloc（usigned int size） //memory allocation
                作用——在内存的动态存储区(堆区)中分配一个长度为 size 的连续空间
                形参 size 的类型为无符号整型，函数返回值是所分配区域的第一个字节的地址，即此函数是一个指针型函数， 返回的指针指向该分配域的开头位置
                malloc(100); 开辟 100 字节的临时空间，返回值为其第一个字节的地址
            函数原型 void *calloc（unsigned n,unsigned size）
                作用——在内存的动态存储区中分配 n 个长度为 size 的连续空间，这个空间一般比较大，足以保存一个数组
                用 calloc 函数可以为一维数组开辟动态存储空间，n 为数组元素个数，每个元素长度为 size.
                函数返回指向所分配域的起始位置的指针；分配不成功，返回 NULL
                p = calloc(50, 4); //开辟 50*4 个字节临时空间，把起始地址分配给指针变量 p
            函数原型：void free（void *p）
                作用——释放变量 p 所指向的动态空间，使这部分空间能重新被其他变量使用。
                p 是最近一次调用 calloc 或 malloc 函数时的函数返回值
                free 函数无返回值
                free(p); // 释放 p 所指向的已分配的动态空间
            函数原型 void *realloc（void *p，unsigned int size)
                作用——重新分配 malloc 或 calloc 函数获得的动态空间大小，将 p 指向的动态空间大小改变为 size，p 的值不 变，分配失败返回 NULL
                realloc(p, 50); // 将 p 所指向的已分配的动态空间 改为 50 字节
     */


    //动态创建数组，输入 5 个学生的成绩，另外一个函数检测成绩低于 60 分的，输出不合格的成绩

    //开辟了一个5*8(double byte)的空间 并将地址 (void *） ， 转成 (double *) , 赋给 scores
    double *scores = malloc(5*sizeof(double)); //c99-> auto (void *)<=>(double *)
    for (int i = 0; i < 5; ++i){
        //scanf("%lf",scores+i);
        scanf("%lf",&scores[i]);
    }
    check(scores);
    //...free 释放
    free(scores);

    /**
        动态分配内存的基本原则
            避免分配大量的小内存块。分配堆上的内存有一些系统开销，所以分配许多小的内存块比分配几个大内存块的 系统开销大
            仅在需要时分配内存。只要使用完堆上的内存块，就需要及时释放它(如果使用动态分配内存，需要遵守原则：谁分配，谁释放)， 否则可能出现内存泄漏
            总是确保释放以分配的内存。在编写分配内存的代码时，就要确定在代码的什么地方释放内存
            在释放内存之前，确保不会无意中覆盖堆上已分配的内存地址，否则程序就会出现内存泄漏。在循环中分配内存时，要特别小心
     */

}

void check(const double *score){
    for (int i = 0; i < 5; ++i){
        double ownScore = score[i];
        if(ownScore<60){
            printf("当前学生成绩不及格，成绩为%.2f\n",ownScore);
        }
    }
