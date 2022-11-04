//引入头文件
#include <stdio.h>
#include <math.h>
#include "function/function.h"

//void clib(){
//    double result = pow(3,2);
//    printf("\nresult %f",result);
//}

void clib(){}

//main function
void main() {
//    printf("hello Word!!");
//    return 0;

    //1) C 程序的主体结构说明 #include ... void main() {} 包括内容， 称为函数体 语句 1; 语句 2; }
    //2) C 程序源文件以“c”为扩展名。
    //3) C 程序的执行入口是 main()函数
    //4) C 语言严格区分大小写。
    //5) C 程序由一条条语句构成，每个语句以“;”结束
    //6) 大括号都是成对出现的，缺一不可

    //常用转义字符使用
    //1. \t 是表示一个制表位
    // 2. \n 表示换行输出
    // 3. \\ 第一个 \ 是转义， 第二个 \ 表示输出内容
    //4. \" 第一个 \ 是转义， 第二个 " 表示输出内容
    printf("你好\"我是小红\"\n");
    printf("北京\t上海\t天津\n");
    printf("姓名\t\t年龄\t籍贯\t住址\nJohn\t23\t上海\t外滩");
    clib();
    //停留 窗口
//    getchar();

    double result = cal(1,2,'*');
    printf("\nfunction test mit %.2f",result);
}

