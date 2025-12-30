#include <stdio.h>
//第一题：编写一个函数reverse_string(char* string)（递归实现）
//将参数字符串中的内容反向排列，不是逆序打印

//void reserve_string(char* str)  //解法一
//{
//	char tmp = *str;//存第一个元素
//	int len = (strlen(str) - 1);
//	*str = *(str + len);//第一个与最后交换
//	*(str + len) = '\0';//最后一个放\0，让中间变成完整新数组
//	if (strlen(str+1)>=2)
//		reserve_string(str + 1);//换下一个数组
//	*(str + len) = tmp;//最后变成第一个
//}
//void reserve_string(char ch[], int left, int right)//解法二（简单）
//{
//	char tmp = ch[left];//得到左右坐标，直接交换左右
//	ch[left] = ch[right];
//	ch[right] = tmp;
//	if (left < right)   //左加右减，再换中间的左右
//		reserve_string(ch, left + 1, right - 1);
//}
//
//int main()
//{
//	char ch[] = "abcdefg";
//	int sz = sizeof(ch) / sizeof(ch[0]);//sizeof包括\0，strlen不包括
//	int left = 0;
//	int right = sz - 2;
//	reserve_string(ch, left, right);
//	//非递归方法
//	//int left = 0;
//	//int right = sz - 2;
//	//while (left<right)
//	//{
//	//	char tmp = ch[left];
//	//	ch[left] = ch[right];
//	//	ch[right] = tmp;
//	//	left++;
//	//	right--;
//	//}
//	printf("%s", ch);
//	return 0;
//}



////第二题：写一个递归函数Digitsum(n),输入一个非负整数，返回它每位数字之和
////        如Digitsum（1729），返回19

//int Digitsum(int n)
//{
//	if (n >= 1)
//		return (n % 10) + Digitsum(n / 10);
//	else
//		return 0;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Digitsum(n);
//	printf("%d\n", ret);
//	return 0;
//}


//第三题：递归实现n的k次方

//double pow(int n, int k)        
//{
//	if (k == 0)
//		return 1;
//	else if (k > 0)
//		return n * pow(n, k - 1);
//	else
//		return 1.0 / pow(n, -k);
//}
//int main()
//{
//	int n = 0, k = 0;
//	scanf("%d %d", &n, &k);
//	double ret = pow(n, k);
//	printf("%lf\n", ret);
//	return 0;
//}