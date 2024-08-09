//字符串函数

#include <stdio.h> 
#include <string.h>
#include <assert.h>	//assert函数的头文件
#include <errno.h>	//errno全局变量的头文件
#include <ctype.h> 	//字符串分类函数的头文件


//strlen - 求字符串长度
//size_t strlen ( const char * str);


// //1. 计算器方法
// int my_strlen1(char* str)
// {
	// int cont = 0;
	// while(*str != '\0')
	// {
		// cont++;
		// str++;
	// }
	// return cont;
// }

// //2.递归——不创建临时变量如：cont
// //传入数组首地址，判断元素是否为'\0'，如果是，返回0，如果不是返回1+（函数调用）
// int my_strlen2(char* str)
// {
	// if(*str == '\0')
	// {
		// return 0;
	// }
	// else
	// {
		// return 1 + my_strlen2(++str);
	// }

// }

// //3.指针法
// //创建两个指针都指向首地址，让一个移动直到遇到'\0'停止，返回两个指针相减的结果
// int my_strlen3(char* str)
// {
	// char *p1 = str;
	// char *p2 = str;
	// //创建两个指针都指向首地址
	
	// while(*p2++ != '\0')//解引用判断
	// {
		// ;//空语句
	// }	
	// return p2 - p1 - 1;//后置自增需要减1
// }


// int main()
// {
	// int len = my_strlen3("abcdef");
	
	// // char arr[] = {'a','b','c','e'};
	// // int len = strlen(arr);
	// //error

	// printf("%d \n",len);

	
	
	// // //3              -         6
	// // if(strlen("abc") - strlen("abcdef") > 0)
	// // {
		// // printf("hehe");
	// // }
	// // else
	// // {
		// // printf("haha");
	// // }
	// // //hehe
	// // //size_t strlen(const char* str)
	// // //size_t 是unsigned int
	// // //两个无符号数相减还是无符号类型的所以是hehe
	
	
	
	// return 0;
// }





//strcopy - 复制字符串
//char* strcopy(char * destination , char * source);
//destination-目的地	source-源头
//目标空间必须足够大,以确保能存放源字符串
//目标空间必须可变


// char* my_strcpy(char * dest , char * src)
// {
	
	//assert()
	//如果该表达式为假， assert() 宏会输出错误信息并终止程序的执行。
	
	
	// // assert(dest ! = NULL);
	// // assert(src ! = NULL);
	
	// char* ret = dest;
	
	// // //复杂版
	// // while(*src != '\0')
	// // {
		// // *dest = *src;
		// // dest++;
		// // src++;
	// // }
	// // *dest = '\0';
	
	// //拷贝src指向的字符串到dest指向的空间,包含'\0'
	// //精简版
	// while(*dest++ = *src++)
	// {
		// ;
	// }
	
	// //返回目的空间的起始地址
	// return ret;
// }

// int main()
// {
	// char arr1[] = "abcdefg";
	// char arr2[] = "afygb";
	
	// //strcpy(arr1,arr2);
	// // //arr1 变成 "ab\0defg"
	
	// //自己实现strcpy函数
	// my_strcpy(arr1,arr2);
	
	// //
	
	// printf("%s",arr1);
	
	// return 0;
// }



//strcat - 在字符串后面追加字符串
//char* strcat(char * strDestination , const char * strSource);
//把'\0'也追加过去了
//目的地必须足够大
//源头必须包含'\0'

// //自己实现
// char* my_strcat(char* dest, const char* src)
// {
	// char* ret = dest;
	// assert(dest != NULL);
	// assert(src);

	
	// // //复杂版
	// // while(*dest != '\0')
	// // {
		// // dest++;
	// // }
	
	// // while(*src != '\0')
	// // {
		// // *dest = *src;
		// // dest++;
		// // src++;
	// // }
	// // *dest = '\0';
	
	// //精简版
	// //1.找到目的字符串'\0'的位置
	// while(*dest != '\0')
	// {
		// dest++;
	// }
	// //2.追加
	// while(*dest++ = *src++)
	// {
		// ;
	// }
	
	// return ret;
// }

// int main()
// {
	// char arr1[30] = "hello";//arr[30] - 目的地必须足够大
	// char arr2[] = "world";
	// my_strcat(arr1 , arr2);
	// printf("%s",arr1);
	
	// return 0;
// }




//strcmp - 字符串比较
//int strcmp(const char * str1 , const char * str2);
//如果字符串1 大于 字符串2 返回 > 0的数
//如果字符串1 等于 字符串2 返回 = 0
//如果字符串1 小于 字符串2 返回 < 0的数

