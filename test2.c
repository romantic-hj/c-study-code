
#include "game2.h"

static void menu()
{
	printf("***********************\n");
	printf("********1.play*********\n");
	printf("********0.exit*********\n");
	printf("***********************\n");
}

static void game()
{
	//设置两个数组
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化两个数组
	init_board(mine, ROWS, COLS, '0');
	init_board(show, ROWS, COLS, '*');
	//打印数组
	display_board(show, ROW, COL);
	//display_board(mine, ROW, COL);
	//设置雷
	set_mine(mine, ROW, COL);
	/*display_board(mine, ROW, COL);*/
	//排雷函数
	play_game(mine, show, ROW, COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择是否进行游戏——>");
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