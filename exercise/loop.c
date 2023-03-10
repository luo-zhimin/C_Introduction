
#include <stdio.h>
#include <math.h>
#include <string.h>

/**
 * loop exercise
 */
void main() {

    //1.实现判断一个整数，属于哪个范围：大于 0；小于 0；等于 0 (多分支)
    //2.判断一个年份是否为闰年
    //3.判断一个整数是否是水仙花数，所谓水仙花数是指一个 3 位数，其各个位上数字立方和等于其本身。例如： 153 = 1*1*1 + 5*5*5 + 3*3*3

    //1
    int acceptNumber = 0;
    printf("请输出您要判断的整数: ");
    scanf("%d", &acceptNumber);
    if (acceptNumber == 0) {
        printf("acceptNumber = %d\n", acceptNumber);
    } else if (acceptNumber > 0) {
        printf("acceptNumber = %d\n", acceptNumber);
    } else {
        printf("acceptNumber = %d\n", acceptNumber);
    }

//    //2 闰年
//    //(1).能被4整除但不能被100整除
//    //(2).能被400整除
    int leapYear = 0;
    printf("请输出您要判断的年数: ");
    scanf("%d", &leapYear);
    if((leapYear%4==0 && leapYear%100!=0) || leapYear%400==0){
        printf("leapYear[%d]是闰年\n",leapYear);
    } else{
        printf("leapYear[%d]不是闰年\n",leapYear);
    }

    //3
    //水仙花数是指一个 3 位数，其各个位上数字立方和等于其本身。例如： 153 = 1*1*1 + 5*5*5 + 3*3*3
    int flowerNumber = 0;
    printf("\n请输入要验证的数是否是水仙花：");
    scanf("%d",&flowerNumber);
    //取它的百分 十分 个位的数
    int bNumber = flowerNumber/100;
    int tNumber = flowerNumber%100/10;
    int gNumber = flowerNumber%10;
    if(pow(bNumber,3)+ pow(tNumber,3)+ pow(gNumber,3)==flowerNumber){
        printf("当前这个数是[%d]是水仙花\n",flowerNumber);
    } else{
        printf("当前这个数不是[%d]是水仙花\n",flowerNumber);
    }

    //5 保存用户名和密码，判断用户名是否为“张三”，密码是否为 1234，如果是，提示登录成功，否则提示登录失败
    char name[5] = "";
    char password[5] = "";
    printf("请输入用户名：");
    scanf("%s",name);
    printf("请输入密码：");
    scanf("%s",password);
    if(strcmp(name,"张三")==0 && strcmp("1234",password)==0){
        printf("登陆成功");
    } else{
        printf("登录失败");
    }

    //6 编写程序，根据输入的月份和年份，求出该月的天数（1-12）, 就是需要考虑闰年(2 月份 29)和平年(2 月份 28)
    //1,3,5,7,8,10,12 --- 31
    //2月---判断
    int year = 0;
    int month = 0;
    printf("请输入年份：");
    scanf("%d",&year);
    printf("请输入月份：");
    scanf("%d",&month);
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("当前%d月，一共有31天",month);
            break;
        case 2:
            //判断平闰年
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                printf("今年%d是闰年,当前2月，一共有29天",month);
                break;
            }
            printf("今年%d是平年,当前2月，一共有28天",month);
            break;
        default:
            printf("当前%d月，一共有30天",month);
            break;
    }

    //7.定义变量保存一个数，判断（if）是否能被 3 整除或(||)能被 7 整除(%)，如果是，则提示：能，否则提示：不能
    int tempNumber = 21;
    if(tempNumber%3==0||tempNumber%7==0){
        printf("能");
    } else{
        printf("不能");
    }

    //8.输入星期几，如果是星期一到星期三，打印：AAA，星期四到星期五，打印：BBB，星期六到星期日，打印 CCC， 如果都不是，提示，输入错误(提示 switch+穿透)
    int week = 0;
    printf("输入星期(1-7): ");
    scanf("%d",&week);
    switch (week) {
        case 1:
        case 2:
        case 3:
            printf("AAA");
            break;
        case 4:
        case 5:
            printf("BBB");
            break;
        case 6:
        case 7:
            printf("CCC");
            break;
        default:
            printf("输入错误");
    }

    //11 复习：请使用 for、while、do—while 三种形式打印 1000——9999 年内所有的闰年
    int start = 1000;
    int end = 9999;
    for (int i = start; i < end; ++i) {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
            printf("%d\n", i);
        }
    }
    while (start<=end){
        if ((start % 4 == 0 && start % 100 != 0) || start % 400 == 0) {
            printf("%d\n", start);
        }
        start++;
    }
    do{
        if ((start % 4 == 0 && start % 100 != 0) || start % 400 == 0) {
            printf("%d\n", start);
        }
        start++;
    } while (start<=end);

    //12 输出小写的 a-z 以及大写的 Z—A
    char c1,c2;
    for (c1 = 'a'; c1 <= 'z'; c1++) {
        printf("%c\t",c1);
    }
    printf("\n");
    for (c2 = 'Z'; c2 >= 'A'; c2--) {
        printf("%c\t",c2);
    }
    printf("\n");

    //13.求出 1-1/2+1/3-1/4…..1/100 的和
    double sum = 0.0;
    //(1/1)-(1/2)+(1/3)-(1/4)....(1/100)
    //分母为奇数时候 +
    //分母为偶数时候 -
    for (int i = 1; i <= 100; ++i){
        //偶数
        if(i%2==0){
            sum-=1.0/i;
        } else{
            sum+=1.0/i;
        }
    }
    printf("sum = %.2f",sum);
}