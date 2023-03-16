#include <stdio.h>
#include "../function/fisrtFunction.h"

void main() {
    //debugInduction

    /**
     断点调试是指自己在程序的某一行设置一个断点，调试时，程序运行到这一行就会停住，
        然后你可以一步一 步往下调试，调试过程中可以看各个变量当前的值，出错的话，调试到出错的代码行即显示错误，停下

      f5： 开始调试 、执行到下一个断点
      f11: 逐句执行代码, 会进入到函数体中
      f10: 逐过程执行(遇到函数，不会进入到函数体)
      shift+f11: 跳出(跳出某个函数, 跳出前，会将该函数执行完)
      shift+f5: 终止调试
     */
    //1
    int sum = 0;
    for (int i = 0; i < 10; ++i){
        sum+=i;
        printf("i=%d\n",i);
        printf("sum=%d\n",sum);
    }
    printf("退出 for 循环了~~\n");


    //3
    int a = 1;
    int b = 3;
    char operation = '*';
    double res = cal(a, b, operation);
    printf("res=%.2f\n", res);
    printf("test");
    printf("test");
};