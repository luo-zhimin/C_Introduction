#include <stdio.h>
#include <math.h>

int main(){

    printf("branch control\n");
    //顺序控制
    //分支控制 单 双 多
    //可以输入人的年龄,如果该同志的年龄大于 18 岁,则输出 “你年龄大于 18,要对自己的行为负责!”
    int age = 0;
    printf("请输入您的年龄：");
    scanf("%d",&age);
    if(age>18){
        printf("你年龄大于 18,要对自己的行为负责!");
    } else{
        printf("您的年龄是%d岁",age);
    }

    //声明 2 个 double 型变量并赋值。判断第一个数大于 10.0，且第 2 个数小于 20.0，打印两数之 和
    double a1 = 11.1;
    double b1 = 12.1;
    if(a1>10.0 && b1<20.0){
        printf("\nsum %.2f",a1+b1);
    }

//    岳小鹏参加 C 二级考试，他和父亲岳不群达成承诺：
//    如果：
//    成绩为 100 分时，奖励一辆 BMW；
//    成绩为(80，99]时，奖励一台 iphone7plus；
//    当成绩为[60,80]时，奖励一个 iPad；
//    其它时，什么奖励也没有。

    double score = 0.0;
    printf("\n岳小鹏的考试成绩:");
    scanf("%lf",&score);

    //多分支控制
    if (score == 100.0) {
        printf("BMW");
    } else if (99 <= score && score > 80) {
        printf("iphone7plus");
    } else if (80 <= score && score > 60) {
        printf("iPad");
    } else {
        printf("score %.2f",score);
    }

    /*
        求 ax^2+bx+c=0 方程的根。a,b,c 分别为函数的参数，
        如果：b^2-4ac>0，则有两个解； b^2-4ac=0，则有一个解；b^2-4ac<0，则无解；
        提示：
            x1=(-b+sqrt(b^2-4ac))/2a
            X2=(-b-sqrt(b^2-4ac))/2a
     */
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    double t = b * b - 4 * a * c;

    if(t>0){
        x1=(-b+sqrt(t))/2*a;
        x2=(-b-sqrt(t))/2*a;
        printf("\nx1=%.2f",x1);
        printf("\nx2=%.2f",x2);
    } else if(t==0){
        x1=(-b+sqrt(t))/2*a;
        printf("\nx1=%.2f",x1);
    } else{
        printf("无解");
    }

    //switch
    /*
        1) switch 语句中的 expression 是一个常量表达式，必须是一个整型(char、short, int, long 等) 或枚举类型
        2) case 子句中的值必须是常量,而不能是变量
        3) default 子句是可选的，当没有匹配的 case 时，执行 default
        4) break 语句用来在执行完一个 case 分支后使程序跳出 switch 语句块；
        5) 如果没有写 break，会执行下一个 case 语句块，直到遇到 break 或者执行到 switch 结尾, 这个现象称为穿透.
        请编写一个程序，该程序可以接收一个字符，比如: a,b,c,d,e,f,g a 表示星期一，b 表示星期 二 … 根据用户的输入显 示相依的信息
     */
    char day = ' ';
    printf("\n请输入星期值(a-g):");
    scanf("%lc",&day);
    scanf("%lc",&day);
    switch (day) {
        case 'a':
            printf("星期一");
            break;
        case 'b':
            printf("星期二");
            break;
        case 'c':
            printf("星期三");
            break;
        case 'd':
            printf("星期四");
            break;
        case 'e':
            printf("星期五");
            break;
        case 'g':
            printf("星期六");
            break;
        default:
            break;
    }

    return 0;
}