#include <stdio.h>
/**
 * 循环 控制
 */
int main(){

    printf("循环 控制 loop controller");

    //for
    for (int i = 0; i < 5; ++i){
        printf("\n爱学习 i=%d",i);
    }

    //打印 1~100 之间所有是 9 的倍数的整数的个数及总和
    int count =0;
    int sum = 0;
    for (int i = 0; i < 100; ++i){
        if(i%9==0){
            sum+=i;
            count++;
        }
    }
    printf("\ncount=%d个，和sum=%d",count,sum);

    //输入一个值 进行 组合
    int num = 0;
    printf("\n请输入您要找的和：");
    scanf("%d",&num);
    for (int i = 0; i < num; ++i){
        printf("\n%d + %d = %d",i,num-i,num);
    }

    return 0;
}