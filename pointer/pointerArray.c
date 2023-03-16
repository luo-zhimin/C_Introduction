#include <stdio.h>

const int Max = 3;
/**
 * <img src="https://cdn.nlark.com/yuque/0/2023/png/27601787/1678977275838-2b03e233-4646-4b83-ae02-cd32a0a04bca.png">
 */
void main() {

    /*
        要让数组的元素 指向 int 或其他数据类型的地址(指针)。可以使用指针数组

        定义
            数据类型 *指针数组名[大小]

            比如： int *ptr[3];
            ptr 声明为一个指针数组
            由 3 个整数指针组成。因此，ptr 中的每个元素，都是一个指向 int 值的指针。
     */

    int var[] = {10, 100, 200};
    int i, *ptr[3];
    for (i = 0; i < Max; i++) {
        ptr[i] = &var[i]; /* 赋值为整数的地址 */
    }

    for (i = 0; i < Max; i++) //指针数组来获取各个值
    {
        printf("Value of var[%d] = %d ptr[%d]本身的地址=%p\n", i, *ptr[i], i, &ptr[i]); // 10, 100, 200
    }

    //请编写程序，定义一个指向字符的指针数组来存储字符串列表(四大名著书名)， 并通过遍历 该指针数组，显示字符串信息

    char *books[] ={"三国演义", "西游记", "红楼梦", "水浒传"};
    char *sPtr = "三国演义";
    for (int j = 0; j < sizeof(books) / sizeof(books[0]); ++j){
        //books[j] 指向地址
        //&books[j] 指针本身地址
        printf("books[%d] 指向字符串是=%s,指向的内容是=%p,指向地址是=%p,本身地址是=%p\n",j,books[j],sPtr,books[j],&books[j]);
    }
}