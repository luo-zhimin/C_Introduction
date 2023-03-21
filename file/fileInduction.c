#include <stdio.h>

/**
 * <img src="https://cdn.nlark.com/yuque/0/2023/png/27601787/1679322234769-07920850-51e7-413e-85e2-dd78effda44e.png">
 */
void main() {

    /*
        文件在程序中是以流的形式来操作的
            流：数据在数据源(文件)和程序(内存)之间经历的路径
            输入流：数据从数据源(文件)到程序(内存)的路径
            输出流：数据从程序(内存)到数据源(文件)

        C 输入 & 输出
            当我们提到输入时，这意味着要向程序写入一些数据。输入可以是以文件的形式或从命令行中进行。C 语言提供了一系列内置的函数来读取给定的输入，并根据需要写入到程序中
            当我们提到输出时，这意味着要在屏幕上、打印机上或任意文件中显示一些数据。C 语言提供了一系列内置的 函数来输出数据到计算机屏幕上和保存数据到文本文件或二进制文件中
            文件指针是访问文件的方式，我们会讲解如何从屏幕读取值以及如何把结果输出到屏幕上。
            C 语言中的 I/O (输入/输出) 通常使用 printf() 和 scanf() 两个函数。
            scanf() 函数用于从标准输入（键盘）读 取并格式化， printf() 函数发送格式化输出到标准输出（屏幕）

        getchar() & putchar() 函数
            int getchar(void) 函数从屏幕读取下一个可用的字符，并把它返回为一个整数。这个函数在同一个时间内只会读 取一个单一的字符。您可以在循环内使用这个方法，以便从屏幕上读取多个字符。
            int putchar(int c) 函数把字符输出到屏幕上，并返回相同的字符。这个函数在同一个时间内只会输出一个单一的字符。您可以在循环内使用这个方法，以便在屏幕上输出多个字符

        gets() & puts() 函数
            char *gets(char *s) 函数从 stdin 读取一行到 s 所指向的缓冲区，直到一个终止符或 EOF
            int puts(const char *s) 函数把字符串 s 和一个尾随的换行符写入到 stdout。
     */

    //输出到屏幕
    printf("ok~~~\n");

    //getchar() & putChar() 函数
    int c;
    printf("Enter a value:");
    //读取--read
    c=getchar();

    printf("you entered: ");
    //输出--out
    putchar(c);
    printf("\n");

    getchar();
    //gets() & puts() 函数
    char str[100];
    printf("Enter any value: ");
    gets(str);
    printf("you entered: ");
    puts(str);

    //scanf() 和 printf() 函数
    //...
}