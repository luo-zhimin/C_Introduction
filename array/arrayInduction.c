#include <stdio.h>

void f1(int arr[]) {
    printf("f1 函数中 的 arr 的地址 = %p\n", arr);
    arr[0] = arr[0] + 1;
}

/**
 * 数组 <br>
 * 数组内存图 <br>
 * <img src="https://cdn.nlark.com/yuque/0/2023/png/27601787/1678633439972-7354bd6d-f145-478a-98bb-b83b608858de.png"><br>
 * <img src="https://cdn.nlark.com/yuque/0/2023/png/27601787/1678634515904-5d71c4dd-8bfb-4e9e-84aa-86433eca0f02.png">
 */
void main() {

    /*
        数组可以存放多个同一类型数据。数组也是一种数据类型，是构造类型。传递是以引用的方式传递(即传递的 是地址)

        数组定义和内存布局
            数据类型 数组名 [数组大小]
            数组名 就代表 该数组的首地址，即 a[0]地址
            数组的各个元素是 连续分布的,假如 a[0] 地址 0x1122 a[1] 地址= a[0]的地址+int 字节数(4) = 0x1122 + 4 = 0x1126
        访问数组元素
            数组名[下标] 比如：你要使用 a 数组的第三个元素 a[2], 下标是从 0 开始计算

         3 种初始化数组的方式
            int arr[1] arr[1]=1;
            int arr2[2] = {1,2};
            int arr3[] ={2,3};

         数组使用注意事项和细节
            数组是多个相同类型数据的组合,一个数组一旦声明/定义了,其长度是固定的, 不能动态变化
            数组创建后，如果没有赋值，则遵守如下规则
                全局数组默认值 0
                非全局数组初值是机器垃圾值(即：原来系统分配给这块空间的值)
            使用数组的步骤 1. 定义数组 2 给数组各个元素赋值 3 使用数组, 也可以一步到位
            数组的下标是从 0 开始的, 不是从 1 开始
            数组下标必须在指定范围内使用，编译通过，否则在运行时会因为数组越界而异常中断
            C 的数组属构造类型， 是引用传递(传递的是地址)，因此当把一个数组传递给一个函数时/或者变量，函数/变 量操作数组会影响到原数组
    */

    //一个养鸡场有 6 只鸡，它们的体重分别是 3kg,5kg,1kg, 3.4kg,2kg,50kg 。请问这六只鸡的总体重是多少?平均体重是多少?
    double chick[6] = {3, 5, 1, 3.4, 2, 50};
    double total = 0;
    for (int i = 0; i < sizeof(chick) / sizeof(double); ++i) {
        total += chick[i];
    }

    //(sizeof(chick) 数组总的大小
    // sizeof(double) 一个double占用的大小
    double avgWeight = total / (sizeof(chick) / sizeof(double));
    printf("总体重是%.2f平 均体重是%.2f\n", total, avgWeight);

    //从终端循环输入 5 个成绩，保存到 double 数组,并输出
    double scores[5] = {};
//    double score = 0;
//    输入 5 个成绩，保存到 double 数组
    for (int i = 0; i < sizeof(scores) / sizeof(double); ++i) {
        printf("请输入第%d学生的成绩: \n", i + 1);
//        scanf("%lf",&score);
//        scores[i]=score;
        scanf("%lf", &scores[i]);
    }
    printf("---------------\n");
    //输出
    for (int i = 0; i < sizeof(scores) / sizeof(double); ++i) {
        printf("第%d学生的成绩为%.2f\n", i + 1, scores[i]);
    }
    printf("---------------\n");

    //C 的数组属构造类型， 是引用传递(传递的是地址)，因此当把一个数组传递给一个函数时/或者变量，函数/变 量操作数组会影响到原数组
    int arr[3] = {3, 4, 5};
    int i;
    printf("main 函数中 的 arr 的地址 = %p\n", arr);
    //数组默认是以 地址传递(传递指针) =>在函数中进行 arr[0]=arr[0]+1的操作 因为是地址传递，所以值是共享的
    f1(arr);
    //遍历  arr
    for (i = 0; i < 3; i++) {
        printf("arr[%d]=%d\n", i, arr[i]); // 4,4,5
    }
    printf("---------------\n");

    //创建一个 char 类型的 26 个元素的数组，分别 放置'A'-'Z‘。使用 for 循环访问所有元素并打印出来
    char charArray[26] ={};
    for (int i = 0; i < 26; ++i){
        charArray[i]='A'+i;
    }
    for (int i = 0; i < 26; ++i){
        printf("charArray=%c\n",charArray[i]);
    }
    printf("---------------\n");

    //请求出一个数组的最大值，并得到对应的下标
    int arr1[] = {0, -1, 89, 99, 4, 0, 23, 876, 9876, 3, 4, 6};
    //最大值 最大下标
    int max,index;
    for (int i = 0; i < sizeof(arr1) / sizeof(int); ++i){
        if(arr1[i]>arr1[i+1]){
            max = arr1[i];
            index=i;
        }
    }
    printf("max=%d index=%d",max,index);
}