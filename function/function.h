#include <stdio.h>
/*
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
         同一个头文件如果被多次引入，多次引入的效果和一次引入的效果相同，因为头文件在代码层面有防止重复引 入的机制
         在一个被包含的文件(.c)中又可以包含另一个文件头文件(.h)
         不管是标准头文件，还是自定义头文件，都只能包含变量和函数的声明，不能包含定义，否则在多次引入时会 引起重复定义错误(!!!!)


        函数调用规则
            当调用(执行)一个函数时，就会开辟一个独立的空间(栈)
            每个栈空间是相互独立
            当函数执行完毕后，会返回到调用函数位置，继续执行
            如果函数有返回值，则，将返回值赋给接收的变量
            当一个函数返回后，该函数对应的栈空间也就销毁
 */

//多次引入会有问题 这是定义 声明可以
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
    printf("\nx %.2f y %.2f operation %c ",x,y,operation);
    return result;
}

void sayName();