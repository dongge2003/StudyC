#include <stdio.h>
#include <string.h>
#include <errno.h>

//文件
//1. 程序文件:  源文件(**.c) 目标文件(**.obj) 可执行文件(**.exe)
//2. 数据文件:  文件的内容不一定是程序,而是程序运行时读写的数据


//文件名
//一个文件要有一个唯一的文件标识,以便用户识别和引用
//文件名: 文件路径+名主干+文件后缀
//例:  c:\code\test.txt


//文件缓冲区
//              ->输出缓冲区-> 输出 >
//程序数据区->                          磁盘
//              ->输入缓冲区-> 输入->


//文件指针
//缓冲文件系统中,关键的概念是"文件类型指针",简称"文件指针".
//每个被使用的文件都在内存中开辟了一个相应的文件信息区,用来存放文件的相关信息(如文件名字,文件状态及文件当前位置).
//这些信息保存在一个结构体变量中,该结构体类型是有系统声明的,取名FILE
/*
struct _iobuf 
{
    char *_ptr; //文件输入的下一个位置
    int _cnt; //当前缓冲区的相对位置
    char *_base; //指基础位置(应该是文件的其始位置)
    int _flag; //文件标志
    int _file; //文件的有效性验证
    int _charbuf; //检查缓冲区状况,如果无缓冲区则不读取
    int _bufsiz; //文件的大小
    char *_tmpfname;//临时文件名
};

typedef struct _iobuf FILE
//typedef - 重命名
*/





//文件的打开与关闭
//fopen - 打开文件
//FILE* fopen(const char* filename, const char* mode);
/*
filename -- 字符串，表示要打开的文件名称。
mode -- 字符串，表示文件的访问模式，可以是以下表格中的值：
------------------------------------------------------------------------------------------------------------------
模式	描述
"r" 	打开一个用于读取的文件。该文件必须存在。
"w" 	创建一个用于写入的空文件。如果文件名称与已存在的文件相同，则会删除已有文件的内容，文件被视为一个新的空文件。
"a" 	追加到一个文件。写操作向文件末尾追加数据。如果文件不存在，则创建文件。
"r+" 	打开一个用于更新的文件，可读取也可写入。该文件必须存在。
"w+" 	创建一个用于读写的空文件。
"a+" 	打开一个用于读取和追加的文件。
使用上面的模式说明符，文件将作为文本文件打开。
为了将文件作为二进制文件打开，模式字符串中必须包含“b”字符。
这个附加的“b”字符可以附加在字符串的末尾（从而形成以下复合模式：“rb”、“wb”、“ab”、“r+b”、“w+b”、“a+b”），
也可以插入在“+”符号之前（“rb+”、“wb+”、“ab+”）。
-------------------------------------------------------------------------------------------------------------------
该函数返回一个 FILE 指针。否则返回 NULL，且设置全局变量 errno 来标识错误。
*/

//fclose - 关闭文件
//int fclose(FILE* stream);

// int main()
// {
//     //打开文件
//     //相对路径(相对于当前文件)
//     //fopen("test.txt","r");
//     //绝对路径
//     //fopen("E:\\AAAAAAAAAAAAAAAAAAAAAAAAA\\code\\test.txt","r");

//     FILE* pf = fopen("test.txt","w");
//     if(pf == NULL)
//     {
//         printf("%s\n",strerror(errno));
//         return 0;
//     }

//     fclose(pf);
  
//     return 0;
// }





//
/*
功能                    函数名                  适用于            
字符输入函数            fgetc                   所有输入流
字符数出函数            fputc                   所有输出流
文本行输入函数          fgets                   所有输入流
文本行输出函数          fputs                   所有输出流
格式化输入函数          fscanf                  所有输入流
格式化输出函数          fprintf                 所有输出流
二进制输入              fread                   文件
二进制输出              fwrite                  文件
*/

/*
    fgetc 和 fputc: 这两个函数用于逐个字符地读取和写入文件。（一次读取（写入）一个）
        int fgetc(FILE *stream);
        int fputc(int character, FILE *stream);

    fgets：从指定文件中读取一行数据（包括换行符），并将其存储到指定的字符数组中。
    char *fgets(char *str, int n, FILE *stream);

    fputs：将指定的字符串写入到指定文件中。（一次写一行数据）
    int fputs(const char *str, FILE *stream);

    fscanf: 该函数用于从文件中按照指定的格式读取数据。
    int fscanf(FILE *stream, const char *format, ...);

    fprintf: 该函数用于向文件中按照指定的格式写入数据。
    int fprintf(FILE *stream, const char *format, ...);

    fread函数：
        size_t fread(void *ptr, size_t size, size_t count, FILE *stream);
        功能：从指定文件中读取二进制数据，并将其存储到指定的内存位置。
        参数：
            ptr：指向存储读取的数据的内存位置的指针。
            size：每个数据项的字节数。
            count：要读取的数据项的个数。
            stream：指向已打开文件的指针，表示从该文件中读取数据。
        返回值：返回实际成功读取的数据项数目，如果返回值少于count，则可能表示已到达文件末尾或发生了错误。

    fwrite函数：
    size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);
        功能：将二进制数据写入指定文件中。
        参数：
            ptr：指向要写入的数据的内存位置的指针。
            size：每个数据项的字节数。
            count：要写入的数据项的个数。
            stream：指向已打开文件的指针，表示将数据写入到该文件中。
        返回值：返回实际成功写入的数据项数目，如果返回值少于count，则可能表示发生了错误。
*/




