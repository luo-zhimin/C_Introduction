//
// Created by 罗志敏 on 2023/3/19.
//

#include <stdio.h>

void main(){
    int i =0;
    char key =' ';
    int loop = 1;
    do {
        printf("1111\n");
        scanf("%c",&key);
        getchar();
        switch (key) {
            case '1':
                break;
            case 2:
                loop=0;
                break;
        }
        i++;
    } while (loop);
}