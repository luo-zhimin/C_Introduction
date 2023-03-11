//系统头文件
#include <stdio.h>
//用户头文件
#include "./fisrtFunction.h"

int main() {

    /*
        函数基本语法
            返回类型 函数名（形参列表）{
            执行语句...; // 函数体
            return 返回值; // 可选
          }

          形参列表：表示函数的输入
          函数中的语句：表示为了实现某一功能代码块
          函数可以有返回值,也可以没有, 如果没有返回值，返回类型 声明为 void
     */
    printf("function");
    //函数封装
    double add = cal(1,4,'+');
    printf("\nadd %.2f",add);

    sayName();

    //传统方法(计算多次 会有多个传统方法产生)
//    switch (operation) {
//        case '+':
//            result = x + y;
//            break;
//        case '-':
//            result = x - y;
//            break;
//        case '*':
//            result = x * y;
//            break;
//        case '/':
//            result = x / y;
//            break;
//        default:
//            break;
//    }
//    printf("\nx %.2f y %.2f operation %c ",x,y,operation);

    return 0;
}

//函数定义
void sayName(){
    printf("\nclion second function~");
}