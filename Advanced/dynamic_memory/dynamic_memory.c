#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>//动态内存函数头文件
#include <windows.h>


//栈区:局部变量,函数的形式参数
//堆区:动态内存分配
//静态区:全局变量,静态变量

// struct S
// {
//     char name[20];
//     int age;
// };

// int main()
// {
//     // int n = 0;
//     // scanf("%d",&n);
//     // struct S arr[n];
//     printf("%d",__STDC_VERSION__);//201710


        // int n = 0;
        // scanf("%d",&n);
        // int arr[n];
        // for(int i = 0;i < n;i++)
        // {
        //     arr[i] = i;
        // }
        // for(int i = 0;i < n;i++)
        // {
        //     printf("%d ",arr[i]);
        // }

//     return 0;
// }
// //这能编译过去是因为c语言在C99中增加了变长数组的功能




//c语言标准

// 如果是 #define __STDC_VERSION__ 199901L，则默认支持的是 C99 标准；
// 如果是 #define __STDC_VERSION__ 201112L，则默认支持的是 C11 标准；
// 如果是 #define __STDC_VERSION__ 201710L，则默认支持的是 C17 标准；
// 如果没查到，则默认支持的是 C89 标准。


//如果想在编译时指定 C 语言标准，可以使用 -std 选项参数进行指定
// -std=c17        # Conform to the ISO 2017 C standard
// -std=c11        # Conform to the ISO 2011 C standard
// -std=c99        # Conform to the ISO 1999 C standard
// -std=c90        # Conform to the ISO 1990 C standard
// -std=c89        # Conform to the ISO 1990 C standard
// -std=gnu17      # Conform to the ISO 2017 C standard with GNU extensions
// -std=gnu11      # Conform to the ISO 2011 C standard with GNU extensions
// -std=gnu99      # Conform to the ISO 1999 C standard with GNU extensions
// -std=gnu90      # Conform to the ISO 1990 C standard with GNU extensions
// -std=gnu89      # Conform to the ISO 1990 C standard with GNU extensions


//使用c89标准进行编译: gcc main.c -o test -std=c89 就会报错
// int main()
// {
//     for(int i = 0 ;i < 100;i++)
//     {
//         printf("%d\n",i);
//     }
//     return 0;
// }
//这是因为 C89 标准不支持在 for 循环中声明变量 i，
//指定 C99 标准再次编译则不会有问题:gcc main.c -o test -std=c89






// //malloc 和 free
// //void* malloc(size_t size);//开辟空间
// //void* free(void* ptr);//回收空间

// int main()
// {
//     //向内存申请10个整形的空间
//     int* p = (int*)malloc(10*sizeof(int));
//     //int* p = (int*)malloc(sizeof(INT_MAX));//INT_MAX 是很大的数
//     if(p == NULL)
//     {
//         printf("%s\n",strerror(errno));//打印错误原因的一个方式
//     }
//     else
//     {
//         //正常使用空间
//         int i = 0;
//         for(i = 0 ; i < 10 ;i++)
//         {
//             *(p + i ) = i;
//         }
//         for(i = 0 ; i < 10 ;i++)
//         {
//             printf("%d ",*(p + i));
//             //0 1 2 3 4 5 6 7 8 9
//         }
//     }
    
//     //当动态申请的空间不在使用的时候
//     //就应该还给操作系统
//     free(p);//主动回收开辟的空间
//     p = NULL;//让p变成空指针,这样就就找不到开辟的那块空间了,更安全


//     return 0;
// }






// //calloc
// //void* calloc(size_t num , size_t size);
// //函数的功能是为num个大小为size的元素开辟一块空间,并且把空间的每个字节初始化为0
// //与malloc的区别在于calloc会再返回地址之前把申请的空间每个字节都初始化为全0

// int main()
// {
//     //malloc(10 * sizeof(int));
//     //calloc(10 , sizeof(int));

//     int* p = (int*)calloc(10 , sizeof(int));
//     if(p == NULL)
//     {
//         printf("%s\n",strerror(errno));
//     }
//     else
//     {
//         int i = 0;
//         for(i = 0 ; i < 10 ;i++)
//         {
//             printf("%d ",*(p + i));
//             //0 0 0 0 0 0 0 0 0 0
//             //malloc 与 calloc 的区别就是calloc会把空间初始化为0 
//         }
//     }
//     //释放空间
//     //free是用来释放动态开辟的空间的
//     free(p);
//     p = NULL;

//     return 0;
// }








// //realloc - 调整动态开辟内存的大小
// //void* realloc(void* ptr , size_t size);
// //ptr 是要调整的内存地址
// //size 调整之后的大小
// //返回值为调整之后的内存起始地址
// //这个函数调整原内存空间的大小的基础上,还会将原来内存中的数据移动到 新 的空间
// //

// //realloc函数可以做到对动态开辟内存大小的调整
// //realloc函数的出现让动态内存管理更加灵活

// int main()
// {
//     // int* p = (int*)malloc(10 * sizeof(int));

