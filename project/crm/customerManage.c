#include <stdio.h>
#include <stdbool.h>

//循环控制
bool loop = true;
//键盘输入值
int key = 0;
//当前多少客户
int customerNumber = 0;
//选择的条件
char choose = ' ';
//编号
int order;

//定义客户结构体
struct Customer {
    //编号
    int id;
    int age; //年龄
    char name[10]; //名字
    char gender; // 'f' 女 'm' 男
    char phone[11]; //电话号码
    char email[20]; //邮箱
};

//最多100个客户->可以拓展
struct Customer customers[100];

/**
 * 主菜单
 */
void mainMenu();

/**
 * 详情展示
 */
void show();

void getCustomerInfo(struct Customer *customer);

void addCustomer();

int findCustomerId(int id);

void editCustomer();

void deleteCustomer();

void customerExit();

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
                addCustomer();
                break;
            case 2:
                editCustomer();
                break;
            case 3:
                deleteCustomer();
                break;
            case 4:
                show();
                break;
            case 5:
                customerExit();
                break;
            default:
                printf("当前菜单不存在，请确认后重新操作！\n");
        }
    } while (loop);

    printf("退出客户信息管理软件～");
}

void show() {
    printf("-----------------客户列表------------------\n");
    printf("编号\t\t姓名\t\t性别\t\t年龄\t\t电话\t\t\t邮箱\n");
    for (int i = 0; i < customerNumber; ++i) {
        getCustomerInfo(&customers[i]);
    }
}

void getCustomerInfo(struct Customer *customer) {
    printf("%d\t\t%s\t\t%c\t\t%d\t\t%s\t\t%s\n",
           (*customer).id, (*customer).name, (*customer).gender,
           (*customer).age, (*customer).phone, (*customer).email);
}

void addCustomer() {
    printf("-----------------添加客户------------------\n");
    //auto
    customers[customerNumber].id = customerNumber + 1;
    printf("姓名: ");
    scanf("%s", customers[customerNumber].name);
    getchar();

    printf("性别: ");
    scanf("%c", &customers[customerNumber].gender);
    getchar();

    printf("年龄: ");
    scanf("%d", &customers[customerNumber].age);
    getchar();

    printf("电话: ");
    scanf("%s", customers[customerNumber].phone);
    getchar();

    printf("邮箱: ");
    scanf("%s", customers[customerNumber].email);
    getchar();

    customerNumber++;
    printf("-----------------添加完成------------------\n");
}

int findCustomerId(int id) {
    int index = -1;
    for (int i = 0; i < customerNumber; ++i) {
        if (customers[i].id == id) {
            index = i;
            break;
        }
    }
    return index;
}

void editCustomer() {
    printf("-----------------修改客户------------------\n");
    printf("请选择待修改的客户编号(-1退出)：");
    scanf("%d", &order);
    getchar();
    if (order == -1) {
        return;
    }

    int index = findCustomerId(order);
    //-1 exit
    if (index == -1) {
        printf("用户不存在无修改\n");
        return;
    }

//    char temp;
    //todo <直接回车表示不修改> 待改
    printf("姓名(%s): ", customers[index].name);
    scanf("%s", customers[index].name);

//    printf("temp=%c\n",temp);

    printf("性别(%c): ", customers[index].gender);
    scanf("%c", &customers[index].gender);
    getchar();

    printf("年龄(%d): ", customers[index].age);
    scanf("%d", &customers[index].age);
    getchar();

    printf("电话(%s): ", customers[index].phone);
    scanf("%s", customers[index].phone);
    getchar();

    printf("邮箱(%s): ", customers[index].email);
    scanf("%s", customers[index].email);
    getchar();

    printf("-----------------修改完成------------------\n");
}

void deleteCustomer() {
    printf("-----------------删除客户------------------\n");
    printf("请选择待删除的客户编号(-1退出)：");
    scanf("%d", &order);
    getchar();
    if (order == -1) {
        return;
    }
    printf("确认是否删除(Y/N)：");
    scanf("%c", &choose);
    getchar();
    if (choose == 'N') {
        return;
    }
    int index = findCustomerId(order);
    //-1 exit
    if (index == -1) {
        printf("用户不存在无法删除\n");
        return;
    }
    //customers 数组从 index +1 位置 开始，整体前移
    for (int i = index + 1; i < customerNumber; ++i) {
        customers[index - 1] = customers[i];
    }
    customerNumber--;
    printf("-----------------删除完成------------------\n");
}

void customerExit() {
    //确认是否退出(Y/N)："，用户必须输入 Y/N, 否则循环提示
    do {
        printf("确认是否退出(Y/N)：");
        scanf("%c", &choose);
        getchar();
    } while (choose != 'N' && choose != 'Y');
    if (choose == 'Y') {
        loop = false;
    }
}