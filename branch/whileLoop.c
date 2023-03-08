#include <stdio.h>
#include <string.h>

int main(){

    /**
     * 循环条件是返回一个表示真(非 0)假(0) 的表达式
     * while 循环是先判断再执行语句
     */

    //循环输出 值 while(判断条件)
    int i = 0;
    while (i<5){
        i++;
        printf("\nwhile 学习c i=%d",i);
    }

    //while
    //打印 1—100 之间所有能被 3 整除的数
    int start = 1;
    int end = 100;
    int count = 0;
    int total = 0;
    while (start <= end) {
        if (start % 3 == 0) {
            printf("number %d\n", start);
            total+=start;
            count++;
        }
        start++;
    }
    printf("count [%d] total [%d]\n",count,total);

    //打印 40—200 之间所有的偶数
    int secondStart =40;
    int secondEnd =200;
    while (secondStart<=secondEnd){
        if(secondStart%2==0){
            printf("second number [%d]\n",secondStart);
        }
        secondStart++;
    }

    //不断输入姓名，直到输入 "exit" 为止[使用 while 完成]
    //int	 strcmp(const char *__s1, const char *__s2);
//    printf("\nstring = %d",strcmp("1", "1"));
    char name[20] = "";
    //judge
    while (strcmp(name,"exit") != 0){
        printf("name: ");
        //write
        scanf("%s",name);
        //out
        printf("name [%s]\n",name);
    }

    return 0;
}
