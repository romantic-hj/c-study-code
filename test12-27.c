#include <stdio.h>
//给定2两个数，求它们的最大公约数。
// 递归
//int ooo(int x, int y)
//{
//	if (x % y != 0)
//	{
//		int t = y;
//		y = x % y;
//		x = t;
//		ooo(x, y);
//	}
//		return y;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int x = 0;
//	int y = 0;
//	scanf("%d %d", &a, &b);
//	if (a < b)
//	{
//		x = b;
//		y = a;
//	}
//	else
//	{
//		x = a;
//		y = b;
//	}
//	int ret = ooo(x, y);
//	printf("%d\n", ret);
//	return 0;
//}
// 普通解法1；
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int min = (a < b) ? a: b;
//	int m = min;
//	for (int i = m; i >= 1; i--)
//	{
//		if (a % i == 0 && b % i == 0)
//		{
//			printf("%d", i);
//			break;
//		}
//	}
//	return 0;
//}
//辗转相除法；
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	while (a % b)
//	{
//		int t = a % b;
//		a = b;
//		b = t;
//	}
//	printf("%d", b);
//	return 0;
//}


//1-100中数字9的个数
//int main()
//{
//	int count = 0;
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9 )
//		{
//			count++;
//		}
//		if (i / 10 == 9)
//		{
//			count++;
//		}
//	}
//	printf("\n%d\n", count);
//	return 0;
//}


//计算1/1-1/2+1/3-1/4+1/5......+1/99-1/100的值，输出结果
//int main()
//{
//	int i = 0;
//	double ret = 0.0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		/*if (i % 2 != 0)
//		{
//			ret = ret + 1.0 / i;
//		}
//		else
//		{
//			ret = ret - 1.0 / i;
//		}*/
//		ret = ret + flag * 1.0 / i;//效率更高，尽量有意识的简化代码
//		flag = -flag;
//	}
//	printf("%lf\n", ret);
//	return 0;
//}

//在屏幕上输出9*9乘法口诀表
//int main()
//{
//	for (int i = 1; i <= 9; i++)            //打印9行
//	{                                    
//		for (int j = 1; j <= i; j++)        //一行i向
//		{
//			printf("%d*%d=%-2d ", j, i, i * j);//两位左对齐！
//		}
//		printf("\n");
//	}
//	return 0;
//}