#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

void test(){
    long sum = 0;
    for (int i = 0; i < 88888888; ++i){
        sum+=i;
    }
//    return sum;
}

//系统函数
int main(){

    //在将 char 数组 类型转成 基本数据类型时，要确保能够转成有效的数据，比如 我们可以把 "123" , 转成一个整数，但是不能把 "hello" 转成一个整数
    //如果格式不正确，会默认转成 0 或者 0.0

    //字符串
    //length copy concat
    char name[30] = "测试字符串函数";
    printf("name length[%lu]\n",strlen(name));
    //init constant
    char src[30],dest[30];
    //copy init
    strcpy(src,"hello");
    strcpy(dest," string copy function");
    printf("string copy [%s]\n",dest);
    //concat
    strcat(src,dest);
    printf("string concat src[%s]\n",src);

    //时间和日期相关函数
    //定义
    time_t currentTime;
    //init currentTime 指针
    time(&currentTime);
    //ctime是返回当地时间的字符串 当地时间 是基于 timer
    printf("当前时间为 %s\n", ctime(&currentTime));

    //消耗的时间 init time time_t
    time_t start,end;
    printf("start\n");
    time(&start);
    //execute test
    test();
    time(&end);
    //时间差
    printf("花费时间为 %.2fs \n", difftime(end,start));
    printf("end\n\n");

    //数学相关的函数
    //1) double exp(double x) 返回 e 的 x 次幂的值。
    printf("exp %.2f\n",exp(2));
    //2) double log(double x) 返回 x 的自然对数（基数为 e 的对数）
    printf("log %.2f\n",log(8));
    //3) double pow(double x, double y) 返回 x 的 y 次幂。
    printf("pow %.2f\n",pow(2.0,3.0));
    //4) double sqrt(double x) 返回 x 的平方根。
    printf("sqrt %.2f\n",sqrt(2.0));
    //5) double fabs(double x) 返回 x 的绝对值。
    printf("fabs %.2f\n",fabs(-2.0));

    //基本数据类型和字符串类型的转换
    //在程序开发中，我们经常需要将基本数据类型转成字符串类型(即 char 数组 )。或者将字符串类型转成基本数 据类型

    //sprintf 函数打印到字符串中，而 printf 函数打印输出到屏幕 上
    //基本类型转字符串类型
    char str1[20]; //字符数组，即字符串
    char str2[20];
    char str3[20];
    int a = 20984, b = 48090;
    double d = 14.309948;
    //格式化的结果，会存放到 str1 中
    sprintf(str1, "%d %d", a, b);
    sprintf(str2, "%.2f", d);
    sprintf(str3, "%8.2f",d);
    //%8.2f 含义是格式化后，一共有 8 位，小数点后占用 2 位， 不够用空格占位
    printf("\nstr1=%s str2=%s str3=%s", str1, str2, str3);
    //字符串类型转基本数据类型
    //通过<stdlib.h>的函数调用 atoi atof 即可
    //atoi 转换整数
    int num1 = atoi(str2);
    short s1 = atoi(str3);
    printf("\nint=%d short=%hd",num1,s1);
    //atof 转换小数
    double d1= atof(str2);
    printf("\ndouble %.2f",d1);
    //数组的第一个元素
    char c = str2[0];
    printf("\nchar %c",c);
    return 0;
}