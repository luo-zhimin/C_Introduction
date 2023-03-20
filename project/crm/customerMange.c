#include <stdio.h>
#include <stdbool.h>

bool loop = true;
int key = 0;

//声明
void mainMenu();


void main() {

    //该软件能够实现对客户对象的插入、修改和删除（用数组实现），并能够打印客户明细表

    //调用
    mainMenu();
}

/**
 * 主菜单
 */
void mainMenu() {

    do {
        printf("--------------客户信息管理软件--------------\n");
        //menu
        printf("\t\t\t1.添加客户\t\t\t\n");
        printf("\t\t\t2.修改客户\t\t\t\n");
        printf("\t\t\t3.删除客户\t\t\t\n");
        printf("\t\t\t4.客户列表\t\t\t\n");
        printf("\t\t\t5.退   出\t\t\t\n");

        printf("请选择(1-5)：");
        scanf("%d", &key);
        //filter \n ''
        getchar();
        switch (key) {
            case 1:
                printf("添加客户\n");
                break;
            case 2:
                printf("修改客户\n");
                break;
            case 3:
                printf("删除客户\n");
                break;
            case 4:
                printf("客户列表\n");
                break;
            case 5:
                loop = false;
                break;
            default:
                printf("当前菜单不存在，请确认后重新操作！\n");
        }
    } while (loop);

    printf("退出客户信息管理软件～");
}