//比的不是字符串的的长度
//比的是ASCII码值


// //自己实现
// int my_strcmp(const char * p1 ,const char * p2)
// {
// 	assert(p1 && p2);

// 	while (*p1 == *p2)
// 	{
// 		if(*p1 == '\0')
// 		{
// 			return 0;//相等
// 		}
// 		p1++;
// 		p2++;
// 	}

// 	// //返回定值
// 	// if(*p1 > *p2)
// 	// 	return 1;//大于
// 	// else if(*p1 < *p2)
// 	// 	return -1;//小于
	
// 	//返回随机值
// 	return (*p1 - *p2);
		

// }

// int main()
// {
// 	char *p1 = "abcde";
// 	char *p2 = "abcda";


// 	// if(strcmp(p1,p2) > 0)
// 	// {
// 	// 	printf("p1 > p2\n");
// 	// }
// 	// else if(strcmp(p1,p2) == 0)
// 	// {
// 	// 	printf("p1 = p2\n");
// 	// }
// 	// else
// 	// {
// 	// 	printf("p1 < p2\n");
// 	// }

// 	my_strcmp(p1,p2);
	
// 	printf("%d\n",my_strcmp(p1,p2));

// 	return 0;
// }




//长度不受限制的字符串函数
//strcpy
//strcat
//strcmp


//长度受限制的字符串函数 - 
//strncoy
//strncat
//strncmp




//strncpy - 拷贝num个字符从源头到字符串目标空间
//char * strncpy(char *strDest ,const char *strSource, size_t count);

// //模拟实现
// //size_t 是unsigned int
// char* my_strncpy(char *dest , const char* sce ,unsigned int count)
// {
// 	char* ret = dest;

// 	for(int i = 0 ; i < count ; i++)
// 	{
// 		*dest = *sce;
// 		dest++;
// 		sce++;
// 	}

// 	return ret;
// }

// int main()
// {
// 	char arr1[5] = "abc";
// 	char arr2[] = "hello";
	
// 	// strncpy(arr1,arr2,4);
// 	// printf("%s\n",arr1);
// 	// //hell

// 	// strncpy(arr1,arr2,1);
// 	// printf("%s\n",arr1);
// 	// //hello

// 	my_strncpy(arr1,arr2,1);
// 	printf("%s\n",arr1);

// 	return 0;
// }





// //strncat

// //模拟实现
// char* my_strncat()
// {

// }

// int main()
// {
// 	char arr1[] = "hello";
// 	char arr2[] = "world";

// 	strncat(arr1,arr2,7);
// 	printf("%s\n",arr1);
	
// 	return 0;
// }



// //strncmp

// int main()
// {

// 	return 0;
// }




//*******
//strstr - 查找字符串函数
//char *strstr(const char *string ,const char *strCharSet);

//算法

// //模拟实现************
// char* my_strstr(const char *p1,const char *p2)
// {
// 	assert(p1 != NULL);
// 	assert(p2 != NULL);
// 	char *s1 = NULL;
// 	char *s2 = NULL;
// 	char *cur = (char *)p1;

// 	if(*p2 == '\0')
// 	{
// 		return (char *) p1;
// 	}
// 	while (*cur)
// 	{
// 		s1 = cur;
// 		s2 = (char *)p2;
// 		while((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
// 		{
// 			s1++;
// 			s2++;
// 		}
// 		if(*s2 == '\0')
// 		{
// 			return cur;//找到子串
// 		}

// 		cur++;
		
// 	}
// 	return NULL;//找不到子串
// }

// int main()
// {
// 	char *p1 = "abbbcefj";
// 	char *p2 = "bbc";

// 	// char* ret = strstr(p1 ,p2);
// 	// if(ret == NULL)
// 	// {
// 	// 	printf("子串不存在\n");
// 	// }
// 	// else
// 	// {
// 	// 	printf("%s\n",ret);
// 	// }

// 	char* ret = my_strstr(p1 ,p2);
// 	if(ret == NULL)
// 	{
// 		printf("子串不存在\n");
// 	}
// 	else
// 	{
// 		printf("%s\n",ret);
// 	}

// 	return 0;
//  }








//strtok - 分割有符号的字符串函数
//char * strtok(char * str , const char * sep);
//sep - 分隔符


// int main()
// {
// 	//点分十进制的表示方式 - ip地址
// 	//192.168.31.79  .
// 	//192 168 31 79

