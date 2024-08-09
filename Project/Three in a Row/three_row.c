//
#include <stdio.h>
#define size 3

void menu()
{
	printf("****************\n");
	printf("***1.开始游戏*****\n");
	printf("***2.退出游戏*****\n");
	printf("****************\n");
	printf("\n");
	
}


void wellcome()//首页
{
	printf("*****************\n");
	printf("****wellcome*****\n");
	printf("*****************\n");
	printf("\n");
}

void byebye()//结束页
{
	printf("*****************\n");
	printf("****byebye*****\n");
	printf("*****************\n");
	printf("\n");
}

void intboard(char arr[size][size])//初始化棋盘
{
	for(int i = 0 ;i < size;i++)
	{
		for(int j = 0 ;j < size;j++)
		{
			arr[i][j]=' ';
		}
	}
	
}

void printf_board(char arr[size][size])//打印棋盘
{
	printf("%c|%c|%c\n",arr[0][0],arr[0][1],arr[0][2]);
	printf("-----\n");
	printf("%c|%c|%c\n",arr[1][0],arr[1][1],arr[1][2]);
	printf("-----\n");
	printf("%c|%c|%c\n",arr[2][0],arr[2][1],arr[2][2]);
}

int  scanf_board(char arr[size][size],int player)//输入棋盘
{
	int row,col;
	scanf("%d %d",&row,&col);
	if(row > 3 || col > 3)
	{
		return 1;
		printf("输入错误\n");
	}
	
	if(player == 1 && player != 2)
	{
		arr[row - 1][col - 1] = 'X';	
	}
	else
	{
		arr[row - 1][col - 1] = 'O';
	}
	
}//1输入错误

int chek_win(char arr[size][size])//检查获胜
{
	//检查行
	if( arr[0][0] == arr[0][1] && arr[0][2] == arr[0][1] && arr[0][1] != ' ' || 
		arr[1][0] == arr[1][1] && arr[1][2] == arr[1][1] && arr[1][1] != ' ' || 
		arr[2][0] == arr[2][1] && arr[2][2] == arr[2][1] && arr[2][1] != ' '
	  )
	{
		printf("win\n"); 
		return 1;
	}
	
	//检查列
	else if(arr[0][0] == arr[1][0] && arr[2][0] == arr[1][0] && arr[1][0] != ' ' ||
			arr[0][1] == arr[1][1] && arr[2][1] == arr[1][1] && arr[1][1] != ' ' ||
			arr[0][2] == arr[1][2] && arr[2][2] == arr[1][2] && arr[1][2] != ' '
		)
	{
		printf("win\n");
		return 1;
	}
	//检查对角线
	else if(arr[0][0] == arr[1][1] && arr[2][2] == arr[1][1] && arr[1][1] != ' ' ||
			arr[0][2] == arr[1][1] && arr[2][0] == arr[1][1] && arr[1][1] != ' '
			)
	{
		printf("win\n");
		return 1;
	}
	else
	{
		return 0;
	}
}//1获胜0没有


void swap_player(int *player)
{
	if(*player == 1)
		*player = 2;
	else 
		*player = 1; 
}

void printf_player(int player)
{
	if(player == 1 && player != 2)
	{
		printf("现在是玩家%d 输入“X”\n请输入行和列，中间用“ ”隔开\n",player);
	}
	else
	{
		printf("现在是玩家%d 输入“O”\n请输入 行 列\n",player);
	}
}

void printf_win(int player)
{
	if(player == 1 && player != 2)
	{
		printf("*****************\n");
		printf("玩家2获胜\n",player);
		printf("*****************\n");
		printf("\n");
		printf("\n");
		
	}
	else
	{
		printf("*****************\n");
		printf("玩家1获胜\n",player);
		printf("*****************\n");
		printf("\n");
		printf("\n");
	}
}

void game(char board[size][size],int player,int row,int col)
{
	wellcome();
	intboard(board);
	
	while(chek_win(board) != 1)
	{
		printf_board(board);
		printf_player(player);
		scanf_board(board,player);
		chek_win(board);
		swap_player(&player);
	}
	printf_win(player);
	
	byebye();
}

// menu();
// wellcome();
// intboard(board);
// printf_board(board);
// scanf_board(board,player);
// chek_win(board);
// swap_player(&player);
// printf_player(player);
// printf_win(player);
// byebye();
// game();
 
 
int main()
{
	char board[size][size];
	int row,col;		//
	int player = 1; 	//1输入x，2输入o
	
	menu();
	
	int choose;
	printf("请选择\n");
	scanf("%d",&choose);
	
	switch(choose)
	{
		case 1:
			game(board,player,row,col);
			break;
		case 2:
			break;
		default:
			printf("选择错误\n");
	}
	


}
