#include <stdio.h>
#include "./function.h"

int main() {

    printf("function");

    double add = cal(1,4,'+');

    printf("\nadd %.2f",add);
    return 0;
}

void sayName(){
    printf("clion second function~");
}