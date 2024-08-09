#include <stdio.h>
#include <stddef.h>


//结构体
//结构体是一些值的集合,这些值称为成员变量,结构体的每个成员可以是不同类型的变量

//结构体的声明
// struct tag
// {
//     number-list;
// }varlable-list;//分号不可少

// //声明一个学生的结构体类型
// struct stu
// {
// 	char name[20];
// 	int tele[20];
// 	int age;
// }s4,s5,s6;//s4,s5,s6全局变量

// struct stu s3;//全局变量

// int main()
// {
// 	//创建结构体变量
// 	struct stu s1;
// 	struct stu s2;
// 	//局部的结构体变量
 
//   return 0;
// }




//匿名结构体类型

// struct 
// {
// 	int a;
// 	char b;
	
// }x;

// struct 
// {
// 	int a;
// 	char b;
	
// }* psa;//结构体指针




//结构体的自引用

// // struct note
// // {
// // 	int date;
// // 	struct note n;	
// // };//数据无限大error

// struct note
// {
// 	int date;//4
// 	struct note* next;//4/8

// };






//typedef

// typedef struct 
// {
// 	int date;
// 	note* next;
// }note;
// //error




// //结构体变量的定义和初始化

// struct t
// {
// 	double bb;
// 	short ss;
// };

// struct s
// {
// 	char c;
// 	int a;
// 	struct t t1;
// 	double d;
// 	char arr[20];
// };

// int main()
// {
// 	//struct s s1 = {'c',10,3.14,"fjajsg"};
// 	//printf("%c %d %lf %s\n",s1.c,s1.a,s1.d,s1.arr);

// 	struct s s2 = {'a',18,{5.12454,89},5.1454,"hakljhg"};//结构体包含结构体	
// 	printf("%c %d %lf %d %lf %s\n",s2.c ,s2.a ,s2.t1.bb ,s2.t1.ss ,s2.d ,s2.arr);

// 	return 0;
// }


//typedef struct stu
//{
//	char name[20];
//	short age;
//	char tele[12];
//	char sex[5];
//}stu;	
//
//int main()
//{
//	struct stu s1 = {"张三" , 20 ,"15022868413" , "男"};	//初始化
//	stu s2 = {"李四" , 20 , "11345683894" , "女"};
//
//	return 0;
//}


//struct s
//{
//	int a;
//	char c;
//	char arr[20];
//	double d;
//};
//
//struct t
//{
//	char ch[10];
//	struct s s1;	//结构体成员包含其他结构体
//	char* pc;
//
//};
//
//
//int main()
//{
//	char arr2[] = {"hello world!"};
//	struct t t1 = { "hehe" , {100 , 'd' , "hello c!" , 3.14} ,arr2}; //结构体包含结构体的初始化也要{}
//	printf("%s\n", t1.ch);		//hehe
//	printf("%d\n", t1.s1.a);	//100
//	printf("%s\n", t1.s1.arr);	//hello c!
//	printf("%s\n", t1.pc);		//hello world!
//
//	return 0;
//}




// //结构体内存对齐

// //对齐规则:
// //1. 结构体第一个成员在结构体变量偏移量为0的地址处
// //2. 其他成员变量要对齐到某个数字(对齐数)的整数倍地址数  	
// //                              对齐数 = 编译器默认的一个对齐数 与 该成员大小的 较小值	.vs默认为8	.gcc没有默认对齐数
// //3. 结构体的总大小为最大对齐数(每个成员变量都有一个对齐数)的整数倍
// //4. 如果嵌套了结构体的情况下,嵌套的结构体对齐到自己的最大对齐数的整数倍处,结构体的整体大小就是所有最大对齐数(含嵌套结构体的对齐数)的整数倍

// struct S1
// {
// 	char c1;
// 	int a;
// 	char c2;
// };//12
// //1000 1111 0001
// struct S2
// {
// 	char c1;
// 	char c2;
// 	int a;	
// };//8
// //1 100 1111
// struct S3
// {
// 	double d;
// 	char c;
// 	int i;
// };//16
// //11111111 1000 1111
// struct S4
// {
// 	char c1;
// 	struct S3 s3;
// 	double d;
// };//32
// //10000000 1111111111111111 11111111 
// struct S5
// {
// 	char c;
// 	float f;
// 	int i;
// 	int a;
// 	double bb;
// };//24


// int main()
// {
// 	struct S1 s1 = {0};
// 	printf("%d\n",sizeof(s1));//12
// 	struct S2 s2 = {0};
// 	printf("%d\n",sizeof(s2));//8
// 	struct S3 s3 = {0};
// 	printf("%d\n",sizeof(s3));//16
// 	struct S4 s4 = {0};
// 	printf("%d\n",sizeof(s4));//32
// 	struct S5 s5 = {0};
// 	printf("%d\n",sizeof(s5));//24
	

// 	return 0;
// }

// //为什么要内存对齐?
// //1. 平台原因(移植原因): 不是所有得硬件平台都能访问任意地址得任意数据得,某些硬件平台只能在某些地址处取特定类型的值,否则抛出硬件出异常
// //2. 性能原因: 			数据结构(尤其是栈)应该尽可能地在自然边界上对齐,原因在于,为了访问为对齐的内存,处理器需要两次内存访问,而对齐的内存访问仅需要一次
// //总的来说: 结构体的内存对齐是拿 空间 换取 时间 的做法





// //修改默认对齐数
// #pragma pack(4)//修改默认对齐数为4
// #pragma pack()//取消设置的默认对齐数





// //offsetof - 宏 - 求出偏移量

// struct S
// {
// 	char c;
// 	int i;
// 	double d;
// };

// int main()
// {
// 	printf("%d\n",offsetof(struct S,c));//0
// 	printf("%d\n",offsetof(struct S,i));//4
// 	printf("%d\n",offsetof(struct S,d));//8

