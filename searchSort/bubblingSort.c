#include <stdio.h>

void bubblingSort(char array[],int len){
    //len-1 需要排序n-1轮
    int temp;
    for (int i = 0; i < len-1; ++i){
        for (int j = 0; j < len - 1 - i; ++j){
            if(array[j]>array[j+1]){
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}

/**
 *bobbling sort
 */
void main() {

    /*

        排序的分类：
             1) 内部排序: 指将需要处理的所有数据都加载到内部存储器(内存)中进行排序。
             2) 外部排序法： 数据量过大，无法全部加载到内存中，需要借助外部存储进行排序
         冒泡排序（Bubble Sorting）的基本思想是：通过对待 排序序列从前向后（从下标较小的元素开始）,依次比较 相邻元素的值，
            若发现逆序则交换，使值较大 的元素逐渐从前移向后部，就象水底下的气泡一样逐渐 向上冒
     */

    char array[] = {3, 9, -1, 10, -2};
    int len = sizeof(array) / sizeof(char);
    //sort
    bubblingSort(array,len);

    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
        printf("bubbling sort array = %d\n", array[i]);
    }
}