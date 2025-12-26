#include <stdio.h>
//使用函数来交换两个整形的值（考察形参与实参）
//当实参传递给形参的时候，形参是实参的一份临时拷贝
//对形参的修改不能改变实参
//此处需要改变实参a，b的值，需要向函数传递地址
//void Swap(int* px, int* py)
//{
//	int z = *px;//z=a
//	*px = *py;  //a=b
//	*py = z;    //b=a
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("交换前a=%d, b=%d\n", a, b);
//	Swap(&a, &b);
//	printf("交换后a=%d, b=%d\n", a, b);
//	return 0;
//}


//生成100-200之间的素数
//#include<math.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//	//for (i = 100; i <= 200; i++)
//	for (i = 101; i <= 200; i+=2)       //从奇数开始找，数据直接少一半
//	{
//		int j = 0;
//		int flag = 1;                   //flag=1表示是素数
//		//for (j = 2; j <= i - 1; j++)
//		for (j = 2; j <= sqrt(i); j++) // 一定有一个因子小于i开平方，这样写遍历数据更少
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\ncount=%d", count);
//	return 0;
//}


//写一个函数来判断一个数是不是素数
//int is_prime(int n)
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(n); j++)
//	{
//		if (n % j == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}


//写一个函数判断是不是闰年
//1.能被4整除，并且不能被100整除
//2.能被400整除
//int is_leap_year(int n)
//{
//	if (((n % 4 == 0) && (n % 100 != 0)) || (n % 400 == 0))
//		return 1;
//	else
//		return 0;
//}


//写一个函数，实现一个整形有序数组的二分查找。
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	int k = 0;
//	scanf("%d", &k);
//	while (1)
//	{
//		int mid = left + (right - left) / 2;//不写left+right防止数据溢出
//		if (k < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else if (k > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了，下标为%d\n", mid);
//			break;
//		}
//		if (left > right)
//		{
//			printf("不在范围内\n");
//			break;
//		}
//	}
//	return 0;
//}
//
//int binary_search(int arr[], int k, int sz)//数组传参传的是首元素指针，函数里还是在调用原数组，没有再创建（为了节省空间）
//{
//	int left = 0;
//	int right = sz - 1;
//	while (1)
//	{
//		int mid = left + (right - left) / 2;//不写left+right防止数据溢出
//		if (k < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else if (k > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			return mid;//找到返回下标
//		}
//
//		return -1;//找不到返回-1
//	}
//}