//文件的顺序读写

// //写入文件 - fputc
// int main()
// {
//     //打开文件
//     FILE* pfwrite = fopen("test.txt", "w");
//     if(pfwrite == NULL)
//     {
//         printf("%s\n",strerror(errno));
//         return 0;
//     }

//     //写文件
//     fputc('h',pfwrite);
//     fputc('e',pfwrite);
//     fputc('l',pfwrite);
//     fputc('l',pfwrite);
//     fputc('o',pfwrite);

//     //关闭文件
//     fclose(pfwrite);
//     pfwrite = NULL;
//     //hello



//     return 0;
// }

// //读取文件 - fgetc
// int main()
// {
//     //打开文件
//     FILE* pfread = fopen("test.txt", "r");
//     if(pfread == NULL)
//     {
//         printf("%s\n",strerror(errno));
//         return 0;
//     }

//     //写文件
//     printf("%c\n",fgetc(pfread));
//     printf("%c\n",fgetc(pfread));
//     printf("%c\n",fgetc(pfread));
//     printf("%c\n",fgetc(pfread));
//     printf("%c\n",fgetc(pfread));

//     //关闭文件
//     fclose(pfread);
//     pfread = NULL;
//     // h
//     // e
//     // l
//     // l
//     // o

//     return 0;
// }




/*
键盘 - 标准输入设备 - stdin(类型:FILE*)
屏幕 - 标准输出设备 - stdout(类型:FILE* )
是一个程序默认打开的两个流设备
*/

// int main()
// {   
//     while (1)
//     {
//         int ch = fgetc(stdin);
//         fputc(ch,stdout);
//     }
//     return 0;
// }





// //读取文件 - fgets

// int main()
// {
//     char buff[1024] = {0};
//     FILE* pfrs = fopen("test.txt","r");
//     if(pfrs == NULL)
//     {
//         printf("%s\n",strerror(errno));
//         return 0;
//     }

//     fgets(buff,1024,pfrs);
//     printf("%s",buff);
//     fgets(buff,1024,pfrs);
//     puts(buff);
//     /*
//     把换行符也读取进去了,所以一般不加\n
//     */

//     fclose(pfrs);
//     pfrs = NULL;

//     return 0;
// }



// //写入文件 - fputs

// int main()
// {
//     char buff[1024] = {0};
//     FILE* pfws = fopen("test.txt","w");
//     if(pfws == NULL)
//     {
//         printf("%s\n",strerror(errno));
//         return 0;
//     }

//     fputs("hello\n",pfws);
//     fputs("world",pfws);
//     //fputs不会自动换行,所以要加上\n

//     fclose(pfws);
//     pfws = NULL;

//     return 0;
// }


// 格式化写入 - fprintf

// struct S
// {
//     int i;
//     float f;
//     char arr[10];
// };

// int main()
// {
//     struct S s = {199,3.14,"hello"};
//     FILE* fp = fopen("test.txt","w");
//     if(fp == NULL)
//     {
//         printf("%s\n",strerror(errno));
//         return 0;
//     }

//     fprintf(fp,"%d %f %s",s.i,s.f,s.arr);

//     fclose(fp);
//     fp = NULL;
//     return 0;
// }


// //格式化写入 - fscanf

// struct S
// {
//     int i;
//     float f;
//     char arr[10];
// };
// int main()
// {
//     struct S s = {0};
//     FILE* fp = fopen("test.txt","r");
//     if(fp == NULL)
//     {
//         printf("%s\n",strerror(errno));
//         return 0;
//     }

//     fscanf(fp,"%d %f %s",&(s.i),&(s.f),&(s.arr));//读取文件的内容写入到S结构体中
//     printf("%d %f %s",s.i,s.f,s.arr);

//     fclose(fp);
//     fp = NULL;
//     return 0;
// }


// struct S
// {
//     int i;
//     float f;
//     char arr[10];
// };
// int main()
// {
//     struct S s = {0};
//     fscanf(stdin,"%d %f %s",&(s.i),&(s.f),&(s.arr));
//     fprintf(stdout,"%d %f %s",s.i,s.f,s.arr);
    
