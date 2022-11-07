#include <stdio.h>

//递归
int test(int n){
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
    //有一堆桃子，猴子第一天吃了其中的一半，并再多吃了一个！以后每天猴子都吃其中的一半，然后再多吃一个。 当到第十天时，想再吃时（还没吃），发现只有 1 个桃子了。问题：最初共多少个桃子
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

//请编写一个函数 swap(int *n1, int *n2) 可以交换 n1 和 n2 的值
void swap(int *n1,int *n2){
    int temp = *n1;
    *n1=*n2;
    *n2 = temp;
}

int main(){

    //一个函数在函数体内又调用了本身，我们称为递归调用

    /*
        函数的形参列表可以是多个
        C 语言传递参数可以是值传递（pass by value），也可以传递指针（a pointer passed by value）也叫引用传递
        函数的命名遵循标识符命名规范，首字母不能是数字，可以采用 驼峰法 或者 下划线法 ，比如 getMax() get_max()
        函数中的变量是局部的，函数外不生效
        基本数据类型默认是值传递的，即进行值拷贝。在函数内修改，不会影响到原来的值
        如果希望函数内的变量能修改函数外的变量，可以传入变量的地址&，函数内以指针的方式操作变量。从效果 上看类似引用(即传递指针)
        C 语言 不支持函数重载
        C 语言支持可变参数函数

        其实，不管是值传递还是引用传递，传递给函数的都是变量的副本，不同的是，值传递的是值的拷贝，引用传 递的是地址的拷贝，一般来说，地址拷贝效率高，因为数据量小，而值拷贝决定拷贝的数据大小，数据越大，效率 越低
        如果希望函数内的变量能修改函数外的变量，可以传入变量的地址&，函数内以指针的方式操作变量(*指针)。`
     */
    test(3);//2,3
    int fbnResult = fbn(7);
    printf("fbnResult %d\n",fbnResult);
    //求出 f(n)的值
    int funResult = fun(7);
    printf("funResult %d\n",funResult);
    //todo 传递指针 pointer
    int a = 9;
    f8(&a);
    printf("print pointer number %d\n",a);
    return 0;
}

