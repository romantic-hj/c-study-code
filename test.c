#define _CRT_SECURE_NO_WARNINGS
//一个三子棋小游戏的实现
//test.c文件用于测试逻辑
//game.c用于写游戏实现的函数
//game.h用于写头文件与各个函数声明
#include "game.h"

static void menu()
{
	printf("*************************\n");
	printf("*********1.play**********\n");
	printf("*********0.exit**********\n");
	printf("*************************\n");
}

static void game()
{
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	infor_board(board, ROW, COL);
	//打印棋盘
	display_board(board, ROW, COL);
	while (1)
	{   //玩家输入
		playermove(board, ROW, COL);
		//判断输赢
		char ret = Iswin(board, ROW, COL);
		if (ret == '*')
		{
			printf("玩家赢了\n");
			display_board(board, ROW, COL);
			break;
		}
		else if (ret == '#')
		{
			printf("电脑赢了\n");
			display_board(board, ROW, COL);
			break;
		}
		else if (ret == 'Q')
		{
			printf("平局\n");
			display_board(board, ROW, COL);
			break;
		}
		display_board(board, ROW, COL);
		//电脑输入
		cputmove(board, ROW, COL);
		//判断输赢
		ret = Iswin(board, ROW, COL);
		if (ret == '*')
		{
			printf("玩家赢了\n");
			display_board(board, ROW, COL);
			break;
		}
		else if (ret == '#')
		{
			printf("电脑赢了\n");
			display_board(board, ROW, COL);
			break;
		}
		else if (ret == 'Q')
		{
			printf("平局\n");
			display_board(board, ROW, COL);
			break;
		}
		display_board(board, ROW, COL);
	}

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择0或1来选择是否进入游戏->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
		}
	} while (input);
	return 0;
}