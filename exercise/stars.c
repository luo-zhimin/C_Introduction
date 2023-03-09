#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("loop controller exercise\n");

    //2n-1
    printf("金字塔");
    //金字塔
    //请编写一个程序，可以接收一个整数,表示层数（totalLevel） while实现
    //先从正方形开始
    //层数
    int totalLevel = 5;

    for (int i = 1; i <= totalLevel; ++i) {

        //1.打印正方形(矩形)
//        for (int j = 0; j < totalLevel; ++j) {

        //2. 打印半个金字塔
//        for (int j = 0; j < i; ++j) {
//            printf("*\t");
//        }

        //3.打印整个金字塔
        //增加缩进
        for (int j = 0; j < totalLevel - i; ++j) {
            printf("\t");
        }

        //找规律打印
//        for (int k = 1; k <= 2 * i - 1; ++k) {
//            printf("*\t");
//        }

        //4. 打印空心金字塔
        for (int k = 1; k <= 2 * i - 1; ++k) {
            //第一层和最后一层都是完美打印 其余都是第一个和最后一个打印 其余补充 \t
            //|| i==totalLevel
            if(k==1 || k== 2 * i - 1){
                printf("*\t");
            } else {
                printf("\t");
            }
        }
        printf("\n");
    }

    //5. 打印空心菱形
    for (int i = 1; i <= totalLevel; ++i) {
        //0->4
        for (int j = 1; j <= i - 1; ++j) {
            printf("\t");
        }
        for (int m = 1; m <= 2 * (totalLevel-i) + 1; ++m) {
            if (m == 1 || m == 2 * (totalLevel-i) + 1) {
                printf("*\t");
            } else {
                printf("\t");
            }
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