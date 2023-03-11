#include <stdio.h>

/**
 * static 关键字
 */
void fn() {
    int n = 10; //普通变量, 每次执行都会初始化，n 在栈区
    printf("n=%d\n", n);
    n++;
    printf("n++=%d\n", n);
}

void fn_static() {
    static int n = 10; //静态局部变量， 放在静态存储区，全局性质空间
    printf("static n=%d\n", n); // 10 n++; // n = 11
    printf("n++=%d\n", n); // 11
}

//普通全局变量 使用另外一个文件的全局变量(普通), 使用 extern 引入即可
int number = 10;
//静态全局变量 只能在本文件中使用，而不能在其它文件使用
static int number2 = 20;

//function
void f1(){
    printf("\n非静态函数");
}
//static function 它只能在本文件中使用
static void f2(){
    printf("\n静态函数");
}

void main() {

    //-----static......
    //static 关键字在 c 语言中比较常用，使用恰当能够大大提高程序的模块化特性，有利于扩展和维护
    /*
        局部变量使用 static 修饰
            局部变量被 static 修饰后，我们称为静态局部变量
            对应静态局部变量在声明时未赋初值，编译器也会把它初始化为 0
            静态局部变量存储于进程的静态存储区(全局性质)，只会被初始一次，即使函数返回，它的值也会保持不变

        全局变量使用 static 修饰
            普通全局变量对整个工程可见，其他文件可以使用 extern 外部声明后直接使用。也就是说其他文件不能再定义 一个与其相同名字的变量了（否则编译器会认为它们是同一个变量），
                静态全局变量仅对当前文件可见，其他 文件不可访问，其他文件可以定义与其同名的变量，两者互不影响
            定义不需要与其他文件共享的全局变量时，加上 static 关键字能够有效地降低程序模块之间的耦合，避免不同 文件同名变量的冲突，且不会误使用

        函数使用 static 修饰
            函数的使用方式与全局变量类似，在函数的返回类型前加上 static，就是静态函数
            非静态函数可以在另一个文件中通过 extern 引用
            静态函数只能在声明它的文件中可见，其他文件不能引用该函数
            不同的文件可以使用相同名字的静态函数，互不影响
     */

    //n->static has a default value init 0
    //静态存储区 只会被初始一次
    static int n;
    printf("static n=%d\n", n);
    printf("--------------------\n");
    //global execute every init (in stack)
    fn();
    printf("--------------------\n");
    //static init once
    fn_static();
    printf("--------------------\n");

    fn();
    printf("--------------------\n");
}