//     return 0;
// }
/*
scanf/printf:   是针对标准输入流/输出流的 格式化输入/输出语句(键盘/屏幕)
fscanf/fprintf: 是针对所有输入流/输出流的 格式化输入/输出语句
sscanf/sprintf: sscanf是从字符串中读取格式化的数据
                sprintf是把格式化的数据输出成(储存到)字符串 
*/



// //文件二进制输入 - fread

// struct P
// {
//     char name[20];
//     int age;
//     double score;
// };

// int main()
// {
//     FILE* pf = fopen("test.txt","wb");
//     if(pf == NULL)
//     {
//         return 0;
//     }

//     //二进制写入
//     struct P p = {"zhangsan",18,65};
//     fwrite(&p,sizeof(struct P),1,pf);

//     fclose(pf);
//     return 0;
// }


// //二进制读取 - fwrite

// struct P
// {
//     char name[20];
//     int age;
//     double score;
// };

// int main()
// {
//     struct P tmp = {0};
//     FILE* pf = fopen("test.txt","rb");
//     if(pf == NULL)
//     {
//         return 0;
//     }

//     //二进制读取

//     fread(&tmp, sizeof(struct P), 1 ,pf);
//     printf("%s %d %f",tmp.name,tmp.age,tmp.score);
//     //zhangsan 18 65.000000

//     fclose(pf);
//     return 0;
// }








//文件的随机读写

// //fseek 
// //根据文件指针的位置和偏移量来定位文件指针
// //int fseek(FILE* stream , long offset ,int origin);
// //FILE* stream(文件指针)    long offset(偏移量(单位:字节))    
// //int origin(文件指针的当前位置):
// //1. SEEK_CUR(文件指针位置)      
// //2. SEEK_END(文件的末尾位置)
// //3. SEEK_SET(文件的起始位置)

// int main()
// {
//     FILE* pf = fopen("test.txt","r");
//     if(pf == NULL)
//     {
//         return 0;
//     }

//     //文件内容:abcdef
//     //1. 定位文件指针
//     fseek(pf,2,SEEK_CUR); 
//     //2. 读取文件
//     int ch = fgetc(pf);
//     printf("%c",ch);//c
    
//     fclose(pf);

//     return 0;
// }



// //ftell - 返回文件指针相对于起始位置的偏移量
// //long in ftell(FILE* stream);

// int main()
// {
//     FILE* pf = fopen("test.txt","r");
//     if(pf == NULL)
//     {
//         return 0;
//     }   
//     //文件内容:abcdeg
//     // fseek(pf,2,SEEK_CUR);
//     // int pos = ftell(pf);
//     // printf("%d",pos);//2 

//     // fseek(pf,0,SEEK_SET);
//     // int pos = ftell(pf);
//     // printf("%d",pos);//0
    
//     fseek(pf,0,SEEK_END);
//     int pos = ftell(pf);
//     printf("%d",pos);//6

//     fclose(pf);
//     pf = NULL;

//     return 0;
// }



// //rewind - 让文件指针的位置回到起始位置
// //void rewind(FILE* stream);

// int main()
// {
//     FILE* pf = fopen("test.txt","r");
//     if(pf == NULL)
//     {
//         return 0;
//     }   
 
//     fseek(pf,0,SEEK_END);
//     printf("%d",ftell(pf));//6
//     rewind(pf);
//     printf("%d",ftell(pf));//0

//     fclose(pf);
//     pf = NULL;
//     return 0;
// }






//文件结束的判断
//feof
//EOF - -1 -  end of file(文件结束标志)

// int main()
// {
//     FILE* pf = fopen("test.txt","r");
//     if(pf == NULL)
//     {
//         return 0;
//     }

//     //文件内容:空   
//     int ch = fgetc(pf);
//     printf("%d\n",ch);//-1

//     fclose(pf);
//     pf = NULL;

//     return 0;
// }
//牢记:在文件读取过程中,不能使用feof函数的返回值直接用来判读文件是否结束.
//而是应用于当文件读取结束的时候,判断是读取失败结束,还是遇到文件尾结束.
/*
1. 文本文件读取是否结束,判断返回值是否是EOF(fgetc),或者NULL(fgets)
2. 二进制文件的读取结束判断,判断返回值是否小于实际要读得个数
*/




// //perror - 自定义异常
// //void perror(const char *str);

// int main()
// {
//     FILE* pf = fopen("test2.txt","r");
//     if(pf == NULL)
//     {   
//         printf("%s\n",strerror(errno));//No such file or directory
//         perror("失败原因");//失败原因: No such file or directory
//     }

//     fclose(pf);
//     pf = NULL;

//     return 0;
// }






//

int main()
{

    return 0;
}