// 	//dongjiancheng@163.com  @ .
// 	//dongjiancheng 163 com



// 	char arr1[] = "dongjiancheng@163.com";
// 	char *p1 = "@.";
	
	
// 	//简单应用
// 	printf("第一次调用:%s\n",strtok(arr1 ,p1));//dongjiancheng
// 	printf("第二次调用:%s\n",strtok(NULL ,p1));//163
// 	printf("第三次调用:%s\n",strtok(NULL ,p1));//com


// 	printf("*****************************\n");


// 	char arr2[] = "192.168.31.79";
// 	char *p2 = ".";
	
// 	//循环应用
// 	char *ret = NULL;
// 	int i = 1;
// 	for(ret = strtok(arr2,p2) ; ret != NULL ;ret = strtok(NULL,p2))
// 	{		
// 		printf("第 %d 次调用:%s\n",i,ret);
// 		i++;	
// 	}

// 	return 0;
// }







//strerror - 错误信息函数
//char * strerror(int errnum);
//返回错误码,所对应的信息


// int main()
// {
// 	// char * str = strerror(0);
// 	// printf("0的错误:%s\n",strerror(0));
// 	// printf("1的错误:%s\n",strerror(1));
// 	// printf("2的错误:%s\n",strerror(2));



// 	// for(int i = 0 ;i < 99 ;i++)
// 	// {
// 	// 	printf("%d的错误: %s\n",i,strerror(i));
// 	// }

// 	//错误码		错误信息																
// 	// 0	的错误: No error								没有错误													
// 	// 1	的错误: Operation not permitted					不允许操作			
// 	// 2	的错误: No such file or directory				没有这样的文件或目录				
// 	// 3	的错误: No such process							没有这样的过程	
// 	// 4	的错误: Interrupted function call				函数调用中断				
// 	// 5	的错误: Input/output error						输入/输出错误	
// 	// 6	的错误: No such device or address				没有这样的设备或地址			
// 	// 7	的错误: Arg list too long						Arg 列表太长		
// 	// 8	的错误: Exec format error						Exec 格式错误		
// 	// 9	的错误: Bad file descriptor						错误的文件描述符		
// 	// 10	的错误: No child processes						无子进程		
// 	// 11	的错误: Resource temporarily unavailable		资源暂时不可用				
// 	// 12	的错误: Not enough space						空间不足	
// 	// 13	的错误: Permission denied						权限被拒绝		
// 	// 14	的错误: Bad address								地址错误	
// 	// 15	的错误: Unknown error							未知错误	
// 	// 16	的错误: Resource device							资源设备	
// 	// 17	的错误: File exists								文件存在							
// 	// 18	的错误: Improper link							链接不当	
// 	// 19	的错误: No such device							没有这样的设备	
// 	// 20	的错误: Not a directory							不是目录
// 	// 21	的错误: Is a directory							是一个目录
// 	// 22	的错误: Invalid argument						参数无效	
// 	// 23	的错误: Too many open files in system			系统中打开的文件太多					
// 	// 24	的错误: Too many open files						打开的文件太多	
// 	// 25	的错误: Inappropriate I/O control operation		不适当的 I/O 控制操作					
// 	// 26	的错误: Unknown error							未知错误	
// 	// 27	的错误: File too large							文件太大	
// 	// 28	的错误: No space left on device					设备上没有剩余空间			
// 	// 29	的错误: Invalid seek							无效的搜索
// 	// 30	的错误: Read-only file system					只读文件系统			
// 	// 31	的错误: Too many links							链接太多
// 	// 32	的错误: Broken pipe								破管
// 	// 33	的错误: Domain error							域错误	
// 	// 34	的错误: Result too large						结果太大	
// 	// 35	的错误: Unknown error							未知错误	
// 	// 36	的错误: Resource deadlock avoided				避免了资源死锁				
// 	// 37	的错误: Unknown error							未知错误							
// 	// 38	的错误: Filename too long						文件名太长	
// 	// 39	的错误: No locks available						没有可用的锁	
// 	// 40	的错误: Function not implemented				功能未实现			
// 	// 41	的错误: Directory not empty						目录不为空	
// 	// 42	的错误: Illegal byte sequence					非法字节序列		
// 	// 43	的错误: Unknown error							未知错误
// 	// 44	的错误: Unknown error							未知错误
// 	// 45	的错误: Unknown error							未知错误
// 	// ..   的错误: Unknown error								未知错误




