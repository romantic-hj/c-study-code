#include <stdio.h>
//写一个函数将数组从小到大排序——冒泡排序算法
void bubble_sort(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz-1; i++)//10个元素一共要排sz-1=9趟
	{
		int j = 0;
		for (j = 0; j <sz-1-i ; j++)//每趟对应的元素个数为sz-i个，交换的次数再减1
		{
			if (arr[j] > arr[j + 1])
			{
				int t = arr[j+1];
				arr[j + 1] = arr[j];
				arr[j] = t;
			}
		}
	}
}
int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);//arr传的是指针，大小要先计算
	bubble_sort(arr,sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
