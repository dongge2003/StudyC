//�ַ�������

#include <stdio.h> 
#include <string.h>
#include <assert.h>	//assert������ͷ�ļ�
#include <errno.h>	//errnoȫ�ֱ�����ͷ�ļ�
#include <ctype.h> 	//�ַ������ຯ����ͷ�ļ�


//strlen - ���ַ�������
//size_t strlen ( const char * str);


// //1. ����������
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

// //2.�ݹ顪����������ʱ�����磺cont
// //���������׵�ַ���ж�Ԫ���Ƿ�Ϊ'\0'������ǣ�����0��������Ƿ���1+���������ã�
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

// //3.ָ�뷨
// //��������ָ�붼ָ���׵�ַ����һ���ƶ�ֱ������'\0'ֹͣ����������ָ������Ľ��
// int my_strlen3(char* str)
// {
	// char *p1 = str;
	// char *p2 = str;
	// //��������ָ�붼ָ���׵�ַ
	
	// while(*p2++ != '\0')//�������ж�
	// {
		// ;//�����
	// }	
	// return p2 - p1 - 1;//����������Ҫ��1
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
	// // //size_t ��unsigned int
	// // //�����޷�������������޷������͵�������hehe
	
	
	
	// return 0;
// }





//strcopy - �����ַ���
//char* strcopy(char * destination , char * source);
//destination-Ŀ�ĵ�	source-Դͷ
//Ŀ��ռ�����㹻��,��ȷ���ܴ��Դ�ַ���
//Ŀ��ռ����ɱ�


// char* my_strcpy(char * dest , char * src)
// {
	
	//assert()
	//����ñ��ʽΪ�٣� assert() ������������Ϣ����ֹ�����ִ�С�
	
	
	// // assert(dest ! = NULL);
	// // assert(src ! = NULL);
	
	// char* ret = dest;
	
	// // //���Ӱ�
	// // while(*src != '\0')
	// // {
		// // *dest = *src;
		// // dest++;
		// // src++;
	// // }
	// // *dest = '\0';
	
	// //����srcָ����ַ�����destָ��Ŀռ�,����'\0'
	// //�����
	// while(*dest++ = *src++)
	// {
		// ;
	// }
	
	// //����Ŀ�Ŀռ����ʼ��ַ
	// return ret;
// }

// int main()
// {
	// char arr1[] = "abcdefg";
	// char arr2[] = "afygb";
	
	// //strcpy(arr1,arr2);
	// // //arr1 ��� "ab\0defg"
	
	// //�Լ�ʵ��strcpy����
	// my_strcpy(arr1,arr2);
	
	// //
	
	// printf("%s",arr1);
	
	// return 0;
// }



//strcat - ���ַ�������׷���ַ���
//char* strcat(char * strDestination , const char * strSource);
//��'\0'Ҳ׷�ӹ�ȥ��
//Ŀ�ĵر����㹻��
//Դͷ�������'\0'

// //�Լ�ʵ��
// char* my_strcat(char* dest, const char* src)
// {
	// char* ret = dest;
	// assert(dest != NULL);
	// assert(src);

	
	// // //���Ӱ�
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
	
	// //�����
	// //1.�ҵ�Ŀ���ַ���'\0'��λ��
	// while(*dest != '\0')
	// {
		// dest++;
	// }
	// //2.׷��
	// while(*dest++ = *src++)
	// {
		// ;
	// }
	
	// return ret;
// }

// int main()
// {
	// char arr1[30] = "hello";//arr[30] - Ŀ�ĵر����㹻��
	// char arr2[] = "world";
	// my_strcat(arr1 , arr2);
	// printf("%s",arr1);
	
	// return 0;
// }




//strcmp - �ַ����Ƚ�
//int strcmp(const char * str1 , const char * str2);
//����ַ���1 ���� �ַ���2 ���� > 0����
//����ַ���1 ���� �ַ���2 ���� = 0
//����ַ���1 С�� �ַ���2 ���� < 0����

//�ȵĲ����ַ����ĵĳ���
//�ȵ���ASCII��ֵ


// //�Լ�ʵ��
// int my_strcmp(const char * p1 ,const char * p2)
// {
// 	assert(p1 && p2);

// 	while (*p1 == *p2)
// 	{
// 		if(*p1 == '\0')
// 		{
// 			return 0;//���
// 		}
// 		p1++;
// 		p2++;
// 	}

// 	// //���ض�ֵ
// 	// if(*p1 > *p2)
// 	// 	return 1;//����
// 	// else if(*p1 < *p2)
// 	// 	return -1;//С��
	
// 	//�������ֵ
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




//���Ȳ������Ƶ��ַ�������
//strcpy
//strcat
//strcmp


//���������Ƶ��ַ������� - 
//strncoy
//strncat
//strncmp




