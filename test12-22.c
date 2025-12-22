#include <stdio.h>

//第一题：计算n的阶乘
//int main()
//{
//	int n = 0;
//	int r = 1;
//	int i = 1;
//	scanf("%d", &n);
//	do
//	{
//		r = r * i;
//		i++;
//	} 
//	while (i <= n);
//	printf("%d", r);
//	return 0;
//}


//第二题：计算1！+2！+3！+···+10！
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	int j = 0;
//	int r = 1;
//	int s = 0;
//	for (i = 0; i < 10; i++)
//	{
//		r = 1;//每次求一个数的阶乘都要重置r的值，不然会累积乘！！！
//		for (j = 1; j <= arr[i]; j++)
//		{
//			r = j * r;
//		}
//		s = r + s;
//	}
//	printf("%d", s);
//	return 0;
//}
//int main()          //解法二
//{
//	int n = 0;
//	int ret = 1;
//	int sum = 0;
//	for (n = 1; n <= 10; n++)
//	{
//		ret = ret * n;    //前一个数的阶乘乘下一个数就是下个数的阶乘
//		sum = sum + ret;
//	}
//	printf("%d", sum);
//
//	return 0;
//}


//第三题：在一个有序数组中查找一个数字（使用二分查找算法更效率）
//int main()            //数据越多此算法效率越高
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 0;
//	scanf("%d", &k);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;         //两种写法
//      int mid = left + (right -left)/2;     //这样写防止数据过大导致溢出。
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("已找到，下标为%d", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到，超出范围。");
//	}
//	return 0;
//}


//第四题：演示多个字符从两端移动，向中间汇聚
//#include <windows.h>
//#include <stdlib.h>
//int main()
//{
//	char arr1[] = "welcome to Shanghai!";
//	char arr2[] = "^^^^^^^^^^^^^^^^^^^^";
//	int left = 0;
//	int right = strlen(arr1) - 1;//int right = sizeof(arr1)/sizeof(arr[0])-2;//sizeof的计算包括了\0
//	while (left<=right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);              //制造时间间隔1s，要引用windows头文件
//		system("cls");            //清空屏幕
//		left++;
//		right--;
//	}
//	printf("%s\n", arr2);
//
//
//	return 0;
//}



//第五题：编写代码，模拟用户登录情景，且只能登录三次。（只允许输入三次）
//比较两个字符串是否相等，用库函数strcmp，头文件为sriing.h,相等时返回0
//#include <string.h>
//int main()
//{
//	int i = 0;
//	char arr1[] = "20041011";
//	char arr2[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码：");
//		scanf("%s", arr2);
//		if (strcmp(arr2, arr1) == 0)
//		{
//			printf("登录成功");
//			break;
//		}
//		else
//		{
//			printf("密码不正确\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("机会用尽，登录失败\n");
//	}
//	return 0;
//}

//第六题：一个易错题
//void fun(int a[])                //实际上传过来的是一个指针，大小为4或8
//{                                //数组名在作为函数参数是会退化为指向首元素的指针
//	printf("%zu", sizeof(a));
//}
//int main()
//{
//	int a[10] = { 0 };
//	printf("%zu\n", sizeof(a));
//	printf("%zu\n", sizeof(a[1]));
//	fun(a);                       //数组传参的时候传递的是数组首元素的【地址】
//	return 0;
//}