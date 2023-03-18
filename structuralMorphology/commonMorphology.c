#include <stdio.h>

//总人数
const int total = 2;

//共用体
union MyUnion{
    double score;
    char course[20];
};

//结构体
struct Person {
    char name[20];
    int num;
    char sex;
    //s->student t->teacher
    char profession;
    //共用体
//    union {
//        double score;
//        char course[20];
//    } sc;
    union MyUnion sc;
};


/**
 * common morphology <br>
 * <img src="https://cdn.nlark.com/yuque/0/2023/png/27601787/1679158705939-856ea18e-d113-42eb-8bfa-41a3a0c004ce.png"><br>
 * <img src="https://cdn.nlark.com/yuque/0/2023/png/27601787/1679159511791-bbad392a-2d99-4b44-a089-f9e96bd8f710.png"><br>
 */
void main() {

    /*
        共用体（Union）属于 构造类型，它可以包含多个类型不同的成员。和结构体非常类似, 但是也有不同的地方. 共用体有时也被称为联合或者联合体, 定义格式为
            union 共用体名
            {
                成员列表
            };

        结构体和共用体的区别在于：结构体的各个成员会占用不同的内存，互相之间没有影响；而共用体的所有成员 占用同一段内存，修改一个成员会影响其余所有成员
     */


    //共用体和结构体的创建一样有3种

    union data {
        //data 就是一个共用体(内存布局)， 包含三个成员, 共享数据空间, 该空间的大小以占用最大的成员为准
        int n;//4 byte
        char ch;//2 byte
        short m;//1 byte
    };

    union data a;
    printf("%d, %d\n", sizeof(a), sizeof(union data));//4,4
    //0x40=> 0100 0000
    a.n = 0x40;//16 进制  ==> 64, @, 64  @=>64=>ASIC
    printf("%d, %c, %d\n", a.n, a.ch, a.m);
    //'9'=> 0011 1001 =>57
    a.ch = '9';//57, 9, 57
    printf("%d, %c, %d\n", a.n, a.ch, a.m);
    a.m = 0x2059;//8281, Y, 8281
    printf("%d, %c, %d\n", a.n, a.ch, a.m);
    a.n = 0x3E25AD54;//1042656596, T, -21164
    printf("%d, %c, %d\n", a.n, a.ch, a.m);

    printf("-----------\n");

    //person array
    struct Person persons[total];

    //输入人员信息
    for (int i = 0; i < total; i++) {
        printf("Input info: ");
        scanf("%s %d %c %c", persons[i].name, &(persons[i].num), &(persons[i].sex), &(persons[i].profession));
        if (persons[i].profession == 's') {
            //如果是学生
            printf("请输入该学生成绩:");
            scanf("%lf", &persons[i].sc.score);
        } else {
            //如果是老师
            printf("请输入该老师课程:");
            scanf("%s", persons[i].sc.course);
        }
        fflush(stdin);//刷新
    }
    //输出人员信息
    printf("\nName\t\tNum\tSex\tProfession\tScore / Course\n");
    for (int i = 0; i < total; i++) {
        if (persons[i].profession == 's') {
            //如果是学生
            printf("%s\t\t%d\t%c\t%c\t\t%f\n", persons[i].name, persons[i].num, persons[i].sex, persons[i].profession,
                   persons[i].sc.score);
        } else {
            //如果是老师
            printf("%s\t\t%d\t%c\t%c\t\t%s\n", persons[i].name, persons[i].num, persons[i].sex, persons[i].profession,
                   persons[i].sc.course);
        }
    }
}