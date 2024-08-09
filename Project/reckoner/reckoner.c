//计算器

#include <stdio.h>

void menu()
{
	printf("**************************\n");
	printf("***1.add          2.sub***\n");
	printf("***3.mul          4.rem***\n");
	printf("***5.rem         0.exit***\n");
	printf("**************************\n");
}
int add(int x,int y)
{
	return x + y;
}
int sub(int x,int y)
{
	return x - y;
}
int mul(int x,int y)
{
	return x * y;
}
int div(int x,int y)
{
	return x / y;
}
int rem(int x,int y)
{
	return x % y;
}

void input2()
{
	printf("请选择\n");
	int (*pcarr[6])(int ,int ) = {0,add,sub,mul,div,rem};
	int input;
	scanf("%d",&input);
	int x,y;
	printf("输入两个数\n");
	scanf("%d%d",&x,&y);
	printf("%d",pcarr[input](x ,y));
	
}




// void input1()
// {
	// printf("请选择\n");
	// int input;
	// scanf("%d",&input);
	// printf("请选择\n");
	// int x,y;

		// switch(input)
		// {
			// case 1:
				// printf("输入两个数\n");
				// scanf("%d%d",&x,&y);
				// printf("相加为%d\n",add(x,y));
				// break;
			// case 2:
				// printf("输入两个数\n");
				// scanf("%d%d",&x,&y);
				// printf("相减为%d\n",sub(x,y));
				// break;
			// case 3:
				// printf("输入两个数\n");
				// scanf("%d%d",&x,&y);
				// printf("相乘为%d\n",mul(x,y));
				// break;
			// case 4:
				// printf("输入两个数\n");
				// scanf("%d%d",&x,&y);
				// printf("相除为%d\n",div(x,y));
				// break;
			// case 5:
				// printf("输入两个数\n");
				// scanf("%d%d",&x,&y);
				// printf("相余为%d\n",rem(x,y));
				// break;
			// case 0:
				// break;
			// default:
				// printf("输入错误\n");
				
		// }
// }

int main()
{
	menu();
	input2();
	return 0;
}
