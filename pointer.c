#include <stdio.h>

/**
 * 指针 <br><br>
 *
 */
int main(){
    int number =1;

    //定义一个指针变量
    //int * 表示类型为 指针类型(执行一个int类型指针)
    //ptr 就是一个int*类型 指向 number 的内存地址
    int *ptr = &number;

    //%p 输出变量的地址
    //&number 指向变量 number 的变量地址
    printf("number value [%d] pointer[%p]\n",number,&number);//0x16cecf578

    //指针变量本身也有地址
    //指针变量存放的地址 ptr
    //指针变量存放的地址的值 *ptr
    printf("ptr address[%p] value[%p] target value value[%d]\n",&ptr,ptr,*ptr);//0x16d467570

    //获取一个 int 变量 num 的地址，并显示到终端将 num 的地址赋给指针 ptr , 并通过 ptr 去修改 num 的值
    int num = 999;
    int* pointer = &num;
    printf("ptr address[%p] value[%p] target value value[%d]",&pointer,pointer,*pointer);
    //基本类型，都有对应的指针类型， 形式为 数据类型 *，比如 int 的对应的指针就是 int *, float 对应的指针类型就是 float * , 依次类推
    //此外还有指向数组的指针、指向结构体的指针，指向共用体的指针，(二级指针，多级指针)后
    return 0;
}