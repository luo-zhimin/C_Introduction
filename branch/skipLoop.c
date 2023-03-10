#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void main(){

    //...break...
    //break 语句用于终止某个语句块的执行，一般使用在 switch 或者循环[三大循环]中。

    //100 以内的数求和，求出 当和 第一次大于 20 的当前数 for
    int sum = 0;
    for (int i = 0; i < 100; ++i){
        sum+=i;
        if (sum>=20){
            printf("this number [%d]\n",i);
            break;
        }
    }

    //实现登录验证，有三次机会，如果用户名为”张无忌” ,密码”888”提示登录成功，否则提示还有几次机会， 请使用 for 循环完成
    int change = 3;
    //值传递
    int logCount = change;
    char name[10] = "";
    char password[10] ="";
    for (int i = 0; i < logCount; ++i){
        printf("请输入登陆的用户名：\n");
        scanf("%s",name);
        printf("请输入登陆的用户的密码：\n");
        scanf("%s",password);
        if (strcmp("张无忌",name)==0 && strcmp("888",password)==0){
            printf("恭喜%s用户登陆成功\n",name);
            break;
        } else{
            change--;
            printf("您还有%d次机会，确认后在去操作\n",change);
        }
    }

    //continue
    //continue 语句用于结束本次循环，继续执行下一次循环
    //continue 语句，只能配合循环语言使用，不能单独和 switch/if 使用

    //从键盘读入个数不确定的整数，并判断读入的正数和负数的个数，输入为 0 时结束程序【使用 for 循环 ，break, continue 完成】 【positive 正数，negative】
    int positive = 0;
    int negative = 0;
    int number = 0;
    int count = 0;

    for (;;) {
        printf("请输入值: ");
        scanf("%d", &number);
        count++;
        if (number == 0) {
            break;
        }
        if (number > 0) {
            positive++;
            continue;
        }
        negative++;
    }
    printf("this accept total[%d],positive[%d],negative[%d]", number, positive, negative);

    //某人有 100,000 元,每经过一次路口，需要交费,规则如下:
    //当现金>50000 时,每次交 5%
    //当现金<=50000 时,每次交 1000
    //编程计算该人可以经过多少次路口,使用 while break 方式完成
    double money = 100000;
    int countRoad = 0;
    while (true) {
        if (money - 1000 < 0) {
            break;
        }
        countRoad++;
        if (money > 50000) {
            money = money - money * 0.05;
            printf("当前剩余%.2f钱\n",money);
        } else if (money <= 50000) {
            money-=1000;
            printf("当前剩余%.2f钱\n",money);
        }
    }
    printf("100000元，可以经过%d次路口",countRoad);

    //todo goto
    //1) C 语言的 goto 语句可以无条件地转移到程序中指定的行。
    //2) goto 语句通常与条件语句配合使用。可用来实现条件转移，跳出循环体等功能。
    //3) 在 C 程序设计中一般不主张使用 goto 语句， 以免造成程序流程的混乱，使理解和调试程序都产生困难

    goto label;
    printf("goto 1");
    printf("goto 2");
    label:
    printf("goto 3");//print

    //return
    //return 使用在函数，表示跳出所在的函数

}