// 	//strerrno(errno);
// 	//errno 是一个全局的错误码的变量
// 	//需要引<errno.h>的头文件
// 	//当c语言的库函数在执行过程中,发生了错误,就会把对应的错误码,赋值到errno中

// 	//例如:打开文件
// 	FILE* pf = fopen("test.txt","r");
// 	if(pf == NULL)
// 	{
// 		printf("%s\n",strerror(errno));
// 	}
// 	else 
// 	{
// 		printf("open file success\n");
// 	}
// 	//输出:No such file or directory - 没有这样的文件或目录


// 	return 0;
// }







//字符分类函数 
//<ctype.h>字符串分类函数的头文件

//  函数    -  如果他的参数符合下列条件就返回真
//
// iscntrl  - 任何控制字符
// isspace  - 空白字符:"空格",换页\f,换行\n,回车\r,制表符\t,垂直制表符\v
// isdigit  - 十进制数字0 - 9
// isxdigit - 十六进制数字,包含十进制数字,小写字母a-f,大写字母A-F
// islower  - 小写字母a - z
// isupper  - 大写字母A - Z
// isalpha  - 字母a - z或者A - Z
// isalnum  - 字母或者数字,a - z,A - Z ,0 - 9
// ispunct  - 标点符号,任何不属于数字或者字母的图形字符(可打印)
// isgraph  - 任何图形字符
// isprint  - 任何可打印字符,包括图形字符和空白字符


// int main()
// {
// 	char ch = '@';
	
// 	int ret = islower(ch);
// 	printf("%d\n",ret);
	 

// 	return 0;
// }







//字符转换函数

// int tolower (int c); - 大写转小写
// int toupper (int c); - 小写转大写


// int main()
// {
// 	char a = 'a';
// 	printf("%c\n",toupper(a));
// 	printf("%c\n",tolower(a));

// 	//将一串字符全部转换
// 	char arr[] = "quan BU daxie";
// 	int i = 0;
// 	while (arr[i])
// 	{
// 		if(isupper(arr[i]))
// 		{ 
// 			arr[i] = toupper(arr[i]);
// 		}
// 		i++;
// 	}
// 	printf("%s\n",arr);

// 	return 0;
// }






//内存操作函数

//memcpy - 内存拷贝函数
//void* memcpy(void * destination ,const void * source ,size_t num);
//void* 通用类型指针 - 无类型指针 	size_t = unsigned int;(单位:字节)

// //模拟实现memcpy
// void* my_memcpy(void *dest,const void *sce ,unsigned int size)
// {
// 	void* ret = dest;
// 	assert(dest != NULL);
// 	assert(sce != NULL);

// 	//自己实现
// 	for(int i = 0;i < size;i++)
// 	{
// 		*((char*)dest) = *((char*)sce);	//先将void类型的指针变量dest和sce先强制转换成char*类型的指针,然后在解引用,
// 		dest++;
// 		sce++;
// 	}

// 	// //简洁
// 	// while(size--)
// 	// {
// 	// 	*((char*)dest) = *((char*)sce);
// 	// 	++((char*)dest);
// 	// 	++((char*)sce); 
	
// 	// }

// 	return ret;
// }


// struct stu
// {
// 	char name[20];
// 	int age;
// };

// int main()
// {
// 	int arr1[] = {1,2,3,4,5,6};
// 	int arr2[6] = {0};
// 	// strcpy(arr2,arr1);
// 	// //error 不能拷贝过去 只能拷贝字符串有局限性

// 	// //int类型数据拷贝

// 	// int size = sizeof(arr2[0]);
// 	// //memcpy(arr1,arr2,size * 6);
// 	// my_memcpy(arr1,arr2,size * 6);

// 	// for(int i = 0;i < 6 ;i++)
// 	// {
// 	// 	printf("%d ",arr1[i]);
// 	// }
// 	// printf("\n");



// 	// //结构体类型数据拷贝

// 	// struct stu arr3[] = {{"张三",18},{"李四",32}};
// 	// struct stu arr4[3] = {0};

// 	// int size = sizeof(arr4[0]);
// 	// printf("%s %d\n",arr3[0].name,arr3[0].age);
// 	// printf("%s %d\n",arr3[1].name,arr3[1].age);
// 	// printf("***************************\n");

// 	// memcpy(arr3,arr4,size * 3);
// 	// my_memcpy(arr3,arr4,size * 3);

// 	// printf("%s %d\n",arr3[0].name,arr3[0].age);
// 	// printf("%s %d\n",arr3[1].name,arr3[1].age);


