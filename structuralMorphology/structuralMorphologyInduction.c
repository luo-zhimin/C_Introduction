#include <stdio.h>
#include <string.h>

/**
 * structural morphology <==>java object
 * /ˈstrʌktʃərəl mɔːˈfɒlədʒi/
 * <br>
 * 内存布局 memory layout <br>
 * <img src="https://cdn.nlark.com/yuque/0/2023/png/27601787/1679147986277-2e148951-b18e-4ad8-a385-4959d5cecfb5.png">
 */
void main() {

    /*
        张老太养了两只猫猫:一只名字叫小白,今年 3 岁,白色。还有一只叫小花,今年 100 岁,花色。
        请编写一个程序，当用户输入小猫的名字时，就显示该猫的 名字，年龄，颜色。
        如果用户输入的小猫名错误，则显示 张老太没有这只猫猫
     */

    //传统方案 不利于数据维护

    /*
        结构体是自定义的数据类型，表示的是一种数据类型
        结构体变量代表一个具体变量
            int num1 ; // int 是数据类型, 而 num1 是一个具体的 int 变量
            struct Cat cat1; // Cat 是结构体数据类型， 而 cat1 是一个 Cat 变量
        Cat 就像一个“模板”，定义出来的结构体变量都含有相同的成员。也可以将结构体比作“图纸”，将结构体 变量比作“零件”，根据同一张图纸生产出来的零件的特性都是一样的

        声明结构体==>java class(Object)
        struct 结构体名称 {// 结构体名首字母大写，比如 Cat, Person
            成员列表;
        };

        成员
            从叫法上看：有些书上称为成员, 有些书说 结构体包含的变量
            成员是结构体的一个组成部分，一般是基本数据类型、也可以是数组、指针、结构体等 。
        注意事项
            成员声明语法同变量，示例： 数据类型 成员名;
            字段的类型可以为：基本类型、数组或指针、结构体等
            在创建一个结构体变量后，需要给成员赋值，如果没有赋值就使用可能导致程序异常终止(!!)
            不同结构体变量的成员是独立，互不影响，一个结构体变量的成员 更改，不影响另外一个
     */

    //创建结构体---数据类型
    struct Cat {// 结构体名字建议首写字母大写
        char *name;//名字--指针
        int age;//年龄
        char *color;//颜色
    };

    //使用结构体创建变量
    struct Cat cat1;
    struct Cat cat2;

    cat1.name = "小白";
    cat1.age = 3;
    cat1.color = "白色";

    cat2.name = "小花";
    cat2.age = 100;
    cat2.color = "花色";

    char name[10] = "";
    scanf("%s", name);

    if (strcmp("小白", name) == 0) {
        printf("name=%s age=%d color=%s\n", cat1.name, cat1.age, cat1.color);
    } else if (strcmp("小花", name) == 0) {
        printf("name=%s age=%d color=%s\n", cat2.name, cat2.age, cat2.color);
    } else {
        printf("张老太没有这只猫猫\n");
    }

    //在创建一个结构体变量后，需要给成员赋值，如果没有赋值就使用可能导致程序异常终止(!!)
    //会有默认值？？？？
    struct Cat cat3;
    //error exception no init struct variable => struct variable hava default value
    printf("name=%s age=%d color=%s\n", cat3.name, cat3.age, cat3.color);
}