//     // if(p == NULL)
//     // {
//     //     printf("%s\n",strerror(errno));
//     // }
//     // else
//     // {
//     //     for(int i = 0;i < 10;i++)
//     //     {
//     //         *(p + i) = i;
//     //     }
//     //     for(int i = 0;i < 10;i++)
//     //     {
//     //         printf("%d ",*(p + i));
//     //     }

        
//     //     //追加30个整形的空间
//     //     int* p2 = realloc(p,40);
//     //     //如果还需要用p接收新的空间
//     //     /*
//     //         int* ptr = realloc(p,40);
//     //         if(ptr != NULL)
//     //         {
//     //         p = ptr;
//     //         }
//     //     */

//     //     for(int i = 0;i < 40 ;i++)
//     //     {
//     //         *(p2 + i) = i;
//     //     }
//     //     for(int i = 0;i < 40;i++)
//     //     {
//     //         printf("%d ",*(p2 + i));
//     //     }
//     // }

//     //      free(p2);

//     //realloc函数使用注意事项:
//     //1. 如果p指向的空间之后有足够的内存空间可以追加,则直接追加,后返回p
//     //2. 如果p指向的空间之后没有足够的空间可以追加,则realloc函数会重新在内存中找到一块空间开辟
//     //   并且将原来空间的内容复制过来,释放原来内存的空间,最后返回新开辟空间的内存地址
//     //3. 得用一个新的变量来接受realloc函数的返回值

//     return 0;
// }






//常见的动态内存分配错误

// //1. 对空指针进行解引用操作 
// int main()
// {
//     int* p = (int*)malloc(40);
//     //如果malloc分配失败,p就是空指针
//     //再进行使用时,前面一定要进行返回值的判断,如果为空指针,则不能使用

//     for(int i = 0;i < 10;i++)
//     {
//         *(p + i) = i;
//     }
//     return 0;
// }

// //2. 对动态开辟内存的越界访问
// int main(){
//     int* p = (int*)malloc(5 * sizeof(int));
//     if(p == NULL){
//         return 0;
//     }
//     else{
//         for(int i = 0;i < 10;i++){
//             //只开辟了5块int类型,但访问了10块
//             *(p + i) = i;
//         }
//     }

//     return 0;
// }

// //3. 对非动态开辟内存的free
// int main(){
//     int a = 10;
//     int* p = &a;
//     *p = 20;
//     free(p);

//     return 0;
// }

// //4. 使用free释放动态开辟内存的一部分
// int main(){
//     int* p = (int*)malloc(40);
//     if(p == NULL){
//         return 0;
//     }
//     for(int i = 0;i < 10;i++){
//         *p++ = i;
//     }
//     free(p);//free失败
//     p = NULL;
//     //free只能从开辟空间的起始位置释放,不能从别的地方进行释放
    
//     return 0;
// }

// //5. 对同一块动态内存的多次释放
// int main(){
//     int* p = (int*)malloc(40);
//     if(p == NULL){
//         return 0;
//     }
//     //使用
//     //释放
//     free(p);
//     //........
//     free(p);

//     /*如何避免:
//     free(p);
//     p = NULL;
//     //p设置成空指针之后,再释放也没用
//     free(p);
//     */

//     return 0;
// }

// //6. ***对动态开辟内存忘记释放(内存泄漏)***
// int main(){
//     //***非常错误的行为***
//     while (1)
//     {
//         malloc(1);
//         //Sleep(10);
//     }
//     //内存会疯狂开辟空间,直到内存占满
    
//     return 0;
// }






// //笔试题:

// //1.
// void* GetMemory(char* p)
// //void* GetMemory(char** p)
// {
//     p = (char*)malloc(100);
//     //*p = (char*)malloc(100);
    
// }
// void Test(void)
// {
//     char *str = NULL;
//     GetMemory(str);
//     //GetMemory(&str);
//     strcpy(str ,"hello world");
//     printf(str);//和printf("%s\n",str);一样
// }
// int main()
// {
//     Test();
//     return 0;
// }
// /*
// 1.形参是实参的临时拷贝,str和p没关系
// 2.开辟的空间没有回收,函数结束形参消失后,没有开辟空间的地址,所以会造成(内存泄漏)
// 3.给strcpy函数传递了一个空指针,所以程序崩溃
// */


// //2.
// void test(void)
// {
//     char *str = (char*)malloc(100);
//     strcpy(str , "hello");
//     free(str);//free释放之后,并不会将str置成空指针
//     //str = NULL;

//     if(str != NULL)
//     {
//         strcpy(str , "world");
//         printf(str);
//     }
//     /*
    
//     */
// }
// int main()
// {
//     test();
//     return 0;
// }
// /*
// 1. 野指针,非法访问内存
// 2.free释放之后,并不会置成空指针
// */


