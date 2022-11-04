#include <stdio.h>

/**
 * 算术运算符 <br><br>
 * <img src="https://cdn.nlark.com/yuque/0/2022/png/27601787/1666876337349-381da533-33fc-4d87-ab7c-c946095ce4bc.png">
 */
int main() {

    printf("arithmetic operation start\n");
    /*
        自增：++
        作为独立的语句使用：
            前++和后++都完全等价于 i=i+1;
        作为表达式使用
            前++：++i 先自增后赋值
            后++：i++先赋值后自增

        对于除号“/”，它的整数除和小数除是有区别的：整数之间做除法时，只保留整数部分而舍弃小数部分
        当对一个数取模时，可以等价 a%b=a-a/b*b ， 这样我们可以看到 取模的一个本质运算
        当 自增 当做一个独立语言使用时，不管是 ++i; 还是 i++; 都是一样的，等价
        当 自增 当做一个 表达式使用时 j = ++i 等价 i = i + 1; j = i
        当 自增 当做一个 表达式使用时 j = i++ 等价 j = i; i = i + 1
     */

    double d = 10 / 4;//->2.000 000
    double d1 = 10.0 / 4;//2.50
    printf("d=%.2f d1=%.2f", d, d1);

    //公式 a-a/b*b
    int n = 10 % 3;//% 取余
    int n1 = -10 % 3;
    printf("\nn=%d n1=%d", n, n1);

    int i = 10;
    int j = i++;

    printf("\ni=%d j=%d", i, j);

    //假如还有 97 天放假，问：xx 个星期零 xx 天
    int days = 97;
    int week = days/7;
    int day = days%7;
    printf("\n%d个星期零%d天",week,day);
    //定义一个变量保存华氏温度，华氏温度转换摄氏温度的公式为：5/9*(华氏温度-100),请求出华氏温度对应的摄氏温度

    double h = 138;
    double s = 5.0/9*(h-100);
    printf("\n华氏温度[%.2f] 对应的摄氏温度[%.2f]",h,s);
    return 0;
}