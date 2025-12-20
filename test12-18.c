#include <stdio.h>
//int main()
//{
//	printf("hello world!\n");
//	printf("你好世界！");
//	return 0;
//}

//getchar函数的应用
//int main() {
//    int ch;
//    printf("请输入字符（按Ctrl+D结束）：\n");
//    // 循环读取，直到遇到EOF
//    while ((ch = getchar()) != EOF) {
//        printf("读取到：%c (ASCII: %d)\n", ch, ch);
//    }
//    printf("已到达输入末尾（EOF）\n");
//    return 0;
//}


//int main() {
//    int num;
//    char ch;
//    printf("请输入一个数字：");
//    scanf("%d", &num);  // 输入123后按回车，缓冲区残留\n
//    printf("数字：%d\n", num);
//
//    // 清空缓冲区的\n（关键步骤）
//    getchar();  // 读取残留的换行符
//
//    printf("请输入一个字符：");
//    ch = getchar();
//    printf("字符：%c\n", ch);
//    return 0;
//}

// 作业1：打印数字对应的字符

//int main()
//{
//	printf("%c%c%c%c", 73, 32, 99, 97);
//	return 0;
//}

 //答案
//int main()
//{
//	int arr[] = { 73, 32, 99, 97 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);//计算数组的大小
//	while (i < sz)                        //遍历数组元素
//	{
//		printf("%c", arr[i]);
//		i++;
//	}
//	return 0;
//}

//作业2：出生年月

//int main()
//{
//	int y = 0;
//	int m = 0;
//	int d = 0;
//	scanf("%4d%2d%2d", &y, &m, &d);
//	printf("year=%4d\n", y);
//	printf("month=%02d\n", m);
//	printf("date=%02d", d);
//	
//	return 0;
//	
//}

//作业3：找四个数中最大的数
//int main()
//{
//	int arr[4] = { 0 };
//	int i = 0;
//	while (i < 4)
//	{
//		scanf("%d", &arr[i]);//可以以空格隔开，scanf不会去读取空格
//		i++;
//	}
//	int max = arr[0];
//	i = 1;
//	while (i < 4)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//		i++;
//	}
//	printf("%d", max);
//	return 0;
//}

//作业4：求给定半径球的体积
//int main()
//{
//	float r = 0.0f;
//	//圆周率给到只读模式
//	const float pi = 3.1415926f;
//	scanf("%f", &r);
//	//注意三分之四必须用小数除法！！！
//	float V = 4.0f / 3.0f * pi * r * r * r;
//	printf("%.3f", V);
//	
//	return 0;
//}

//作业5：计算BMI指数
//int main()
//{
//	float w = 0.0f;
//	float h = 0.0f;
//	float BMI = 0.0f;
//	scanf("%f", &w);
//	scanf("%f", &h);
//	BMI = w / h / h * 10000;
//	printf("%.2f", BMI);
//
//	return 0;
//}