//strncpy - ����num���ַ���Դͷ���ַ���Ŀ��ռ�
//char * strncpy(char *strDest ,const char *strSource, size_t count);

// //ģ��ʵ��
// //size_t ��unsigned int
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

// //ģ��ʵ��
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
//strstr - �����ַ�������
//char *strstr(const char *string ,const char *strCharSet);

//�㷨

// //ģ��ʵ��************
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
// 			return cur;//�ҵ��Ӵ�
// 		}

// 		cur++;
		
// 	}
// 	return NULL;//�Ҳ����Ӵ�
// }

// int main()
// {
// 	char *p1 = "abbbcefj";
// 	char *p2 = "bbc";

// 	// char* ret = strstr(p1 ,p2);
// 	// if(ret == NULL)
// 	// {
// 	// 	printf("�Ӵ�������\n");
// 	// }
// 	// else
// 	// {
// 	// 	printf("%s\n",ret);
// 	// }

// 	char* ret = my_strstr(p1 ,p2);
// 	if(ret == NULL)
// 	{
// 		printf("�Ӵ�������\n");
// 	}
// 	else
// 	{
// 		printf("%s\n",ret);
// 	}

// 	return 0;
//  }








//strtok - �ָ��з��ŵ��ַ�������
//char * strtok(char * str , const char * sep);
//sep - �ָ���


// int main()
// {
// 	//���ʮ���Ƶı�ʾ��ʽ - ip��ַ
// 	//192.168.31.79  .
// 	//192 168 31 79

// 	//dongjiancheng@163.com  @ .
// 	//dongjiancheng 163 com



// 	char arr1[] = "dongjiancheng@163.com";
// 	char *p1 = "@.";
	
	
// 	//��Ӧ��
// 	printf("��һ�ε���:%s\n",strtok(arr1 ,p1));//dongjiancheng
// 	printf("�ڶ��ε���:%s\n",strtok(NULL ,p1));//163
// 	printf("�����ε���:%s\n",strtok(NULL ,p1));//com


// 	printf("*****************************\n");


// 	char arr2[] = "192.168.31.79";
// 	char *p2 = ".";
	
// 	//ѭ��Ӧ��
// 	char *ret = NULL;
// 	int i = 1;
// 	for(ret = strtok(arr2,p2) ; ret != NULL ;ret = strtok(NULL,p2))
// 	{		
// 		printf("�� %d �ε���:%s\n",i,ret);
// 		i++;	
// 	}

// 	return 0;
// }







//strerror - ������Ϣ����
//char * strerror(int errnum);
//���ش�����,����Ӧ����Ϣ


// int main()
// {
// 	// char * str = strerror(0);
// 	// printf("0�Ĵ���:%s\n",strerror(0));
// 	// printf("1�Ĵ���:%s\n",strerror(1));
// 	// printf("2�Ĵ���:%s\n",strerror(2));



// 	// for(int i = 0 ;i < 99 ;i++)
// 	// {
// 	// 	printf("%d�Ĵ���: %s\n",i,strerror(i));
// 	// }

