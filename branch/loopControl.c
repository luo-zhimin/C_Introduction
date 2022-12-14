#include <stdio.h>
#include <string.h>

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

    //while
    //循环输出 值 while(判断条件)
    int i = 0;
    while (i<5){
        i++;
        printf("\nwhile 学习c i=%d",i);
    }

    //打印 1—100 之间所有能被 3 整除的数 while
    int max = 100;
    int j = 0;
    while (j<max){
        if(j%3==0 && j!=0){
            printf("\nwhile value = %d ",j);
        }
        j++;
    }

    //打印 40—200 之间所有的偶数
    int k = 40;
    int maxK = 200;
    while (k<maxK){
        if(k%2==0){
            printf("\nwhile value2 = %d ",k);
        }
        k++;
    }

    printf("\n");
    //不断输入姓名，直到输入 "exit" 为止[使用 while 完成]
    //int	 strcmp(const char *__s1, const char *__s2);
//    printf("\nstring = %d",strcmp("1", "1"));
    char name[20] = "";
    while (strcmp(name,"exit")!=0){
        printf("name:");
        scanf("%s",name);
        printf("name [%s]\n",name);
    }

    //do...while...
    //1) 打印 1—100
    //2) 计算 1—100 的和
    //3) 统计 1——200 之间能被 5 整除但不能被 3 整除的个数
    int x = 0;
    int maxX = 200;
    int doSum = 0;
    int doCount = 0;
    do {
        x++;
        if(x<=100){
            printf("do..while..[%d]\n",x);
            doSum+=x;
        }
        if (x % 5 == 0 && x % 3 != 0) {
            doCount++;
        }
    } while (x<=maxX);

    printf("do..while..sum[%d]\n",doSum);
    printf("do..while..count[%d]",doCount);
    return 0;
}