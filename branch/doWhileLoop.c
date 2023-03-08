#include <stdio.h>
#include <string.h>

int main() {

    /**
     * 循环条件是返回一个表示真(非 0)假(0) 的表达式
     * do..while 循环是先执行，再判断
     */

//    1) 打印 1—100
//    2) 计算 1—100 的和
    int start = 1;
    int end = 100;
    int sum = 0;
    do {
        printf("outlet number [%d]\n", start);
        sum += start;
        start++;
    } while (start <= end);

    printf("outlet total[%d]\n", sum);

//    3) 统计 1——200 之间能被 5 整除但不能被 3 整除的个数
    int secondStart = 1;
    int secondEnd = 200;
    int count = 0;
    do {
        if (secondStart % 5 == 0 && secondStart % 3 != 0) {
            printf("outlet second number [%d]\n", secondStart);
            count++;
        }
        secondStart++;
    } while (secondStart <= secondEnd);

    printf("outlet second count[%d]\n", count);

//    4) 如果老公同意老婆购物，则老婆将一直购物，直到老公说不同意为止 [printf("老婆问：我可以继续购物吗？y/n")]
    char agree[2] = "";
    do {
        printf("老婆问：我可以继续购物吗？y/n ");
        scanf("%s", agree);
        printf("judge:[%s]\n", agree);
    } while (strcmp(agree, "n") != 0);

    return 1;
}