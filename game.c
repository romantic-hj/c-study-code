#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

//初始化棋盘
void infor_board(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//打印棋盘
void display_board(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (j < col - 1)
				printf(" %c |", board[i][j]);
			else
				printf(" %c \n", board[i][j]);
		}
		if (i<row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				if (j < col - 1)
					printf("---|");
				else
					printf("---\n");
			}
		}
	}
}

// 玩家输入
void playermove(char board[ROW][COL], int row, int col)
{
	printf("玩家输入\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入坐标-->");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("该坐标已被占用，请重新输入\n");
		}
		else
			printf("坐标不合法，请重新输入\n");
	}
}

// 智能版电脑落子函数（替换原有纯随机逻辑）
void cputmove(char board[ROW][COL], int row, int col)
{
	printf("电脑落子\n");
	int x = -1, y = -1;

	// 优先级1：电脑自己一步赢
	if (check_win_pos(board, row, col, '#', &x, &y))
	{
		board[x][y] = '#';
		return;
	}

	// 优先级2：阻止玩家一步赢
	if (check_win_pos(board, row, col, '*', &x, &y))
	{
		board[x][y] = '#';
		return;
	}

	// 优先级3：抢占中心位置（3x3棋盘中心坐标是(1,1)）
	int center_x = row / 2;
	int center_y = col / 2;
	if (board[center_x][center_y] == ' ')
	{
		board[center_x][center_y] = '#';
		return;
	}

	// 优先级4：抢占四个角落（(0,0)、(0,2)、(2,0)、(2,2)）
	int corners[4][2] = { {0, 0}, {0, 2}, {2, 0}, {2, 2} };
	for (int i = 0; i < 4; i++)
	{
		int cx = corners[i][0];
		int cy = corners[i][1];
		if (board[cx][cy] == ' ')
		{
			board[cx][cy] = '#';
			return;
		}
	}

	// 优先级5：兜底随机落子（以上点位都被占时）
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//判断输赢
//返回*表示玩家赢，#表示电脑，Q表示平局，C表示继续
char Iswin(char board[ROW][COL], int row, int col)
{
	//行
	for (int i = 0; i < row; i++)
	{
		int count = 0;
		for (int j = 0; j < col; j++)
		{
			if (board[i][j]==board[i][0])
				count++;
		}
		if (count == col)
			return board[i][0];
	}
	//列
	for (int i = 0; i < col; i++)
	{
		int count = 0;
		for (int j = 0; j < row; j++)
		{
			if (board[j][i]==board[0][i])
				count++;
		}
		if (count == row)
			return board[0][i];
	}
	//对角线
	int count1 = 0;
	for (int i = 0, j = col-1; i < row && j>=0; i++, j--)
	{
		if (board[i][j]==board[0][col-1])
			count1++;
	}
	if (count1 == col)
		return board[0][col-1];
	int count2 = 0;
	for (int i = 0, j = 0; i < row && j < col; i++, j++)
	{
		if (board[i][j]==board[row-1][col-1])
			count2++;
	}
	if (count2 == col)
		return board[0][0];
	//平局或继续
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 'C';
		}
	}
	return 'Q';
}

// 辅助函数：检查是否有一步获胜/堵截的点位
int check_win_pos(char board[ROW][COL], int row, int col, char target, int* x, int* y)
{
	// 1. 检查行
	for (int i = 0; i < row; i++)
	{
		int count = 0; // 目标棋子数量
		int empty_x = -1, empty_y = -1; // 空位置坐标
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == target)
				count++;
			else if (board[i][j] == ' ')
			{
				empty_x = i;
				empty_y = j;
			}
		}
		// 有2个目标棋子 + 1个空位 → 落子到空位
		if (count == 2 && empty_x != -1)
		{
			*x = empty_x;
			*y = empty_y;
			return 1;
		}
	}

	// 2. 检查列
	for (int j = 0; j < col; j++)
	{
		int count = 0;
		int empty_x = -1, empty_y = -1;
		for (int i = 0; i < row; i++)
		{
			if (board[i][j] == target)
				count++;
			else if (board[i][j] == ' ')
			{
				empty_x = i;
				empty_y = j;
			}
		}
		if (count == 2 && empty_x != -1)
		{
			*x = empty_x;
			*y = empty_y;
			return 1;
		}
	}

	// 3. 检查正对角线（左上→右下）
	int count = 0;
	int empty_x = -1, empty_y = -1;
	for (int i = 0; i < row; i++)
	{
		if (board[i][i] == target)
			count++;
		else if (board[i][i] == ' ')
		{
			empty_x = i;
			empty_y = i;
		}
	}
	if (count == 2 && empty_x != -1)
	{
		*x = empty_x;
		*y = empty_y;
		return 1;
	}

	// 4. 检查反对角线（右上→左下）
	count = 0;
	empty_x = -1;
	empty_y = -1;
	for (int i = 0; i < row; i++)
	{
		int j = col - 1 - i;
		if (board[i][j] == target)
			count++;
		else if (board[i][j] == ' ')
		{
			empty_x = i;
			empty_y = j;
		}
	}
	if (count == 2 && empty_x != -1)
	{
		*x = empty_x;
		*y = empty_y;
		return 1;
	}

	// 无获胜/堵截点位
	return 0;
}