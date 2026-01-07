#include <stdio.h>

//编写代码实现：求一个整数存储在内存中的二进制中1的个数
//求补码的二进制中1的个数

//int main()
//{
//	int n = 0;
//	if (scanf("%d", &n) != 1)
//	{
//		printf("请输入整数\n");
//		while (getchar() != '\n')
//			return 1;
//	}
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if ((n & 1) == 1)
//		{
//			count++;
//		}
//		n >>= 1;
//	}
//	printf("%d\n", count);
//	return 0;
//}



//小乐乐上课需要走n阶台阶，他每次可以走1或2阶台阶，他一共有多少种走法？
//fib（n）——计算n个台阶的走法
//n = 1    fib(1) = 1
//n = 2    fib(2) = 2
//n > 2    fib(n) = fib(n-1) + fib(n-2)

//int fib(int n)
//{
//	if (n <= 2)
//	{
//		return n;
//	}
//	else
//	{
//		return fib(n - 1) + fib(n - 2);
//	}
//}
//int main()
//{
//	int n = 0;
//	//输入
//	scanf("%d", &n);
//	//计算
//	int m = fib(n);
//	//输出
//	printf("%d", m);
//	return 0;
//}



//删除一串数字中的指定数字

//int main()
//{
//	int n = 0;
//	//输入数字个数
//	scanf("%d", &n);
//	int arr[50] = { 0 };
//	int i = 0;
//	//输入数组
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	//要删除的数
//	int del = 0;
//	scanf("%d", &del);
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (arr[i] != del)
//		{
//			arr[j] = arr[i];//arr[j]中存放不删除的数，存放了j就+1
//			j++;
//		}
//	}
//	for (i = 0; i < j; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//输入n个成绩，换行输出n个成绩中最高分与最低分的差。

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[100] = { 0 };
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int max = arr[0], min = arr[0];
//	for (i = 0; i < n; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//		if (arr[i] < min)
//		{
//			min = arr[i];
//		}
//	}
//	printf("%d\n", (max - min));
//	return 0;
//}



//完成字母大小写的转换

//int main()
//{
//	char ch = 0;
//
//	while (scanf("%c", &ch) == 1)
//	{
//		if (ch >= 'a' && ch <= 'z')//if(islower(ch))
//			printf("%c\n", ch - 32);
//		else if (ch >= 'A' && ch <= 'Z')//if(isupper(ch))
//			printf("%c\n", ch + 32);
//	}
//	return 0;
//}



//变种水仙花数：判断一个五位数是不是lily number

//#include <math.h>
//int main()
//{
//	int i = 0;
//	for (i = 10000; i <= 99999; i++)
//	{
//		int j = 0;
//		int sum = 0;
//		for (j = 1; j <= 4; j++)
//		{
//			int k = pow(10, j);
//			sum += (i / k) * (i % k);
//		}
//		if (sum == i)
//			printf("%d", i);
//	}
//	return 0;
//}