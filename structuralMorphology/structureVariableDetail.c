#include <stdio.h>
#include <string.h>

struct Dog {
    char *name;
    int age;
    double weight;
};

struct Box{
    int length;
    int weight;
    int height;
};

struct Visitor{
    //名字和年龄
    char name[10];
    int age;
//    double pay;
};

char *say(struct Dog dog);

int volume(struct Box *box);

void checkVisitor(struct Visitor *visitor);

void main() {

    //创建结构体的三种方式
    //1.先定义结构体，然后再创建结构体变量
    struct Student {
        char *name;
        int age;
        int number;
        char group;
        float score;
    } w = {"贾宝玉", 11, 18, 'B', 90.50};
//    struct Student s1,s2;

    //2.在定义结构体的同时定义结构体变量
//    struct Student{
//        int age;//...
//    }s1,s2;

    //3.该结构体数据类型，没有名, 匿名结构体
//    struct {
//        int age;//...
//    } s1, s2;

    //成员的获取和赋值
    //结构体 使用点号.获取单个成员。获取结构体成员的一般格式为 结构体变量名.成员名
    struct Student s1;
    s1.name = "jack";
    printf("s1 name = %s\n", s1.name);

    //在定义结构体变量时，整体赋值，需要对应
    struct Student s2 = {"林黛玉", 12, 16, 'A', 100};

    struct Student s3;
    //error
    //s3 = {"林黛玉", 12, 16, 'A', 100};
    printf("s2 name = %s\n", s2.name);
    printf("w name = %s\n", w.name);


    //application
    //编写一个 Dog 结构体，包含 name(char[10])、age(int)、weight(double)属性
    //编写一个 say 函数，返回字符串，方法返回信息中包含所有成员值
    struct Dog dog;
    char *speak = NULL;
    dog.name = "小黄";
    dog.age = 1;
    dog.weight = 3.4;
    speak = say(dog);
    printf("speak = %s\n", speak);
    //小黄
    printf("dog name = %s\n", dog.name);

    //编程创建一个 Box 结构体，在其中定义三个成员表示一个立方体的长、宽和高，长宽高可以通过控制台输入。
    //定义一个函数获取立方体的体积(volume)。 创建一个结构体，打印给定尺寸的立方体的体积
    int length,weight,height;
    printf("请输入长宽高：");
    scanf("%d %d %d",&length,&weight,&height);
    struct Box box = {length,weight,height};
    int volumeValue = volume(&box);
    printf("立方体的体积=%d\n",volumeValue);

    //一个景区根据游人的年龄收取不同价格的门票。
    //请编写游人结构体(Visitor)，根据年龄段决定能够购买的门票价格并输出
    //规则：年龄>18 , 门票为 20 元，其它情况免费。
    //可以循环从控制台输入名字和年龄，打印门票收费情况, 如果名字输入 n ,则退出程序
    struct Visitor visitor;

    while (1){
        printf("请输入您的名字：");
        scanf("%s",visitor.name);
        if(!strcmp(visitor.name,"n")){
            break;
        }
        printf("请输入您的年龄：");
        scanf("%d",&visitor.age);
        checkVisitor(&visitor);
    }
    printf("exit visitor~~\n");
}

char *say(struct Dog dog) {
    static char speak[50];
    //输出到字符串
    sprintf(speak, "dog name=%s,age=%d,weight=%.2f", dog.name, dog.age, dog.weight);
    dog.name = "小白";
    return speak;
}

int volume(struct Box *box){
    return (*box).length*(*box).weight*(*box).height;
}

//因为结构体默认是值传递，会拷贝一份完整数据，效率较低
// 因此，为了提高效率，我们直接接收地址(指针)
void checkVisitor(struct Visitor *visitor){
    if((*visitor).age>18){
        printf("visitor name=%s,age=%d,money=%d\n",(*visitor).name,(*visitor).age,20);
    } else{
        printf("visitor name=%s,age=%d,money=%d\n",(*visitor).name,(*visitor).age,0);
    }
}