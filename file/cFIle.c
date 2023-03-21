#include <stdio.h>
#include <string.h>

char sourcePath[88] = "/Users/luozhimin/Desktop/File/picture/daily";

/**
 * 文件操作<br>
 * <img src="https://cdn.nlark.com/yuque/0/2023/png/27601787/1679325640862-1cfaf580-bdf2-43db-b89b-97b02db0eb57.png">
 */
void main(){

    //!!!如何创建、打开、关闭文本文件或二进制文件

    //一个文件，无论它是文本文件还是二进制文件，都是代表了一系列的字节。C 语言不仅提供了访问顶层的函数， 也提供了底层（OS）调用来处理存储设备上的文件
    //打开文件

    //使用 fopen( ) 函数来创建一个新的文件或者打开一个已有的文件，这个调用会初始化类型 FILE 的一个对象， 类型 FILE 包含了所有用来控制流的必要的信息。下面是这个函数调用的原型：
    //FILE *fopen( const char * filename, const char * mode );
    //说明：在这里，filename 是字符串，用来命名文件，访问模式 mode 的值可以是下列值中的一个
    //如果处理的是二进制文件(图片，视频..)，则需使用下面的访问模式: "rb", "wb", "ab", "rb+", "r+b", "wb+", "w+b", "ab+", "a+b" //b :binary 二进制

    //关闭文件
    //关闭文件，使用 fclose( ) 函数。函数的原型如下：
    // int fclose( FILE *fp );
    //如果成功关闭文件，fclose( ) 函数返回零，如果关闭文件时发生错误，函数返回 EOF。这个函数实际上，会清 空缓冲区中的数据，
    // 关闭文件，并释放用于该文件的所有内存。EOF 是一个定义在头文件 stdio.h 中的常量。
    //C 标准库提供了各种函数来按字符或者以固定长度字符串的形式读写文件
    //使用完文件后(读，写)，一定要将该文件关闭

    //写入文件 int fputc( int c, FILE *fp );
    //说明：函数 fputc() 把参数 c 的字符值写入到 fp 所指向的输出流中。如果写入成功，它会返回写入的字符， 如果发生错误，则会返回 EOF。
    // 您可以使用下面的函数来把一个以 null 结尾的字符串写入到流中： int fputs( const char *s, FILE *fp )
    //：函数 fputs() 把字符串 s 写入到 fp 所指向的输出流中。如果写入成功，它会返回一个非负值，如果发生 错误，则会返回 EOF。您也可以使用
    // int fprintf(FILE *fp,const char *format, ...) 函数来写把一个字符串写入到文件中

    FILE  *fb = NULL;
    strcat(sourcePath,"/Ctest.text");
    printf("sourcePath=%s\n",sourcePath);
    //!! w+ truncate Rewrite
//    fb = fopen(sourcePath,"w+");
    //append
    fb = fopen(sourcePath,"a+");
    //将内容写入文件中
    fprintf(fb,"你好，C程序写入fprintf\n");
    fputs("fputs写入\n",fb);

    //!!!关闭文件 不关闭我们写的内容没有保存到文件
    fclose(fb);
    printf("write finish~\n");

    //读取文件
    /*
        读取单个字符的函数
            int fgetc( FILE * fp );
                fgetc() 函数从 fp 所指向的输入文件中读取一个字符。返回值是读取的字符，如果发生错误则返回 EOF
            char *fgets( char *buf, int n, FILE *fp )
                函数 fgets() 从 fp 所指向的输入流中读取 n - 1 个字符。它会把读取的字符串复制到缓冲区 buf，并在 最后追加一个 null 字符来终止字符串
                如果这个函数在读取最后一个字符之前就遇到一个换行符 '\n' 或文件的末尾 EOF，则只会返回读取到的字符， 包括换行符
                也可以使用 int fscanf(FILE *fp, const char *format, ...) 函数来从文件中读取字符串，但是在遇到第一个空格字符时，它会停止读取
     */

    FILE *read = NULL;
    //定义一个缓冲区
    char buff[1024];
    //打开文件
    read = fopen(sourcePath,"r");
    //1.读取一行
    //fscanf(read,"%s",buff);

    //读取整个文件
    //循环读取 read指向的内容 一直读取到NULL 就结束
    while (fgets(buff,1024,read)!=NULL){
        //输出
        printf("%s\n",buff);
    }
    //fgets(buff,1024,read);

    fclose(read);
}
