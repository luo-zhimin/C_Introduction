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

int *fun() {
    //局部变量 执行完函数就会被销毁 destroy
    //int n = 100;
    static int n = 100;
    return &n;
}

int *f1() {
    static int a[10];

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        a[i] = rand();
    }
    return a;
}

//normal
int f2() {
    int a = 100;
    a++;
    return a;
}

int max(int a, int b) {
    return a > b ? a : b;
}

//获取随机值
int getNextNode(){
 return rand();
}

/**
 * 初始化数组
 * @param waitArray 待初始化的数组
 * @param arraySize 数组的大小
 * @param initValue getNextNode() -> 作为函数指针传递
 */
void initArray(int *waitArray,int arraySize,int (*initValue)()){
    for (int i = 0; i < arraySize; ++i){
        waitArray[i]=initValue();
    }
}

/**
 * 指针函数
 */
void main() {

    /*
        C 语言 允许函数的返回值是一个指针（地址），这样的函数称为指针函数
     */
    printf("指针函数\n");
    char str1[30], str2[30], *str; // str 是一个指针类型，指向一个字符串
    printf("请输入第 1 个字符串\n");
    scanf("%s", str1);
//    gets(str1);
    printf("请输入第 2 个字符串\n");
//    gets(str2);
    scanf("%s", str2);
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
    printf("value = %d,normal=%d\n", n, normal);

    //编写一个函数，它会生成 10 个随机数，并使用表示指针的数组名（即第一个数组元素的地址）来返回它们
    int *f = f1();
    for (int i = 0; i < 10; ++i) {
        printf("%d\n", *f);
        f++;
    }

    printf("--------------------\n");
    printf("函数指针\n");

    /*
        函数指针（指向函数的指针）
            一个函数总是占用一段连续的内存区域，函数名在表达式中有时也会被转换为该函数所在内存区域的首地址， 这和数组名非常类似
            把函数的这个首地址（或称入口地址）赋予一个指针变量，使指针变量指向函数所在的内存区域，然后通过指 针变量就可以找到并调用该函数。这种指针就是函数指针
        函数指针定义
            returnType (*pointerName)(param list)
                returnType 为函数指针指向的函数返回值类型
                pointerName 为函数指针名称
                param list 为函数指针指向的函数的参数列表
                参数列表中可以同时给出参数的类型和名称，也可以只给出参数的类型，省略参数的名称
                注意( )的优先级高于*，第一个括号不能省略，如果写作 returnType *pointerName(param list);就成了函数原型， 它表明函数的返回值类型为 returnType *
     */
    /**
     * <img src="https://cdn.nlark.com/yuque/0/2023/png/27601787/1679118576980-34643bd4-b2e2-4272-8ff2-d1a103cd727d.png">
     */
    //用函数指针来实现对函数的调用, 返回两个整数中的最大值
    int x, y, maxValue;
    //函数指针名称是pMax
    //返回类型是 int
    //入参 (int,int)
//    int (*pMax)(int,int) =max;
    int (*pMax)(int x, int y) =max;
    printf("input two value: \n");
    scanf("%d %d", &x, &y);
    maxValue = (*pMax)(x, y);
    printf("MaxValue=%d,pMax的引用地址=%p,pMax本身地址=%p\n", maxValue, pMax, &pMax);

    printf("--------------------\n");
    printf("回调函数\n");
    //回调函数
    //函数指针变量可以作为某个函数的参数来使用的，回调函数就是一个通过函数指针调用的函数
    //简单的讲：回调函数是由别人的函数执行时调用你传入的函数（通过函数指针完成）
    int waitArray[10];
    initArray(waitArray,10,getNextNode);

    for (int i = 0; i < sizeof(waitArray) / sizeof(waitArray[0]); ++i){
        printf("%d\n",waitArray[i]);
    }

    printf("--------------------\n");

    /*
        注意事项和细节
            指针变量存放的是地址，从这个角度看指针的本质就是地址。
            变量声明的时候，如果没有确切的地址赋值，为指针变量赋一个 NULL 值是好的编程习惯
            赋为 NULL 值的指针被称为空指针，NULL 指针是一个定义在标准库 <stdio.h>中的值为零的常量 #define NULL 0
     */
    int *w = NULL;
    int number = 30;
    w=&number;
    printf("null - > pinter w =%d",*w);
}