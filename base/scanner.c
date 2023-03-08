#include <stdio.h>

//键盘输入
int main(){
    //接受名字
    char name[10] ="";
    int age =0;
    double salary = 0.0;
    char gender =' ';

    printf("请输入名字:");
    //接收字符串 放到name
    scanf("%s",name);
    printf("请输入年龄:");
    //存放到age的地址中
    scanf("%d",&age);
    printf("请输入薪水:");
    scanf("%lf",&salary);
    printf("请输入性别（m/w）:");//接收到了上面的回车
    scanf("%c",&gender);
    scanf("%c",&gender);

    printf("得到name %s age %d salary %.2f gender %c\n",name,age,salary,gender);

    //exercise
    //定义变量保存 秒数，打印输出 xx 小时 xx 分钟 xx 秒
    int seconds = 0;
    printf("请输入秒时间:");
    scanf("%d",&seconds);
    int minute = seconds/60;
    int hour = seconds/3600;
    int leftSecond = seconds % 60;
    printf("%d 小时 %d 分钟 %d 秒",hour,minute,seconds);
    return 0;
}