// 	//把12345拷贝到34567的位置上
// 	//应该是:1 2 1 2 3 4 5 8 9 10
// 	int arr[] = {1,2,3,4,5,6,7,8,9,10};
// 	my_memcpy(arr+2 , arr , sizeof(arr[0]) * 5);
// 	for(int i = 0;i < 10 ;i++)
// 	{
// 		printf("%d ",arr[i]);
// 	}
// 	printf("\n");
// 	//但是变为:1 2 1 2 1 2 1 8 9 10
// 	//重叠拷贝不适用

// 	//虽然memcpy可以适用内存重叠拷贝的情况
// 	//但c语言标准库函里有专门的用于内存重叠拷贝的函数 - memmove
// 	//就像60分及格,但memcpy考了100分

// 	return 0;
// }





// //memmove -  内存重叠拷贝函数

// //模拟实现
// void* my_memmove(void* dest, void* src,unsigned int count)
// {
// 	assert(dest != NULL);
//  	assert(src != NULL);
// 	void* ret = dest;
	
// 	// //复杂
// 	// //从 前 -> 后 拷贝
// 	// if(dest < src)
// 	// {
// 	// 	for(int i = 0 ;i < count ;i++)
// 	// 	{
// 	// 		*(char *)dest = *(char *)src;
// 	// 		dest++;
// 	// 		src++;
// 	// 	}
// 	// }
// 	// //从 后 -> 前 拷贝
// 	// else
// 	// {
// 	// 	for(int i = 0 ;i < count ;i++)
// 	// 	{
// 	// 		*(char *)dest = *(char *)src;
// 	// 		dest--;
// 	// 		src--;
// 	// 	}
// 	// }


// 	//简洁
// 	if (dest <= src || (char *)dest >= ((char *)src + count))
// 	{
// 		while (count--)
// 		{
// 			*(char*)dest = *(char*)src;
// 			dest = (char*)dest + 1;
// 			src = (char*)src + 1;
// 		}
// 	}
// 	else
// 	{
// 		dest = (char*)dest + count - 1;
// 		src = (char*)src + count - 1;
// 		while (count--)
// 		{
// 			*(char*)dest = *(char*)src;
// 			dest = (char*)dest - 1;
// 			src = (char*)src - 1;
// 		}
// 	}
	
// 	return ret;

// }

// int main()
// {
// 	// //把12345拷贝到34567的位置上
// 	// //应该是:1 2 1 2 3 4 5 8 9 10
// 	// int arr[] = {1,2,3,4,5,6,7,8,9,10};
// 	// memmove(arr+2 , arr , sizeof(arr[0]) * 5);
// 	// for(int i = 0;i < 10 ;i++)
// 	// {
// 	// 	printf("%d ",arr[i]);
// 	// }
// 	// printf("\n");
// 	// //1 2 1 2 3 4 5 8 9 10


// 	//把12345拷贝到34567的位置上
//  	//应该是:1 2 1 2 3 4 5 8 9 10
// 	int arr[] = {1,2,3,4,5,6,7,8,9,10};
// 	my_memmove(arr + 2, arr , sizeof(arr[0]) * 5);
// 	for(int i = 0;i < 10 ;i++)
// 	{
// 		printf("%d ",arr[i]);
// 	}
// 	printf("\n");
	


// 	return 0;	
// }




// //memcmp - 内存比较函数

// int main()
// {
// 	int arr1[]={1,2,3,4,5};
// 	int arr2[]={1,2,4,3,5};
// 	int ret1 = memcmp(arr1,arr2,8);
// 	printf("%d\n",ret1);//0

// 	int ret2 = memcmp(arr1,arr2,9);
// 	printf("%d\n",ret2);//-1


// 	return 0;
// }




//memset //内存设置函数
//vod* memset(void* dest,int c ,size_t count);
//int c 指的是设置的字符是什么

int main()
{
	// char arr[10] ="";
	// memset(arr , '#' ,10);
	// int i = 0;
	// for(i = 0 ; i < 10;i++)
	// {
	// 	printf("%c ",arr[i]);
	// }
	// //# # # # # # # # # # 

	//注意
	int arr2[10] = {0};
	memset(arr2 , 1 ,10);
	for(int i = 0 ; i < 10;i++)
	{
		printf("%d ",arr2[i]);
	}
	//16843009 16843009 257 0 0 0 0 0 0 0 
	//用错了会出现这样的情况,因为是一个字节一个字节改的

	return 0;
}
