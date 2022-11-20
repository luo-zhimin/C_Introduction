#include <stdio.h>
#include <string.h>
//系统函数
int main(){

    //字符串
    //length copy concat
    char name[30] = "测试字符串函数";
    printf("name length[%lu]\n",strlen(name));
    //init constant
    char src[30],dest[30];
    strcpy(src,"hello");
    strcpy(dest," string copy function");
    printf("string copy [%s]\n",dest);
    strcat(src,dest);
    printf("string concat src[%s]",src);
    return 0;
}