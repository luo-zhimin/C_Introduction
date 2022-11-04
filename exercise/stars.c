#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("loop controller exercise\n");
    printf("九九乘法表");
    //打印出九九乘法表
    int level = 9;
    for (int i = 0; i <= level; ++i){
        for (int j = 1; j <=i; j++){
            printf("%d*%d=%d\t",i,j,(i*j));
        }
        printf("\n");
    }

    //打印出金字塔
    printf("\n");
    //2n-1
    printf("金字塔");
    int totalLevel = 6;
    for (int i = 0; i < totalLevel; ++i){
        //输出空格\t
        for (int k = 0; k < totalLevel - i; ++k){
            printf("\t");
        }

        for (int j = 0; j < 2 * i - 1; ++j) {
            printf("*\t");
        }
        printf("\n");
    }

    //随机生成一个数，直到生成了 97 这个数，看看你一共用了几次
//    for (int i = 0; i < 5; ++i) {
//        printf("rand=%d\t",rand());
//    }
    //break 语句用于终止某个语句块的执行，一般使用在 switch 或者循环[三大循环]中
    int count=0;
    for (;;){
        int value = rand();
        printf("rand=%d\n",value);
        count++;
        if (value==97){
            break;
        }
    }
    printf("第%d回找到97",count);

    //continue 语句用于结束本次循环，继续执行下一次循环
    //continue 语句，只能配合循环语言使用，不能单独和 switch/if 使用

    //todo goto
    //1) C 语言的 goto 语句可以无条件地转移到程序中指定的行。
    //2) goto 语句通常与条件语句配合使用。可用来实现条件转移，跳出循环体等功能。
    //3) 在 C 程序设计中一般不主张使用 goto 语句， 以免造成程序流程的混乱，使理解和调试程序都产生困难

    goto label;
    printf("goto 1");
    printf("goto 2");
    label:
    printf("goto 3");//print

    return 0;
}