#include <stdio.h>

//传递
int main(){
    /*
        值传递和地址传递
        C 语言传递参数(或者赋值)可以是值传递（pass by value），也可以传递指针（a pointer passed by value）, 传递指针也叫地址传递
        默认传递值的类型：基本数据类型 (整型类型、小数类型，字符类型), 结构体, 共用体
        默认传递地址的类似：指针、数组

        值传递和地址传递使用特点
        值传递：将变量指向的存储内容，在传递/赋值时，拷贝一份给接收变量
        地址传递 也叫 指针传递：如果是指针，就将指针变量存储的地址，传递给接收变量，如果是数组，就将数 组的首地址传递给接收变量
     */

    int num = 100;
    int *p = &num;
    int *p2 = p;
    *p2 = 55;
    printf("num=%d *p=%d *p2=%d \n", num, *p, *p2);

    //homework
    //试编写程序实现如下效果
    // 姓名 年龄 成绩 性别 爱好
    // xx xx xx xx xx
    // 要求：
    // a、用变量将姓名、年龄、成绩、性别、爱好存储
    // b、添加适当的注释
    // c、添加转义字符
    char name[] = {"tom"};
    int age = 22;
    double score =66;
    char sex[] = {"男"};
    char hobby[] = {"羽毛球"};
    printf("姓名\t年龄\t成绩\t性别\t爱好\n%s\t%d\t%.2f\t%s\t%s\n",name,age,score,sex,hobby);

    //实现两个整数的加减乘除以及取余算法
    //判断一个整数是偶数还是奇数 , if
    int num1 = 1;
    int num2 = 3;
    printf("add sum %d\n",num1+num2);
    printf("sub sum %d\n",num1-num2);
    printf("mul sum %d\n",num1*num2);
    printf("div sum %d\n",num1/num2);
    printf("取膜 %d\n",num1%num2);

    if(num2%2==0){
        printf("偶数");
    }
    printf("奇数");
    return 0;
}