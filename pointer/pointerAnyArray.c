#include <stdio.h>

//函数声明
void test(int *p);

double getAverage(int *arr, int size);

double getAverage2(int *arr, int size);

/**
 * 指向指针的指针(多重指针) <br>
 * <img src="https://cdn.nlark.com/yuque/0/2023/png/27601787/1678980865942-366f7735-e74b-44be-9831-a4f1f1bff849.png"><br>
 * <img src="https://cdn.nlark.com/yuque/0/2023/png/27601787/1678981412933-f8345210-3e0d-4984-8216-2e2fbc49a835.png">
 */
void main() {

    /*
        指向指针的指针是一种多级间接寻址的形式，或者说是一个指针链。通常，一个指针包含一个变量的地址。当 我们定义一个指向指针的指针时，
        第一个指针包含了第二个指针的地址，第二个指针指向包含实际值的位置

        多重指针(二级,三级)
            一个指向指针的指针变量必须如下声明，即在变量名前放置两个星号。例如，下面声明了一个指向 int 类型指 针的指针: int **ptr; // ptr 的类型是 int **

     */

    int var;
    int *ptr; //一级指针
    int **pptr; //二级指针
    int ***ppptr; // 三级指针
    var = 3000;

    ptr = &var; // var 变量的地址赋给 ptr
    pptr = &ptr;// 表示将 ptr 存放的地址，赋给 pptr
    ppptr = &pptr; // 表示将 pptr 存放的地址，赋给 ppptr

    printf("var 的地址=%p var = %d \n", &var, var);// 0x1133 3000
    printf("ptr 的本身的地址=%p ptr 存放的地址=%p *ptr = %d \n", &ptr, ptr, *ptr);
    printf("pptr 本身地址 = %p pptr 存放的地址=%p **pptr = %d\n", &pptr, pptr, **pptr);
    printf("ppptr 本身地址 = %p ppptr 存放的地址=%p ***pptr = %d\n", &ppptr, ppptr, ***ppptr);

    printf("---------\n");

    //传递指针(地址)给函数
    //当函数的形参类型是指针类型时，是使用该函数时，需要传递指针，或者地址，或者数组给该形参

    int num = 90;
    //num地址赋值给 p指针
    int *p = &num;
    //传地址
    test(&num);
    printf("main() 中的 num=%d\n", num);
    //传指针
    test(p);
    printf("main() 中的 num=%d\n", num);

    //传数组给指针变量

    printf("---------\n");

    /* 带有 5 个元素的整型数组 */
    int balance[5] = {1000, 2, 3, 17, 50};
    double avg; /* 传递一个指向数组的指针作为参数 */
    avg = getAverage(balance, 5); /* 输出返回值 */
    printf("Average value is: %f\n", avg);
}

/**
 * <img src="https://cdn.nlark.com/yuque/0/2023/png/27601787/1678982450389-d55c3eab-267a-4afa-b07c-87797f5daf26.png">
 */
void test(int *p) {
    *p += 1;//向后移动一个int字节(4 byte)
}

double getAverage(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        //移动一个一个int字节=》4byte
        sum += arr[i];
        printf("arr 存放的地址=%p\n", arr);
    }
    return (double) sum / size;
}

double getAverage2(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += *arr;
        printf("arr 存放的地址=%p\n", arr);
        //pointer move int byte
        arr++;
    }
    return (double) sum / size;
}