#include <stdio.h>
/*
    头文件是扩展名为 .h 的文件 包含了 C 函数声明和宏定义，被多个源文件中引用共享。有两种类型的头文件： 程序员编写的头文件和 C 标准库自带的头文件
    在程序中要使用头文件，需要使用 C 预处理指令 #include 来引用它。前面我们已经看过 stdio.h 头文件，它是 C 标准库自带的头文件
    #include 叫做文件包含命令，用来引入对应的头文件（.h 文件）。#include 也是 C 语言预处理命令的一种。
        #include 的处理过程很简单，就是将头文件的内容插入到该命令所在的位置，从而把头文件和当前源文件连接成一个源 文件，这与复制粘贴的效果相同。
        但是我们不会直接在源文件中复制头文件的内容，因为这么做很容易出错， 特别在程序是由多个源文件组成的时候
    建议把所有的常量、宏、系统全局变量和函数原型写在头文件中，在需要的时候随时引用这些头文件

    头文件的注意事项和细节说明
        引用头文件相当于复制头文件的内容
        源文件的名字 可以不和头文件一样，但是为了好管理，一般头文件名和源文件名一样
        C 语言中 include <> 与 include "" 的区别
            include <>：引用的是编译器的类库路径里面的头文件，用于引用系统头文件
            include ""：引用的是你程序目录的相对路径中的头文件，如果在程序目录没有找到引用的头文件则到编译器的
            类库路径的目录下找该头文件，用于引用用户头文件
            所以：
                * 引用 系统头文件，两种形式都会可以，include <> 效率高
                * 引用 用户头文件，只能使用 include ""
         一个 #include 命令只能包含一个头文件，多个头文件需要多个 #include 命令
         同一个头文件如果被多次引入，多次引入的效果和一次引入的效果相同，因为头文件在代码层面有防止重复引入的机制
         在一个被包含的文件(.c)中又可以包含另一个文件头文件(.h)
         不管是标准头文件，还是自定义头文件，都只能包含变量和函数的声明，不能包含定义，否则在多次引入时会 引起重复定义错误(!!!!)

        函数调用规则
            函数调用的规则(适用于 java, c++, php 等)
            1.当调用(执行)一个函数时，就会开辟一个独立的空间(栈)
            2.每个栈空间是相互独立
            3.当函数执行完毕后，会返回到调用函数位置，继续执行
            4.如果函数有返回值，则，将返回值赋给接收的变量
            5.当一个函数返回后，该函数对应的栈空间也就销毁
 */

//多次引入会有问题 这是定义 声明可以
/**
 * 头文件工作原理<br><br>
 * <img src="https://cdn.nlark.com/yuque/0/2023/png/27601787/1678528215753-0c85e818-1282-4e99-982b-9b4fa94a69ca.png">
 * 函数调用规则<br>
 * <img src="https://cdn.nlark.com/yuque/0/2023/png/27601787/1678528657907-78385f7d-a201-4716-bd13-5d9d94cccbc9.png?x-oss-process=image%2Fresize%2Cw_1112">
 */
double cal(double x, double y, char operation) {

    double result = 0.0;

    switch (operation) {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            result = x / y;
            break;
        default:
            break;
    }
    printf("\n (function in) x %.2f y %.2f operation %c ",x,y,operation);
    return result;
}

//函数申明
void sayName();