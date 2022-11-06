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

int main(){

    //一个函数在函数体内又调用了本身，我们称为递归调用
    test(3);//2,3
    int fbnResult = fbn(7);
    printf("fbnResult %d\n",fbnResult);
    //求出 f(n)的值
    int funResult = fun(7);
    printf("funResult %d\n",funResult);

    return 0;
}

