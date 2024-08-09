#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int main()
//{
//	int a = 10;
//	int *p = &a;	//指针变量
//	
//	return 0;
//}



//指针和指针类型


//int main()
//{
//	printf("%d\n",sizeof(int*));
//	printf("%d\n", sizeof(char*));
//	printf("%d\n", sizeof(short*));
//	printf("%d\n", sizeof(float*));
//	printf("%d\n", sizeof(double*));
//	printf("%d\n", sizeof(long*));
//	printf("%d\n", sizeof(long long*));
//	//32位是4 4 4 4 4 4
//	//64位是8 8 8 8 8 8
//
//	return 0;
//}


//int main()
//{
//	//int a = 0x11223344;		//44 33 22 11 cc cc cc cc cc 
//	//int* pa = &a;
//	//*pa = 0;					//00 00 00 00 cc cc cc cc cc	int*修改4个字节的内容
////----------------------------------------------------------------
//	//int a = 0x11223344;		//44 33 22 11 cc cc cc cc cc
//	//char* pa = &a;	
//	//*pa = 0;					//00 cc cc cc cc cc cc cc cc	char*修改1个字节的内容
////---------------------------------------------------------------------
//	//int a = 0x11223344;		//44 33 22 11 cc cc cc cc cc cc cc cc
//	//double* pa = &a;
//	//*pa = 0;					//00 00 00 00 00 00 00 00 00 00 00 00	double*修改8个字节的内容
////---------------------------------------------------------------------------------------
//	//指针类型决定能访问几个字节
//
//
//
//	//char* pc = &a;
//
//	//printf("%p\n",pa);		// 000000A5233EF784
//	//printf("%p\n",pc);		// 000000A5233EF784
//
//
//	return 0;
//}


//int main()
//{
//	int a = 0x11223344;
//	int* pa = &a;
//	char* pc = &a;
//	printf("%p\n",pa);		//0000006ED52FF8B4	
//	printf("%p\n", pa+1);	//0000006ED52FF8B8	差4
//
//	printf("%p\n", pc);		//0000006ED52FF8B4
//	printf("%p\n", pc+1);	//0000006ED52FF8B5  差1
//
//	//指针类型决定了：指针走一步走多远（指针的步长）(单位：字节)
//	//int* pa;pa + 1 -->4
//	//char* pa; pa + 1 -- > 1
//	//double* pa; pa + 1 -- > 8
//
//	return 0;
//}


//int main()
//{
//	int arr[10] = {0};
//	int* p = arr;	//数组名：首元素地址
//	for (int i = 0;i < 10;i++)
//	{
//		*(p + i) = 1;
//	}
//	//把arr所有元素值改为1
//
//	return 0;
//}





////野指针-野指针的位置是不可知的
//
//int test()
//{
//	int c = 10;
//	return &c;
//}
//
//int main()
//{
//	//指针未初始化
//	int a;	//局部变量不初始化，默认是随机值
//	int* p; //局部的指针变量，被初始化随机值
//	*p = 20;
//
//	//指针越界访问
//	int arr[10] = { 0 };
//	int* q = arr;
//	int i = 0;
//	for (i = 0; i < 12; i++)
//	{
//		q++;
//	}
//
//	//指针指向的空间释放
//	int* g = test();
//	*g = 20;
//
//	return 0;
//}

//int main()
//{
//	int b = 0;
//	int a = 10;
//	int* pa = &a;	//初始化
//	int* p = NULL;	//用来初始化指针，给指针赋值
//	*pa = 20;
//	pa = NULL;
//	if (pa != NULL)
//	{
//	}
//
//	return 0;
//}



//指针运算

//int main()
//{
//	//指针加减整数
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* p = arr;
//	//用指针打印数组
//	/*for (i = 0;i < sz;i++)
//	{
//		printf("%d\n",*p);
//		p = p + 1;
//		
//	}*/
//
//	/*for (i = 0; i < 5; i++)
//	{
//		printf("%d\n", *p);
//		p = p + 2;
//
//	}*/
//
//	int* q = &arr[9];
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d\n", *q);
//		q -= 2;
//
//	}
//
//	return 0;
//} 




//指针和数组


//int main()
//{
//	int arr[10] = {0};
//	printf("%p\n",arr);	//00000015A94FFCF8			首元素地址
//	printf("%p\n", arr + 1); //00000015A94FFCFC		差4
//
//	printf("%p\n",&arr[0]);//00000015A94FFCF8
//	printf("%p\n",&arr[0] + 1);//00000015A94FFCFC		差4
//
//	printf("%p\n",&arr); //00000015A94FFCF8
//	printf("%p\n", &arr + 1);// 00000015A94FFD20			差40
//
//	//1.&arr -&数组名-数组名不是首元素地址-数组名表示整个数组 - &arr数组名 取出的是整个数组的地址
//	//sizeof(arr) - sizeof(数组名) - 数组名表示的是整个数组- sizeof(数组名)计算的是整个数组的大小
//	return 0;
//}

//int main()
//{
//	int arr[10] = {0};
//	int* p = arr;
//	
//	for (int i = 0;i < 10;i++)
//	{
//		printf("%p  =====  %p\n",p+i,&arr[i]);
//	}
//	/*  000000F4E772F7B8  ==== = 000000F4E772F7B8
//		000000F4E772F7BC  ==== = 000000F4E772F7BC
//		000000F4E772F7C0  ==== = 000000F4E772F7C0
//		000000F4E772F7C4  ==== = 000000F4E772F7C4
//		000000F4E772F7C8  ==== = 000000F4E772F7C8
//		000000F4E772F7CC  ==== = 000000F4E772F7CC
//		000000F4E772F7D0  ==== = 000000F4E772F7D0
//		000000F4E772F7D4  ==== = 000000F4E772F7D4
//		000000F4E772F7D8  ==== = 000000F4E772F7D8
//		000000F4E772F7DC  ==== = 000000F4E772F7DC   */
//
//
//	int i = 0;
//	for (int n = 0;n < 10;n++)
//	{
//		*(p + n) = n;
//
//	}
//	for (int n = 0; n < 10; n++)
//	{
//		printf("%d\n", arr[n]);
//
//	}
//	//0 1 2 3 4 5 6 7 8 9
//
//	return 0;
//}



//二级指针


//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	int* *ppa = &pa;//ppa二级指针
//	int* **pppa = &ppa;//三级指针
//	* *ppa = 20;
//	printf("%d\n",a);
//
//	return 0;
//}




//指针数组 -- 数组 -- 存放指针的数组
//数组指针 -- 指针


int main()
{
	int a = 10, b = 20, c = 30;
	//int* pa = &a;
	//int* pb = &b;
	//int* pc = &c;
	//整形数组 - 存放整形
	//字符数组 - 存放字符
	//指针数组 - 存放指针

	int arr[10];
	int* arr2[3] = {&a,&b,&c};//指针数组
	for (int i = 0;i<3;i++)
	{
		printf("%d\n", *(arr2[i]));
	}


	return 0;
}
