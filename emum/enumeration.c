#include <stdio.h>

//枚举 enum
int main(){

    enum DAY{
        MON=1, TUE=2, WED=3, THU=4, FRI=5, SAT=6, SUN=7//如果没有给赋值，就会按照顺序赋值
    } day;

    enum DAY day1;
    day1=MON;
    printf("enumeration day %d",day1);

    //枚举类型是被当做 int 或者 unsigned int 类型来处理的，枚举类型必须连续是可以实现有条件的 遍历
    for (day=MON; day <= SUN; day++) {
        printf("\n for day %d",day);
    }

    //switch enum
    enum SEASONS {
        Spring = 1, SUMMER, AUTUMN, WINTER
    } seasons;

    printf("\n请输入你喜欢的季节(1-4):");
    scanf("%d",&seasons);

    switch (seasons) {
        case Spring:
            printf("Spring");
            break;
        case SUMMER:
            printf("SUMMER");
            break;
        case AUTUMN:
            printf("AUTUMN");
            break;
        case WINTER:
            printf("WINTER");
            break;
        default:
            break;
    }

    //不能直接将一个整数，赋给枚举变量，但是可以将整数，转成枚举类型，再赋给枚举变量
    int number = 4;
    //seasons = number;
    seasons = (enum SEASONS) number;
    printf("\nenumeration season %d",seasons);
    return 0;
}