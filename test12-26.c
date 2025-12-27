#include <stdio.h>
                            //函数的递归！！！
//例1：接收一个无符号整形，按照顺序打印它的每一位。
//例如：输入：1234， 输出：1 2 3 4.
//void print(unsigned int n)       //递归的实现
//{                                //print（1234）
//    if (n > 9)                   //先print（123），再4
//    {                            //先print（12），再3
//        print(n / 10);           //先print（1），再2
//    }
//    printf("%d ", n % 10);
//}
//int main()
//{
//    unsigned int n = 0;
//    scanf("%u", &n);
//    print(n);
//    return 0;
//}



//例2：编写一个函数（不允许创建临时变量），求字符串长度。
//     模拟实现strlen（）的效果
//循环形式（非答案）
//int my_strlen(char* ch)//数组传参是首元素地址，与char ch[]一样
//{
//    int count = 0;     //计数变量，是临时变量
//    while (*ch != '\0')
//    {
//        count++;
//        ch++;
//    }
//    return count;
//}

//递归求解
//int my_strlen(char* ch)
//{
//    if (*ch != '\0')
//        return 1 + my_strlen(ch + 1);
//    else
//        return 0;
//}
//
//int main()
//{
//    char ch[20] = { 0 };
//    scanf("%s", ch);
//    int len = my_strlen(ch);
//    printf("%d\n", len);
//
//    return 0;
//}


//递归求n的阶乘                       //fac(n)=1. 1   n<=1;
//int fac(int n)                               2. n*fac(n-1)  n>1
//{
//    if (n <= 1)
//        return 1;
//    else
//        return n * fac(n - 1);
//}

//int fac2(int n)
//{
//    int i = 0;
//    int ret = 1;
//    for (i = 1; i <= n; i++)
//    {
//        ret = ret * i;
//    }
//    return ret;
//}
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int ret = fac2(n);
//    printf("%d\n", ret);
//    return 0;
//}



//求第n个斐波那契数
//1 1 2 3 5 8 13 21 34 55......后一个数是前两个数的和
//递归与迭代要合理取舍，代码简洁和时间复杂度问题
//int count = 0;
// 递归求法
//int fib(int n)            //时间复杂度极高，为o(2^n), 采用迭代更好
//{
//    if (n == 3)
//    {
//        count++;
//    }
//    if (n <= 2)
//        return 1;
//    else
//        return fib(n - 1) + fib(n - 2);
//}
//迭代求法
//int fib(int n)
//{
//    int a = 1;
//    int b = 1;
//    int c = 0;
//    if (n >= 3)
//    {
//        for (int i = 3; i <= n; i++)     //时间复杂度只有n-2
//        {
//            c = a + b;
//            a = b;
//            b = c;
//        }
//        return c;
//    }
//    else
//        return 1;
//}
//int main()
//{
//    int n = 0;
//    int ret = 0;
//    scanf("%d", &n);
//    ret = fib(n);
//    printf("%d\n", ret);
//    printf("%d\n", count);
//    return 0;
//}