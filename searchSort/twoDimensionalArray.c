#include <stdio.h>

/**
 * show array
 * @param row 行
 * @param clo 列
 * @param dimensionalArray 二维数组
 */
void showDimensionalArray(int row,int clo,int dimensionalArray[row][clo]){
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < clo; ++j){
            printf("%d\t",dimensionalArray[i][j]);
        }
        printf("\n");
    }
}

/**
 * 二维数组
 */
void main() {

    /*

        请用二维数组输出如下图形
            0 0 0 0 0 0
            0 0 1 0 0 0
            0 2 0 3 0 0
            0 0 0 0 0 0

     */

    //init array
    int fiveChess[4][6];
    //assignment 0
    for (int i = 0; i < 4; ++i) {
        //行
        for (int j = 0; j < 6; ++j) {
            fiveChess[i][j] = 0;
        }
    }
    //[1][2]=>1 [2][1]=>2 [2][3]=>3
    fiveChess[1][2] = 1;
    fiveChess[2][1] = 2;
    fiveChess[2][3] = 3;

    //show 灵活遍历
    int fRow = sizeof(fiveChess)/sizeof (fiveChess[0]);
    int fClo = sizeof(fiveChess[0])/sizeof (int);
    showDimensionalArray(fRow,fClo,fiveChess);

    //直接初始化
    //定义 类型 数组名[大小][大小] = {{值 1,值 2..},{值 1,值 2..},{值 1,值 2..}};
    //或者 类型 数组名[大小][大小] = { 值 1,值 2,值 3,值 4,值 5,值 6 ..};
    /**
     * <img src="https://cdn.nlark.com/yuque/0/2023/png/27601787/1678807051118-ddb2bdf3-ae20-4370-bc4e-6841bf128b0f.png">
     */

    //求和
    int arr[3][2] = {
            {4,  6},
            {1,  4},
            {-2, 8}
    };

    int sum = 0;

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        for (int j = 0; j < sizeof(arr[i]) / sizeof(arr[i][0]); ++j) {
            printf("%d\t", arr[i][j]);
            sum += arr[i][j];
        }
        printf("\n");
    }
    printf("arr sum = %d\n", sum);

    //定义二维数组，用于保存三个班，每个班五名同学成绩，并求出每个班级平均分、 以及所有班级平均分
    //保存三个班，每个班五名同学成绩
    //init
    double scores[3][5] = {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
    };

    int row = sizeof(scores) / sizeof(scores[0]);
    int clo = sizeof(scores[0]) / sizeof(double);

    double totalScore = 0;

    //terminal scanner
    for (int i = 0; i < row; ++i) {
        //班级
        double classTotalScore = 0;
        for (int j = 0; j < clo; ++j) {
            //学生
            printf("请输入第%d个班，第%d个学生的成绩：",i+1,j+1);
            scanf("%lf",&scores[i][j]);
            classTotalScore+=scores[i][j];
        }
        totalScore+=classTotalScore;
        printf("第%d个班,平均成绩为%.2f\n",i+1,classTotalScore/clo);
    }
    printf("全部平均成绩为%.2f\n",totalScore/(row*clo));
    //show
    for (int i = 0; i < row; ++i) {
        //班级
        for (int j = 0; j < clo; ++j) {
            //学生
            printf("%.2f\t",scores[i][j]);
        }
        printf("\n");
    }

    /**
        二维数组使用细节和注意事项
            可以只对部分元素赋值，未赋值的元素自动取“零”值
            如果对全部元素赋值，那么第一维的长度可以不给出
                int a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
                可以写为：
                int a[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9}
            二维数组可以看作是由一维数组嵌套而成的；如果一个数组的每个元素又是一个数组，那么它就是二维数组。
     */

    //可以只对部分元素赋值，未赋值的元素自动取“零”值
    int a[4][5] = {{1}, {2}, {3},{1}};

    int aRow = sizeof(a)/sizeof (a[0]);
    int aClo = sizeof(a[0])/sizeof (int);
    showDimensionalArray(aRow,aClo,a);
}