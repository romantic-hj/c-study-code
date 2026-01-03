
#include "game2.h"

//初始化数组
void init_board(char ch[ROWS][COLS], int rows, int cols, char target)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			ch[i][j] = target;
		}
	}
}

//打印数组
void display_board(char ch[ROWS][COLS], int row, int col)
{
	printf("-----扫雷游戏-----\n");
	for (int j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", ch[i][j]);
		}
		printf("\n");
	}
	printf("-----扫雷游戏-----\n");

}

//设置雷
void set_mine(char ch[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	int count = EASY;
	while (count)
	{
		//1--9
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (ch[x][y] == '0')
		{
			ch[x][y] = '1';
			count--;
		}
	}
}

//数出坐标周围的雷
int get_mine(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] 
		+ mine[x - 1][y] 
		+ mine[x - 1][y + 1]
		+ mine[x][y - 1]
		+ mine[x][y + 1]
		+ mine[x + 1][y - 1]
		+ mine[x + 1][y]
		+ mine[x + 1][y + 1] - 8 * '0';
}

//排雷函数
void play_game(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	while (judge(show, ROW, COL))
	{
		printf("请输入排查的坐标-->");
		int x = 0, y = 0;
		// 补充：处理非数字输入（可选但建议）
		if (scanf("%d %d", &x, &y) != 2) {
			printf("输入格式错误！请输入两个数字\n");
			// 清空输入缓冲区
			while (getchar() != '\n');
			continue;
		}

		// 修正1：先检查坐标合法性（核心！）
		if (x < 1 || x > 9 || y < 1 || y > 9) {
			printf("坐标不在范围内，请重新输入\n");
			continue;
		}
		// 修正2：再检查是否已点击
		if (show[x][y] != '*') {
			printf("该位置已排查过，请重新输入\n");
			continue;
		}

		// 踩雷逻辑
		if (mine[x][y] == '1') {
			printf("很遗憾，你被炸死了\n");
			display_board(mine, ROW, COL);
			break;
		}
		else {
			// 修正3：先调用展开，无需重复赋值（spread 内部已处理）
			spread(mine, show, x, y);
			display_board(show, ROW, COL);
		}
	}
	if (judge(show, ROW, COL) == 0)
		printf("恭喜你，排完了所有的雷！\n");
}


//展开无雷区域函数
// 修正后的 spread 函数（核心逻辑：先算当前格子雷数，0 才展开周围）
void spread(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	// 1. 终止条件：坐标越界 / 已展开 / 是雷 → 直接返回
	if (x < 1 || x > ROW || y < 1 || y > COL || show[x][y] != '*' || mine[x][y] == '1')
		return;

	// 2. 计算当前格子周围雷数
	int num = get_mine(mine, x, y);
	if (num > 0) {
		// 有雷数 → 仅显示数字，不展开
		show[x][y] = num + '0';
		return;
	}

	// 3. 无雷数 → 显示空白，再递归展开周围 8 格
	show[x][y] = ' ';
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			// 跳过自身
			if (i == 0 && j == 0) continue;
			spread(mine, show, x + i, y + j);
		}
	}
}


//判断输赢
int judge(char show[ROWS][COLS], int row, int col)
{
	int count = 0;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (show[i][j] != '*')
			{
				count++;
			}
		}
	}
	if (count == row * col - EASY)
	{
		return 0;
	}
	else
		return 1;
}