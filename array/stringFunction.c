#include <stdio.h>
#include <string.h>

/**
 * 字符串函数<br>
 * <img src="https://cdn.nlark.com/yuque/0/2023/png/27601787/1678720521883-674c41c0-8edb-4c4e-9639-d7b662814c65.png">
 */
void main(){

    char a[10] ="Hello";
    char b[10]="Word";
    char c[10];

    //strcpy=>copy
    //(dest,source)
    strcpy(c,a);
    printf("c=%s\n",c);

    //strcat=>concat
    strcat(a,b);
    printf("a=%s\n",a);
    //strcmp=>equals
    printf("is equals=%d\n",strcmp(a,b));
    //strchr(str,char)=>index
    printf("strchr=%s\n",strchr(a,'H'));
    //strstr(str,str)->index
    printf("strstr=%s\n",strstr(a,b));
}