// 	return 0;
// }






// //结构体传参

// struct S
// {
// 	char c;
// 	int i;
// 	double d;
// };

// void Init(struct S* ps)//传指针
// {
// 	ps->c = 'c';
// 	ps->i = 100;
// 	ps->d = 3.14;

// }

// void print1(struct S tmp)//传值
// {
// 	printf("%c %d %lf\n",tmp.c ,tmp.i ,tmp.d);
// }
// void print2(const struct S* ptmp)//传地址 - 加上const修饰后更加安全
// {
// 	printf("%c %d %lf\n",ptmp->c ,ptmp->i ,ptmp->d);
// }

// int main()
// {
// 	struct S s = {0};
// 	Init(&s);
// 	print1(s);
// 	print2(&s);
// 	//print2更好, 函数传参数是需要压栈的,如果传值的话,结构体过大,参数压栈的开销会比较大

// 	return 0;
// }






// //位段
// //位:二进制位

// //位段的声明和结构体是类似的,有两个不同:
// //1. 位段的成员必须是int ,unsigned int 或者 signed int
// //2. 位段的成员名后边有一个冒号 和一个 数字

// //比如:
// struct A
// {
// 	int _a : 2;//a只需要 2 个比特位
// 	int _b : 5;//b只需要 5 个比特位
// 	int _c : 10;//c只需要 10 个比特位
// 	int _d : 30;//d只需要 30 个比特位
// 	//47个bit - 6个字节 - 48bit 但这占了8个字节
// };
// //A 就是一个位段

// //位段的内存分配
// //1. 位段的空间上是按照需要以4个字节(int)或者1个字节(char)的方式来开辟的
// //2. 位段涉及很多不确定因素,位段是 不跨平台的,注重可移植的程序应该避免使用位段

// int main()
// {
// 	struct A a;
// 	printf("%d\n",sizeof(a));//占8个字节
// 	//
	
// 	return 0;
// }

// //位段的跨平台问题:
// //1. int 位段被当成有符号数还是无符号数是不确定的
// //2. 位段中最大味的数目不能确定.(16位机器最大16 ,32机器最大32 ,写成27,在16位机器会出问题)
// //3. 位段中的成员子在内存中从左向右分配,还是从右向左分配标准尚未定义
// //4. 当一个结构包含两个位段,第二个位段成员比较大,无法容纳第一个位段剩余的位时,时舍弃剩余的位还是利用,这是不确定的

// //总结:
// //跟结构体相比,位段可以达到同样的效果,但是可以很好的节省空间,但是有跨平台的问题存在.






// //枚举 - 把可能的取值一一列举

// //枚举类型的定义 - enum
// enum Sex
// {
// 	//枚举的可能取值 - 枚举常量 - 
// 	MALE = 1,
// 	FEMALE = 3,
// 	SECRET = 5,

// };//分号不可少

// enum Color
// {
// 	//枚举常量
// 	RED,
// 	BLUE,
// 	YELLOW

// };
// int main()
// {
// 	enum Sex s = MALE;
// 	enum Color c = RED;

// 	printf("%d %d %d\n",RED,BLUE,YELLOW);//0 1 2	
// 	printf("%d %d %d\n",MALE,FEMALE,SECRET);//1 3 5

// 	//RED = 6;
// 	//初始值可以更改,但不能之后赋值(常量)


// 	return 0;
// }

//枚举的优点:
//1. 增加了代码的可读性和可维护性
//2. 和#define定义的标识符比较枚举有类型检查,更加严谨
//3. 防止了命名污染(封装)
//4. 使用方便,一次可以定义多个常量
//5. 便于调试




// //枚举的大小

// enum Color
// {
// 	RED,
// 	BLUE,
// 	YELLOW
// };

// int main()
// {
// 	enum Color c = RED;
// 	printf("%d\n",sizeof(c));//4

// 	return 0;
// }
// //





//联合体(公用体) - union
//联合也是一种特殊的自定义类型,这种类型定义变量也包含一系列的成员,特征是这些成员公用的一块空间(所以也叫共用体)

// //联合体的声明
// union Un
// {
// 	char c;//1
// 	int i;//4	
// };

// int main()
// {
// 	union Un u;
// 	printf("%d\n",sizeof(u));//4

// 	printf("%p\n",&u);//000000000061FE1C

// 	printf("%p\n",&(u.c));//000000000061FE1C
// 	printf("%p\n",&(u.i));//000000000061FE1C

// 	return 0;
// }
// //联合的特点:
// //联合的成员是公用一块内存空间的,这样一个联合变量的大小,至少是最大成员的大小(因为联合至少有得有能力保存最大的那个成员).


// 	return 0;
// }



// //如何判断机器是 大端 还是 小端?

// //1.变量法
// int check_bs1()
// {
// 	//0为大端,1为小端
// 	int a = 1;
// 	return *(char*)&a;
// }

// //2.联合体方法
// int check_bs2()
// {
// 	//0为大端,1为小端
// 	union Un
// 	{
// 		char c;
// 		int i;
// 	}u;
// 	u.i = 1;
// 	return u.c;
// }

// int main()
// {
// 	int a = 0x11223344;
	
// 	//低地址-------------------->高地址
// 	//.....[][][[[][11][22][33][44][][][[][][][]...		大端字节序存储模式
// 	//.....[][][[[][44][33][22][11][][][[][][][]...		小端字节序存储模式
// 	//讨论一个数据,放在内存中的字节存放顺序
// 	//大端小端字节序问题

// 	if(check_bs2() == 1)
// 	{
// 		printf("小端\n");
// 	}
// 	else
// 	{
// 		printf("大端\n");
// 	}

// 	return 0;
// }











































































