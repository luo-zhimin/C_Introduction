#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strLong(char *str1, char *str2) {
    //%lu 32位无符号整数
    printf("str1 的长度=%lu str2 的长度=%lu\n", strlen(str1), strlen(str2));
    if (strlen(str1) >= strlen(str2)) {
        return str1;
    } else {
        return str2;
    }
}

int *fun(){
    //局部变量 执行完函数就会被销毁 destroy
    //int n = 100;
    static int n =100;
    return &n;
}

int *f1(){
    static int a[10];

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i){
        a[i]=rand();
    }
    return a;
}

//normal
int f2(){
    int a = 100;
    a++;
    return a;
}

/**
 * 指针函数
 */
void main() {

    /*
        C 语言 允许函数的返回值是一个指针（地址），这样的函数称为指针函数
     */

    char str1[30], str2[30], *str; // str 是一个指针类型，指向一个字符串
    printf("请输入第 1 个字符串\n");
    scanf("%s",str1);
//    gets(str1);
    printf("请输入第 2 个字符串\n");
//    gets(str2);
    scanf("%s",str2);
    str = strLong(str1, str2);
    printf("Longer string: %s \n", str);

    printf("--------------------\n");
    //detail
    //用指针作为函数返回值时需要注意，函数运行结束后会销毁在它内部定义的所有局部数据，包括局部变量、局部数组和形式参数，函数返回的指针不能指向这些数据
    //函数运行结束后会销毁该函数所有的局部数据，这里所谓的销毁并不是将局部数据所占用的内存全部清零，而是程序放弃对它的使用权限，后面的代码可以使用这块内存
    //C 语言不支持在调用函数时返回局部变量的地址，如果确实有这样的需求，需要定义局部变量为 static 变量
    int *p = fun();
    int normal = f2();
    int n;
    //(返回指针类型)返回局部变量时候 直接输出可能会占用刚才放弃的内存
    printf("ok~~~\n");
    n = *p;
    //如果不使用static 修饰 直接返回局部变量 不一定返回是你想要的值 执行完就会被销毁 空间权限被放弃 如果中间穿插其他暂用内存地方 有可能内存会被重新使用
    printf("value = %d,normal=%d\n", n,normal);

    //编写一个函数，它会生成 10 个随机数，并使用表示指针的数组名（即第一个数组元素的地址）来返回它们
    int *f = f1();
    for (int i = 0; i < 10; ++i) {
        printf("%d\n",*f);
        f++;
    }

    printf("--------------------\n");

    /*

     */
}