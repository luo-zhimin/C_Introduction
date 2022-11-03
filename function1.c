//实现自己定义的h文件 头文件
double cal(double x, double y, char operation) {

    double result = 0.0;

    switch (operation) {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            result = x / y;
            break;
        default:
            break;
    }

    return result;
}