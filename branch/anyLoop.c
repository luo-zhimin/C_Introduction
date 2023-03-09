
#include <stdio.h>

/**
 * 多重循环控制
 */
void main() {

    /**
     * 将一个循环放在另一个循环体内，就形成了嵌套循环。其中，for ,while ,do…while 均可以作为外层循环和内层 循环。【建议一般使用两层，最多不要超过 3 层】, 如果嵌套循环过多，会造成可读性降低
     * 实质上，嵌套循环就是把内层循环当成外层循环的循环体。当只有内层循环的循环条件为 false 时，才会完全 跳出内层循环，才可结束外层的当次循环，开始下一次的循环
     * 设外层循环次数为 m 次，内层为 n 次，则内层循环体实际上需要执行 m*n 次
     */

    //1) 统计 3 个班成绩情况，每个班有 5 名同学，求出各个班的平均分和所有班级的平均分[学生的成绩从键盘输入]
    //2) 统计三个班及格人数，每个班有 5 名同学

    //班级
    int classNum = 3;
    //班级里面的人
    int classStudentNum = 5;
    //所有班级的平均分
    double allClassAverage = 0.0;
    //统计三个班及格人数
    int passCount = 0;
    //分数
    double score = 0.0;
    for (int i = 0; i < classNum; ++i) {
        //每次给一个班级输出成绩的时候 需要清零
        //每个班的平均分
        double classAverage = 0.0;

        for (int j = 0; j < classStudentNum; ++j) {
            printf("请输入当前第%d班级的第%d个学生的分数 \n", (i + 1), (j + 1));
            scanf("%lf", &score);
            classAverage += score;
            if (score >= 60) {
                passCount++;
            }
        }
        printf("当前第%d个班级，平均分是%.2f\n", (i + 1), (classAverage / classStudentNum));
        allClassAverage += classAverage;
    }
    printf("所有班级的平均分是%.2f，及格人数是%d人", allClassAverage / (classNum * classStudentNum), passCount);

    //打印出九九 乘法表]
    for (int i = 1; i <= 9; ++i) {
        //倒叙打印
//        for (int j = 9; j >= i; j--) {
        //正叙打印
        for (int j = 1; j <= i; j++) {
            printf("%d * %d = %d\t", i, j, (i * j));
        }
        printf("\n");
    }
}