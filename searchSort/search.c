#include <stdio.h>

/**
 * 顺序查找
 * @param array 要查找的数组
 * @param value 要查的value
 * @return 找到的下标或者-1
 */
int seqSearch(int array[], int value) {
    for (int i = 0; i < sizeof(array) / sizeof(int); ++i) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

/**
 * 二分查找
 * @param binaryArray 有序数组
 * @param value 要查找的value
 * @param left 左边
 * @param right 右边
 * @return 查找到的下标或者-1
 */
int binarySearch(int binaryArray[], int left, int right, int value) {

    //先找到中间的数
    int middleIndex = (left+right)/2;
    int middleValue = binaryArray[middleIndex];

    // left -- / right ++ (no hava stack overflow)
    if(left>right){
        return -1;
    }

    printf("middle index = %d,middleValue=%d,findValue=%d\n",middleIndex,middleValue,value);
    if(middleValue>value){
        //递归
        binarySearch(binaryArray,left,middleIndex-1,value);
    } else if(middleValue<value){
        binarySearch(binaryArray,middleIndex+1,right,value);
    } else{
        return middleIndex;
    }
    //return question need have a default value ？？？
//    return -888;
}


/**
 * search
 */
void main() {

    /*
        顺序查找

        二分查找

     */

    //猜数游戏：从键盘中任意输入一个数，判断数列中是否包含该数【顺序查找】 要求: 如果找到了，就提示找到， 并给出下标值, 找不到提示 没有
    int findArray[] = {23, 1, 34, 89, 101};
    int number = 0;
    printf("output one number find isLive: ");
    scanf("%d", &number);
    int index = seqSearch(findArray, number);
    printf("index = %d,%s\n", index, index != -1 ? "找到" : "没有");

    //请对一个有序数组进行二分查找 {1,8, 10, 89, 1000, 1234} ，输入一个数看看该数组是否存在此数，并且求出下 标，如果没有就提示"没有这个数"
    int binaryArray[] = {1, 8, 10, 89, 1000, 1234};
    //思路分析 先找到中间数 middleValue
    // middleValue>findValue left --
    // middleValue<findValue right++
    // middleValue=findValue index
    int len = sizeof(binaryArray) / sizeof(int);
    int binaryIndex = binarySearch(binaryArray,0,len-1,-89);
    printf("binaryIndex = %d \n", binaryIndex);
}