// 	//������		������Ϣ																
// 	// 0	�Ĵ���: No error								û�д���													
// 	// 1	�Ĵ���: Operation not permitted					���������			
// 	// 2	�Ĵ���: No such file or directory				û���������ļ���Ŀ¼				
// 	// 3	�Ĵ���: No such process							û�������Ĺ���	
// 	// 4	�Ĵ���: Interrupted function call				���������ж�				
// 	// 5	�Ĵ���: Input/output error						����/�������	
// 	// 6	�Ĵ���: No such device or address				û���������豸���ַ			
// 	// 7	�Ĵ���: Arg list too long						Arg �б�̫��		
// 	// 8	�Ĵ���: Exec format error						Exec ��ʽ����		
// 	// 9	�Ĵ���: Bad file descriptor						������ļ�������		
// 	// 10	�Ĵ���: No child processes						���ӽ���		
// 	// 11	�Ĵ���: Resource temporarily unavailable		��Դ��ʱ������				
// 	// 12	�Ĵ���: Not enough space						�ռ䲻��	
// 	// 13	�Ĵ���: Permission denied						Ȩ�ޱ��ܾ�		
// 	// 14	�Ĵ���: Bad address								��ַ����	
// 	// 15	�Ĵ���: Unknown error							δ֪����	
// 	// 16	�Ĵ���: Resource device							��Դ�豸	
// 	// 17	�Ĵ���: File exists								�ļ�����							
// 	// 18	�Ĵ���: Improper link							���Ӳ���	
// 	// 19	�Ĵ���: No such device							û���������豸	
// 	// 20	�Ĵ���: Not a directory							����Ŀ¼
// 	// 21	�Ĵ���: Is a directory							��һ��Ŀ¼
// 	// 22	�Ĵ���: Invalid argument						������Ч	
// 	// 23	�Ĵ���: Too many open files in system			ϵͳ�д򿪵��ļ�̫��					
// 	// 24	�Ĵ���: Too many open files						�򿪵��ļ�̫��	
// 	// 25	�Ĵ���: Inappropriate I/O control operation		���ʵ��� I/O ���Ʋ���					
// 	// 26	�Ĵ���: Unknown error							δ֪����	
// 	// 27	�Ĵ���: File too large							�ļ�̫��	
// 	// 28	�Ĵ���: No space left on device					�豸��û��ʣ��ռ�			
// 	// 29	�Ĵ���: Invalid seek							��Ч������
// 	// 30	�Ĵ���: Read-only file system					ֻ���ļ�ϵͳ			
// 	// 31	�Ĵ���: Too many links							����̫��
// 	// 32	�Ĵ���: Broken pipe								�ƹ�
// 	// 33	�Ĵ���: Domain error							�����	
// 	// 34	�Ĵ���: Result too large						���̫��	
// 	// 35	�Ĵ���: Unknown error							δ֪����	
// 	// 36	�Ĵ���: Resource deadlock avoided				��������Դ����				
// 	// 37	�Ĵ���: Unknown error							δ֪����							
// 	// 38	�Ĵ���: Filename too long						�ļ���̫��	
// 	// 39	�Ĵ���: No locks available						û�п��õ���	
// 	// 40	�Ĵ���: Function not implemented				����δʵ��			
// 	// 41	�Ĵ���: Directory not empty						Ŀ¼��Ϊ��	
// 	// 42	�Ĵ���: Illegal byte sequence					�Ƿ��ֽ�����		
// 	// 43	�Ĵ���: Unknown error							δ֪����
// 	// 44	�Ĵ���: Unknown error							δ֪����
// 	// 45	�Ĵ���: Unknown error							δ֪����
// 	// ..   �Ĵ���: Unknown error								δ֪����




// 	//strerrno(errno);
// 	//errno ��һ��ȫ�ֵĴ�����ı���
// 	//��Ҫ��<errno.h>��ͷ�ļ�
// 	//��c���ԵĿ⺯����ִ�й�����,�����˴���,�ͻ�Ѷ�Ӧ�Ĵ�����,��ֵ��errno��

// 	//����:���ļ�
// 	FILE* pf = fopen("test.txt","r");
// 	if(pf == NULL)
// 	{
// 		printf("%s\n",strerror(errno));
// 	}
// 	else 
// 	{
// 		printf("open file success\n");
// 	}
// 	//���:No such file or directory - û���������ļ���Ŀ¼


// 	return 0;
// }







//�ַ����ຯ�� 
//<ctype.h>�ַ������ຯ����ͷ�ļ�

//  ����    -  ������Ĳ����������������ͷ�����
//
// iscntrl  - �κο����ַ�
// isspace  - �հ��ַ�:"�ո�",��ҳ\f,����\n,�س�\r,�Ʊ��\t,��ֱ�Ʊ��\v
// isdigit  - ʮ��������0 - 9
// isxdigit - ʮ����������,����ʮ��������,Сд��ĸa-f,��д��ĸA-F
// islower  - Сд��ĸa - z
// isupper  - ��д��ĸA - Z
// isalpha  - ��ĸa - z����A - Z
// isalnum  - ��ĸ��������,a - z,A - Z ,0 - 9
// ispunct  - ������,�κβ��������ֻ�����ĸ��ͼ���ַ�(�ɴ�ӡ)
// isgraph  - �κ�ͼ���ַ�
// isprint  - �κοɴ�ӡ�ַ�,����ͼ���ַ��Ϳհ��ַ�


// int main()
// {
// 	char ch = '@';
	
// 	int ret = islower(ch);
// 	printf("%d\n",ret);
	 

// 	return 0;
// }







//�ַ�ת������

// int tolower (int c); - ��дתСд
// int toupper (int c); - Сдת��д


// int main()
// {
// 	char a = 'a';
// 	printf("%c\n",toupper(a));
// 	printf("%c\n",tolower(a));

// 	//��һ���ַ�ȫ��ת��
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






//�ڴ��������

//memcpy - �ڴ濽������
//void* memcpy(void * destination ,const void * source ,size_t num);
//void* ͨ������ָ�� - ������ָ�� 	size_t = unsigned int;(��λ:�ֽ�)

// //ģ��ʵ��memcpy
// void* my_memcpy(void *dest,const void *sce ,unsigned int size)
// {
// 	void* ret = dest;
// 	assert(dest != NULL);
// 	assert(sce != NULL);