//内存分布说明:
//1. 内核空间： 放置操作系统相关的代码和数据。（用户不能直接进行操作 ------ 可以通过调用系统提供的 api 函数）
//2. 栈又叫堆栈，非静态局部变量/函数参数/返回值等等，栈是向下增长的。
//3. 内存映射段是高效的I/O映射方式，用于装载一个共享的 动态内存库。用户可使用系统接口创建共享共享内存，做进程间通信。
//4. 堆用于程序运行时动态内存分配，堆是可以上增长的。
//5. 数据段–存储全局数据和静态数据。
//6. 代码段–可执行的代码/只读常量。

//内存区域：栈、堆、全局区、常量区、代码区
//1. 栈：系统自动分配的空间，只要不特殊声明，就定义在栈区，函数的区域也在栈上。栈是向下增长的。（const 在栈里）
//2. 堆：使用动态内存分配的方式可以申请堆空间，用完要手动释放。
//3. 全局区：全局变量、静态变量（static）
//4. 常量区：代码中的数字，字符等常量，例如’a’，—1.2等
//5. 代码区：存放可执行代码，避免频繁的读硬盘。
//6. Data:数据段，要放在可执行文件中的数据，包括堆、栈、以初始化的全局变量
//7. Bss: 未初始化的全局变量，不占用可执行文件的大小
//8. Text: 只读区域，包括常量区和代码区






// //柔性数组 - 数组的大小是可以调整的
// //c99中,结构中最后一个元素允许是未知大小的数组,这叫做[柔性数组]成员

//1.
// struct S
// {
// 	int n;
// 	int arr[0];//未知大小 - 柔性数组成员 - 数组的大小是可以调整的
// };

// int main()
// {
// 	//struct S s1;
// 	//printf("%d \n",sizeof(s1));//4 - arr[] 占 0 字节

// 	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));//24个字节
// 	/*
// 	sizeof(struct S)大小是4 - int n的4个字节的空间  
// 	而5 * sizeof(int) 就是为int arr[]柔性数组成员开辟的20(5个整形)个字节的空间
// 	*/

// 	ps->n = 100;
// 	for(int i = 0;i < 5 ; i++)
// 	{
// 		ps->arr[i] = i;
// 	}

// 	printf("%d\n",ps->n);//100
// 	for(int i = 0;i < 5 ; i++)
// 	{
// 		printf("%d ",ps->arr[i]);
// 	}
// 	//0 1 2 3 4

// 	//追加
// 	struct S* pss = realloc(ps,4 + 20*sizeof(int));
// 	if(pss != NULL)
// 	{
// 		ps = pss;
// 	}
// 	for(int i = 5;i < 20 ; i++)
// 	{
// 		ps->arr[i] = i;
// 	}
// 	for(int i = 0;i < 20 ; i++)
// 	{
// 		printf("%d ",ps->arr[i]);
// 	}
	
// 	//释放
// 	free(ps);
// 	ps = NULL;

// 	return 0;
// }


// 2.
// struct S
// {
// 	int n;
// 	int* arr;//通过指针达到同样效果
// };
// int main()
// {
// 	struct S s;
// 	struct S* ps = (struct S*)malloc(sizeof(struct S));
// 	ps->arr = (int* )malloc(5 * sizeof(int));

// 	初始化
// 	ps->n = 99;
// 	for(int i = 0;i < 5;i++)
// 	{
// 		ps->arr[i] = i;
// 	}
// 	printf("%d\n",ps->n);//99
// 	for(int i = 0;i < 5;i++)
// 	{
// 		printf("%d ",ps->arr[i]);
// 	}
// 	0 1 2 3 4 

// 	追加
// 	struct S* pss = realloc(ps , 4 + 10 * sizeof(int));
// 	if(pss != NULL)
// 	{
// 		ps = pss;
// 	}
// 	for(int i = 0;i < 10;i++)
// 	{
// 		ps->arr[i] = i;
// 	}
// 	for(int i = 0;i < 10;i++)
// 	{
// 		printf("%d ",ps->arr[i]);
// 	}
	
// 	释放
// 	free(ps->arr);
// 	ps->arr = NULL;
// 	free(ps);
// 	ps = NULL;

// 	return 0;
// }

//柔性数组的优势：
//1. 方便内存释放
//2. 有利于提升访问速度(柔性数组在内存中是连续的，也有利于减少内存碎片化)




main(){
      int x=0,y[14],*z=&y;*(z++)=0x48;*(z++)=y[x++]+0x1D;
      *(z++)=y[x++]+0x07;*(z++)=y[x++]+0x00;*(z++)=y[x++]+0x03;
      *(z++)=y[x++]-0x43;*(z++)=y[x++]-0x0C;*(z++)=y[x++]+0x57;
      *(z++)=y[x++]-0x08;*(z++)=y[x++]+0x03;*(z++)=y[x++]-0x06;
      *(z++)=y[x++]-0x08;*(z++)=y[x++]-0x43;*(z++)=y[x]-0x21;
      x=*(--z);while(y[x]!=NULL)putchar(y[x++]);
    }




























































































