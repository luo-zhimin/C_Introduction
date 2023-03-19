#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//是否退出循环
bool flag = true;
double money = 0;
//!!
char temp[100];
/**
 * 收支明细
 */
struct order {
    //收支
//    char name[20];
    int flag;
    //账号金额
    double accountMemory;
    //说明
    char remark[30];
    //!!
    char details[1000];
};

/**
 * show detail
 * @param order order array
 * @param size order size
 */
void show(struct order *order) {
    if ((*order).flag <= 0) {
        printf("当前没有收支明细... 来一笔吧!\n");
    } else {
        printf("收支\t\t收支金额\t\t账号金额\t\t说明\n");
//            printf("%s\t\t%.2f\t\t%.2f\t\t%s\n", order[i].name, order[i].memory, order[i].accountMemory,
//                   order[i].remark);
        printf("%s", (*order).details);
    }
}

void menuExit() {
    char choose[2] = "";
    int outPut = 1;
    while (outPut) {
        printf("确认是否退出(Y?N): ");
        scanf("%s", choose);
        getchar();
        //只有Y.N 进来
        if (!strcmp(choose, "N") || !strcmp(choose, "Y")) {
            outPut = 0;
        }
        if (!strcmp(choose, "Y")) {
            //exit
            flag = false;
        }
    }
}

/**
 * 收入
 * @param order
 */
void addMoney(struct order *order) {
//    order->name="收入";
//    (*order).name = "收入";
    printf("本次收入金额：");
    scanf("%lf", &money);
    //更新余额
    (*order).accountMemory += money;
    getchar();
    printf("本次收入说明：");
    scanf("%s", (*order).remark);
    getchar();
    sprintf(temp, "收入\t\t%.2f\t\t%.2f\t\t%s\n", money, (*order).accountMemory, (*order).remark);
    strcat((*order).details, temp);
    (*order).flag = 1;
}

/**
 * 支出
 * @param order
 */
void addPay(struct order *order) {
    printf("本次支出金额：");
    scanf("%lf", &money);
    if ((*order).accountMemory - money <= 0) {
        printf("余额不足，请检查后重新消费\n");
        //!! getchar
        getchar();
    } else {
        //更新余额
        (*order).accountMemory -= money;
        getchar();
        printf("本次支出说明：");
        scanf("%s", (*order).remark);
        getchar();
        sprintf(temp, "支出\t%.2f\t\t%.2f\t\t\t%s\n", money, (*order).accountMemory, (*order).remark);
        strcat((*order).details, temp);
        (*order).flag = 1;
    }
}

void main() {
    char key = ' ';
    struct order order;

    do {
        printf("\n--------------家庭收支记账软件--------------\n");
        //menu
        printf("\t\t\t1.收支明细\t\t\t\n");
        printf("\t\t\t2.登记收入\t\t\t\n");
        printf("\t\t\t3.登记支出\t\t\t\n");
        printf("\t\t\t4.退出\t\t\t\n");

        printf("\t\t\t请选择(1-4): ");
        scanf("%c", &key);
        //过滤空格
        getchar();
        switch (key) {
            case '1':
                //show
                show(&order);
                break;
            case '2':
                //收入
                addMoney(&order);
                break;
            case '3':
                //支出
                addPay(&order);
                break;
            case '4':
                menuExit();
                break;
            default:
                printf("该菜单不存在～\n");
        }
    } while (flag);

    printf("exit~~family~~system!");
}