// 	//�Լ�ʵ��
// 	for(int i = 0;i < size;i++)
// 	{
// 		*((char*)dest) = *((char*)sce);	//�Ƚ�void���͵�ָ�����dest��sce��ǿ��ת����char*���͵�ָ��,Ȼ���ڽ�����,
// 		dest++;
// 		sce++;
// 	}

// 	// //���
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
// 	// //error ���ܿ�����ȥ ֻ�ܿ����ַ����о�����

// 	// //int�������ݿ���

// 	// int size = sizeof(arr2[0]);
// 	// //memcpy(arr1,arr2,size * 6);
// 	// my_memcpy(arr1,arr2,size * 6);

// 	// for(int i = 0;i < 6 ;i++)
// 	// {
// 	// 	printf("%d ",arr1[i]);
// 	// }
// 	// printf("\n");



// 	// //�ṹ���������ݿ���

// 	// struct stu arr3[] = {{"����",18},{"����",32}};
// 	// struct stu arr4[3] = {0};

// 	// int size = sizeof(arr4[0]);
// 	// printf("%s %d\n",arr3[0].name,arr3[0].age);
// 	// printf("%s %d\n",arr3[1].name,arr3[1].age);
// 	// printf("***************************\n");

// 	// memcpy(arr3,arr4,size * 3);
// 	// my_memcpy(arr3,arr4,size * 3);

// 	// printf("%s %d\n",arr3[0].name,arr3[0].age);
// 	// printf("%s %d\n",arr3[1].name,arr3[1].age);


// 	//��12345������34567��λ����
// 	//Ӧ����:1 2 1 2 3 4 5 8 9 10
// 	int arr[] = {1,2,3,4,5,6,7,8,9,10};
// 	my_memcpy(arr+2 , arr , sizeof(arr[0]) * 5);
// 	for(int i = 0;i < 10 ;i++)
// 	{
// 		printf("%d ",arr[i]);
// 	}
// 	printf("\n");
// 	//���Ǳ�Ϊ:1 2 1 2 1 2 1 8 9 10
// 	//�ص�����������

// 	//��Ȼmemcpy���������ڴ��ص����������
// 	//��c���Ա�׼�⺯����ר�ŵ������ڴ��ص������ĺ��� - memmove
// 	//����60�ּ���,��memcpy����100��

// 	return 0;
// }





// //memmove -  �ڴ��ص���������

// //ģ��ʵ��
// void* my_memmove(void* dest, void* src,unsigned int count)
// {
// 	assert(dest != NULL);
//  	assert(src != NULL);
// 	void* ret = dest;
	
// 	// //����
// 	// //�� ǰ -> �� ����
// 	// if(dest < src)
// 	// {
// 	// 	for(int i = 0 ;i < count ;i++)
// 	// 	{
// 	// 		*(char *)dest = *(char *)src;
// 	// 		dest++;
// 	// 		src++;
// 	// 	}
// 	// }
// 	// //�� �� -> ǰ ����
// 	// else
// 	// {
// 	// 	for(int i = 0 ;i < count ;i++)
// 	// 	{
// 	// 		*(char *)dest = *(char *)src;
// 	// 		dest--;
// 	// 		src--;
// 	// 	}
// 	// }


// 	//���
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
// 	// //��12345������34567��λ����
// 	// //Ӧ����:1 2 1 2 3 4 5 8 9 10
// 	// int arr[] = {1,2,3,4,5,6,7,8,9,10};
// 	// memmove(arr+2 , arr , sizeof(arr[0]) * 5);
// 	// for(int i = 0;i < 10 ;i++)
// 	// {
// 	// 	printf("%d ",arr[i]);
// 	// }
// 	// printf("\n");
// 	// //1 2 1 2 3 4 5 8 9 10


// 	//��12345������34567��λ����
//  	//Ӧ����:1 2 1 2 3 4 5 8 9 10
// 	int arr[] = {1,2,3,4,5,6,7,8,9,10};
// 	my_memmove(arr + 2, arr , sizeof(arr[0]) * 5);
// 	for(int i = 0;i < 10 ;i++)
// 	{
// 		printf("%d ",arr[i]);
// 	}
// 	printf("\n");
	


// 	return 0;	
// }




// //memcmp - �ڴ�ȽϺ���

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




//memset //�ڴ����ú���
//vod* memset(void* dest,int c ,size_t count);
//int c ָ�������õ��ַ���ʲô

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

	//ע��
	int arr2[10] = {0};
	memset(arr2 , 1 ,10);
	for(int i = 0 ; i < 10;i++)
	{
		printf("%d ",arr2[i]);
	}
	//16843009 16843009 257 0 0 0 0 0 0 0 
	//�ô��˻�������������,��Ϊ��һ���ֽ�һ���ֽڸĵ�

	return 0;
}
