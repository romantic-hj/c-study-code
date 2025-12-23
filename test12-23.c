//猜数字的小游戏
//电脑产生一个随机数（1-100）
//猜数字（猜大，猜小，猜对了结束）
//1.设置一个菜单函数menu（使用dowhile循环）
//2.输入0/1来选择菜单，也用做dowhile的条件，用switch语句来判断输入
//3.封装game函数，功能为生成随机数并通过循环判断大小，在case 1里调用
//4.rand()是标准库提供的伪随机数生成函数，其生成的序列是确定性的：若不主动设置 “种子”，rand()默认使用固定种子（通常是 1），因此每次运行程序，生成的随机数序列完全相同。
//5.需用srand()（种子设置函数）指定变化的种子，通常用当前系统时间作为种子（时间是动态变化的）。
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu()
{
	printf("********************\n");
	printf("*******1.play*******\n");
	printf("*******0.exit*******\n");
	printf("********************\n");
}
void game()
{
	int ret = 0;
	int guess = 0;
	ret = rand() % 100 + 1;//rand生成0-32767的数，若要取a<=x<=b，用rand()%(b-a+1)+a
	while (1)
	{
		printf("请输入数字：");
		scanf("%d", &guess);
		if (guess < ret)
		{
			printf("猜小了\n");
		}
		else if (guess > ret)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("恭喜你，猜对了！\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//种子在工程中只需要设置一次即可，NULL为空指针
	do
	{
		menu();
		printf("请选择->");
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
			printf("输入错误，请重新输入！\n");
		}
	} while (input);

	return 0;
}