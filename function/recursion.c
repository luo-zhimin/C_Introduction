#include <stdio.h>
#include <stdarg.h>

//int number = 99;
//递归
void test(int n){
    if(n>2){
        test(n-1);
    }
    printf("n=%d\n",n);
}

int fbn(int n){
    //斐波那契数 1,1,2,3,5,8,13...
    if(n==1 || n==2){
        return 1;
    } else{
        return fbn(n-1)+ fbn(n-2);
    }
}

int fun(int n){
    //求出 f(n)的值?
    //f(1)=3; f(n) = 2*f(n-1)+1
    if(n==1){
        return 3;
    } else{
      return 2*fun(n-1)+1;
    }
}

int eatPeach(int day){
    //有一堆桃子，猴子第一天吃了其中的一半，并再多吃了一个！以后每天猴子都吃其中的一半，然后再多吃一个。
    // 当到第十天时，想再吃时（还没吃），发现只有 1 个桃子了。问题：最初共多少个桃子
    /*
        day 10 - > 1
        每天吃 n/2 +1 个
        day 9 (day10+1)*2
        day 8 (day9+1)*2
     */
    if(day==10){
        return 1;
    } else{
        return (eatPeach(day+1)+1)*2;
    }
}

// 如果希望函数内的变量能修改函数外的变量，可以传入变量的地址&，函数内以指针的方式操作变量。从效果 上看类似引用(即传递指针)
void f8(int *p){
    (*p)++;
}
//基本数据类型默认是值传递的，即进行值拷贝。在函数内修改，不会影响到原来的值
//void f8(int p){
//    p++;
//}

//请编写一个函数 swap(int *n1, int *n2) 可以交换 n1 和 n2 的值
void swap(int *n1,int *n2){
    int temp = *n1;
    *n1=*n2;
    *n2 = temp;
}

//支持可变参数函数
/**
 * @param number 一共几个数(运行几次)
 * @param ... 可变参数 和number 类型一致 简单来说就是和java的array一样 遍历array下标取值 相加
 * @return numberTotalSum
 */
int anyFun(int number, ...) {
    int i, totalSum = 0; //totalSum 一定要初始化
    int val = 0;
    va_list v1; //v1 实际是一个字符指针，从头文件里可以找到
    va_start(v1, number); //使 v1 指向可变列表中第一个值，即 num 后的第一个参数
    printf("*v = %d\n", *v1);
    for (i = 0; i < number; i++) //num 减一是为了防止下标超限
    {
        val = va_arg(v1, int); //该函数返回 v1 指向的值，并使 v1 向下移动一个 int 的距离，使其指向下一个 int
        printf("val = %d\n", val);
        totalSum += val;
    }
    va_end(v1); //关闭 v1 指针，使其指向 null return totalSum;
    return totalSum;
}

/**
 * 值传递和引用传递使用特点<br>
 * <img src="https://cdn.nlark.com/yuque/0/2023/png/27601787/1678545559581-38c68fd8-b80b-45d6-ba67-375f0c2ab8fa.png">
 */
int main(){

    //一个函数在函数体内又调用了本身，我们称为递归调用

    /*
        函数递归需要遵守的重要原则
            执行一个函数时，就创建一个新的受保护的独立空间(新函数栈)
            函数的局部变量是独立的，不会相互影响
            递归必须向退出递归的条件逼近，否则就是无限递归，死龟了
            当一个函数执行完毕，或者遇到 return，就会返回，遵守谁调用，就将结果返回给谁

        函数注意事项和细节讨论
            函数的形参列表可以是多个
            C 语言传递参数可以是值传递（pass by value），也可以传递指针（a pointer passed by value）也叫引用传递
            函数的命名遵循标识符命名规范，首字母不能是数字，可以采用 驼峰法 或者 下划线法 ，比如 getMax() get_max()
            函数中的变量是局部的，函数外不生效
            基本数据类型默认是值传递的，即进行值拷贝。在函数内修改，不会影响到原来的值
            如果希望函数内的变量能修改函数外的变量，可以传入变量的地址&，函数内以指针的方式操作变量。从效果 上看类似引用(即传递指针)
            C 语言 不支持函数重载
            C 语言支持可变参数函数

        函数参数的传递方式
            传递方式(俩种)
                1.值传递
                    变量直接存储值，内存通常在栈中分配
                    默认是值传递的数据类型有：1.基本数据类型 2.结构体 3.共用体 4.枚举
                2.引用传递(传递指针、地址)
                    变量存储的是一个地址，这个地址对应的空间才真正存储数据数据(值)
                    默认是引用传递的数据类型有：指针和数组
                3.其实，不管是值传递还是引用传递，传递给函数的都是变量的副本，不同的是，值传递的是值的拷贝，引用传递的是地址的拷贝，一般来说，
                    地址拷贝效率高，因为数据量小，而值拷贝决定拷贝的数据大小，数据越大，效率越低
                4.如果希望函数内的变量能修改函数外的变量，可以传入变量的地址&，函数内以指针的方式操作变量(*指针)。`
     */
    test(3);//2,3
    int fbnResult = fbn(7);
    printf("fbnResult %d\n",fbnResult);
    //求出 f(n)的值
    int funResult = fun(7);
    printf("funResult %d\n",funResult);
    //todo 传递指针 pointer
    int a = 9;
    f8(&a);//10
    printf("print pointer number %d\n",a);

    //可变参数
    int result = anyFun(2,40,44);
    printf("result %d",result);

    return 0;
}

