#include <stdio.h>
#if _WIN32 //如果是 windows 平台, 就执行#include <windows.h>
#include <windows.h>
#elif __linux__ //否则判断是不是 linux ,如果是 linux 就引入<unistd.h>
#include <unistd.h>
#endif

/**
 * 预处理入门
 */
void main(){

    /*
        预处理命令基本介绍
            使用库函数之前，应该用#include 引入对应的头文件。这种以#号开头的命令称为预处理命令。
            这些在编译之前对源文件进行简单加工的过程，就称为预处理（即预先处理、提前处理）
            预处理主要是处理以#开头的命令，例如#include <stdio.h>等。预处理命令要放在所有函数之外，而且一般都放 在源文件的前面
            预处理是 C 语言的一个重要功能，由预处理程序完成。当对一个源文件进行编译时，系统将自动调用预处理程 序对源程序中的预处理部分作处理，处理完毕自动进入对源程序的编译
            C 语言提供了多种预处理功能，如宏定义、文件包含、条件编译等，合理地使用它们会使编写的程序便于阅读、 修改、移植和调试，也有利于模块化程序设计

        提示
            Windows 平台下的暂停函数的原型是 void Sleep(DWORD dwMilliseconds)，参数的单位是“毫秒”，位 于 <windows.h> 头文件。
            Linux 平台下暂停函数的原型是 unsigned int sleep (unsigned int seconds)，参数的单位是“秒”，位于 <unistd.h> 头文件
            #if、#elif、#endif 就是预处理命令，它们都是在编译之前由预处理程序来执行的

        预处理命令总结
            预处理指令是以#号开头的代码行，# 号必须是该行除了任何空白字符外的第一个字符。# 后是指令关键字， 在关键字和 # 号之间允许存在任意个数的空白字符，
                整行语句构成了一条预处理指令，该指令将在编译器进行编 译之前对源代码做某些转换

        常见的预处理指令
            指令  说明
            #    空指令，无任何效果
            #include 包含一个源代码文件

            #define 定义宏
            #undef 取消已定义的宏

            #ifdef 如果宏已经定义，则编译下面代码
            #ifndef 如果宏没有定义，则编译下面代码

            #if 如果给定条件为真，则编译下面代码
            #elif 如果前面的#if 给定条件不为真，当前条件 为真，则编译下面代码
            #endif 结束一个#if……#else 条件编译块
     */

    //开发一个 C 语言程序，让它暂停 5 秒以后再输出内容 在 Windows 和 Linux 下都能运行，如何处理

    #if _WIN32
    Sleep(5000);//ms
    #elif __linux__
    sleep(5);//5s
    #endif
    puts("hello pretreatment~");//输出
}